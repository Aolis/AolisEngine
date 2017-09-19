#include <cstdio>

#include "functions.h"
#include "log.h"
#include "mainwindow.h"


int main(int argc, char** argv) {
	MainWindow* window = new MainWindow();
	window->setBackground("cave.png");
	window->setMusic("title.ogg", true);

	unsigned int index = 0;
	while (window->isActive()) {
		window->manageEvents();

		index++;

		const std::string msg = "Current iteration: ";
		log(msg + toString(index));

		/*
		if (index > 9) {
			window->close();
		}
		*/

		SDL_Delay(win::refresh);
	}

	return 0;
}
