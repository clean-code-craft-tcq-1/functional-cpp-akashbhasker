#include <assert.h>
#include <iostream>

#include "BatteryManagementSystem.h"
#include "PrintOutput.h"

using namespace std;

BMS::BMS()
{
}

BMS::~BMS()
{
	umap_BMSData.clear();
}

/**
 * Description     : AddParameter : Adds the Parameter and its info to BMS map, if parameter not added already
 *
 */
bool BMS::AddParameter(BatteryParameter parameter,ParameterInfo data)
{
	if(umap_BMSData.find(parameter) == umap_BMSData.end())
	{
		umap_BMSData[parameter] = data;
		return true;
	}
	return false;
}

/**
 * Description     : RemoveParameter : Removes the Parameter and its info from BMS map, if parameter present in map
 *
 */
bool BMS::RemoveParameter(BatteryParameter parameter)
{
	if(umap_BMSData.find(parameter) != umap_BMSData.end())
	{
		umap_BMSData.erase(parameter);
		return true;
	}
	return false;
}

/**
 * Description     : checkBatteryParameter_withValue : Tests the Battery Parameter State based on configuration, with the input Value.
 * 					 Returns false if lesser than min threshold or greater than max threshold. Returns true if within range.
 *
 */
bool BMS::checkBatteryParameter_withValue(BatteryParameter parameter,float currentValue)
{
	return isParamWithinRange(parameter, currentValue);
}

/**
 * Description     : checkBounds : checks and returns the state of value wrt to min and max
 *
 */
Bounds BMS::checkBounds(float currentValue, float min, float max)
{
	return ( currentValue < min ) ? Low : ( currentValue > max ) ? High : Normal;
}

/**
 * Description     : isParamWithinRange : Tests the Battery Parameter with the input Value.
 * 					 Prints Output and returns false if lesser than min threshold or greater than max threshold. Returns true if within range.
 *
 */
bool BMS::isParamWithinRange(BatteryParameter parameter,float currentValue)
{
	BMSMap::iterator itr = umap_BMSData.find(parameter);
	if(itr != umap_BMSData.end())
	{
		Bounds bound = checkBounds(currentValue, itr->second.min, itr->second.max);
		if(bound == Normal)
		{
			return true;
		}
		printOutput(itr->second, bound, currentValue);
	}
	return false;
}





