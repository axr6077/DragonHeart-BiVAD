#define LOAD_CAPE "echo BB-ADC > /sys/devices/bone_capemgr.8/slots"
#define ANALOG_SYSPATH "/sys/devices/ocp.2/helper.14/AIN"

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <cstdlib>
#include <stdio.h>
#include <accessor.h>

using namespace std;

class Analog_In: protected Accessor
{
private:
  int len,fd_analog;
  unsigned char analog_pinNum;
  bool is_attached;
  char analog_Path[150];
public:
  Analog_In();
  bool attach(unsigned char pin_num);
  bool detach();
  int analogRead();
};
