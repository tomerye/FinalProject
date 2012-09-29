/*
 ============================================================================
 Name        : FinalProject.cpp
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */

#include <iostream>

#include "Configurator.h"
#include "Logger.h"

using namespace std;

int main(void) {
	

	Logger logger("my test logger");

	
	Event event("first event");
	logger.sendLog(event);
	

//	while(true){}
	return 0;
}
