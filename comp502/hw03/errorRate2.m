function [r]=errorRate2(w,v)
	y=[];
	number=20;
	steps=0.9/number;
	for i=0:number-1
		y=[y gety(w,v,0.1+i*steps)];
	end

	y1=gety(w,v,[1 1 1]);
	y2=gety(w,v,[1 1 0]);
	y3=gety(w,v,[1 0 1]);
	y4=gety(w,v,[1 0 0]);



	
	%r=sqrt((-1-y1)^2)+sqrt((1-y2)^2)+sqrt((1-y3)^2)+sqrt((-1-y4)^2);
	r=abs((-1-y1))+abs((1-y2))+abs((1-y3))+abs((-1-y4));

end