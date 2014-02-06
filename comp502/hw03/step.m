function [w1,v1]=step(n)
	w=initWeights(3,2,0.01);
	v=initWeights(3,1,0.01);
	%w=win;
	%v=vin;
	x=[1 1 1; 1 1 0; 1 0 1; 1 0 0];
	D=[-1 ;1 ;1 ;-1];
	rate=0.001;

for i=1:n
	no=randi(4);
	%no=rem(i,4)+1;
	input=x(no,:);
	y1=input*w;
	y1=tanh(y1);
	y1=[1 y1];
	y2=tanh(y1*v);

	err2=(D(no,1)-y2)*(1-y2^2);
	err1=err2*v(2:3).*(1-y1(2:3)'.^2);
	dv=rate*err2*y1;

	dw=rate*[x(no,:)', x(no,:)'].*repmat(err1',[3,1]);
	w=w+dw;
	v=v+dv';

	if rem(i,100)==0
		%str = ['i is' num2str(i)]; 
		%disp(str); 
		str = [ num2str(D(no)) '----' num2str(y2)]; 
		disp(str); 

	end
end

w1=w;
v1=v;
end