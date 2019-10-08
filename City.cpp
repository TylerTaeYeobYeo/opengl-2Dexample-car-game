#include "City.h"
using namespace std;

City::City(){
	cout << "City Created" << endl;
}

void City::displayCity(float cposX, float cposY, bool displayList) {
	dpl = displayList;
	if (smooth == TRUE) glPolygonMode(GL_COLOR, GL_SMOOTH);
	else glPolygonMode(GL_COLOR, GL_FLAT);
	glTranslatef(cposX, cposY, 0);
	//cout << "X:" << cposX << " Y: " << cposY << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			giveTexture(map[i][j], i, j, dpl);
		}
	}
	drawObjects(tile * 3 + tile / 2, tile * 3 + tile / 2, 0, 0); //double
	drawObjects(tile * 5 + tile / 2, tile * 5 + tile / 2, 0, 1); //static
	drawObjects(tile * 4 + tile / 4, tile * 4 + tile / 4, 0, 2); //car
	if (dpl == TRUE) {
		glCallList(index);
	}
}

void City::giveTexture(int map,int i,int j,bool dpl){
	GLuint texture;
	if (map != 0 && map < 6){
		if (dpl == true) {
			glNewList(index, GL_COMPILE);
			glColor3f(1, 1, 1);
			glDepthMask(GL_FALSE);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_TEXTURE_2D);
			if (map == 0) texture = roadH;
			if (map == 1) texture = building1;
			else if (map == 2) texture = building2;
			else if (map == 3) texture = building3;
			else if (map == 4) texture = building4;
			else texture = building5;
			glBindTexture(GL_TEXTURE_2D, texture);
			glBegin(GL_QUADS);
			glVertex2f(tile * i, tile * j);					glTexCoord2f(1, 0);
			glVertex2f(tile * i, tile * j + tile);			glTexCoord2f(1, 1);
			glVertex2f(tile * i + tile, tile * j + tile);	glTexCoord2f(0, 1);
			glVertex2f(tile * i + tile, tile * j);			glTexCoord2f(0, 0);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			glDisable(GL_BLEND);
			glDepthMask(GL_TRUE);
			glEndList();
		}
		else {
			glColor3f(1, 1, 1);
			glDepthMask(GL_FALSE);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_TEXTURE_2D);
			if (map == 0) texture = roadH;
			if (map == 1) texture = building1;
			else if (map == 2) texture = building2;
			else if (map == 3) texture = building3;
			else if (map == 4) texture = building4;
			else texture = building5;
			glBindTexture(GL_TEXTURE_2D, texture);
			glBegin(GL_QUADS);
			glVertex2f(tile * i, tile * j);					glTexCoord2f(1, 0);
			glVertex2f(tile * i, tile * j + tile);			glTexCoord2f(1, 1);
			glVertex2f(tile * i + tile, tile * j + tile);	glTexCoord2f(0, 1);
			glVertex2f(tile * i + tile, tile * j);			glTexCoord2f(0, 0);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			glDisable(GL_BLEND);
			glDepthMask(GL_TRUE);
		}

	}
	else if (map == 0 || map == 9 || map == 8){
		if(dpl ==true){
			glNewList(index, GL_COMPILE);
			glColor3f(1, 1, 1);
			glDepthMask(GL_FALSE);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_TEXTURE_2D);
			if (map == 0) texture = roadH;
			else if (map == 9)texture = roadV;
			else texture = crossroad;
			glBindTexture(GL_TEXTURE_2D, texture);
			glBegin(GL_QUADS);
			glVertex2f(tile * i, tile * j);					glTexCoord2f(1, 0);
			glVertex2f(tile * i, tile * j + tile);			glTexCoord2f(1, 1);
			glVertex2f(tile * i + tile, tile * j + tile);	glTexCoord2f(0, 1);
			glVertex2f(tile * i + tile, tile * j);			glTexCoord2f(0, 0);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			glDisable(GL_BLEND);
			glDepthMask(GL_TRUE);
			glEndList();
		}
		else {
			glColor3f(1, 1, 1);
			glDepthMask(GL_FALSE);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_TEXTURE_2D);
			if (map == 0) texture = roadH;
			else if (map == 9)texture = roadV;
			else texture = crossroad;
			glBindTexture(GL_TEXTURE_2D, texture);
			glBegin(GL_QUADS);
			glVertex2f(tile * i, tile * j);					glTexCoord2f(1, 0);
			glVertex2f(tile * i, tile * j + tile);			glTexCoord2f(1, 1);
			glVertex2f(tile * i + tile, tile * j + tile);	glTexCoord2f(0, 1);
			glVertex2f(tile * i + tile, tile * j);			glTexCoord2f(0, 0);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			glDisable(GL_BLEND);
			glDepthMask(GL_TRUE);
		}
	}
	else {
		if (dpl == true) {
			glNewList(index, GL_COMPILE);
			glColor3f(0.3, 0.6, 0.3);
			glBegin(GL_QUADS);
			glVertex2f(tile * i, tile * j);
			glVertex2f(tile * i, tile * j + tile);
			glVertex2f(tile * i + tile, tile * j + tile);
			glVertex2f(tile * i + tile, tile * j);
			glEnd();
			glEndList();
		}
		else {
			glColor3f(0.3, 0.6, 0.3);
			glBegin(GL_QUADS);
			glVertex2f(tile * i, tile * j);
			glVertex2f(tile * i, tile * j + tile);
			glVertex2f(tile * i + tile, tile * j + tile);
			glVertex2f(tile * i + tile, tile * j);
			glEnd();
		}
	}
}

