/*
 * BatteryManagementSystem.h
 *
 *  Created on: Mar 3, 2021
 *      Author: ahk7kor
 */

#ifndef BATTERYMANAGEMENTSYSTEM_H_
#define BATTERYMANAGEMENTSYSTEM_H_

#include <unordered_map>
#include "BatteryManagementSystem_Types.h"

typedef std::unordered_map<BatteryParameter, ParameterInfo, std::hash<int> > BMSMap;

class BMS
{
	BMSMap umap_BMSData;
	Bounds checkBounds(float currentValue, float min, float max);
	bool isParamWithinRange(BatteryParameter parameter,float currentValue);

public :

	BMS();
   ~BMS();
	bool AddParameter(BatteryParameter parameter,ParameterInfo data);
	bool RemoveParameter(BatteryParameter parameter);
	bool checkBatteryParameter_withValue(BatteryParameter parameter,float currentValue);
};




#endif /* BATTERYMANAGEMENTSYSTEM_H_ */
