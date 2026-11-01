//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: dc_motor_discrete_pi.h
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
#ifndef dc_motor_discrete_pi_h_
#define dc_motor_discrete_pi_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include <cstring>
#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Class declaration for model dc_motor_discrete_pi
class dc_motor_control final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    real_T TmpSignalConversionAtStateSpace[2];
    real_T TmpRTBAtAddInport1;         // '<Root>/Noise'
    real_T ADC;                        // '<Root>/ADC'
    real_T Sum;                        // '<S47>/Sum'
    real_T Integrator_DSTATE;          // '<S38>/Integrator'
    real_T TmpRTBAtAddInport1_Buffer0; // synthesized block
    real_T NextOutput;                 // '<Root>/Noise'
    uint32_T RandSeed;                 // '<Root>/Noise'
  };

  // Continuous states (default storage)
  struct X {
    real_T StateSpace_CSTATE[2];       // '<S1>/State-Space'
  };

  // State derivatives (default storage)
  struct XDot {
    real_T StateSpace_CSTATE[2];       // '<S1>/State-Space'
  };

  // State disabled
  struct XDis {
    boolean_T StateSpace_CSTATE[2];    // '<S1>/State-Space'
  };

  // Constant parameters (default storage)
  struct ConstP {
    // Computed Parameter: StateSpace_A_pr
    //  Referenced by: '<S1>/State-Space'

    real_T StateSpace_A_pr[4];

    // Computed Parameter: StateSpace_B_pr
    //  Referenced by: '<S1>/State-Space'

    real_T StateSpace_B_pr[2];

    // Computed Parameter: StateSpace_A_ir
    //  Referenced by: '<S1>/State-Space'

    uint32_T StateSpace_A_ir[4];

    // Computed Parameter: StateSpace_B_ir
    //  Referenced by: '<S1>/State-Space'

    uint32_T StateSpace_B_ir[2];
  };

  // Real-time Model Data Structure
  using odeFSubArray = real_T[2];
  struct RT_MODEL {
    const char_T *errorStatus;
    RTWSolverInfo solverInfo;
    X *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    XDis *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T CTOutputIncnstWithState;
    real_T odeY[2];
    real_T odeF[3][2];
    ODE3_IntgData intgData;

    //
    //  Sizes:
    //  The following substructure contains sizes information
    //  for many of the model attributes such as inputs, outputs,
    //  dwork, sample times, etc.

    struct {
      int_T numContStates;
      int_T numPeriodicContStates;
      int_T numSampTimes;
    } Sizes;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      uint32_T clockTick0;
      time_T stepSize0;
      uint32_T clockTick1;
      struct {
        uint8_T TID1_2;
      } RateInteraction;

      time_T tStart;
      SimTimeStep simTimeStep;
      boolean_T stopRequestedFlag;
      time_T *t;
      time_T tArray[3];
    } Timing;

    time_T** getTPtrPtr();
    boolean_T getStopRequested() const;
    void setStopRequested(boolean_T aStopRequested);
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus);
    time_T* getTPtr() const;
    void setTPtr(time_T* aTPtr);
    boolean_T* getStopRequestedPtr();
    const char_T** getErrorStatusPtr();
    boolean_T isMajorTimeStep() const;
    boolean_T isMinorTimeStep() const;
    time_T getTStart() const;
  };

  // Copy Constructor
  dc_motor_control(dc_motor_control const&) = delete;

  // Assignment Operator
  dc_motor_control& operator= (dc_motor_control const&) & = delete;

  // Move Constructor
  dc_motor_control(dc_motor_control &&) = delete;

  // Move Assignment Operator
  dc_motor_control& operator= (dc_motor_control &&) = delete;

  // Real-Time Model get method
  dc_motor_control::RT_MODEL * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model step function
  void step2();

  // Constructor
  dc_motor_control();

  // Destructor
  ~dc_motor_control();

  // private data and function members
 private:
  // Block states
  DW rtDW;

  // Block continuous states
  X rtX;

  // Block Continuous state disabled vector
  XDis rtXDis;

  // Global mass matrix

  // Continuous states update member function
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  // Derivatives member function
  void dc_motor_discrete_pi_derivatives();

  // Real-Time Model
  RT_MODEL rtM;
};

