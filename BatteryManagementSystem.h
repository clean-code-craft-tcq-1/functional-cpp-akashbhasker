/**************************************************************************************
f* @file        : BatteryManagementSystem.h
* @brief        : File contains necessary business logic to handle core logic of BMS
**************************************************************************************/

#ifndef BATTERYMANAGEMENTSYSTEM_H_
#define BATTERYMANAGEMENTSYSTEM_H_

#include <unordered_map>
#include "BatteryManagementSystem_Types.h"

namespace BatteryManagementSystem
{

typedef std::unordered_map<BatteryParameter, ParameterInfo, std::hash<int> > BMSMap;

class BMSTestIF
{
public:
	BMSTestIF(){}
	virtual ~BMSTestIF(){}
	virtual bool checkBatteryParameter_withValue(BatteryParameter parameter,float currentValue) = 0;
};

class BMS : public BMSTestIF
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


}//namespace BatteryManagementSystem

#endif /* BATTERYMANAGEMENTSYSTEM_H_ */
