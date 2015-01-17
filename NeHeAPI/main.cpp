#include "main.h"

HGLRC hRC = NULL;	//Create rendering context
HDC hDC = NULL;		//Create device context
HWND hWnd = NULL;	//Create the thing that holds the window handle
HINSTANCE hInstance = NULL;		//Thing that holds the window instance(the birth certificate of Windows)

static Keys testKey;
static PrintText printtext;
static xc3DShapes xc3dshapes;
bool active = true;		//If window is minimized or not(false for minimized, vice versa)
bool fullscreen = true;		//Take a guess
WPARAM main::g_wParam = NULL;

GLuint base;
GLfloat cnt1;
GLfloat cnt2;

HWND TextBox;
char text[20];

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	//Register the WndProc

GLvoid ResizeGLScene(GLsizei width, GLsizei height){	//Reset the sizes of things to original on startup
	if (height == 0){
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int InitGL(GLvoid){		//Init GL
	glShadeModel(GL_SMOOTH);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	return true;
}


int DrawGLScene(GLvoid){
	//MessageBoxA(NULL, "inside graphics.cpp", "testx", MB_OK);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -6.0f);
	
	Graphics::Draw();

	if (testKey.isS()){
		TextBox = CreateWindow("EDIT", "", WS_BORDER | WS_CHILD | WS_VISIBLE, 10, 10, 400, 20, hWnd, NULL, NULL, NULL);

		CreateWindow("BUTTON", "Go", WS_VISIBLE | WS_CHILD | WS_BORDER, 420, 10, 70, 20, hWnd, (HMENU) 1, NULL, NULL);
	}

	return true;
}



GLvoid KillGLWindow(GLvoid){
	if (fullscreen){
		ChangeDisplaySettings(NULL, 0);
		ShowCursor(true);
	}
	if (hRC){
		if (!wglMakeCurrent(NULL, NULL)){
			MessageBox(NULL, "Release of DC and RC failed", "Shutdown error", MB_OK | MB_ICONINFORMATION);
		}
		if (!wglDeleteContext(hRC)){
			MessageBox(NULL, "Release of RC failed", "Shutdown error", MB_OK | MB_ICONEXCLAMATION);
		}
	}
	hRC = NULL;
	if (hDC && !ReleaseDC(hWnd, hDC)){
		MessageBox(NULL, "Release of DC failed", "Shutdown error", MB_OK | MB_ICONINFORMATION);
	}
	hDC = NULL;
	if (hWnd && !DestroyWindow(hWnd)){
		MessageBox(NULL, "Release of hWnd failed", "Shutdown error", MB_OK | MB_ICONINFORMATION);
	}
	hWnd = NULL;
	if (hInstance && !UnregisterClass("OpenGL", hInstance)){
		MessageBox(NULL, "Could not unregister window class", "Shutdown error", MB_OK | MB_ICONINFORMATION);
	}
	hInstance = NULL;

}

bool CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenFlag){
	GLuint PixelFormat;
	WNDCLASS wc;
	DWORD dwStyle;
	DWORD dwExStyle;

	RECT WindowRect;
	WindowRect.left = (long)0;
	WindowRect.right = (long)width;
	WindowRect.top = (long)0;
	WindowRect.bottom = (long)height;

	fullscreen = fullscreenFlag;

	hInstance = GetModuleHandle(NULL);
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "OpenGL";

	if (!RegisterClass(&wc)){
		MessageBox(NULL, "Failed to register the window class", "Error", MB_OK | MB_ICONINFORMATION);
		return false;
	}
	if (fullscreen){
		DEVMODE dmScreenSettings;
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmBitsPerPel = bits;
		dmScreenSettings.dmPelsHeight = height;
		dmScreenSettings.dmPelsWidth = width;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSHEIGHT | DM_PELSWIDTH;

		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL){
			if (MessageBox(NULL, "The requested fullscreen mode is not supported by your \ngraphics card, would you like to run in minimized?", "XcoxGL", MB_YESNO | MB_ICONEXCLAMATION) == IDYES){
				fullscreen = false;
			}
			else{
				MessageBox(NULL, "Program will now close", "Error", MB_OK | MB_ICONSTOP);
				return false;
			}
		}
	}
	if (fullscreen){
		dwExStyle = WS_EX_APPWINDOW;
		dwStyle = WS_POPUP;
		ShowCursor(false);
	}
	else{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		dwStyle = WS_OVERLAPPEDWINDOW;
	}
	AdjustWindowRectEx(&WindowRect, dwStyle, false, dwExStyle);
	if (!(hWnd = CreateWindowEx(dwExStyle, "OpenGL", title, WS_CLIPSIBLINGS | WS_CLIPCHILDREN | dwStyle, 0, 0, WindowRect.right - WindowRect.left, WindowRect.bottom - WindowRect.top, NULL, NULL, hInstance, NULL))){
		KillGLWindow();
		MessageBox(NULL, "Window creation error", "Startup error", MB_OK | MB_ICONINFORMATION);
		return false;
	}
	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		bits,
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		16,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};
	if (!(hDC = GetDC(hWnd))){
		KillGLWindow();
		MessageBox(NULL, "Cannot create a GL-DC", "Error", MB_OK | MB_ICONINFORMATION);
		return false;
	}
	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd))){
		KillGLWindow();
		MessageBox(NULL, "Cannot find a sutiable pixel format", "Error", MB_OK | MB_ICONINFORMATION);
		return false;
	}
	if (!SetPixelFormat(hDC, PixelFormat, &pfd)){
		KillGLWindow();
		MessageBox(NULL, "Cannot set the pixel format", "Error", MB_OK | MB_ICONINFORMATION);
		return false;
	}
	if (!(hRC = wglCreateContext(hDC))){
		KillGLWindow();
		MessageBox(NULL, "Cannot create GL-RC", "Error", MB_OK | MB_ICONINFORMATION);
		return false;
	}
	if (!wglMakeCurrent(hDC, hRC)){
		MessageBox(NULL, "Cannot activate GL-RC", "Error", MB_OK | MB_ICONINFORMATION);
		return false;
	}

	ShowWindow(hWnd, SW_SHOW);
	SetForegroundWindow(hWnd);
	SetFocus(hWnd);
	ResizeGLScene(width, height);

	if (!InitGL()){
		KillGLWindow();
		MessageBox(NULL, "Init failed", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	return true;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	switch (uMsg){
		case WM_ACTIVATE: {
			if (!HIWORD(wParam)){
				active = true;
			}
			else{
				active = false;
			} return 0;
		}
		case WM_SYSCOMMAND: {
				switch (wParam){
					case SC_SCREENSAVE:
					case SC_MONITORPOWER:
						return 0;
			}	break;
		}
		case WM_CLOSE: {
			PostQuitMessage(0);
			return 0;
		}
		case WM_KEYDOWN: {
			main::g_wParam = wParam;
			
			return 0;
		}
		case WM_KEYUP: {
			main::g_wParam = NULL;
			return 0;
		}
		case WM_SIZE: {
			ResizeGLScene(LOWORD(lParam), HIWORD(lParam));
			return 0;
		}
		case WM_COMMAND: {
			switch (LOWORD(wParam)){
				case 1:
					int gwtstat = 0;
					
					gwtstat = GetWindowText(TextBox, &text[0], 20);

					std::string test1 = std::to_string(gwtstat);
					MessageBoxA(NULL, test1.c_str(), "testx", MB_OK);

					::MessageBox(hWnd, text, text, MB_OK);
			}
		}
	}  
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	MSG msg;
	bool done = false;

	if (MessageBox(NULL, "Would you like to run in fullscreen mode?", "Fullscreen mode?", MB_YESNO | MB_ICONQUESTION) == IDNO){
		fullscreen = false;
	}
	if (!CreateGLWindow("XcoxGL", 640, 480, 16, fullscreen)){
		return 0;
	}
	while (!done){
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
			if (msg.message == WM_QUIT){
				done = true;
			}
			else{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else{
			if (active){
				testKey.testALL();
				
				if (testKey.isA()){
					KillGLWindow();
				}
				else{
					DrawGLScene();
					SwapBuffers(hDC);
				}
			}
				
			}
		}
		KillGLWindow();
		return (msg.wParam);
}


