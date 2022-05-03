#include <gtest/gtest.h>
#include "pid_controller.h"

TEST(PID_CONTROLLER_TESTS, PIDClassTests)
{
  PIDController testPIDController(0.02f, -0.2f, -0.2f, 0.0f, 0.0f, 100.0f);

  // Test setter
  float testPGain = 1.234f;
  testPIDController.set_p_gain(testPGain);
  EXPECT_FLOAT_EQ(testPIDController.get_p_gain(), testPGain);

  // Test update
  float PIDOutput = testPIDController.update(1.1f, 2.2f);
  float ExpectedValue = -1.353f;
  EXPECT_FLOAT_EQ(PIDOutput, ExpectedValue);
}