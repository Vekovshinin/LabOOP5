#pragma once
#include <iostream>
#include <string>

using namespace std;

class object {	
public:	
	object() {};
	virtual ~object() {};
	virtual void output() = 0;
};