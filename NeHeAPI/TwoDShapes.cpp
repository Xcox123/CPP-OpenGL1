#include <Windows.h>
#include <gl\GL.h>
#include <sstream>
#include <iostream>
#include "main.h"

float c11;
float c21;
float c31;
float c41;
float c51;
float c61;
float c71;
float c81;
float c91;

float angleRot;
float xRot;
float yRot;
float zRot;

PrintText printText;

bool TwoDShapes::xc_2DTri(int size, float x, float y, float z){
	

	glLoadIdentity();
	glTranslatef(x, y, z + -6.0f);
	if (size == 1){
		glBegin(GL_TRIANGLES);
			glRotatef(angleRot, xRot, yRot, zRot);
			glColor3f(c11, c21, c31);
			glVertex3f(0.0f, 0.5f, 0.0f);
			glColor3f(c41, c51, c61);
			glVertex3f(-0.5f, -0.5f, 0.0f);
			glColor3f(c71, c81, c91);
			glVertex3f(0.5f, -0.5f, 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f);
		glEnd();
		return true;
	}

	else if(size == 2){
	
			glRotatef(angleRot, xRot, yRot, zRot);
			
			glBegin(GL_TRIANGLES);
			glColor3f(c11, c21, c31);
			glVertex3f(0.0f, 1.0f, 0.0f);
			glColor3f(c41, c51, c61);
			glVertex3f(-1.0f, -1.0f, 0.0f);
			glColor3f(c71, c81, c91);
			glVertex3f(1.0f, -1.0f, 0.0f);
			glEnd();
		
			glColor3f(1.0f, 1.0f, 1.0f);
		
		return true;
		
	}
	 if (size == 3){
		glBegin(GL_TRIANGLES);
			glRotatef(angleRot, xRot, yRot, zRot);
			glColor3f(c11, c21, c31);
			glVertex3f(0.0f, 2.0f, 0.0f);
			glColor3f(c41, c51, c61);
			glVertex3f(-2.0f, -2.0f, 0.0f);
			glColor3f(c71, c81, c91);
			glVertex3f(2.0f, -2.0f, 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f);
		glEnd();
		return true;
	}
	else{
	//	MessageBox(NULL, "size = no", "textx", MB_OK);
	}
}

bool TwoDShapes::xc_2DSquare(int size, float x, float y, float z){

	glLoadIdentity();
	glTranslatef(x, y, z + -6.0f);
	if (size == 1){
		glBegin(GL_QUADS);
			glVertex3f(-0.5f, 0.5f, 0.0f);
			glVertex3f(0.5f, 0.5f, 0.0f);
			glVertex3f(0.5f, -0.5f, 0.0f);
			glVertex3f(-0.5f, -0.5f, 0.0f);
		glEnd();
		return true;
	}
	else if (size == 2){
		glBegin(GL_QUADS);
			glVertex3f(-1.0f, 1.0f, 0.0f);
			glVertex3f(1.0f, 1.0f, 0.0f);
			glVertex3f(1.0f, -1.0f, 0.0f);
			glVertex3f(-1.0f, -1.0f, 0.0f);
		glEnd();
		return true;
	}
	else if (size == 3){
		glBegin(GL_QUADS);
			glVertex3f(-1.5f, 1.5f, 0.0f);
			glVertex3f(1.5f, 1.5f, 0.0f);
			glVertex3f(1.5f, -1.5f, 0.0f);
			glVertex3f(-1.5f, -1.5f, 0.0f);
		glEnd();
		return true;
	}
	else{
		MessageBox(NULL, "size = no", "textx", MB_OK);
		return false;
	}
}

void TwoDShapes::setColour(float _c1, float _c2, float _c3, float _c4, float _c5, float _c6, float _c7, float _c8, float _c9){
	c11 = _c1;
	c21 = _c2;
	c31 = _c3;
	c41 = _c4;
	c51 = _c5;
	c61 = _c6;
	c71 = _c7;
	c81 = _c8;
	c91 = _c9;
}

void TwoDShapes::setRotation(float _angleRot, float _xRot, float _yRot, float _zRot){

	angleRot = _angleRot;
	xRot = _xRot;
	yRot = _yRot;
	zRot = _zRot;
	
}



