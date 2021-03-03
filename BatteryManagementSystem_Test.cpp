#include <assert.h>
#include <iostream>
using namespace std;

#include "BatteryManagementSystem.h"

/**
 * Description     : configureBMS : Configures the BMS instance with Parameters and Parameter related info ("paramterName in String" , " Units" ,Min Threshold, Max Threshold)
 *
 */
void configureBMS(BMS* bmsInstance)
{
	if(bmsInstance != NULL)
	{
		bmsInstance->AddParameter(Temperature_in_celcius, ParameterInfo("Temperature", "Celcius",   0,  45 ));
		bmsInstance->AddParameter(Soc_in_percent        , ParameterInfo("Temperature", "Percent",  20,  80 ));
		bmsInstance->AddParameter(ChargeRate_in_C       , ParameterInfo("Charge Rate", "C"      , 0.5, 0.8 ));
	}
}

void testBMS(BMS* bmsInstance)
{
	if(bmsInstance != NULL)
	{
		assert(bmsInstance->checkBatteryParameter_withValue(Temperature_in_celcius, 25)  == true);
		assert(bmsInstance->checkBatteryParameter_withValue(Temperature_in_celcius, -10 )  == false);
		assert(bmsInstance->checkBatteryParameter_withValue(Temperature_in_celcius, 100) == false);

		assert(bmsInstance->checkBatteryParameter_withValue(Soc_in_percent , 50)  == true);
		assert(bmsInstance->checkBatteryParameter_withValue(Soc_in_percent, 10 )  == false);
		assert(bmsInstance->checkBatteryParameter_withValue(Soc_in_percent, 100) == false);

		assert(bmsInstance->checkBatteryParameter_withValue(ChargeRate_in_C, 0.6)  == true);
		assert(bmsInstance->checkBatteryParameter_withValue(ChargeRate_in_C, 0.4)  == false);
		assert(bmsInstance->checkBatteryParameter_withValue(ChargeRate_in_C, 1.0) == false);
	}
}

int main() {

	BMS bmsInstance;
	configureBMS(&bmsInstance);
	testBMS(&bmsInstance);

}
