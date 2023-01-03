/**
 * @file pid_control.c
 * @brief A simple PID control example for the BeagleBone Black using C++
 *
 * This program continuously reads from an ADC and outputs to a DAC using the
 * BeagleBone Black. The program uses a simple PID control algorithm to maintain
 * a setpoint for the control system.
 *
 * @author Ayush Rout
 * @date 2023/01/02
 **/
#include <iostream>
#include <fstream>

// Constants for the PID control
/*
 * @brief Constants for the PID control
 *
 * Constants for the PID control.
 * K_P: Proportional gain constant
 * K_I: Integral gain constant
 * K_D: Derivative gain constant
 */
constexpr double K_P = 1.0;
constexpr double K_I = 0.1;
constexpr double K_D = 0.01;

/*
 * @brief ADC and DAC device files
 *
 * ADC and DAC device files.
 * These files are used to read from the ADC and write to the DAC on the BeagleBone Black.
 */
// ADC and DAC device files
constexpr char ADC_DEVICE[] = "/dev/adc0";
constexpr char DAC_DEVICE[] = "/dev/dac0";
int main() {
    /*
     * @brief Open the ADC and DAC device files
     *
     * Open the ADC and DAC device files.
     * These files are used to read from the ADC and write to the DAC on the BeagleBone Black.
     */
    std::ifstream adc_file(ADC_DEVICE);
    std::ofstream dac_file(DAC_DEVICE);
    if (!adc_file || !dac_file) {
        std::cerr << "Unable to open ADC or DAC device file" << std::endl;
        return 1;
    }

    // Variables for storing ADC and DAC values, error, and PID control terms
    int adc_value;
    int dac_value;
    double error;
    double p_term;
    double i_term = 0.0;
    double d_term;
    double control_signal;
    /**
     * @brief Setpoint for the control system
     **/
    double setpoint = 50.0;  // Setpoint for the control system

    // Continuously run the PID control loop
    while (true) {
        // Read the ADC value
        adc_file >> adc_value;
        if (adc_file.fail()) {
            std::cerr << "Unable to read from ADC device file" << std::endl;
            break;
        }

        // Calculate the error
        error = setpoint - adc_value;

        // Calculate the proportional term
        p_term = K_P * error;
	
	// Update the integral term
        i_term += error;

        // Calculate the derivative term
        d_term = K_D * (error - prev_error);
        prev_error = error;

        // Calculate the control signal
        control_signal = p_term + K_I * i_term + d_term;

        // Output the control signal to the DAC
        dac_value = (int)(control_signal + 0.5);
        dac_file << dac_value << std::endl;
        if (dac_file.fail()) {
            std::cerr << "Unable to write to DAC device file" << std::endl;
            break;
        }

        // Sleep for a short time to allow the control system to stabilize
        usleep(1000);
    }

    return 0;
}
