
%% OPEN-LOOP DC MOTOR WITH LOAD DISTURBANCE
% Project: Model-Based Design of DC Motor Speed Controller
% Author: Muhammad Taha Ansari

clear; clc; close all;

%% 1. Initialize motor model

p = motor_parameters();
motor = create_motor_model(p);

sys = motor.sys;

%% 2. Simulation time

t = (0:p.dt:8)';

%% 3. Define input signals

% Constant armature voltage
V = p.V_test * ones(size(t));

% Load torque applied at t = 3 seconds
TL = p.TL_test * double(t >= p.t_load);

% Combine voltage and load torque inputs
u = [V, TL];

%% 4. Simulate motor response

[omega, tout] = lsim(sys, u, t);

%% 5. Plot voltage, load torque and speed

figure('Name', 'Open-Loop Load Disturbance');

subplot(3, 1, 1);

plot(tout, V, 'b', 'LineWidth', 1.5);
ylabel('Voltage (V)');
title('Applied Armature Voltage');
grid on;

subplot(3, 1, 2);

plot(tout, TL, 'r', 'LineWidth', 1.5);
ylabel('Load Torque (N*m)');
title('External Load Disturbance');
grid on;

subplot(3, 1, 3);

plot(tout, omega, 'k', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('Speed (rad/s)');
title('Open-Loop Motor Speed');
grid on;

sgtitle('DC Motor Response to Load Disturbance');

%% 6. Theoretical steady-state values

denominator = p.R*p.b + p.Kt*p.Ke;

omega_before = ...
    (p.Kt * p.V_test) / denominator;

omega_after = ...
    (p.Kt * p.V_test - p.R*p.TL_test) / denominator;

speed_reduction = omega_before - omega_after;

%% 7. Display results

fprintf('\n=== OPEN-LOOP LOAD ANALYSIS ===\n');

fprintf('Speed before load: %.4f rad/s\n', omega_before);
fprintf('Speed after load:  %.4f rad/s\n', omega_after);
fprintf('Speed reduction:   %.4f rad/s\n', speed_reduction);
