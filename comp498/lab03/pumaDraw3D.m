function pumaDraw3D( path_file )
% MECH 498 - Intro to Robotics - Spring 2014
% Lab 3 - Inverse Kinematics
%
%    DESCRIPTION - Plot a graphical representation of the PUMA 560
%    Industrial robot with attached coordinate frames as it moves through a
%    series of poses defined by path_file.
%    
%    ADDITIONAL CODE NEEDED: lots

% Initialize the puma struct
puma = pumaInit();

% Get path position data
data = load(path_file);
s = data.s;

% Draw PUMA initially in zero position (do not change)
prev_angles = zeros(1,6);
puma.handles = drawPuma(prev_angles,puma);
hold on;

[T,pt]=pumaFK([0,0,0, 0, 0,0],puma);

% Select desired orientation for the tool
R = [];
pre=prev_angles;
% Draw in 3D
for t = 1:size(s,2)

	T(1,4)=s(1,t);
    T(2,4)=s(2,t);
    T(3,4)=s(3,t);

    [is, angle]=pumaIK(T,pre,puma);
    pre=angle;
    
    if is==1

    	setPuma(angle, puma);
    end
    
    % Select desired position for the tool
    
    % Solve inverse kinematics for nearest solution

    % Move robot using setPuma() if solution exists
    
    % Plot a point at the tool tip
    
    % Update previous joint angles

end




end

