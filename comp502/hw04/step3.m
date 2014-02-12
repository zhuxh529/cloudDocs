function [w1,v1]=step3(n,s1,s2)
	w=initWeights(s1,s2-1,0.01);
	v=initWeights(s2,1,0.01);
	%w=win;
	%v=vin;
	%x=0.1:0.0045000:1.0-0.0045000;
	%x=x';
	D=1:0.045000:10-0.045000;
	D=D';
	x=1./D;
	x=[ones(size(D)(1),1) x];
	rate=0.0005;
	slope=0.001;

	error_rate=[];
	desired_out=[];
	actual_out=[];

for i=1:n
	j=rem(i,200)+1;
	no=j;
	err2=0;
	%no=rem(i,4)+1;
	input=x(no,:);
	y1=input*w;
	y1=4.5*tanh(slope*y1)+5.5;
	y1=[1 y1];
	y2=4.5*tanh(slope*y1*v)+5.5;

	err2=err2+(D(no,1)-y2)*(1-y2^2);
	err1=err2*v(2:s2).*(1-y1(2:s2)'.^2);
	dv=rate*err2*y1;

	%dw=rate*[x(no,:)', x(no,:)'].*repmat(err1',[s1,1]);
	dw=rate*repmat(x(no,:)', [1,s2-1]).*repmat(err1',[s1,1]);

	w=w+dw;
	v=v+dv';
	

	if rem(i,155)==0
		%str = ['i is' num2str(i)]; 
		%disp(str); 
		str = [ num2str(D(no)) '>>>>>>' num2str(y2)]; 
		disp(str); 
	end
	
	
end

w1=w;
v1=v;
end