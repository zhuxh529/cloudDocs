function drawPhantom( actuator_angles, gimbal_angles )
% MECH 498 - Intro to Robotics - Spring 2014
% Lab #2
% Solutions by Craig McDonald
%
%    Plot a graphical representation of the Phantom Premium robot with
%    attached coordinate frames, and include a frame to represent the ideal
%    gimbal at the end effector that allows any 3D orientation.
%

% Convert actuator angles to joint angles
joint_angles = actuator2joint(actuator_angles);

% Phantom link and frame colors (three RGB values between 0 and 1)
L_1_color = [0.8,0,0]; % link 1 and frame 1 color
L_2_color = [0,0.8,0]; % link 2 and frame 2 color
L_3_color = [0,0,0.8]; % link 3 and frame 3 color
e_color = [0.5,0,0.5]; % end effector frame color
g_color = [0,0.6,0.6]; % gimbal frame color

% Create structure of phantom forward kinematics transforms
phantom_T_0_ = phantomFK(joint_angles,gimbal_angles);

% Create figure window
figure('Color','w');

% Plot links
p_0 = [0,0,0]';
p_1 = phantom_T_0_{1}(1:3,4);
p_2 = phantom_T_0_{2}(1:3,4);
p_3 = phantom_T_0_{3}(1:3,4);
p_e = phantom_T_0_{4}(1:3,4);
plot3([p_0(1),p_1(1)],[p_0(2),p_1(2)],[p_0(3),p_1(3)],'Color',L_1_color,...
    'LineWidth',2);
hold on;
plot3([p_2(1),p_3(1)],[p_2(2),p_3(2)],[p_2(3),p_3(3)],'Color',L_2_color,...
    'LineWidth',2);
plot3([p_3(1),p_e(1)],[p_3(2),p_e(2)],[p_3(3),p_e(3)],'Color',L_3_color,...
    'LineWidth',2);

% Plot world frame (frame zero)
drawPhantomFrame(eye(4),[0,0,0]);

% Plot intermediate frames
drawPhantomFrame(phantom_T_0_{1},L_1_color);
drawPhantomFrame(phantom_T_0_{2},L_2_color);
drawPhantomFrame(phantom_T_0_{3},L_3_color);

% Plot end effector frame (frame 4)
drawPhantomFrame(phantom_T_0_{4},e_color);

% Plot gimbal frame
drawPhantomFrame(phantom_T_0_{5},g_color);

% Set plot properties
xlabel('X (mm)','FontSize',16);
ylabel('Y (mm)','FontSize',16);
zlabel('Z (mm)','FontSize',16);
title('Plot Phantom Pose','FontSize',20);
grid on;
axis equal;
hold off;
rotate3d;



    function drawPhantomFrame( transform, color )
        
        % Plot properties
        origin_size = 20;
        vector_size = 20;
        marker_size = 10;
        
        % Check color input argument
        if nargin > 1
            if ~isequal(size(color),[1,3])
                error('Input argument "color" must be a 3 element row vector')
            end
            for i = 1:3
                if color(i) < 0 || color(i) > 1
                    error('All 3 elements of input argument "color" cannot be outside range 0 to 1')
                end
            end
        else
            color = [0,0,1]; % set default color to blue
        end
        
        % Extract position vector from transform
        p = transform(1:3,4);
        
        % Plot reference frame
        X_b = transform*[vector_size,0,0,1]';
        Y_b = transform*[0,vector_size,0,1]';
        Z_b = transform*[0,0,vector_size,1]';
        plot3(p(1),p(2),p(3),'.','MarkerSize',origin_size,'Color',color);
        plot3([p(1),X_b(1)],[p(2),X_b(2)],[p(3),X_b(3)],'LineWidth',1.5,'Color',color);
        plot3([p(1),Y_b(1)],[p(2),Y_b(2)],[p(3),Y_b(3)],'LineWidth',1.5,'Color',color);
        plot3([p(1),Z_b(1)],[p(2),Z_b(2)],[p(3),Z_b(3)],'LineWidth',1.5,'Color',color);
        plot3(X_b(1),X_b(2),X_b(3),'LineWidth',1.5,'Marker','x','MarkerSize',marker_size,'Color',color);
        plot3(Y_b(1),Y_b(2),Y_b(3),'LineWidth',1.5,'Marker','o','MarkerSize',marker_size,'Color',color);
        plot3(Z_b(1),Z_b(2),Z_b(3),'LineWidth',1.5,'Marker','d','MarkerSize',marker_size,'Color',color);
        
    end


end

