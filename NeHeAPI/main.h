#pragma once
#include <Windows.h>
#include <iostream>
#include <gl\GL.h>
#include <gl/GLAux.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include <string>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "TwoDShapes.h"
#include "PrintText.h"
#include "Keys.h"
#include "Debug.h"
#include "xc3DShapes.h"
#include "Graphics.h"
#include "Vars.h"
class main{
public:
	static WPARAM g_wParam;
	void xc_SetColorTri();
};