#include <array>
#include <memory>

#include "functions.h"

using namespace std;


const string toString(const int value) {
	ostringstream ss;
	ss << value;
	return ss.str();
}


const string sysExec(const string cmd) {
	array<char, 128> buffer;
	string output;

	shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);
	if (!pipe) throw runtime_error("Could not execute command");
	while (!feof(pipe.get())) {
		if (fgets(buffer.data(), 128, pipe.get()) != nullptr) output += buffer.data();
	}

	return output;
}


const string getRootDir(const char* exe) {
#ifdef __unix__
	string relative = sysExec((string("dirname ") + string(exe)).c_str());
	string absolute = sysExec((string("cd ") + relative).c_str());
	return sysExec("pwd");
#endif
	return "ERROR: Unknown operating system";
}
