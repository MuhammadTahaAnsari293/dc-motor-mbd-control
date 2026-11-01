
%% INITIAL PI CONTROLLER DESIGN
% Project: Model-Based Design of DC Motor Speed Controller
% Author: Muhammad Taha Ansari

clear; clc; close all;

%% 1. Initialize motor model

p = motor_parameters();
motor = create_motor_model(p);

G = motor.G;

%% 2. Display plant transfer function

disp('=== MOTOR TRANSFER FUNCTION ===');
disp(tf(G));

%% 3. Automatic PI tuning

C_pi = pidtune(G, 'PI');

Kp_auto = C_pi.Kp;
Ki_auto = C_pi.Ki;

fprintf('\n=== AUTOMATIC PI GAINS ===\n');
fprintf('Kp = %.6f\n', Kp_auto);
fprintf('Ki = %.6f\n', Ki_auto);

%% 4. Closed-loop transfer function

T = feedback(C_pi * G, 1);

%% 5. Plot closed-loop step response

figure('Name', 'Initial PI Controller Response');

step(T, 8);

title('Closed-Loop DC Motor Speed - Initial PI');
xlabel('Time (s)');
ylabel('Angular Speed (rad/s)');
grid on;

%% 6. Evaluate performance

info = stepinfo(T);

fprintf('\n=== INITIAL PI PERFORMANCE ===\n');

fprintf('Rise time: %.4f s\n', info.RiseTime);
fprintf('Settling time: %.4f s\n', info.SettlingTime);
fprintf('Overshoot: %.2f %%\n', info.Overshoot);
fprintf('DC gain: %.6f\n', dcgain(T));
fprintf('Stable: %d\n', isstable(T));
