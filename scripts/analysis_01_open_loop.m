
%% OPEN-LOOP DC MOTOR ANALYSIS
% Project: Model-Based Design of DC Motor Speed Controller
% Author: Muhammad Taha Ansari

clear; clc; close all;

%% 1. Initialize motor model

p = motor_parameters();
motor = create_motor_model(p);

G = motor.G;

disp('=== OPEN-LOOP MOTOR ANALYSIS ===');

%% 2. Display mathematical model

disp('State-space model:');
disp(G);

disp('Voltage-to-speed transfer function:');
disp(tf(G));

%% 3. Unit-step response (1 V)

figure('Name', 'Open-Loop Unit-Step Response');

step(G, 5);

title('Open-Loop DC Motor Response (1 V)');
xlabel('Time (s)');
ylabel('Angular Speed (rad/s)');
grid on;

%% 4. Response to different armature voltages

t = 0:p.dt:5;

voltage_values = [1, 5, 10, 20];

figure('Name', 'Response at Different Voltages');
hold on;

for k = 1:length(voltage_values)

    V = voltage_values(k);

    [omega, tout] = step(V * G, t);

    plot(tout, omega, 'LineWidth', 1.5, ...
        'DisplayName', sprintf('%g V', V));

end

xlabel('Time (s)');
ylabel('Angular Speed (rad/s)');
title('DC Motor Response at Different Voltages');

legend('show', 'Location', 'best');
grid on;
hold off;

%% 5. Voltage versus steady-state speed

Kdc = dcgain(G);

V_range = 0:1:100;

omega_ss = Kdc * V_range;

figure('Name', 'Voltage vs Steady-State Speed');

plot(V_range, omega_ss, 'LineWidth', 2);

xlabel('Armature Voltage (V)');
ylabel('Steady-State Angular Speed (rad/s)');
title('Voltage vs Steady-State Speed');

grid on;

fprintf('\nDC gain: %.6f rad/s/V\n', Kdc);

%% 6. Transient performance

info = stepinfo(G);

fprintf('\n=== TRANSIENT PERFORMANCE ===\n');
fprintf('Rise time: %.4f s\n', info.RiseTime);
fprintf('Settling time: %.4f s\n', info.SettlingTime);
fprintf('Overshoot: %.2f %%\n', info.Overshoot);

%% 7. Poles and stability

motor_poles = pole(G);

disp('Open-loop poles:');
disp(motor_poles);

fprintf('Open-loop stable: %d\n', isstable(G));

%% 8. Steady-state speed at test voltage

omega_test = Kdc * p.V_test;

fprintf('\nAt %.2f V, steady-state speed = %.4f rad/s\n', ...
    p.V_test, omega_test);
