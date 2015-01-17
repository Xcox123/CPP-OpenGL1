#include "PrintText.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/glut.h>
#define GLUT_DISABLE_ATEXIT_HACK
#include <gl/GLAux.h>
#include <iostream>
#include <string>

void PrintText::drawText(const char *text, int length, int x, int y){
	glMatrixMode(GL_PROJECTION); // change the current matrix to PROJECTION
	double matrix[16]; // 16 doubles in stack memory
	glGetDoublev(GL_PROJECTION_MATRIX, matrix); // get the values from PROJECTION matrix to local variable
	glLoadIdentity(); // reset PROJECTION matrix to identity matrix
	glOrtho(0, 800, 0, 600, -5, 5); // orthographic perspective
	glMatrixMode(GL_MODELVIEW); // change current matrix to MODELVIEW matrix again
	glLoadIdentity(); // reset it to identity matrix
	glPushMatrix(); // push current state of MODELVIEW matrix to stack
	glLoadIdentity(); // reset it again. (may not be required, but it my convention)
	glRasterPos2i(x, y); // raster position in 2D
	for (int i = 0; i<length; i++){
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]); // generation of characters in our text with 9 by 15 GLU font
	}
	glPopMatrix(); // get MODELVIEW matrix value from stack
	glMatrixMode(GL_PROJECTION); // change current matrix mode to PROJECTION
	glLoadMatrixd(matrix); // reset
	glMatrixMode(GL_MODELVIEW); // change current matrix mode to MODELVIEW
}
void PrintText::floatToCharMessageB(float vFloat){
	char cVal[32];
	sprintf(cVal, "%f", vFloat); // string result '65' is stored in char array cVal
	MessageBox(NULL, cVal, "PrintText - floatDebug", MB_DEFBUTTON1);
}