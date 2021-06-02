#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include "DxLib.h"
#include "dx_lib_ext.h"

void DrawStringEx(int x, int y, int color, char* _str, ...) {

	char buff[255] = { 0 };
	va_list argptr;

	va_start(argptr, _str);
	vsprintf(buff, _str, argptr);
	va_end(argptr);

	DrawString(x, y, buff, color);

}


