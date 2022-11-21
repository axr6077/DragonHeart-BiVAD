#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

using namespace std;

class Accessor
{
private:
  static bool isAvailable_GPIO[200];
  static bool isAvailable_ANALOG[6];


public:
  static bool isLoaded_CAPE;
  Accessor();
  //gpio pins
  void gpio_makeAvailable(unsigned int pin_Num);
  void gpio_makeUnAvailable(unsigned int pin_Num);
  bool gpio_isAvailable(unsigned int pin_Num);

  //analog pins
  void analog_makeAvailable(unsigned int pin_Num);
  void analog_makeUnAvailable(unsigned int pin_Num);
  bool analog_isAvailable(unsigned int pin_Num);

};
