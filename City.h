#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <GL/glut.h>

#ifndef _City
#define _City

#define tile 50

extern GLuint index;


const int map[9][9] = {
	{ 1, 2, 3, 4, 5, 4, 3, 2, 1 },
	{ 2, 8, 9, 9, 8, 9, 9, 8, 2 },
	{ 3, 0, 1, 4, 0, 3, 2, 0, 3 },
	{ 4, 0, 5, 6, 0, 2, 5, 0, 4 },
	{ 5, 8, 9, 9, 8, 9, 9, 8, 5 },
	{ 4, 0, 3, 1, 0, 6, 3, 0, 4 },
	{ 3, 0, 1, 2, 0, 4, 1, 0, 3 },
	{ 2, 8, 9, 9, 8, 9, 9, 8, 2 },
	{ 1, 2, 3, 4, 5, 4, 3, 2, 1 }
};
class City {
	int angle1 = 0;
	int angle2 = 0;
	int drive = 30;
	bool left = false; //for neutral random car moving
	bool smooth = true;
	bool dpl = false;
public:
	//private로 구현해야되는데 시간없어서 public으로함
	GLuint building1;
	GLuint building2;
	GLuint building3;
	GLuint building4;
	GLuint building5;
	GLuint roadH;
	GLuint roadV;
	GLuint crossroad;
	GLuint car;
	City();
	void displayCity(float cposX, float cposY, bool displayList);
	void giveTexture(int map, int i, int j, bool dpl);

	void drawObjects(float x, float y, float z, int mode);

	bool getPolygon();
	void setPolygon(bool a);
};

#endif _City