function [w1,v1, mytest, mytrain]=BPlearn(n,s2,x,D, testX, testY, paras)
	
	mytest=[];
	mytrain=[];


	alpha=paras(1); % momentum term constant
	rate=paras(2); % learning rate
	slope=paras(3); % tanh slope
	epoch=paras(4); 


	m=6000;

	s1=size(x)(2);
	s3=size(D)(2);


	w=initWeights(s1,s2-1,0.02)
	v=initWeights(s2,s3,0.02)

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

	dv=rate*y1'*err2;
	dv_prev=dv;


	dw=rate*repmat(x(no,:)', [1,s2-1]).*repmat(err1',[s1,1]);
	dw_prev=dw;

	if rem(i,epoch)==0
		w=w+dw;
		v=v+dv;
		wtemp=w;
		vtemp=v;
		[err_train, o1]=BPrecall(wtemp,vtemp,10,D,x,paras);
		%disp(err_train);
		wtemp1=w;
		vtemp1=v;
		[err_test,o2]=BPrecall(wtemp1,vtemp1,10,testY,testX,paras);
		%str=[num2str(err_train) '       ' num2str(err_test)];
		%disp(str);
		mytest=[mytest err_test];
		mytrain=[mytrain err_train];
		
		
		


	end

	if rem(i,m)==0
		str = [ num2str(i) '       ' num2str(input) '       ' num2str(D(no,:)) '       ' num2str(y2) '       ' num2str(D(no,:)-y2)]; 
		disp(str);
		
	end


end
	w1=w;
	v1=v;


end
