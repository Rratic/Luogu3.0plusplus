#include "core.h"
#include <fstream>
#include <iostream>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::getline;
queue<string> getfromfile(string filename);
bool initstackfromfile(string filename);
bool lgwork(string filename);
