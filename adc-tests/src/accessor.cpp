#include<accessor.h>

bool Accessor::isAvailable_GPIO[] = {0};
bool Accessor::isAvailable_ANALOG[] = {0};
bool Accessor::isLoaded_CAPE = 0;

Accessor::Accessor()
{

}

void Accessor::gpio_makeAvailable(unsigned int pin_Num)
{
  isAvailable_GPIO[pin_Num] = 0;
}

void Accessor::gpio_makeUnAvailable(unsigned int pin_Num)
{
  isAvailable_GPIO[pin_Num] = 1;
}

bool Accessor::gpio_isAvailable(unsigned int pin_Num)
{

  if(isAvailable_GPIO[pin_Num])
    return 0;

  else
    return 1;
}

void Accessor::analog_makeAvailable(unsigned int pin_Num)
{
  isAvailable_ANALOG[pin_Num] = 0;
}

void Accessor::analog_makeUnAvailable(unsigned int pin_Num)
{
  isAvailable_ANALOG[pin_Num] = 1;
}

bool Accessor::analog_isAvailable(unsigned int pin_Num)
{
  if(isAvailable_ANALOG[pin_Num])
    return 0;
  else
    return 1;
}
