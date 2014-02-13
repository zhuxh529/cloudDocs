function [w1,v1]=step3(n,s1,s2)
	w=initWeights(s1,s2-1,0.01);
	v=initWeights(s2,1,0.01);
	xx=0.9*rand(200,1)+0.1;
	%xx=xx';
	DD=1./xx;
	x=2.*xx.-1.1;
	alpha=0.9;
	
	rate=0.05;
	slope=1;
	x=[ones(size(DD)(1),1) x];
	D=[];
	D=DD.*2/9-11/9;

	error_rate=[];
	desired_out=[];
	actual_out=[];
	dw_prev=zeros(s1,s2-1);
	dv_prev=zeros(1,s2);

for i=1:n
	j=rem(i,200)+1;
	no=randi(200);
	err2=0;
	input=x(no,:);
	y1=input*w;
	y1=tanh(slope*y1);
	y1=[1 y1];
	y2=tanh(slope*y1*v);

	err2=err2+(D(no,1)-y2)*(1-y2^2);
	err1=err2*v(2:s2).*(1-y1(2:s2)'.^2);
	dv=rate*err2*y1+ dv_prev.*alpha.*rate;
	dv_prev=dv;

	%dw=rate*[x(no,:)', x(no,:)'].*repmat(err1',[s1,1]);
	dw=rate*repmat(x(no,:)', [1,s2-1]).*repmat(err1',[s1,1]) + dw_prev.*alpha.*rate;
	dw_prev=dw;
	
	

	if rem(i,200)==0
		w=w+dw;
		v=v+dv';
		%str = ['i is' num2str(i)]; 
		%disp(str); 
		%str = [ num2str(D(no)) '>>>>>>' num2str(y2)]; 
		%disp(str); 
		str = [ num2str(i) '       ' num2str(input) '       ' num2str(D(no)) '       ' num2str(y2) '       ' num2str(D(no)-y2)]; 
		disp(str);
	end
	
	
end

w1=w;
v1=v;
end