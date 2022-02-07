#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "program.h"

int main(int argc, char* argv[]) {
	LoadLibraryA("C:\\Users\\jackk\\source\\repos\\DllTesting\\Release\\DllTesting.dll");
	program app;
	app.mainLoop();
	return 0;
}