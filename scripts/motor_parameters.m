
function p = motor_parameters()
%MOTOR_PARAMETERS DC motor parameters and controller settings.
%
% Project: Model-Based Design of DC Motor Speed Controller
% Author: Muhammad Taha Ansari
%
% Note: These are illustrative motor parameters, not values
% identified from a specific commercial DC motor.

    % Electrical parameters
    p.R  = 1.0;       % Armature resistance [Ohm]
    p.L  = 0.5;       % Armature inductance [H]
    p.Kt = 0.01;      % Torque constant [N*m/A]
    p.Ke = 0.01;      % Back-EMF constant [V*s/rad]

    % Mechanical parameters
    p.J = 0.01;       % Rotor inertia [kg*m^2]
    p.b = 0.1;        % Viscous friction [N*m*s/rad]

    % Selected PI controller gains
    p.Kp = 16.579207;
    p.Ki = 35.0;

    % Initial automatic PI integral gain (for comparison)
    p.Ki_initial = 49.184749;

    % Simulation settings
    p.dt = 0.01;          % Simulation time step [s]
    p.V_test = 10;        % Test armature voltage [V]
    p.TL_test = 0.005;    % Applied load torque [N*m]
    p.t_load = 3;         % Load application time [s]
    p.omega_ref = 1;      % Reference speed [rad/s]

end
