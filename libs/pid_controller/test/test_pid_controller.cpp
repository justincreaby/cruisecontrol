#include <gtest/gtest.h>
#include "pid_controller.h"

TEST(PID_CONTROLLER_TESTS, PIDClassTests)
{
  PIDController testPIDController(0.02f, 500.0f, 10.0f, 10.0f, 0.0f, 12000.0f);

  // Test setter
  float testPGain = 500.0f;
  testPIDController.set_p_gain(testPGain);
  EXPECT_FLOAT_EQ(testPIDController.get_p_gain(), testPGain);

  // Test update
  float PIDOutput = testPIDController.update(30.0f, 2.2f);
  float ExpectedValue = 12000.0f;
  EXPECT_FLOAT_EQ(PIDOutput, ExpectedValue);
}