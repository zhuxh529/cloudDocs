function [w1,v1]=step4(n,s2,x,D)
	maxi=repmat(max(x), [size(x)(1),1]);
	mini=repmat(min(x), [size(x)(1),1]);
	x= (x-mini).*2 ./(maxi-mini) -1;
	


	alpha=0.9;
	rate=0.05;
	slope=1;
	epoch=10;

	s1=size(x)(2)+1;
	s3=size(D)(2);

	x=[ones(size(x)(1),1) x];

	w=initWeights(s1,s2-1,0.01);
	v=initWeights(s2,s3,0.01);

	dw_prev=zeros(s1,s2-1);
	dv_prev=zeros(s2,s3);


for i=1:n

	no=randi(size(x)(1));
	input =x(no, :);
	y1=input*w;
	y1=tanh(slope*y1);
	y1=[1 y1];
	y2=tanh(slope*y1*v);
	%size(y1)
	err2=(D(no,:) -y2).*(1-y2.^2);
	err1=v(2:s2,:)*err2'.*(1-y1(2:s2)'.^2);

	dv=rate*y1'*err2+ dv_prev.*alpha.*rate;
	dv_prev=dv;

	dw=rate*repmat(x(no,:)', [1,s2-1]).*repmat(err1',[s1,1]) + dw_prev.*alpha.*rate;
	dw_prev=dw;

	if rem(i,200)==0
		w=w+dw;
		v=v+dv;
		str = [ num2str(i) '       ' num2str(input) '       ' num2str(D(no,:)) '       ' num2str(y2) '       ' num2str(D(no,:)-y2)]; 
		disp(str);
	end
end
	w1=w;
	v1=v;


end
