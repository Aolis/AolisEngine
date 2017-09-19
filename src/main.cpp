#include "functions.h"
#include "log.h"
#include "mainwindow.h"

using namespace std;


int main(int argc, char** argv) {
	const string root_dir = getRootDir(argv[0]);
	log(string("Root directory: ") + root_dir);

	MainWindow* window = new MainWindow();
	window->setBackground("cave.png");
	window->setMusic("title.ogg", true);

	unsigned int index = 0;
	while (window->isActive()) {
		window->manageEvents();

		index++;

#ifdef DEBUG
		const string msg = "Current iteration: ";
		log(msg + toString(index));
#endif

		/*
		if (index > 9) {
			window->close();
		}
		*/

		SDL_Delay(win::refresh);
	}

	return 0;
}
