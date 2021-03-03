/*
 * BatteryManagementSystem_Types.h
 *
 *  Created on: Mar 2, 2021
 *      Author: ahk7kor
 */

#ifndef BATTERYMANAGEMENTSYSTEM_TYPES_H_
#define BATTERYMANAGEMENTSYSTEM_TYPES_H_


enum BatteryParameter
{
	Temperature_in_celcius = 0,
	Soc_in_percent,
	ChargeRate_in_C,
	BatteryParameters_end
};

enum Bounds
{
	Low = -1,
	Normal,
	High
};

struct ParameterInfo
{
	std::string BatteryParametersStr;
	std::string units;
	float min;
	float max;
	ParameterInfo(std::string _name = "",std::string _units="", float _min = 0, float _max = 0)
	: BatteryParametersStr(_name)
	, units(_units)
	, min(_min)
	, max(_max)
	{
	}

};




#endif /* BATTERYMANAGEMENTSYSTEM_TYPES_H_ */
