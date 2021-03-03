/**************************************************************************************
f* @file        : BatteryManagementSystem_test.cpp
* @brief        : File contains necessary business logic to test the various parameters of BMS
**************************************************************************************/

#include <assert.h>
#include <iostream>
using namespace std;

#include "BatteryManagementSystem_Factory.h"

void testElectricVehicle_BMS(BatteryManagementSystem::BMSTestIF* bmsTestInstance)
{
	if(bmsTestInstance != NULL)
	{
		assert(bmsTestInstance->checkBatteryParameter_withValue(BatteryManagementSystem::Temperature_in_celcius, 25)  == true);
		assert(bmsTestInstance->checkBatteryParameter_withValue(BatteryManagementSystem::Temperature_in_celcius, -10 )  == false);
		assert(bmsTestInstance->checkBatteryParameter_withValue(BatteryManagementSystem::Temperature_in_celcius, 100) == false);

		assert(bmsTestInstance->checkBatteryParameter_withValue(BatteryManagementSystem::Soc_in_percent , 50)  == true);
		assert(bmsTestInstance->checkBatteryParameter_withValue(BatteryManagementSystem::Soc_in_percent, 10 )  == false);
		assert(bmsTestInstance->checkBatteryParameter_withValue(BatteryManagementSystem::Soc_in_percent, 100) == false);

		assert(bmsTestInstance->checkBatteryParameter_withValue(BatteryManagementSystem::ChargeRate_in_C, 0.6)  == true);
		assert(bmsTestInstance->checkBatteryParameter_withValue(BatteryManagementSystem::ChargeRate_in_C, 0.4)  == false);
		assert(bmsTestInstance->checkBatteryParameter_withValue(BatteryManagementSystem::ChargeRate_in_C, 1.0) == false);
	}
}

int main() {

	BatteryManagementSystem::BMSFactory bmsFactoryObject;
	BatteryManagementSystem::BMSTestIF* bmsEV_TestInstance = bmsFactoryObject.getElectricVehicle_BMSTestObject();

	testElectricVehicle_BMS(bmsEV_TestInstance);

}
