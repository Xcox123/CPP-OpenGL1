#include "Keys.h"
#include "main.h"
#include <string>
#include <Windows.h>
#include <iostream>

bool Keys::testALL(){
	if (Keys::isA()){
		return true;
	}
	if (Keys::isB()){
		return true;
	}
	if (Keys::isC()){
		return true;
	}
	if (Keys::isD()){
		return true;
	}
	if (Keys::isE()){
		return true;
	}
	if (Keys::isF()){
		return true;
	}
	if (Keys::isG()){
		return true;
	}
	if (Keys::isH()){
		return true;
	}
	if (Keys::isI()){
		return true;
	}
	if (Keys::isJ()){
		return true;
	}
	if (Keys::isK()){
		return true;
	}
	if (Keys::isL()){
		return true;
	}
	if (Keys::isM()){
		return true;
	}
	if (Keys::isN()){
		return true;
	}
	if (Keys::isO()){
		return true;
	}
	if (Keys::isP()){
		return true;
	}
	if (Keys::isQ()){
		return true;
	}
	if (Keys::isR()){
		return true;
	}
	if (Keys::isS()){
		return true;
	}
	if (Keys::isT()){
		return true;
	}
	if (Keys::isU()){
		return true;
	}
	if (Keys::isV()){
		return true;
	}
	if (Keys::isW()){
		return true;
	}
	if (Keys::isX()){
		return true;
	}
	if (Keys::isY()){
		return true;
	}
	if (Keys::isZ()){
		return true;
	}
	return false;
}

bool Keys::isA(){
	if (main::g_wParam == 0x41){
		return true;
	} return false;
}

bool Keys::isB(){
	if (main::g_wParam == 0x42){
		return true;
	} return false;
}

bool Keys::isC(){
	if (main::g_wParam == 0x43){
		return true;
	} return false;
}

bool Keys::isD(){
	if (main::g_wParam == 0x44){
		return true;
	} return false;
}

bool Keys::isE(){
	if (main::g_wParam == 0x45){
		return true;
	} return false;
}

bool Keys::isF(){
	if (main::g_wParam == 0x46){
		return true;
	} return false;
}

bool Keys::isG(){
	if (main::g_wParam == 0x47){
		return true;
	} return false;
}

bool Keys::isH(){
	if (main::g_wParam == 0x48){
		return true;
	} return false;
}

bool Keys::isI(){
	if (main::g_wParam == 0x49){
		return true;
	} return false;
}

bool Keys::isJ(){
	if (main::g_wParam == 0x4A){
		return true;
	} return false;
}

bool Keys::isK(){
	if (main::g_wParam == 0x4B){
		return true;
	} return false;
}

bool Keys::isL(){
	if (main::g_wParam == 0x4C){
		return true;
	} return false;
}

bool Keys::isM(){
	if (main::g_wParam == 0x4D){
		return true;
	} return false;
}

bool Keys::isN(){
	if (main::g_wParam == 0x4E){
		return true;
	} return false;
}

bool Keys::isO(){
	if (main::g_wParam == 0x4F){
		return true;
	}	return false;
}

bool Keys::isP(){
	if (main::g_wParam == 0x50){
		return true;
	} return false;
}

bool Keys::isQ(){
	if (main::g_wParam == 0x51){
		return true;
	} return false;
}

bool Keys::isR(){
	if (main::g_wParam == 0x52){
		return true;
	} return false;
}

bool Keys::isS(){
	if (main::g_wParam == 0x53){
		return true;
	} return false;
}

bool Keys::isT(){
	if (main::g_wParam == 0x54){
		return true;
	} return false;
}

bool Keys::isU(){
	if (main::g_wParam == 0x55){
		return true;
	} return false;
}

bool Keys::isV(){
	if (main::g_wParam == 0x56){
		return true;
	} return false;
}

bool Keys::isW(){
	if (main::g_wParam == 0x57){
		return true;
	} return false;
}

bool Keys::isX(){
	if (main::g_wParam == 0x58){
		return true;
	} return false;
}

bool Keys::isY(){
	if (main::g_wParam == 0x59){
		return true;
	} return false;
}

bool Keys::isZ(){
	if (main::g_wParam == 0x5A){
		return true;
	} return false;
}