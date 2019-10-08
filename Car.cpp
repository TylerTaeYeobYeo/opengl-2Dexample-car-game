#include "Car.h"
using namespace std;




Car::Car(){
	cout << "Car Created" << endl;
}

void Car::display(){
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glColor3f(1,1, 1);
	Rotate(direction);

	glDepthMask(GL_FALSE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, car_texture);
	glBegin(GL_QUADS);/*0.15 -0.15 -0.1 -0.4*/
	glTexCoord2f(1, 0);	glVertex2f(0.15, 0.15);
	glTexCoord2f(1, 1);	glVertex2f(0.15, -0.15);
	glTexCoord2f(0, 1);	glVertex2f(-0.15, -0.15); 
	glTexCoord2f(0, 0);	glVertex2f(-0.15, 0.15); 
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
}

void Car::textureOn(GLuint texture){
	car_texture = texture;
}

void Car::Rotate(car_direction dir){

	if (dir == UP){
		glRotatef(0, 0, 0, 1);
	}
	else if (dir == DOWN){
		glRotatef(180, 0, 0, 1);
	}
	else if (dir == LEFT){
		glRotatef(90, 0, 0, 1);
	}
	else{
		glRotatef(270, 0, 0, 1);
	}
}



void Car::changeView(){
	if (direction == UP){
		pos_y -= speed;
	}
	else if (direction == DOWN){
		pos_y += speed;
	}
	else if (direction == RIGHT){
		pos_x -= speed;
	}
	else if (direction == LEFT){
		pos_x += speed;
	}
}


///DIRECTION
car_direction Car::getDirection(){
	return direction;
}
void Car::setDirection(car_direction new_direction){
	direction = new_direction;
}

///POSITION
float Car::posX(){
	return pos_x;
}
float Car::posY(){
	return pos_y;
}
void Car::reset(double time) {
	int score = 100 - time;
	pos_x = resetX;
	pos_y = resetY;
	speed = 0;
	if (highScore < score)
		highScore = score;
	else {
		char _score[10];
		_itoa(score, _score, 10);
		char text[50] = "Your Score : ";
		strcat(text, _score);
		MessageBox(NULL, text, "Game Over!", 0);
	}
}

///SPEED

float Car::getSpeed(){
	return speed;
}
void Car::setSpeed(float newSpeed){
	if (speed < mode || newSpeed < speed)
		speed = newSpeed;
}
void Car::setPosX(float x){
	pos_x = x;
}
void Car::setPosY(float y){
	pos_y = y;
}

float Car::getAccel(){
	return accel;
}
void Car::accelerate(car_direction dir){
	if (direction == dir){
		if (speed < mode)
			speed += accel;
	}
	direction = dir;
}
void Car::deAccelerate(){
	if (speed > 0)
		speed *= 0.7;
	if (speed < 0.2) speed = 0;
}
void Car::modeSlow(){
	mode = 1;
	accel = 0.1;
}
void Car::modeMedium(){
	mode = 2;
	accel = 0.2;
}
void Car::modeFast(){
	mode = 3;
	accel = 0.4;
}
void Car::faster() {
	mode++;
}