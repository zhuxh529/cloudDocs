function drawScrew( translation, rotation, ax, color )
% MECH 498 - Intro to Robotics - Spring 2014
% Lab #2
% Solutions by Craig McDonald
%
%    Plot a reference frame generated by a screw transformation described
%    by translation, rotation, and ax using drawFrame.m in the given color.
%    
% 

% Check color input argument
if nargin < 4
    color = [0,0,1]; % set default color to blue
end

S = screwtf(translation,rotation,ax);
drawFrame(S,color);
title('Plot a Screw Transform','FontSize',20);
hold on;

% Generate a curve depicting the given screw transformation
X = [1,0,0]'; % fixed X unit vector
new_ax = cross(X,ax); % calculate new rotation axis
r = acos(dot(X,ax)/norm(ax)); % angle of rotation
T = screwtf(0,r,new_ax); % axis-angle rotation transform
R = T(1:3,1:3); % extract rotation matrix
scale = [translation/rotation,0,0;0,1,0;0,0,1]; % scaling matrix along axis
x = 0:5e-3:rotation; % 3D coordinates of exponential function
y = real(exp(1i*x));
z = imag(exp(1i*x));
curve = R*scale*[x;y;z]; % scale and rotate the curve to align with axis ax

% Plot the new screw curve connecting the reference frames
plot3([0,translation*ax(1)],[0,translation*ax(2)],[0,translation*ax(3)],'k--');
plot3([0,curve(1,1)],[0,curve(2,1)],[0,curve(3,1)],'Color','k');
segment = 25;
N = ceil(length(x)/segment);
for k = 1:N-1
    plot3(curve(1,(k-1)*segment+1:k*segment),curve(2,(k-1)*segment+1:k*segment),...
        curve(3,(k-1)*segment+1:k*segment),'Color',(k-1)/N*color);
end
plot3(curve(1,k*segment+1:end),curve(2,k*segment+1:end),curve(3,k*segment+1:end),...
    'Color',(N-1)/N*color);
plot3([curve(1,end),S(1,4)],[curve(2,end),S(2,4)],[curve(3,end),S(3,4)],'Color',color);
axis equal


end
