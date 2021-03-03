/*
 * BatteryManagementSystem_Types.h
 *
 *  Created on: Mar 2, 2021
 *      Author: ahk7kor
 */

#ifndef BATTERYMANAGEMENTSYSTEM_TYPES_H_
#define BATTERYMANAGEMENTSYSTEM_TYPES_H_

namespace BatteryManagementSystem
{

/**
 * Description     : All Possible Parameters Supported by Battery Management System To be Added here
 */
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
	ParameterInfo(std::string _name = "", std::string _units="", float _min = 0, float _max = 0)
	: BatteryParametersStr(_name)
	, units(_units)
	, min(_min)
	, max(_max)
	{
	}

};

} // namespace BatteryManagementSystem

#endif /* BATTERYMANAGEMENTSYSTEM_TYPES_H_ */
