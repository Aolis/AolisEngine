#include <iostream>
#include <vector>
using namespace std;

#include "log.h"


const vector<string> ll = {"SILENT", "INFO", "ERROR", "DEBUG"};

void log(const string msg) {
	log(3, msg);
}

void log(const unsigned int level, const string msg) {
	cout << ll.at(level) << ": " << msg << endl;
}
