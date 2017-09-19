#ifndef AOLIS_MAINWINDOW_H
#define AOLIS_MAINWINDOW_H

#include <SDL2/SDL.h>


// Window default attributes
namespace win {
	static const char* title = "Aolis Engine";
	static const unsigned int width = 640;
	static const unsigned int height = 480;
	static const unsigned int refresh = 1000;
}


class MainWindow {
public:
	MainWindow();
	~MainWindow();
	void manageEvents();
	void close(const char* msg=NULL);
	const bool isActive() {return (window != NULL);};
	const bool loadBackground(const char* img);
private:
	SDL_Event events;
	//SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Surface* screen;
};


#endif /* AOLIS_MAINWINDOW_H */
