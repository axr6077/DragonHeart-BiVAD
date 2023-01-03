#include <iostream>
#include <fstream>

// Constants for the PID control
constexpr double K_P = 1.0;
constexpr double K_I = 0.1;
constexpr double K_D = 0.01;

// ADC and DAC device files
constexpr char ADC_DEVICE[] = "/dev/adc0";
constexpr char DAC_DEVICE[] = "/dev/dac0";
