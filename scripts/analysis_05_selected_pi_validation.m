
%% SELECTED PI CONTROLLER VALIDATION
% Project: Model-Based Design of DC Motor Speed Controller
% Author: Muhammad Taha Ansari

clear; clc; close all;

%% 1. Initialize motor model

p = motor_parameters();
motor = create_motor_model(p);

G = motor.G;
Gd = motor.Gd;

%% 2. Selected PI controller

Kp = p.Kp;
Ki = p.Ki;

C_pi = pid(Kp, Ki);

%% 3. Closed-loop transfer functions

Loop = C_pi * G;

Tref = feedback(Loop, 1);

S = feedback(1, Loop);

Tload = minreal(Gd * S);

%% 4. Reference tracking performance

info = stepinfo(Tref);

fprintf('\n=== SELECTED PI CONTROLLER ===\n');
fprintf('Kp = %.6f\n', Kp);
fprintf('Ki = %.6f\n', Ki);

fprintf('\n=== TRACKING PERFORMANCE ===\n');
fprintf('Rise time: %.4f s\n', info.RiseTime);
fprintf('Settling time: %.4f s\n', info.SettlingTime);
fprintf('Overshoot: %.2f %%\n', info.Overshoot);
fprintf('DC gain: %.6f\n', dcgain(Tref));
fprintf('Closed-loop stable: %d\n', isstable(Tref));

%% 5. Reference tracking with load disturbance

t = (0:p.dt:8)';

r = p.omega_ref * ones(size(t));

TL = p.TL_test * double(t >= p.t_load);

y_ref = lsim(Tref, r, t);
y_load = lsim(Tload, TL, t);

omega = y_ref + y_load;

%% 6. Plot selected controller response

figure('Name', 'Selected PI Validation');

plot(t, omega, 'b', 'LineWidth', 1.8);
hold on;

plot(t, r, 'k--', 'LineWidth', 1.2);

xline(p.t_load, 'r:', 'Load Applied');

xlabel('Time (s)');
ylabel('Angular Speed (rad/s)');
title('Selected PI Controller: Tracking and Load Rejection');

legend('Motor Speed', 'Reference', ...
    'Location', 'best');

grid on;
hold off;

%% 7. Disturbance recovery check

% Evaluate the final simulated speed
final_speed = omega(end);

final_error = r(end) - final_speed;

fprintf('\n=== DISTURBANCE RESPONSE ===\n');
fprintf('Final simulated speed: %.6f rad/s\n', final_speed);
fprintf('Final tracking error: %.6f rad/s\n', final_error);

% Note:
% This is the error at the end of the simulation,
% not a formal disturbance-recovery-time metric.
