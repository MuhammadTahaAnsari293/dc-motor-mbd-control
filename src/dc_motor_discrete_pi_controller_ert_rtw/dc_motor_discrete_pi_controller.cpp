//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: dc_motor_discrete_pi_controller.cpp
//
// Code generated for Simulink model 'dc_motor_discrete_pi_controller'.
//
// Model version                  : 1.14
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Sun Nov  1 21:36:29 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "dc_motor_discrete_pi_controller.h"
#include "rtwtypes.h"

// Model step function
void dc_motor_control::step()
{
  real_T rtb_Subtract;

  // Sum: '<Root>/Subtract' incorporates:
  //   Inport: '<Root>/omega_measured'
  //   Inport: '<Root>/omega_ref'

  rtb_Subtract = rtU.omega_ref - rtU.omega_measured;

  // Outport: '<Root>/voltage_cmd' incorporates:
  //   DiscreteIntegrator: '<S36>/Integrator'
  //   Gain: '<S41>/Proportional Gain'
  //   Sum: '<S45>/Sum'

  rtY.voltage_cmd = 16.579207 * rtb_Subtract + rtDW.Integrator_DSTATE;

  // Update for DiscreteIntegrator: '<S36>/Integrator' incorporates:
  //   Gain: '<S33>/Integral Gain'

  rtDW.Integrator_DSTATE += 35.0 * rtb_Subtract * 0.01;
}

// Model initialize function
void dc_motor_control::initialize()
{
  // (no initialization code required)
}

// Constructor
dc_motor_control::dc_motor_control():
  rtU(),
  rtY(),
  rtDW()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
dc_motor_control::~dc_motor_control() = default;

//
// File trailer for generated code.
//
// [EOF]
//
