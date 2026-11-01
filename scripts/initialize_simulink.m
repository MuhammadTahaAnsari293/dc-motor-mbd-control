
%% SIMULINK MODEL INITIALIZATION
% Project: Model-Based Design of DC Motor Speed Controller
% Author: Muhammad Taha Ansari

% Load common project parameters
p = motor_parameters();

% Create continuous-time motor model
motor = create_motor_model(p);

% Reference-speed profile
t_ref = [0 2 5 7 10]';

omega_ref = [1 1.5 0.5 1 1]';

speed_reference = timeseries(omega_ref, t_ref);

speed_reference = setinterpmethod( ...
    speed_reference, 'zoh');

disp('Simulink model parameters initialized.');
