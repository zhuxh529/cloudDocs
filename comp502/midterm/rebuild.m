function [out,outbefore]=rebuild(w,v,s2,x, D,paras)
	
	alpha=paras(1); % momentum term constant
	rate=paras(2); % learning rate
	slope=paras(3); % tanh slope
	epoch=paras(4); 

	s1=size(x,2)+1;
	s3=size(D,2);

	out=[];
	temp=[];
	no=1;
	outbefore=[];
%for no=1:20	
for no=1:size(x,1)
	%no=randi(size(x,1);
	input =x(no, :);
	y1=input*w;
	y1=tanh(slope*y1);
	y1=[1 y1];
	y2=tanh(slope*y1*v);
	outbefore=[outbefore; y2];
	%if rem(no, 32)==0
	%	temp=[temp, reshape(y2,[8 8])'];
	%	out=[out; temp];
	%	temp=[];
	%else
	%	temp=[temp, reshape(y2,[8 8])'];
	%end
	%out=[out; y2];
	%size(out)

end

end