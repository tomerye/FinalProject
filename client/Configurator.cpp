/*
 * Configurator.cpp
 *
 *  Created on: Aug 25, 2012
 *      Author: tomer
 */

#include "Configurator.h"



bool Configurator::init()
{
	try
	{
		read_xml(m_xml_path, m_property_tree,boost::property_tree::xml_parser::trim_whitespace);
	}
	catch (std::exception &e) {
		DEBUG_MSG("error read XML file");
		return false;
	}
	return true;
}

std::string Configurator::getParameterValue(std::string parameter)
{
	return m_property_tree.get<std::string>(parameter);
}

void setParameterValue(std::string parameter, std::string value)
{
	//TODO add function
}

void close()
{
	//TODO add function
}
