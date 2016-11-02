#include <iostream>
#include <cstdlib>
#include <string>
#pragma once

using namespace std;

struct card{
	string suit; //hearts, diamonds, etc
	char face; //J, 2, 6, A
	int value; //value of face, A = 1 initially
	bool faced_up; 
};
