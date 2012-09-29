/*
 * Event.h
 *
 *  Created on: Aug 25, 2012
 *      Author: tomer
 */

#ifndef EVENT_H_
#define EVENT_H_
#include <string>


class Event
{
public:
	Event(std::string tstring):m_test(tstring){}
	std::string get(){return m_test;}
private:
	std::string m_test;
};


#endif /* EVENT_H_ */
