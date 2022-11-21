#define LOAD_CAPE "echo BB-ADC > /sys/devices/bone_capemgr.8/slots"
#define ANALOG_SYSPATH "/sys/devices/ocp.2/helper.14/AIN"

#include <analog_access.h>

/*
Load analog cape
*/

Analog_In::Analog_In()
{
  if(isLoaded_CAPE != 1)
    {
      cout<<"Attaching\n";
      system("echo BB-ADC > /sys/devices/bone_capemgr.8/slots");
      cout<<"Attaching Finished\n";
      is_attached = 0;
      isLoaded_CAPE = 1;
    }
  else
    {
      cout<<"Analog Cape already loaded\n";
    }
}


