[puma]=pumaInit();
puma.handles= drawPuma( [0,0,0,0,0,0], puma);
hold on;
[T,pt]=pumaFK([0,0,0, 0, 0,0],puma);
path_file='box.mat';
data = load(path_file);
s = data.s;


pre=[0,0,0,0,0,0];
han1=puma.handles;
for t = 1:1000
    
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