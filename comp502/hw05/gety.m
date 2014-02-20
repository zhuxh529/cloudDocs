function y=gety(w,v,x)
	input=x;
	slope=60;
	y1=input*w;
	y1=tanh(slope*y1);
	y1=[1 y1];
	y=tanh(slope*y1*v);
end