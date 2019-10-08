#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <cstdio>

#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SOIL/SOIL.h>

#include "Car.h"
#include "ControlPanel.h"
#include "City.h"

using namespace std;

#define HEIGHT 600
#define WIDTH 600

int Width = WIDTH;
int Height = HEIGHT;
int aspectRatio = WIDTH / HEIGHT;
#define FPS 60 //frame per second
//CLASSES
ControlPanel control;	//콘트롤뷰
City city;				//도시
Car car;				//차

GLuint index = glGenLists(1);

//TEXTURES
GLuint texture;
GLuint roadV;
GLuint roadH;
GLuint building1;
GLuint building2;
GLuint building3;
GLuint building4;
GLuint building5;


enum MENU_TYPE
{
	MENU_SPEED_FAST,
	MENU_SPEED_MEDIUM,
	MENU_SPEED_SLOW,
	MENU_RESTART,
	MENU_POLYGON_FILLED,
	MENU_POLYGON_OUTLINE,
	MENU_DISPLAYLIST_ON,
	MENU_DISPLAYLIST_OFF,
	MENU_QUIT,
};
MENU_TYPE show = MENU_SPEED_MEDIUM;

void timer_callback(int);
void keyboard(int key, int x, int y);
void update();
void reshape(int width, int height);
void menu(int item);
void popupMenu();
void drawControlPanel();
void drawCity();
void drawCar();
void display_callback();
void init();
void WCharToChar(const wchar_t* pwstrSrc, char pstrDest[])
{
	int nLen = (int)wcslen(pwstrSrc);
	wcstombs(pstrDest, pwstrSrc, nLen + 1);
}
// char to LPCWSTR
void CharToWChar(const char* pstrSrc, wchar_t pwstrDest[])
{
	int nLen = (int)strlen(pstrSrc) + 1;
	mbstowcs(pwstrDest, pstrSrc, nLen);
}