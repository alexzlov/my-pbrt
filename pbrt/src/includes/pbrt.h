#include <string>
#include <vector>
#include <iostream>

struct Options {
	int nThreads     = 0;
	bool quickRender = false;
	bool quiet       = false;
	bool cat         = false,
		 toPly       = false;
	std::string imageFile;
};