function y=gety(w,v,x)
	input=x;
	y1=input*w;
	y1=tanh(y1);
	y1=[1 y1];
	y=tanh(y1*v);
end