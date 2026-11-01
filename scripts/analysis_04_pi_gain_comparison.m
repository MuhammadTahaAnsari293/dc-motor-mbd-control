
%% PI CONTROLLER GAIN COMPARISON
% Project: Model-Based Design of DC Motor Speed Controller
% Author: Muhammad Taha Ansari

clear; clc; close all;

%% 1. Initialize motor model

p = motor_parameters();
motor = create_motor_model(p);

G = motor.G;
Gd = motor.Gd;

%% 2. Controller candidates

Kp = p.Kp;

Ki_values = [p.Ki_initial, 35, 25];

%% 3. Simulation settings

t = (0:p.dt:8)';

r = p.omega_ref * ones(size(t));

TL = p.TL_test * double(t >= p.t_load);

%% 4. Create comparison figures

figure_tracking = figure( ...
    'Name', 'PI Reference Tracking Comparison');

hold on;

figure_disturbance = figure( ...
    'Name', 'PI Load Disturbance Comparison');

hold on;

%% 5. Compare integral gains

fprintf('\n=== PI GAIN COMPARISON ===\n');

for k = 1:length(Ki_values)

    Ki = Ki_values(k);

    % PI controller
    C_pi = pid(Kp, Ki);

    % Open-loop transfer function
    Loop = C_pi * G;

    % Reference-to-speed transfer function
    Tref = feedback(Loop, 1);

    % Sensitivity function
    S = feedback(1, Loop);

    % Load-torque-to-speed transfer function
    Tload = minreal(Gd * S);

    %% Reference tracking

    y_tracking = lsim(Tref, r, t);

    figure(figure_tracking);

    plot(t, y_tracking, 'LineWidth', 1.5, ...
        'DisplayName', sprintf('Ki = %.2f', Ki));

    %% Reference tracking with load disturbance

    y_load = lsim(Tload, TL, t);

    omega = y_tracking + y_load;

    figure(figure_disturbance);

    plot(t, omega, 'LineWidth', 1.5, ...
        'DisplayName', sprintf('Ki = %.2f', Ki));

    %% Performance metrics

    info = stepinfo(Tref);

    fprintf('\nKp = %.6f, Ki = %.6f\n', Kp, Ki);
    fprintf('Rise time: %.4f s\n', info.RiseTime);
    fprintf('Settling time: %.4f s\n', info.SettlingTime);
    fprintf('Overshoot: %.2f %%\n', info.Overshoot);
    fprintf('Stable: %d\n', isstable(Tref));

end

%% 6. Format reference-tracking figure

figure(figure_tracking);

yline(p.omega_ref, 'k--', 'Reference', ...
    'HandleVisibility', 'off');

xlabel('Time (s)');
ylabel('Angular Speed (rad/s)');
title('Effect of Integral Gain on Reference Tracking');

legend('show', 'Location', 'best');
grid on;
hold off;

%% 7. Format disturbance-rejection figure

figure(figure_disturbance);

yline(p.omega_ref, 'k--', 'Reference', ...
    'HandleVisibility', 'off');

xline(p.t_load, 'k:', 'Load Applied', ...
    'HandleVisibility', 'off');

xlabel('Time (s)');
ylabel('Angular Speed (rad/s)');
title('PI Controller Load Disturbance Rejection');

legend('show', 'Location', 'best');
grid on;
hold off;
