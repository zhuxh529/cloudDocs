%Xihao Zhu
%problem 3
%fprintf('Running warmUpExercise ... \n');


b=90 ;% b is angle pi/2 degree
z=45 ;% z is angle pi/4 degree

Ry=[cosd(b) 0 sind(b); 0 1 0;-sind(b) 0 cosd(b)];
Rz=[cosd(z) -sind(z) 0; sind(z) cosd(z) 0; 0 0 1];	


%p4 solution
Rtotal=Rz*Ry;
p2=Rtotal*[1;0;0];
disp("question 4 p2:");
disp(p2);

%p5 solution
Rtotal=Ry*Rz;
p2=Rtotal*[1;0;0];
disp("question 5 p2:");
disp(p2);




