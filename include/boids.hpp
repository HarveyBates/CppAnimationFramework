#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <math.h>
#include <cstdlib>
#include <cmath>

extern const int screenWidth;
extern const int screenHeight;

class Boid{
	Vector2 position, velocity, acceleration;
	float radius = 5.0f;
	const int perceptionRadius = 50;
public:
	Boid();
	void show();
	void edge_wrap();
	Vector2 align(std::vector<Boid> boids);
	Vector2 cohesion(std::vector<Boid> boids);
	void flock(std::vector<Boid> boids);
	void apply(Vector2 force);
	void update();
};
