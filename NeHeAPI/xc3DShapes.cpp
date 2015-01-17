#include "main.h"

float angleRot1;
float xRot1;
float yRot1;
float zRot1;

float c1, c2, c3, c4, c5, c6, c7, c8, c9;
float c12, c22, c32, c42, c52, c62, c72, c82, c92;
float c13, c23, c33, c43, c53, c63, c73, c83, c93;
float c14, c24, c34, c44, c54, c64, c74, c84, c94;


bool xc3DShapes::xc_3DTri(int size, float x, float y, float z){

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -6.0f);

	glRotatef(angleRot1, xRot1, yRot1, zRot1);

	glTranslatef(x, y, z);

	glBegin(GL_TRIANGLES);
				//Front
		glColor3f(c1, c2, c3);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(c4, c5, c6);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glColor3f(c7, c8, c9);
		glVertex3f(1.0f, -1.0f, 1.0f);
				//Right
		glColor3f(c12, c22, c32);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(c42, c52, c62);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glColor3f(c72, c82, c92);
		glVertex3f(1.0f, -1.0f, -1.0f);
				//Back
		glColor3f(c13, c23, c33);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(c43, c53, c63);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glColor3f(c73, c83, c93);
		glVertex3f(-1.0f, -1.0f, -1.0f);
				//Left
		glColor3f(c14, c24, c34);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(c44, c54, c64);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glColor3f(c74, c84, c94);
		glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();
	return true;
}

bool xc3DShapes::xc_3DCube(int size, float x, float y, float z){
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -6.0f);

	glRotatef(angleRot1, xRot1, yRot1, zRot1);

	glTranslatef(x, y, z);

	glBegin(GL_QUADS);
				//Top
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
				//Bottom
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
				//Front
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
				//Back
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
				//Left
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
				//Right
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();

	return true;
}

void xc3DShapes::xc_SetRotation(float _angleRot, float _xRot, float _yRot, float _zRot){
	angleRot1 = _angleRot;
	xRot1 = _xRot;
	yRot1 = _yRot;
	zRot1 = _zRot;
}

void xc3DShapes::xc_SetSideColorTri(char _side, int _num, float _c1, float _c2, float _c3){
	//Colors the front
	if (_num == 1 && _side == 'f'){
		c1 = _c1;
		c2 = _c2;
		c3 = _c3;
	}
	if (_num == 2 && _side == 'f'){
		c4 = _c1;
		c5 = _c2;
		c6 = _c3;
	}
	if (_num == 3 && _side == 'f'){
		c7 = _c1;
		c8 = _c2;
		c9 = _c3;
	}

	//Colors the right

	if (_num == 1 && _side == 'r'){
		c12 = _c1;
		c22 = _c2;
		c32 = _c3;
	}
	if (_num == 2 && _side == 'r'){
		c42 = _c1;
		c52 = _c2;
		c62 = _c3;
	}
	if (_num == 3 && _side == 'r'){
		c72 = _c1;
		c82 = _c2;
		c92 = _c3;
	}

	//Colors the back

	if (_num == 1 && _side == 'b'){
		c13 = _c1;
		c23 = _c2;
		c33 = _c3;
	}
	if (_num == 2 && _side == 'b'){
		c43 = _c1;
		c53 = _c2;
		c63 = _c3;
	}
	if (_num == 3 && _side == 'b'){
		c73 = _c1;
		c83 = _c2;
		c93 = _c3;
	}

	//Colors the left

	if (_num == 1 && _side == 'l'){
		c14 = _c1;
		c24 = _c2;
		c34 = _c3;
	}
	if (_num == 2 && _side == 'l'){
		c44 = _c1;
		c54 = _c2;
		c64 = _c3;
	}
	if (_num == 3 && _side == 'l'){
		c74 = _c1;
		c84 = _c2;
		c94 = _c3;
	}
}