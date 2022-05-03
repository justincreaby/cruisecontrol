#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PIDController
{
public:
  PIDController(float timestepsec, float pgain, float igain, float dgain, float minvalue, float maxvalue);
  float update(float setpoint, float measuredValue);
  void limit_output(float& value);
  void update_gains(float pGain, float iGain, float dGain);
  void set_p_gain(float pGain);
  float get_p_gain();
  void set_i_gain(float iGain);
  void set_integral_term(float integralTerm);
  void set_d_gain(float dGain);
  void set_min_value(float minValue);
  void set_max_value(float maxValue);
  void saturate_value(float& value, float minValue, float maxValue);
  float get_p_term();
  float get_i_term();
  float get_d_term();

private:
  const float timeStepSec;
  float pGain;
  float iGain;
  float dGain;
  float minValue;
  float maxValue;
  float proportionalTerm;
  float integralTerm;
  float derivativeTerm;
  float previousError;
};

#endif //PID_CONTROLLER_H