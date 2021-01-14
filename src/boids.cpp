#include "boids.hpp"

/*
Still need to firgure out why boids are flying everywhere and add seperation
*/

Boid::Boid(){
	int randomx = rand() % screenWidth;
	int randomy = rand() % screenHeight;
	int randXv = (rand() % 4) - 2;
	position = {(float)randomx, (float)randomy};  
	velocity = {float(randXv), float(randXv)};
	acceleration = {0.0f, 0.0f};
}

void Boid::show(){
	DrawCircleV(position, radius, WHITE); 		
}

void Boid::edge_wrap(){
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

Vector2 Boid::align(std::vector<Boid> boids){
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
	return steering;
}

Vector2 Boid::cohesion(std::vector<Boid> boids){
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

void Boid::flock(std::vector<Boid> boids){
	Vector2 ali = align(boids);
	Vector2 coh = cohesion(boids);
	apply(ali);
	apply(coh);
}

void Boid::apply(Vector2 force){
	acceleration.x += force.x;
	acceleration.y += force.y;
}

void Boid::update(){
	velocity.x += acceleration.x; 
	velocity.y += acceleration.y;

	position.x += velocity.x;
	position.y += velocity.y;

	acceleration = {0.0f, 0.0f};
}
