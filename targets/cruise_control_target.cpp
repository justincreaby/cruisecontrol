
#include "pid_controller.h"
#include "vehicle_model.h"
#include <fstream>
#include <iostream>

// Model Parameters
const float COEFF_DRAG = 0.32f;
const float MASS_KG = 2000.0f;
const float AIR_DENSITY_KG_PER_M3 = 1.225f;
const float FRONTAL_AREA_M2 = 2.4f;

// PID Parameters
const float MIN_INTEGRAL = 0.0f;
const float MAX_INTEGRAL = 12000.0f;
const float P_GAIN = 500.0f;
const float I_GAIN = 10.0f;
const float D_GAIN = 10.0f;

// Sim time
const float TIME_STEP_SEC = 0.02f;
const float MAX_SIM_TIME = 200.0f;

int main()
{
  VehicleModel vehicleModel(TIME_STEP_SEC, COEFF_DRAG, MASS_KG, AIR_DENSITY_KG_PER_M3, FRONTAL_AREA_M2);
  PIDController PIDController(TIME_STEP_SEC, P_GAIN, I_GAIN, D_GAIN, MIN_INTEGRAL, MAX_INTEGRAL);

  // File Header
  std::ofstream dataFile;
  dataFile.open ("data_file.csv");
  dataFile << "time,setpoint,velocity,pterm,iterm,dterm,ffterm,force\n";
;
std::cout << PIDController.update(30.0f, 2.2f) << std::endl;
  float timeSec = 0.0f;
  float setPointMPerSec = 30.0f; // 30 m/s = 108 kph
  while (0) //(timeSec < MAX_SIM_TIME)
  {
    // Update set point mid way through sim
    if (timeSec > (0.5f * MAX_SIM_TIME))
    {
      setPointMPerSec = 40.0f;
    }

    // Measure: Get vehicle speed from model
    float vehicleVelocityMPerSec = vehicleModel.get_velocity();

    // Control: Run PID Controller
    float PIDOutput = PIDController.update(setPointMPerSec, vehicleVelocityMPerSec);
    float ffTerm = 0.0f; // Use a lookup table to get steady state force
    float force = ffTerm + PIDOutput;

    // Actuate: Update model with new force
    vehicleModel.update(force);

    // Log the data
    float pTerm = PIDController.get_p_term();
    float iTerm = PIDController.get_i_term();
    float dTerm = PIDController.get_d_term();
    dataFile << timeSec << "," << setPointMPerSec << "," << vehicleVelocityMPerSec << ",";
    dataFile << pTerm << "," << iTerm << "," << dTerm << "," << ffTerm << "," << force << "\n";

    // Increment time
    timeSec += TIME_STEP_SEC;
  }
  dataFile.close();
}