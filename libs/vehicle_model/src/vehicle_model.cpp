#include "vehicle_model.h"

VehicleModel::VehicleModel(float timestepsec, float coeffDrag, float massKg, float airDensityKgPerMCubed, float frontalAreaMSquare) :
  timeStepSec(timestepsec),
  coeffDrag(coeffDrag),
  airDensityKgPerMCubed(airDensityKgPerMCubed),
  velocityMPerSec(0.0f),
  massKg(massKg),
  frontalAreaMSquare(frontalAreaMSquare)
{}

void VehicleModel::update(float forceN)
{
  float disturbanceForceN = 0.5f * airDensityKgPerMCubed * coeffDrag * frontalAreaMSquare * velocityMPerSec * velocityMPerSec;

  velocityMPerSec += timeStepSec * (forceN - disturbanceForceN) / massKg;
}

float VehicleModel::get_velocity()
{
  return velocityMPerSec;
}
