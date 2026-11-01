//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: dc_motor_discrete_pi_data.cpp
//
// Code generated for Simulink model 'dc_motor_discrete_pi'.
//
// Model version                  : 1.12
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Sun Nov  1 21:12:31 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "dc_motor_discrete_pi.h"

// Constant parameters (default storage)
const dc_motor_control::ConstP rtConstP{
  // Computed Parameter: StateSpace_A_pr
  //  Referenced by: '<S1>/State-Space'

  { -10.0, -0.02, 1.0, -2.0 },

  // Computed Parameter: StateSpace_B_pr
  //  Referenced by: '<S1>/State-Space'

  { 2.0, -100.0 },

  // Computed Parameter: StateSpace_A_ir
  //  Referenced by: '<S1>/State-Space'

  { 0U, 1U, 0U, 1U },

  // Computed Parameter: StateSpace_B_ir
  //  Referenced by: '<S1>/State-Space'

  { 1U, 0U }
};

//
// File trailer for generated code.
//
// [EOF]
//
