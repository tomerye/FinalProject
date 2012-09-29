/*
 * Configurator.h
 *
 *  Created on: Aug 25, 2012
 *      Author: tomer
 */

#ifndef CONFIGURATOR_H_
#define CONFIGURATOR_H_

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <set>
#include <exception>
#include <iostream>


#include "debug.h"


using boost::property_tree::ptree;


class Configurator
{
public:
	Configurator(std::string path):m_xml_path(path){init();};//path to XML file
	bool init();//init property_tree return true on success
	void close();
	std::string getParameterValue(std::string parameter);
	void setParameterValue(std::string parameter, std::string value);
private:
	std::string m_xml_path;
	ptree m_property_tree;
};


#endif /* CONFIGURATOR_H_ */
