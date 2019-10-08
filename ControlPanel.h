#include <windows.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <sstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Car.h"

#ifndef _ControlPanel
#define _ControlPanel

#define FixedY 300
#define FixedX 30
#define VarX 150

class ControlPanel{
	std::string text;
	std::clock_t start;
	std::string duration;
public:
	bool displayList = false;
	ControlPanel();

	void displayAll(Car car);

	void showText(const char *text, int length, int x, int y);

	void startTimer();	//���� �ð��� start�� ���
	double stopTimer();	//start���� ���� �ð� duration�� ���
	void resetTimer();	//wraps startTimer
	

};

#endif _ControlPanel;