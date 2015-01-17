#include "main.h"


float rtri = 0.0f;
static TwoDShapes xc2dshapes;
static Keys testkey;
static PrintText printText;
static xc3DShapes xc3dshapes;

void Graphics::Draw(){

	//	xc2dshapes.xc_2DTri(3, -2.0f, 0.0f, 0.0f, &rgb[9]);
	if (testkey.isH()){


		xc2dshapes.setColour(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
		xc2dshapes.setRotation(rtri, 0.0f, 1.0f, 0.0f);
		//	xc2dshapes.xc_2DTri(1, -2.3f, 0.0f, 0.0f);
		xc2dshapes.xc_2DTri(2, -0.8f, 0.0f, 0.0f);
		//xc2dshapes.xc_2DTri(3, 2.0f, 0.0f, 0.0f);
		printText.drawText("TRIANGLES!!!", 12, 450, 500);
		rtri += 0.2f;
	}

	//xc2dshapes.xc_2DTri(1, 2.0f, 0.0f, 0.0f, &rgb[9]);

	if (testkey.isF()){
		std::string text;
		text = "This is a simple text.";
		glColor3f(0.72, 0.5, 0);
		printText.drawText(text.data(), text.size(), 50, 200);
	}
	if (testkey.isD()){
		xc3dshapes.xc_SetRotation(rtri, 0.0f, 1.0f, 0.0f);
		xc3dshapes.xc_SetSideColorTri('f', 1, 1.0f, 0.0f, 0.0f);
		xc3dshapes.xc_SetSideColorTri('f', 2, 0.0f, 1.0f, 0.0f);
		xc3dshapes.xc_SetSideColorTri('f', 3, 0.0f, 0.0f, 1.0f);
		xc3dshapes.xc_SetSideColorTri('r', 1, 1.0f, 0.0f, 0.0f);
		xc3dshapes.xc_SetSideColorTri('r', 2, 0.0f, 0.0f, 1.0f);
		xc3dshapes.xc_SetSideColorTri('r', 3, 0.0f, 1.0f, 0.0f);
		xc3dshapes.xc_SetSideColorTri('b', 1, 1.0f, 0.0f, 0.0f);
		xc3dshapes.xc_SetSideColorTri('b', 2, 0.0f, 1.0f, 0.0f);
		xc3dshapes.xc_SetSideColorTri('b', 3, 0.0f, 0.0f, 1.0f);
		xc3dshapes.xc_SetSideColorTri('l', 1, 1.0f, 0.0f, 0.0f);
		xc3dshapes.xc_SetSideColorTri('l', 2, 0.0f, 0.0f, 1.0f);
		xc3dshapes.xc_SetSideColorTri('l', 3, 0.0f, 1.0f, 0.0f);
		xc3dshapes.xc_3DTri(2, 0.0f, 0.0f, 0.0f);
		rtri += 0.2f;
	}
	glTranslatef(3.0f, 0.0f, 0.0f);
	//	xc2dshapes.xc_2DSquare(1, 0.0f, 1.5f, 0.0f);
}