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

bool Analog_In::attach(unsigned char pin_num)
{
  char analog_input[4];
  char dummy_input[4];

  if(!is_attached)
    {

      if(pin_num == '0' || pin_num == '1' || pin_num == '2' || pin_num == '3' || pin_num == '4' || pin_num == '5')
        {
          len = snprintf(analog_Path,sizeof(analog_Path),ANALOG_SYSPATH"%c",pin_num);
          is_attached = 1;
          analog_pinNum = pin_num;
          analog_makeUnAvailable(pin_num);
          return 1;
        }
      else
        {
          cout<<"Wrong Pin Number\n";
          return 0;
        }
    }
  else
    {
      cout<<"Pin already Attached\n";
      return 0;
    }
}

bool Analog_In::detach()
{
  if(is_attached)
    {
      is_attached = 0;
      analog_makeAvailable(analog_pinNum);
      return 1;
    }
  else
    cout<<"No pin Attached\n";
}
