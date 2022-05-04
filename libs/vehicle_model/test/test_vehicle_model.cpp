#include <gtest/gtest.h>
#include "vehicle_model.h"

TEST(VEH_MODEL_TESTS, VehModelTests)
{
  VehicleModel vehicleModel(0.02f, 0.32f, 2000.0f, 1.225f, 2.4f);

  // Test update
  vehicleModel.update(5000.0f);
  float ExpectedValue = 0.05f;
  EXPECT_FLOAT_EQ(vehicleModel.get_velocity(), ExpectedValue);
}