
function motor = create_motor_model(p)
%CREATE_MOTOR_MODEL Build the continuous-time DC motor model.
%
% States:
%   x(1) = angular speed [rad/s]
%   x(2) = armature current [A]
%
% Inputs:
%   u(1) = armature voltage [V]
%   u(2) = opposing load torque [N*m]
%
% Output:
%   y = angular speed [rad/s]

    A = [-p.b/p.J,    p.Kt/p.J;
         -p.Ke/p.L,  -p.R/p.L];

    B = [0,         -1/p.J;
         1/p.L,      0];

    C = [1, 0];

    D = [0, 0];

    % Two-input continuous-time state-space model
    sys = ss(A, B, C, D);

    sys.InputName = {'Voltage', 'LoadTorque'};
    sys.OutputName = 'AngularSpeed';

    % Extract individual input channels
    G  = sys(:, 1);   % Voltage -> speed
    Gd = sys(:, 2);   % Load torque -> speed

    % Return model components
    motor.A = A;
    motor.B = B;
    motor.C = C;
    motor.D = D;

    motor.sys = sys;
    motor.G = G;
    motor.Gd = Gd;

end
