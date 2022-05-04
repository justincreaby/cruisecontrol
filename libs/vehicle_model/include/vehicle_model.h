#ifndef VEHICLE_MODEL_H
#define VEHICLE_MODEL_H

class VehicleModel
{
public:
  VehicleModel(float timestepsec, float coeffDrag, float massKg, float airDensityKgPerMCubed, float frontalAreaMSquare);
  void update(float forceN);
  float get_velocity();

private:
  const float timeStepSec;
  const float frontalAreaMSquare;
  const float massKg;
  const float coeffDrag;
  const float airDensityKgPerMCubed;
  float velocityMPerSec;
};

#endif //VEHICLE_MODEL_H