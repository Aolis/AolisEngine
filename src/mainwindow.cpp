#include <cstdio>
#include <SDL2/SDL_image.h>

#include "mainwindow.h"

MainWindow::MainWindow() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("ERROR: Could not initialize SDL\n");
		close(SDL_GetError());
		return;
	}

	window = SDL_CreateWindow(win::title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, win::width, win::height, SDL_WINDOW_OPENGL);
	if (window == NULL) {
		printf("ERROR: Could not create SDL window\n");
		close(SDL_GetError());
		return;
	}

	/* Unused
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) {
		printf("ERROR: Could not create SDL renderer\n");
		close(SDL_GetError());
		return;
	}
	*/

	// Initialize image support
	int flags = IMG_INIT_PNG;
	if ((IMG_Init(flags)&flags) != flags) {
		printf("ERROR: Could not initialize PNG support\n");
		close(SDL_GetError());
		return;
	}

	//screen = SDL_GetWindowSurface(window);
}


void MainWindow::manageEvents() {
	// Listen for events
	while (SDL_PollEvent(&events)) {
		if (events.type == SDL_QUIT) close();
	}
}


MainWindow::~MainWindow() {
	close();
}


void MainWindow::close(const char* msg) {
	// FIXME: Create "log" functions
	if (msg != NULL) {
		printf("%s\n", msg);
	}
	printf("Shutting down ...\n");

	if (screen != NULL) {
		SDL_FreeSurface(screen);
		screen = NULL;
	}

	/* Unused
	if (renderer != NULL) {
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
	}
	*/

	if (window != NULL) {
		SDL_DestroyWindow(window);
		window = NULL;
	}

	IMG_Quit();
	SDL_Quit();
}


const bool MainWindow::setBackground(const char* img) {
	screen = IMG_Load(img);
	if (screen == NULL) {
		printf("ERROR: Could not load background image\n%s\n", SDL_GetError());
		return false;
	}

	SDL_BlitSurface(screen, NULL, SDL_GetWindowSurface(window), NULL);
	SDL_UpdateWindowSurface(window);

	return true;
}
