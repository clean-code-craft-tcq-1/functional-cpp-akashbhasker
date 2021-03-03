/**************************************************************************************
f* @file        : BatteryManagementSystem_Factory.h
* @brief        : File contains necessary business logic to create, configure, access instances of different types of BatteryManagementSystems
**************************************************************************************/

#ifndef BATTERYMANAGEMENTSYSTEM_FACTORY_H_
#define BATTERYMANAGEMENTSYSTEM_FACTORY_H_

#include "BatteryManagementSystem.h"

namespace BatteryManagementSystem
{

class BMSFactory
{
	BMS* _electricVehicle_bmsInstance;
	void configureElectricVehicleBMS(BMS* const bmsInstance);

public:
	BMSFactory();
	~BMSFactory();
	BMSTestIF* getElectricVehicle_BMSTestObject();

};

} //namespace BatteryManagementSystem

#endif /* BATTERYMANAGEMENTSYSTEM_FACTORY_H_ */
