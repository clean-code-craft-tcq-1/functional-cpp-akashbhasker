/*
 * PrintOutput.hpp
 *
 *  Created on: Mar 2, 2021
 *      Author: ahk7kor
 */

#ifndef PRINTOUTPUT_CPP_
#define PRINTOUTPUT_CPP_

#include <iostream>
#include "PrintOutput.h"

/**
 * Description     : printOutput : Prints a Warning Message to CONSOLE if current value of a parameter is lesser or greater than threshold.
 *                                 Also prints the current value, Min Value and Max Value of the paramter
 *
 */
void printOutput(ParameterInfo parameter, Bounds bound, float currentValue)
{
	if(bound == High)
	{
		std::cout<<" WARNING   : "<< parameter.BatteryParametersStr<< " is High" << std::endl;
	}
	else if(bound == Low)
	{
		std::cout<<" WARNING   : "<< parameter.BatteryParametersStr<< " is Low" << std::endl;
	}
	std::cout<<" Current Value  : "<< currentValue << " " << parameter.units << std::endl;
	std::cout<<" Min Value : "<< parameter.min << " " << parameter.units << std::endl;
	std::cout<<" Max Value : "<< parameter.max << " " << parameter.units << std::endl;
	std::cout<< std::endl;
}

#endif /* PRINTOUTPUT_CPP_ */
