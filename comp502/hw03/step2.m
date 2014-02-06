function [w1,v1]=step2(n,win,vin)
	%w=initWeights(3,2,0.01);
	%v=initWeights(3,1,0.01);
	w=win;
	v=vin;
	x=[1 1 1; 1 1 0 ;1 0 1;1 0 0 ];
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

for i=1:n
	%no=randi(4);
	no=rem(i,4)+1;
	input=x(no,:);
	dd=D(no);
	x1=input(2);
	x2=input(3);

	net1=w10+w11*x1+w12*x2;
	net2=w20+w21*x1+w22*x2;
	y1=tanh(net1);
	y2=tanh(net2);
	net3=v10+v11*y1+v12*y2;
	y3=tanh(net3);

	err3=(dd-y3)*(1-y3^2);
	err1=err3*v11*(1-y1^2);
	err2=err3*v12*(1-y2^2);

	%dv=rate*err2*y1;
	dv=[rate*err3*1;rate*err3*y1;rate*err3*y2];
	dw=[rate*err1*1 rate*err2*1; rate*err1*x1 rate*err2*x1;rate*err1*x2 rate*err2*x2];

	%dw=rate*[x(no,:)', x(no,:)'].*repmat(err1',[3,1]);
	w=w+dw;
	v=v+dv;

	%if rem(i,1000)==0
		%disp("i is: ");
		%disp(i);
		%[rate, yout]=errorRate(w,v);
		%disp(rate);
	%end
end
w1=w;
v1=v;

end