
#include "pid_controller.h"
#include <fstream>
#include <iostream>

const float TIME_STEP_SEC = 0.02f;
const float MIN_INTEGRAL = 0.0f;
const float MAX_INTEGRAL = 100.0f;
const float P_GAIN = 1.0f;
const float I_GAIN = 0.0f;
const float D_GAIN = 0.0f;

const float MAX_SIM_TIME = 1.0f;
int main()
{
  std::cout << "Hello Cruise Control" << std::endl;

  PIDController testPIDController(TIME_STEP_SEC, P_GAIN, I_GAIN, D_GAIN, MIN_INTEGRAL, MAX_INTEGRAL);

// File Header
// time,setpoint,velocity,pterm,iterm,dterm,ffterm,force
  std::ofstream dataFile;
  dataFile.open ("data_file.csv");
  dataFile << "time,setpoint,velocity,pterm,iterm,dterm,ffterm,force\n";

  float timeSec = 0.0f;
  float setPointMPerSec = 30.0f; // 30 m/s = 108 kph
  while (timeSec < MAX_SIM_TIME)
  {
    // Measure: Get vehicle speed from model
    float vehicleVelocityMPerSec = 10.0f; // CALL VEHICLE MODEL

    // Control: Run PID Controller
    float PIDOutput = testPIDController.update(1.1f, 2.2f);
    PIDOutput++;
    float ffTerm = 0.0f; // Use a lookup table to get steady state force
    float force = ffTerm + PIDOutput;

    // Actuate: Update model with new force
    // model.update(force);

    // Increment time
    timeSec += TIME_STEP_SEC;
    std::cout << "time = " << timeSec << std::endl;

    // Log the data
    float pTerm = testPIDController.get_p_term();
    float iTerm = testPIDController.get_i_term();
    float dTerm = testPIDController.get_d_term();
    dataFile << timeSec << "," << setPointMPerSec << "," << vehicleVelocityMPerSec << ",";
    dataFile << pTerm << "," << iTerm << "," << dTerm << "," << ffTerm << "," << force << "\n";
  }
  dataFile.close();

}