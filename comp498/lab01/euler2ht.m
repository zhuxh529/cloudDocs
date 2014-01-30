%xihao zhu
% i assume the input order is from z to y to x
function [T, T_inv]= euler2ht(angles, pos)

	x=angles(3);
	y=angles(2);
	z=angles(1);
	Rx=[1 0 0; 0 cosd(x) -sind(x); 0 sind(x) cosd(x)];
	Ry=[cosd(y) 0 sind(y); 0 1 0;-sind(y) 0 cosd(y)];
	Rz=[cosd(z) -sind(z) 0; sind(z) cosd(z) 0; 0 0 1];
	Rtotal=Rz*Ry*Rx;

	position=[pos'(3); pos'(2); pos'(1)];
	T=[Rtotal position];
	T=[T; 0 0 0 1];

	T_inv=[transpose(Rtotal) -transpose(Rtotal)*position];
	T_inv=[T_inv;0 0 0 1];

end