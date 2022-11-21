#define ANALOG_SYSFS "/sys/devices/bone_capemgr.*/slots"

#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<cstdlib>
#include "analog_access.h"

using namespace std;

int main(void) {
	int len;
  unsigned char x;
  cout<<"Starting\n";
//system("echo BB-ADC > /sys/devices/bone_capemgr.8/slots");
//cout<<"Finished\n";
  int out,out_p;
  Analog_In test_analog;
  cout<<"Enter pin number\n";
  cin>>x;
  test_analog.attach(x);
  while(1)
    {
//cout<<"Enter pin number -1 to exit\n";

//cin>>x;

//if(x == '6')
//break;

//else{
      out = test_analog.analogRead();
      if(out != out_p)
        cout<<"Analog Value is "<<out<<"\n";
      out_p = out;
      sleep(1);
//}

    }

  return 0;
}
