function [r]=errorRate(w,v)
	y=0;
	y1=gety(w,v,[1 1 1]);
	y2=gety(w,v,[1 1 0]);
	y3=gety(w,v,[1 0 1]);
	y4=gety(w,v,[1 0 0]);



	if y1<0 & y2>0 & y3>0 & y4<0
		%disp("correct prediction here")
	end
	%r=sqrt((-1-y1)^2)+sqrt((1-y2)^2)+sqrt((1-y3)^2)+sqrt((-1-y4)^2);
	r=abs((-1-y1))+abs((1-y2))+abs((1-y3))+abs((-1-y4));

end