void City::drawObjects(float x, float y, float z, int mode){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glColor3f(1, 1, 1);

	if (mode > 1) {
		glTranslatef(drive, 0, 0);
		if(left == false){
			drive++;
			if (drive > 150) {
				left = true;
			}
		}
		else{
			drive--;
			if (drive < -150) {
				left = false;
			}
		}
		glDepthMask(GL_FALSE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, car);
		glBegin(GL_QUADS);
		glVertex2f(x, y);			glTexCoord2f(1, 0);
		glVertex2f(x, y + 10);		glTexCoord2f(1, 1);
		glVertex2f(x + 20, y + 10);	glTexCoord2f(0, 1);
		glVertex2f(x + 20, y);		glTexCoord2f(0, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);
		glDepthMask(GL_TRUE);
	}
	else {
		angle1 = (angle1 + 1) % 360;
		angle2 = (angle2 + 2) % 360;

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();

		glBegin(GL_QUADS);
		glColor3f(1, 0, 0);
		glVertex2f(x - 3, y - 3);
		glColor3f(0, 1, 0);
		glVertex2f(x - 3, y + 3);
		glColor3f(0, 0, 1);
		glVertex2f(x + 3, y + 3);
		glColor3f(0, 0, 0);
		glVertex2f(x + 3, y - 3);
		glEnd();

		if (mode == 0) {
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glTranslatef(x, y, 0);
			glRotatef(angle1, 0, 0, 1);
			glTranslatef(-x - 15, -y - 15, 0);

			glBegin(GL_TRIANGLES);
			glColor3f(1, 0, 0);
			glVertex2f(x, y);
			glColor3f(0, 1, 0);
			glVertex2f(x - 3, y - 5);
			glColor3f(0, 0, 1);
			glVertex2f(x + 3, y - 5);
			glEnd();

			glMatrixMode(GL_MODELVIEW);
			glTranslatef(x, y, 0);
			glPushMatrix();
			glRotatef(angle2, 0, 0, 1);
			glTranslatef(10, 10, 0);

			glBegin(GL_QUADS);
			glColor3f(1, 0, 0);
			glVertex2f(-2.5, -2.5);
			glColor3f(0, 1, 0);
			glVertex2f(-2.5, 2.5);
			glColor3f(0, 0, 1);
			glVertex2f(2.5, 2.5);
			glColor3f(0, 0, 0);
			glVertex2f(2.5, -2.5);
			glEnd();
		}
		else {
			glMatrixMode(GL_MODELVIEW);
			glTranslatef(x, y, 0);
			glPushMatrix();
			glRotatef(-angle1, 0, 0, 1);
			glTranslatef(10, 0, 0);
			glRotatef(angle1, 0, 0, 1);

			glBegin(GL_TRIANGLES);
			glColor3f(1, 0, 0);
			glVertex2f(0, 2.5);
			glColor3f(0, 1, 0);
			glVertex2f(-2.5, -2.5);
			glColor3f(0, 0, 1);
			glVertex2f(2.5, -2.5);
			glEnd();
		}
	}
	glPopMatrix();
}

//polygon filled or outline
bool City::getPolygon() {
	return smooth;
}
void City::setPolygon(bool a) {
	smooth = a;
}