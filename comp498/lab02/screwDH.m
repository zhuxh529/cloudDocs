function m=screwDH(a,alpha,d,theta)
	m=screwtf(a,alpha,[1;0;0])*screwtf(d,theta,[0;0;1]);
	%m2=[cos(theta) -sin(theta) 0 a;...
	%	sin(theta)*cos(alpha) cos(theta)*cos(alpha) -sin(alpha) -sin(alpha)*d;...
	%	sin(theta)*sin(alpha) cos(theta)*sin(alpha) cos(alpha) cos(alpha)*d;...
	%	0 0 0 1]
end