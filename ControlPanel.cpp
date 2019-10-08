#include "ControlPanel.h"
using namespace std;

ControlPanel::ControlPanel(){
	cout << "ControlPanel Created" << endl;
	startTimer();
}

/*
* Direction: 입력된 방향키
* Timer: 프로그램 실행부터 스탑워치 실행
* Speed: 현재 속도 디스플레이`
*/
void ControlPanel::displayAll(Car car) {
	// Make background colour white

	glColor3f(1, 1, 1);
	/*  Set Control Pannel part
	// Sets up FIRST viewport spanning the left-bottom quarter of the interface window
	glViewport(0, 0, 100, 100);		// (x, y, width, height)
	// Sets up the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();*/
	glColor3f(0, 0, 0);

	//direction
	text = "HighScore : ";
	showText(text.data(), text.size(), FixedX, FixedY);
	std::ostringstream ostr;
	ostr << car.highScore;
	text = ostr.str();
	showText(text.data(), text.size(), VarX, FixedY);

	//timer
	text = "timer : ";
	showText(text.data(), text.size(), FixedX, FixedY - 70);
	stopTimer();
	showText(duration.data(), duration.size(), VarX, FixedY - 70);

	//speed
	text = "speed : ";
	showText(text.data(), text.size(), FixedX, FixedY - 140);
	std::ostringstream speed;
	speed << car.getSpeed() * 100 << "km/h";
	text = speed.str();
	showText(text.data(), text.size(), VarX, FixedY - 140);

	//Display List
	if (displayList == false) text = "Display List OFF";
	else text = "Display List ON";
	showText(text.data(), text.size(), FixedX, FixedY - 210);
}

void ControlPanel::showText(const char *text, int length, int x, int y)
{
	gluOrtho2D(0, 2800, 0, 400);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2f(x, y);
	for (int i = 0; i < length; i++){
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}
	glPopMatrix();
}

void ControlPanel::startTimer(){
	start = std::clock();
}

double ControlPanel::stopTimer(){
	double flow = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::ostringstream ostr;
	ostr << flow;
	duration = ostr.str();
	return flow;
}

void ControlPanel::resetTimer(){
	startTimer();
}