#include <string>

using namespace std;

#ifndef Input_Handling_h
#define Input_Handling_h

class Invalid_Input
{
public: 
	Invalid_Input(string in_ptr) : msg_ptr (in_ptr) { } ;
	const string msg_ptr;

private:
	Invalid_Input();
};

#endif