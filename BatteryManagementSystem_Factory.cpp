/**************************************************************************************
f* @file        : BatteryManagementSystem_Factory.cpp
* @brief        : File contains necessary business logic to create, configure, access instances of different types of BatteryManagementSystems
**************************************************************************************/

#include "BatteryManagementSystem_Factory.h"
using namespace BatteryManagementSystem;

BMSFactory::BMSFactory()
: _electricVehicle_bmsInstance(NULL)
{

}

BMSFactory::~BMSFactory()
{
	delete _electricVehicle_bmsInstance;
	_electricVehicle_bmsInstance = NULL;
}


/**
 * Description     : getBMSTestObject : Configures and returns an instance of BMS for Test
 *
 */
BMSTestIF* BMSFactory::getElectricVehicle_BMSTestObject()
{
	if(_electricVehicle_bmsInstance == NULL)
	{
		_electricVehicle_bmsInstance = new BMS();
		configureElectricVehicleBMS(_electricVehicle_bmsInstance);
	}
	return static_cast<BMSTestIF *>(_electricVehicle_bmsInstance);
}

/**
 * Description     : configureBMS : Configures the ElectricVehicle BMS instance with Parameters and Parameter related info ("paramterName in String" , " Units" ,Min Threshold, Max Threshold)
 *
 */
void BMSFactory::configureElectricVehicleBMS(BMS* const bmsInstance)
{
	bmsInstance->AddParameter(Temperature_in_celcius, ParameterInfo("Temperature", "Celcius",   0,  45 ));
	bmsInstance->AddParameter(Soc_in_percent        , ParameterInfo("Soc"        , "Percent",  20,  80 ));
	bmsInstance->AddParameter(ChargeRate_in_C       , ParameterInfo("Charge Rate", "C"      , 0.5, 0.8 ));
}

