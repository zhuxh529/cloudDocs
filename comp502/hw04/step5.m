function [w1,v1, testOut, trainOut]=BPlearn(n,s2,x,D, paras)
	maxi=repmat(max(x), [size(x)(1),1]);
	mini=repmat(min(x), [size(x)(1),1]);
	%x= (x-mini).*2 ./(maxi-mini) -1;
	%x=2.*x.-1.1;

	maxy=repmat(max(D), [size(D)(1),1]);
	miny=repmat(min(D), [size(D)(1),1]);
	%D= (D-miny).*1.8 ./(maxy-miny) -0.9;
	
	testX=0.9*rand(100,1)+0.1;
	testY=1./testX;
	testX=2.*testX.-1.1;
	testY=testY.*2/9-11/9;
	testX=[ones(size(testX)(1),1) testX];


	xx=0.9*rand(200,1)+0.1;
	xx=x;
	DD=1./xx;
	x=2.*xx.-1.1;
	D=DD.*2/9-11/9;


	testOut=[];
	trainOut=[];


	alpha=paras(1); % momentum term constant
	rate=paras(2); % learning rate
	slope=paras(3); % tanh slope
	epoch=paras(4); 

	%alpha=0.9;
	%rate=0.05;
	%slope=1;
	%epoch=10;

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

	dv=rate*y1'*err2+ dv_prev.*alpha;
	dv_prev=dv;

	dw=rate*repmat(x(no,:)', [1,s2-1]).*repmat(err1',[s1,1]) + dw_prev.*alpha;
	dw_prev=dw;

	if rem(i,epoch)==0
		w=w+dw;
		v=v+dv;
		%str = [ num2str(i) '       ' num2str(input) '       ' num2str(D(no,:)) '       ' num2str(y2) '       ' num2str(D(no,:)-y2)]; 
		%disp(str);
		wtemp=w;
		vtemp=v;
		err_train=BPrecall(wtemp,vtemp,10,D,x,[0.8,0.05,1,200]);
		%disp(err_train);
		err_test=BPrecall(wtemp,vtemp,10,testY,testX,[0.8,0.05,1,200]);
		str=[num2str(err_train) '       ' num2str(err_test)];
		disp(str);
		%testOut=[testOut err_test];
		%trainOut=[trainOut err_train];


	end
end
	w1=w;
	v1=v;


end
