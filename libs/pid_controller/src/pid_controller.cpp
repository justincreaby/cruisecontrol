#include "pid_controller.h"
#include <iostream>

PIDController::PIDController(float timestepsec, float pgain, float igain, float dgain,
                             float minvalue, float maxvalue) :
  timeStepSec(timestepsec),
  pGain(pgain),
  iGain(igain),
  dGain(dgain),
  minValue(minvalue),
  maxValue(maxvalue),
  proportionalTerm(0.0f),
  integralTerm(0.0f),
  derivativeTerm(0.0f),
  previousError(0.0f)
{}

float PIDController::update(float setpoint, float measuredValue)
{
  float error = setpoint - measuredValue;

  // Calculate the proportional term
  proportionalTerm = pGain * error;

  // Calculate the integral term
  integralTerm += error * timeStepSec * iGain;
  limit_output(integralTerm); // Anti-Windup

  // Calculate the derivative term
  derivativeTerm = dGain * (error - previousError) / timeStepSec;

  float PIDOutput = proportionalTerm + integralTerm + derivativeTerm;

  previousError = error;

  std::cout << "measuredValue: " << measuredValue << ", error: " << error << ", PIDOutput: " << PIDOutput << ", PTerm: " << proportionalTerm << ", ITerm: " << integralTerm << std::endl;
  return PIDOutput;
}

void PIDController::limit_output(float& value)
{
  saturate_value(value, minValue, maxValue);
}

void PIDController::set_p_gain(float pGain)
{
  this->pGain = pGain;
}

float PIDController::get_p_gain()
{
  return pGain;
}

void PIDController::set_i_gain(float iGain)
{
  this->iGain = iGain;
}

void PIDController::set_integral_term(float integralTerm)
{
  this->integralTerm = integralTerm;
}

void PIDController::set_d_gain(float dGain)
{
  this->dGain = dGain;
}

void PIDController::set_min_value(float minValue)
{
  this->minValue = minValue;
}

void PIDController::set_max_value(float maxValue)
{
  this->maxValue = maxValue;
}

void PIDController::saturate_value(float& value, float minValue, float maxValue)
{
  if (value > maxValue)
  {
    value = maxValue;
  }
  else if (value < minValue)
  {
    value = minValue;
  }
}

float PIDController::get_p_term()
{
  return proportionalTerm;
}

float PIDController::get_i_term()
{
  return integralTerm;
}

float PIDController::get_d_term()
{
  return derivativeTerm;
}