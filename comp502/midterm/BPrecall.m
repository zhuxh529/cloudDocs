function [err, out]=BPrecall(w,v, s2, D, train, paras)
	alpha=paras(1); % momentum term constant
	rate=paras(2); % learning rate
	slope=paras(3); % tanh slope
	epoch=paras(4); 

	x=train;
	s1=size(x,2)+1;
	s3=size(D,2);

	%	x=[ones(size(x,1),1) x];

	out=[];

for no=1:size(x,1)
	%no=randi(size(x,1);
	input =x(no, :);
	y1=input*w;
	y1=tanh(slope*y1);
	y1=[1 y1];
	y2=tanh(slope*y1*v);
	out=[out; y2];
end
	err=abs(D- out);
	err=sum(sum(err))/(192*256);

end