function y3=gety2(w,v,x)
	D=[-1 ;1 ;1 ;-1];
	rate=0.001;
	w10=w(1,1);
	w11=w(2,1);
	w12=w(3,1);
	w20=w(1,2);
	w21=w(2,2);
	w22=w(3,2);
	v10=v(1);
	v11=v(2);
	v12=v(3);


	input=x;
	x1=input(2);
	x2=input(3);

	net1=w10+w11*x1+w12*x2;
	net2=w20+w21*x1+w22*x2;
	y1=tanh(net1);
	y2=tanh(net2);
	net3=v10+v11*y1+v12*y2;
	y3=tanh(net3);
end