//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: dc_motor_discrete_pi.cpp
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
#include "rtwtypes.h"
#include <cmath>

extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);

// private model entry point functions
extern void dc_motor_discrete_pi_derivatives();

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
void dc_motor_control::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3]{
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3]{
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t { rtsiGetT(si) };

  time_T tnew { rtsiGetSolverStopTime(si) };

  time_T h { rtsiGetStepSize(si) };

  real_T *x { rtsiGetContStates(si) };

  ODE3_IntgData *id { static_cast<ODE3_IntgData *>(rtsiGetSolverData(si)) };

  real_T *y { id->y };

  real_T *f0 { id->f[0] };

  real_T *f1 { id->f[1] };

  real_T *f2 { id->f[2] };

  real_T hB[3];
  int_T i;
  int_T nXc { 2 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  dc_motor_discrete_pi_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  dc_motor_discrete_pi_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  this->step();
  dc_motor_discrete_pi_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  // Uniform random number generator (random number between 0 and 1)

  // #define IA      16807                      magic multiplier = 7^5
  // #define IM      2147483647                 modulus = 2^31-1
  // #define IQ      127773                     IM div IA
  // #define IR      2836                       IM modulo IA
  // #define S       4.656612875245797e-10      reciprocal of 2^31-1
  // test = IA * (seed % IQ) - IR * (seed/IQ)
  // seed = test < 0 ? (test + IM) : test
  // return (seed*S)

  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return static_cast<real_T>(*u) * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  // Normal (Gaussian) random number generator
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = std::sqrt(-2.0 * std::log(si) / si) * sr;
  return y;
}

// Model step function for TID0
void dc_motor_control::step()          // Sample time: [0.0s, 0.0s]
{
  // local block i/o variables
  real_T rtb_IntegralGain;
  boolean_T tmp;
  if ((&rtM)->isMajorTimeStep()) {
    // set solver stop time
    rtsiSetSolverStopTime(&(&rtM)->solverInfo,(((&rtM)->Timing.clockTick0+1)*
      (&rtM)->Timing.stepSize0));

    // Update the flag to indicate when data transfers from
    //   Sample time: [0.01s, 0.0s] to Sample time: [0.1s, 0.0s]
    ((&rtM)->Timing.RateInteraction.TID1_2)++;
    if (((&rtM)->Timing.RateInteraction.TID1_2) > 9) {
      (&rtM)->Timing.RateInteraction.TID1_2 = 0;
    }
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if ((&rtM)->isMinorTimeStep()) {
    (&rtM)->Timing.t[0] = rtsiGetT(&(&rtM)->solverInfo);
  }

  // RateTransition generated from: '<Root>/Add'
  tmp = ((&rtM)->isMajorTimeStep());
  if (tmp) {
    if ((&rtM)->Timing.RateInteraction.TID1_2 == 1) {
      // RateTransition generated from: '<Root>/Add'
      rtDW.TmpRTBAtAddInport1 = rtDW.TmpRTBAtAddInport1_Buffer0;
    }

    // ZeroOrderHold: '<Root>/ADC' incorporates:
    //   StateSpace: '<S1>/State-Space'
    //   Sum: '<Root>/Add'

    rtDW.ADC = rtDW.TmpRTBAtAddInport1 + rtX.StateSpace_CSTATE[0U];

    // Sum: '<S47>/Sum' incorporates:
    //   Constant: '<Root>/Constant'
    //   DiscreteIntegrator: '<S38>/Integrator'
    //   Gain: '<S43>/Proportional Gain'
    //   Sum: '<Root>/Subtract'

    rtDW.Sum = (10.0 - rtDW.ADC) * 16.579207 + rtDW.Integrator_DSTATE;
  }

  // End of RateTransition generated from: '<Root>/Add'

  // SignalConversion generated from: '<S1>/State-Space'
  rtDW.TmpSignalConversionAtStateSpace[0] = rtDW.Sum;

  // Step: '<Root>/Step1'
  if ((&rtM)->Timing.t[0] < 3.0) {
    // SignalConversion generated from: '<S1>/State-Space'
    rtDW.TmpSignalConversionAtStateSpace[1] = 0.0;
  } else {
    // SignalConversion generated from: '<S1>/State-Space'
    rtDW.TmpSignalConversionAtStateSpace[1] = 0.005;
  }

  // End of Step: '<Root>/Step1'
  if (tmp) {
    // Gain: '<S35>/Integral Gain' incorporates:
    //   Constant: '<Root>/Constant'
    //   Sum: '<Root>/Subtract'

    rtb_IntegralGain = (10.0 - rtDW.ADC) * 35.0;
  }

  if ((&rtM)->isMajorTimeStep()) {
    if ((&rtM)->isMajorTimeStep()) {
      // Update for DiscreteIntegrator: '<S38>/Integrator'
      rtDW.Integrator_DSTATE += 0.01 * rtb_IntegralGain;
    }
  }                                    // end MajorTimeStep

  if ((&rtM)->isMajorTimeStep()) {
    rt_ertODEUpdateContinuousStates(&(&rtM)->solverInfo);

    // Update absolute time
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++(&rtM)->Timing.clockTick0;
    (&rtM)->Timing.t[0] = rtsiGetSolverStopTime(&(&rtM)->solverInfo);

    // Update absolute time
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.01, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    (&rtM)->Timing.clockTick1++;
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void dc_motor_control::dc_motor_discrete_pi_derivatives()
{
  dc_motor_control::XDot *_rtXdot;
  int32_T ri;
  uint32_T StateSpace_CSTATE_tmp;
  _rtXdot = ((XDot *) (&rtM)->derivs);

  // Derivatives for StateSpace: '<S1>/State-Space'
  _rtXdot->StateSpace_CSTATE[0] = 0.0;
  _rtXdot->StateSpace_CSTATE[1] = 0.0;
  for (ri = 0; ri < 2; ri = static_cast<int32_T>(static_cast<uint32_T>(ri) + 1U))
  {
    StateSpace_CSTATE_tmp = rtConstP.StateSpace_A_ir[static_cast<uint32_T>(ri)];
    _rtXdot->StateSpace_CSTATE[StateSpace_CSTATE_tmp] +=
      rtConstP.StateSpace_A_pr[static_cast<uint32_T>(ri)] *
      rtX.StateSpace_CSTATE[0U];
  }

  while (ri < 4) {
    StateSpace_CSTATE_tmp = rtConstP.StateSpace_A_ir[static_cast<uint32_T>(ri)];
    _rtXdot->StateSpace_CSTATE[StateSpace_CSTATE_tmp] +=
      rtConstP.StateSpace_A_pr[static_cast<uint32_T>(ri)] *
      rtX.StateSpace_CSTATE[1U];
    ri = static_cast<int32_T>(static_cast<uint32_T>(ri) + 1U);
  }

  _rtXdot->StateSpace_CSTATE[rtConstP.StateSpace_B_ir[0U]] +=
    rtConstP.StateSpace_B_pr[0U] * rtDW.TmpSignalConversionAtStateSpace[0U];
  _rtXdot->StateSpace_CSTATE[rtConstP.StateSpace_B_ir[1U]] +=
    rtConstP.StateSpace_B_pr[1U] * rtDW.TmpSignalConversionAtStateSpace[1U];

  // End of Derivatives for StateSpace: '<S1>/State-Space'
}

// Model step function for TID2
void dc_motor_control::step2()         // Sample time: [0.1s, 0.0s]
{
  real_T rtb_Noise;

  // RandomNumber: '<Root>/Noise'
  rtb_Noise = rtDW.NextOutput;

  // RateTransition generated from: '<Root>/Add'
  rtDW.TmpRTBAtAddInport1_Buffer0 = rtb_Noise;

  // Update for RandomNumber: '<Root>/Noise'
  rtDW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed) * 0.2;
}

// Model initialize function
void dc_motor_control::initialize()
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&(&rtM)->solverInfo, &(&rtM)->Timing.simTimeStep);
    rtsiSetTPtr(&(&rtM)->solverInfo, (&rtM)->getTPtrPtr());
    rtsiSetStepSizePtr(&(&rtM)->solverInfo, &(&rtM)->Timing.stepSize0);
    rtsiSetdXPtr(&(&rtM)->solverInfo, &(&rtM)->derivs);
    rtsiSetContStatesPtr(&(&rtM)->solverInfo, (real_T **) &(&rtM)->contStates);
    rtsiSetNumContStatesPtr(&(&rtM)->solverInfo, &(&rtM)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&rtM)->solverInfo, &(&rtM)
      ->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&rtM)->solverInfo, &(&rtM)
      ->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&rtM)->solverInfo, &(&rtM)
      ->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&(&rtM)->solverInfo, (boolean_T**) &(&rtM)
      ->contStateDisabled);
    rtsiSetErrorStatusPtr(&(&rtM)->solverInfo, (&rtM)->getErrorStatusPtr());
    rtsiSetRTModelPtr(&(&rtM)->solverInfo, (&rtM));
  }

  rtsiSetSimTimeStep(&(&rtM)->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&(&rtM)->solverInfo, false);
  rtsiSetIsContModeFrozen(&(&rtM)->solverInfo, false);
  (&rtM)->intgData.y = (&rtM)->odeY;
  (&rtM)->intgData.f[0] = (&rtM)->odeF[0];
  (&rtM)->intgData.f[1] = (&rtM)->odeF[1];
  (&rtM)->intgData.f[2] = (&rtM)->odeF[2];
  (&rtM)->contStates = ((X *) &rtX);
  (&rtM)->contStateDisabled = ((XDis *) &rtXDis);
  (&rtM)->Timing.tStart = (0.0);
  rtsiSetSolverData(&(&rtM)->solverInfo, static_cast<void *>(&(&rtM)->intgData));
  rtsiSetSolverName(&(&rtM)->solverInfo,"ode3");
  (&rtM)->setTPtr(&(&rtM)->Timing.tArray[0]);
  (&rtM)->Timing.stepSize0 = 0.01;

  // InitializeConditions for StateSpace: '<S1>/State-Space'
  rtX.StateSpace_CSTATE[0] = 0.0;
  rtX.StateSpace_CSTATE[1] = 0.0;

  // InitializeConditions for RandomNumber: '<Root>/Noise'
  rtDW.RandSeed = 1144108930U;
  rtDW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed) * 0.2;
}

