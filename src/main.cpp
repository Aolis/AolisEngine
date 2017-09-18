#include <cstdio>

//#include "mainwindow.h"
#include <SDL2/SDL.h>


int main(int argc, char** argv) {
	printf("Hello world!\n");

	SDL_Window* window;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("ERROR: Could not initialize SDL: %s\n", SDL_GetError());
	}

	window = SDL_CreateWindow(
		"Test SDL Application",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);

	if (window == NULL) {
		printf("ERROR: Could not create window: %s\n", SDL_GetError());
	}

	SDL_Delay(3000);

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
