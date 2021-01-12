#include "main.h"
#include "stdlib.h"

const int screenWidth = 800;
const int screenHeight = 450;

class Boid{
	Vector2 position, velocity, acceleration;
	float radius = 5.0f;
	const int perceptionRadius = 50;
public:
	Boid(){
		int randomx = rand() % screenWidth;
		int randomy = rand() % screenHeight;
		int randXv = rand() % 4;
		position = {(float)randomx, (float)randomy};  
		velocity = {0.1f, float(randXv)};
		acceleration = {0.0f, 0.0f};
	}

	void show(){
		DrawCircleV(position, radius, WHITE); 		
	}

	void edge_wrap(){
		if(this->position.x > screenWidth){
			this->position.x = 0;
		}
		else if(this->position.x < 0){
			this->position.x = screenWidth;
		}
		else if(this->position.y > screenHeight){
			this->position.y = 0;
		}
		else if(this->position.y < 0){
			this->position.y =screenHeight;
		}
	}

	void align(std::vector<Boid> boids){
		int sum = 0;
		Vector2 steering; 
		for(int i = 0; i < boids.size(); i++){
			int distance = std::abs(this->position.x - boids[i].position.x) + 
				std::abs(this->position.y - boids[i].position.y);
			if(distance != 0 && distance < perceptionRadius){
					steering.x += boids[i].velocity.x;
					steering.y += boids[i].velocity.y;
					sum++;
			}
		}
		if(sum > 0){
			steering.x = (steering.x / sum) - this->velocity.x;
			steering.y = (steering.y / sum) - this->velocity.y;
		}
		this->acceleration.x = steering.x;
		this->acceleration.y = steering.y;
	}

	Vector2 cohesion(std::vector<Boid> boids){
		int sum = 0;
		Vector2 steering;
		for(int i = 0; i < boids.size(); i++){
			int distance = std::abs(this->position.x - boids[i].position.x) + 
				std::abs(this->position.y - boids[i].position.y);
			if(distance != 0 && distance < perceptionRadius){
				steering.x += boids[i].position.x;
				steering.y += boids[i].position.y;
				sum++;
			}
		}
		if(sum > 0){
			steering.x = (steering.x / sum) - this->position.x - this->velocity.x;
			steering.y = (steering.y / sum) - this->position.y - this->velocity.y;
		}
		return steering;	
	}

	//void flock(std::vector<Boid> boids){
	//	Vector2 alignment = align(boids);
	//	acceleration.x = alignment.x;
	//	acceleration.y = alignment.y;
	//}

	void update(){
		position.x += velocity.x;
		position.y += velocity.y;

		velocity.x += acceleration.x;
		velocity.y += acceleration.y;
	}
};

std::vector<Boid> flock;


int main(void)
{
    InitWindow(screenWidth, screenHeight, "Window");

    const int frameRate = 60;
    SetTargetFPS(frameRate);
	const int numBoids = 100;


	for(int i = 0; i < numBoids; i++){
		flock.push_back(Boid());
	}

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(BLACK);

		for(int i = 0; i < flock.size(); i++){
			flock[i].edge_wrap();
			flock[i].align(flock);
			flock[i].show();
       		flock[i].update(); 
		}
       
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
