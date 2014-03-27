function out=test(x,y,w)
	
D=solve('px=cos(t1)*(a2*cos(t2) +a3*cos(t2+t3)-d4*sin(t2+t3)) -d3*sin(t1)',...
	'py=sin(t1)*(a2*cos(t2) +a3*cos(t2+t3)-d4*sin(t2+t3)) +d3*cos(t1)',...
	'pz=-a3*sin(t2+t3)-a2*sin(t2)-d4*cos(t2+t3)','t1','t2','t3');



end