// Constant parameters (default storage)
extern const dc_motor_control::ConstP rtConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<Root>/Manual Switch' : Eliminated due to constant selection input
//  Block '<S3>/fromWS_Signal 1' : Unused code path elimination


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
//  '<Root>' : 'dc_motor_discrete_pi'
//  '<S1>'   : 'dc_motor_discrete_pi/DC Motor'
//  '<S2>'   : 'dc_motor_discrete_pi/PID Controller'
//  '<S3>'   : 'dc_motor_discrete_pi/Signal Editor'
//  '<S4>'   : 'dc_motor_discrete_pi/PID Controller/Anti-windup'
//  '<S5>'   : 'dc_motor_discrete_pi/PID Controller/D Gain'
//  '<S6>'   : 'dc_motor_discrete_pi/PID Controller/External Derivative'
//  '<S7>'   : 'dc_motor_discrete_pi/PID Controller/Filter'
//  '<S8>'   : 'dc_motor_discrete_pi/PID Controller/Filter ICs'
//  '<S9>'   : 'dc_motor_discrete_pi/PID Controller/I Gain'
//  '<S10>'  : 'dc_motor_discrete_pi/PID Controller/Ideal P Gain'
//  '<S11>'  : 'dc_motor_discrete_pi/PID Controller/Ideal P Gain Fdbk'
//  '<S12>'  : 'dc_motor_discrete_pi/PID Controller/Integrator'
//  '<S13>'  : 'dc_motor_discrete_pi/PID Controller/Integrator ICs'
//  '<S14>'  : 'dc_motor_discrete_pi/PID Controller/N Copy'
//  '<S15>'  : 'dc_motor_discrete_pi/PID Controller/N Gain'
//  '<S16>'  : 'dc_motor_discrete_pi/PID Controller/P Copy'
//  '<S17>'  : 'dc_motor_discrete_pi/PID Controller/Parallel P Gain'
//  '<S18>'  : 'dc_motor_discrete_pi/PID Controller/Reset Signal'
//  '<S19>'  : 'dc_motor_discrete_pi/PID Controller/Saturation'
//  '<S20>'  : 'dc_motor_discrete_pi/PID Controller/Saturation Fdbk'
//  '<S21>'  : 'dc_motor_discrete_pi/PID Controller/Sum'
//  '<S22>'  : 'dc_motor_discrete_pi/PID Controller/Sum Fdbk'
//  '<S23>'  : 'dc_motor_discrete_pi/PID Controller/Tracking Mode'
//  '<S24>'  : 'dc_motor_discrete_pi/PID Controller/Tracking Mode Sum'
//  '<S25>'  : 'dc_motor_discrete_pi/PID Controller/Tsamp - Integral'
//  '<S26>'  : 'dc_motor_discrete_pi/PID Controller/Tsamp - Ngain'
//  '<S27>'  : 'dc_motor_discrete_pi/PID Controller/postSat Signal'
//  '<S28>'  : 'dc_motor_discrete_pi/PID Controller/preInt Signal'
//  '<S29>'  : 'dc_motor_discrete_pi/PID Controller/preSat Signal'
//  '<S30>'  : 'dc_motor_discrete_pi/PID Controller/Anti-windup/Passthrough'
//  '<S31>'  : 'dc_motor_discrete_pi/PID Controller/D Gain/Disabled'
//  '<S32>'  : 'dc_motor_discrete_pi/PID Controller/External Derivative/Disabled'
//  '<S33>'  : 'dc_motor_discrete_pi/PID Controller/Filter/Disabled'
//  '<S34>'  : 'dc_motor_discrete_pi/PID Controller/Filter ICs/Disabled'
//  '<S35>'  : 'dc_motor_discrete_pi/PID Controller/I Gain/Internal Parameters'
//  '<S36>'  : 'dc_motor_discrete_pi/PID Controller/Ideal P Gain/Passthrough'
//  '<S37>'  : 'dc_motor_discrete_pi/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S38>'  : 'dc_motor_discrete_pi/PID Controller/Integrator/Discrete'
//  '<S39>'  : 'dc_motor_discrete_pi/PID Controller/Integrator ICs/Internal IC'
//  '<S40>'  : 'dc_motor_discrete_pi/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S41>'  : 'dc_motor_discrete_pi/PID Controller/N Gain/Disabled'
//  '<S42>'  : 'dc_motor_discrete_pi/PID Controller/P Copy/Disabled'
//  '<S43>'  : 'dc_motor_discrete_pi/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S44>'  : 'dc_motor_discrete_pi/PID Controller/Reset Signal/Disabled'
//  '<S45>'  : 'dc_motor_discrete_pi/PID Controller/Saturation/Passthrough'
//  '<S46>'  : 'dc_motor_discrete_pi/PID Controller/Saturation Fdbk/Disabled'
//  '<S47>'  : 'dc_motor_discrete_pi/PID Controller/Sum/Sum_PI'
//  '<S48>'  : 'dc_motor_discrete_pi/PID Controller/Sum Fdbk/Disabled'
//  '<S49>'  : 'dc_motor_discrete_pi/PID Controller/Tracking Mode/Disabled'
//  '<S50>'  : 'dc_motor_discrete_pi/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S51>'  : 'dc_motor_discrete_pi/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S52>'  : 'dc_motor_discrete_pi/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S53>'  : 'dc_motor_discrete_pi/PID Controller/postSat Signal/Forward_Path'
//  '<S54>'  : 'dc_motor_discrete_pi/PID Controller/preInt Signal/Internal PreInt'
//  '<S55>'  : 'dc_motor_discrete_pi/PID Controller/preSat Signal/Forward_Path'

#endif                                 // dc_motor_discrete_pi_h_

//
// File trailer for generated code.
//
// [EOF]
//
