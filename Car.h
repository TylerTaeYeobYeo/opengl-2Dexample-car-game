//#include <windows.h>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>


#ifndef _Car
#define _Car

#define resetX -465
#define resetY -494

typedef enum{
	LEFT,
	RIGHT,
	UP,
	DOWN
}car_direction;


class Car{
	GLuint car_texture;
	car_direction direction = UP;
	float speed = 0;
	float accel = 0.2f;
	float pos_x = resetX, pos_y = resetY;
	int mode = 2;
	int angle = 0;
public:
	Car();
	//position
	float posX();
	float posY();
	void setPosX(float x);
	void setPosY(float y);
	void reset(double time);
	int highScore = 0;

	void changeView();
	car_direction getDirection();
	void setDirection(car_direction new_direction);
	

	void display();
	void textureOn(GLuint texture);//텍스쳐 입힘
	void Rotate(car_direction dir);//입력받은 키에 따라 텍스쳐가 돌아감
	
	void accelerate(car_direction dir);
	void deAccelerate();
	float getAccel();
	float getSpeed();
	void setSpeed(float newSpeed);

	void modeSlow();
	void modeMedium();
	void modeFast();
	void faster();
};

#endif _Car