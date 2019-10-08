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

	void startTimer();	//현재 시간을 start에 기록
	double stopTimer();	//start부터 지난 시간 duration에 기록
	void resetTimer();	//wraps startTimer
	

};

#endif _ControlPanel;