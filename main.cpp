#include "main.h"
void init(){
	popupMenu();
	MessageBox(NULL, "Find the Treasure, it's somewhere in the building. Press SHIFT for break!\n", "Game Start", 0);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	texture = SOIL_load_OGL_texture
		(
		"carY.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
	car.textureOn(texture);
	city.car = SOIL_load_OGL_texture
	(
		"car.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	city.crossroad = SOIL_load_OGL_texture
		(
		"crossroad.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
	city.roadH = SOIL_load_OGL_texture
		(
		"roadH.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
	city.roadV = SOIL_load_OGL_texture
		(
		"roadV.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
	city.building1 = SOIL_load_OGL_texture
		(
		"building1.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
	city.building2 = SOIL_load_OGL_texture
		(
		"building2.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
	city.building3 = SOIL_load_OGL_texture
		(
		"building3.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
	city.building4 = SOIL_load_OGL_texture
		(
		"building4.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
	city.building5 = SOIL_load_OGL_texture
		(
		"building5.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);
}

void timer_callback(int){
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer_callback, 0);
}

void keyboard(int key, int x, int y){//message로 보내
	switch (key) {
	case GLUT_KEY_UP:
		car.accelerate(UP);
		break;
	case GLUT_KEY_DOWN:
		car.accelerate(DOWN);
		break;
	case GLUT_KEY_RIGHT:
		car.accelerate(RIGHT);
		break;
	case GLUT_KEY_LEFT:
		car.accelerate(LEFT);
		break;
	case GLUT_KEY_F4:
		car.faster();
		break;
	case GLUT_KEY_F1:
		car.modeFast();
		break;
	case GLUT_KEY_F2:
		car.modeMedium();
		break;
	case GLUT_KEY_F3:
		car.modeSlow();
		break;
	default:
		if (car.getSpeed() > 0)
			car.setSpeed(car.getSpeed()* 0.5);
		if (car.getSpeed() < 0.5) car.setSpeed(0);
		break;
	}
}

void update(){
	
	if (car.getSpeed() > 0)
		car.setSpeed(car.getSpeed() * 0.95);
	if (car.getSpeed() < 0.2) car.setSpeed(0);
}

void reshape(int width, int height){
	Width = width;
	Height = height;
	if (height == 0) Height = 1;
	aspectRatio = Width / Height;
}
void menu(int item)
{
	switch (item)
	{
	case MENU_POLYGON_FILLED:
		city.setPolygon(true);
		glShadeModel(GL_SMOOTH);
		break;
	case MENU_POLYGON_OUTLINE:
		city.setPolygon(false);
		glShadeModel(GL_FLAT);
		break;
	case MENU_SPEED_FAST:
		car.modeFast();
		break;
	case MENU_SPEED_MEDIUM:
		car.modeMedium();
		break;
	case MENU_SPEED_SLOW:
		car.modeSlow();
		break;
	case MENU_RESTART:
		car.reset(control.stopTimer());
		control.resetTimer();
		break;
	case MENU_DISPLAYLIST_ON:
		control.displayList = true;
		break;
	case MENU_DISPLAYLIST_OFF:
		control.displayList = false;
		break;
	case MENU_QUIT:
		exit(1);
		break;
	}
}
void popupMenu(){
	int popupMenu;
	// 서브 메뉴
	GLint subMenuSpeed = glutCreateMenu(menu);
	glutAddMenuEntry("Fast", MENU_SPEED_FAST);
	glutAddMenuEntry("Medium", MENU_SPEED_MEDIUM);
	glutAddMenuEntry("Slow", MENU_SPEED_SLOW);
	

	
	GLint subMenuPolygon = glutCreateMenu(menu);
	glutAddMenuEntry("Filled", MENU_POLYGON_FILLED);
	glutAddMenuEntry("Outline", MENU_POLYGON_OUTLINE);
	

	GLint subMenuDisplay = glutCreateMenu(menu);
	glutAddMenuEntry("ON", MENU_DISPLAYLIST_ON);
	glutAddMenuEntry("OFF", MENU_DISPLAYLIST_OFF);

	popupMenu = glutCreateMenu(menu);
	// 서브 메뉴를 메인 메뉴에 붙인다.
	glutAddSubMenu("Speed", subMenuSpeed);
	glutAddSubMenu("Polygons", subMenuPolygon);
	glutAddSubMenu("Display List", subMenuDisplay);
	glutAddMenuEntry("Restart", MENU_RESTART);
	glutAddMenuEntry("Quit", MENU_QUIT);


	// associate a mouse button with menu
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}
//display
void drawControlPanel(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(-1, 1, 1, -1);
	control.displayAll(car);
}
void drawCity(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300, 300, -300, 300);
	//gluOrtho2D(0.0, 100.0, 0.0, 100.0);
	city.displayCity(car.posX(), car.posY(), control.displayList);
}
void drawCar(){
	car.changeView();
	car.display();
}
void display_callback() {
	glClearColor(0.3, 0.6, 0.3, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//glViewport(0, 0, WIDTH, HEIGHT / 4);

	glViewport(0, 0, WIDTH * 5, HEIGHT / 4);
	drawControlPanel();
	//glViewport(0, HEIGHT / 4, WIDTH, HEIGHT);
	glViewport(0, HEIGHT / 4, WIDTH * 5, HEIGHT * 5);
	drawCity();
	glViewport(0, 0, WIDTH, HEIGHT);
	//gluOrtho2D(-1, 1, -1, 1);
	drawCar();

	glutSwapBuffers();
	if (car.posX() < -350 && car.posX() > -380 && car.posY() < -430 && car.posY() > -460) {
		MessageBox(NULL, "Found Treasure", "Congratulation", 0);
		car.reset(control.stopTimer());
		control.resetTimer();
	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Car");
	init();
	glutDisplayFunc(display_callback);
	timer_callback(0);
	glutSpecialFunc(keyboard);
	//glutIdleFunc(update);
	//glutKeyboardFunc();
	glutReshapeFunc(reshape); //뷰포트 매트릭스랑 

	glutMainLoop();

	glDeleteTextures(1, &texture);
	glDeleteTextures(1, &roadV);
	glDeleteTextures(1, &roadH);
	glDeleteTextures(1, &building1);
	glDeleteTextures(1, &building2);
	glDeleteTextures(1, &building3);
	glDeleteTextures(1, &building4);
	glDeleteTextures(1, &building5);
	return 0;
}