//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: dc_motor_discrete_pi_controller.h
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
#ifndef dc_motor_discrete_pi_controller_h_
#define dc_motor_discrete_pi_controller_h_
#include <cmath>
#include "rtwtypes.h"

// Class declaration for model dc_motor_discrete_pi_controller
class dc_motor_control final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    real_T Integrator_DSTATE;          // '<S36>/Integrator'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU {
    real_T omega_ref;                  // '<Root>/omega_ref'
    real_T omega_measured;             // '<Root>/omega_measured'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY {
    real_T voltage_cmd;                // '<Root>/voltage_cmd'
  };

  // Copy Constructor
  dc_motor_control(dc_motor_control const&) = delete;

  // Assignment Operator
  dc_motor_control& operator= (dc_motor_control const&) & = delete;

  // Move Constructor
  dc_motor_control(dc_motor_control &&) = delete;

  // Move Assignment Operator
  dc_motor_control& operator= (dc_motor_control &&) = delete;

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // Constructor
  dc_motor_control();

  // Destructor
  ~dc_motor_control();

  // private data and function members
 private:
  // Block states
  DW rtDW;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'dc_motor_discrete_pi_controller'
//  '<S1>'   : 'dc_motor_discrete_pi_controller/PID Controller'
//  '<S2>'   : 'dc_motor_discrete_pi_controller/PID Controller/Anti-windup'
//  '<S3>'   : 'dc_motor_discrete_pi_controller/PID Controller/D Gain'
//  '<S4>'   : 'dc_motor_discrete_pi_controller/PID Controller/External Derivative'
//  '<S5>'   : 'dc_motor_discrete_pi_controller/PID Controller/Filter'
//  '<S6>'   : 'dc_motor_discrete_pi_controller/PID Controller/Filter ICs'
//  '<S7>'   : 'dc_motor_discrete_pi_controller/PID Controller/I Gain'
//  '<S8>'   : 'dc_motor_discrete_pi_controller/PID Controller/Ideal P Gain'
//  '<S9>'   : 'dc_motor_discrete_pi_controller/PID Controller/Ideal P Gain Fdbk'
//  '<S10>'  : 'dc_motor_discrete_pi_controller/PID Controller/Integrator'
//  '<S11>'  : 'dc_motor_discrete_pi_controller/PID Controller/Integrator ICs'
//  '<S12>'  : 'dc_motor_discrete_pi_controller/PID Controller/N Copy'
//  '<S13>'  : 'dc_motor_discrete_pi_controller/PID Controller/N Gain'
//  '<S14>'  : 'dc_motor_discrete_pi_controller/PID Controller/P Copy'
//  '<S15>'  : 'dc_motor_discrete_pi_controller/PID Controller/Parallel P Gain'
//  '<S16>'  : 'dc_motor_discrete_pi_controller/PID Controller/Reset Signal'
//  '<S17>'  : 'dc_motor_discrete_pi_controller/PID Controller/Saturation'
//  '<S18>'  : 'dc_motor_discrete_pi_controller/PID Controller/Saturation Fdbk'
//  '<S19>'  : 'dc_motor_discrete_pi_controller/PID Controller/Sum'
//  '<S20>'  : 'dc_motor_discrete_pi_controller/PID Controller/Sum Fdbk'
//  '<S21>'  : 'dc_motor_discrete_pi_controller/PID Controller/Tracking Mode'
//  '<S22>'  : 'dc_motor_discrete_pi_controller/PID Controller/Tracking Mode Sum'
//  '<S23>'  : 'dc_motor_discrete_pi_controller/PID Controller/Tsamp - Integral'
//  '<S24>'  : 'dc_motor_discrete_pi_controller/PID Controller/Tsamp - Ngain'
//  '<S25>'  : 'dc_motor_discrete_pi_controller/PID Controller/postSat Signal'
//  '<S26>'  : 'dc_motor_discrete_pi_controller/PID Controller/preInt Signal'
//  '<S27>'  : 'dc_motor_discrete_pi_controller/PID Controller/preSat Signal'
//  '<S28>'  : 'dc_motor_discrete_pi_controller/PID Controller/Anti-windup/Passthrough'
//  '<S29>'  : 'dc_motor_discrete_pi_controller/PID Controller/D Gain/Disabled'
//  '<S30>'  : 'dc_motor_discrete_pi_controller/PID Controller/External Derivative/Disabled'
//  '<S31>'  : 'dc_motor_discrete_pi_controller/PID Controller/Filter/Disabled'
//  '<S32>'  : 'dc_motor_discrete_pi_controller/PID Controller/Filter ICs/Disabled'
//  '<S33>'  : 'dc_motor_discrete_pi_controller/PID Controller/I Gain/Internal Parameters'
//  '<S34>'  : 'dc_motor_discrete_pi_controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S35>'  : 'dc_motor_discrete_pi_controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S36>'  : 'dc_motor_discrete_pi_controller/PID Controller/Integrator/Discrete'
//  '<S37>'  : 'dc_motor_discrete_pi_controller/PID Controller/Integrator ICs/Internal IC'
//  '<S38>'  : 'dc_motor_discrete_pi_controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S39>'  : 'dc_motor_discrete_pi_controller/PID Controller/N Gain/Disabled'
//  '<S40>'  : 'dc_motor_discrete_pi_controller/PID Controller/P Copy/Disabled'
//  '<S41>'  : 'dc_motor_discrete_pi_controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S42>'  : 'dc_motor_discrete_pi_controller/PID Controller/Reset Signal/Disabled'
//  '<S43>'  : 'dc_motor_discrete_pi_controller/PID Controller/Saturation/Passthrough'
//  '<S44>'  : 'dc_motor_discrete_pi_controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S45>'  : 'dc_motor_discrete_pi_controller/PID Controller/Sum/Sum_PI'
//  '<S46>'  : 'dc_motor_discrete_pi_controller/PID Controller/Sum Fdbk/Disabled'
//  '<S47>'  : 'dc_motor_discrete_pi_controller/PID Controller/Tracking Mode/Disabled'
//  '<S48>'  : 'dc_motor_discrete_pi_controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S49>'  : 'dc_motor_discrete_pi_controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S50>'  : 'dc_motor_discrete_pi_controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S51>'  : 'dc_motor_discrete_pi_controller/PID Controller/postSat Signal/Forward_Path'
//  '<S52>'  : 'dc_motor_discrete_pi_controller/PID Controller/preInt Signal/Internal PreInt'
//  '<S53>'  : 'dc_motor_discrete_pi_controller/PID Controller/preSat Signal/Forward_Path'

#endif                                 // dc_motor_discrete_pi_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