time_T** dc_motor_control::RT_MODEL::getTPtrPtr()
{
  return &(Timing.t);
}

boolean_T dc_motor_control::RT_MODEL::getStopRequested() const
{
  return (Timing.stopRequestedFlag);
}

void dc_motor_control::RT_MODEL::setStopRequested(boolean_T aStopRequested)
{
  (Timing.stopRequestedFlag = aStopRequested);
}

const char_T* dc_motor_control::RT_MODEL::getErrorStatus() const
{
  return (errorStatus);
}

void dc_motor_control::RT_MODEL::setErrorStatus(const char_T* const aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

time_T* dc_motor_control::RT_MODEL::getTPtr() const
{
  return (Timing.t);
}

void dc_motor_control::RT_MODEL::setTPtr(time_T* aTPtr)
{
  (Timing.t = aTPtr);
}

boolean_T* dc_motor_control::RT_MODEL::getStopRequestedPtr()
{
  return (&(Timing.stopRequestedFlag));
}

const char_T** dc_motor_control::RT_MODEL::getErrorStatusPtr()
{
  return &errorStatus;
}

boolean_T dc_motor_control::RT_MODEL::isMajorTimeStep() const
{
  return ((Timing.simTimeStep) == MAJOR_TIME_STEP);
}

boolean_T dc_motor_control::RT_MODEL::isMinorTimeStep() const
{
  return ((Timing.simTimeStep) == MINOR_TIME_STEP);
}

time_T dc_motor_control::RT_MODEL::getTStart() const
{
  return (Timing.tStart);
}

// Constructor
dc_motor_control::dc_motor_control() :
  rtDW(),
  rtX(),
  rtXDis(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
dc_motor_control::~dc_motor_control() = default;

// Real-Time Model get method
dc_motor_control::RT_MODEL * dc_motor_control::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
