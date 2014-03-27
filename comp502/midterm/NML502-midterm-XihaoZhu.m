%P1

load ocelot;

trainX=ocelot;
maxi=repmat(max(max(trainX)), [size(trainX,1),size(trainX,2)]);
mini=repmat(min(min(trainX)), [size(trainX,1),size(trainX,2)]);
trainX= (trainX-mini).*2 ./(maxi-mini) -1;



testX=fruitstill;
maxt=repmat(max(max(testX)), [size(testX,1),size(testX,2)]);
mint=repmat(min(min(testX)), [size(testX,1),size(testX,2)]);
testX= (testX-mint).*2 ./(maxt-mint) -1;


testinput=[];
testinput2=mat2cell(testX, 8*ones(size(testX,1)/8, 1),8*ones(size(testX,2)/8,1));
for i=1:size(testinput2,2)
	for j=1:size(testinput2,1)
		a=testinput2{j,i}';
		testinput=[testinput; a(:)'];
	end
end

testoutput=testinput;
testinput=[testinput ones(size(testinput,1),1)];

testinput=[];
testoutput=testX;
testinput=[testX ones(size(testX,1),1)];




input=[];
input2=mat2cell(trainX, 8*ones(size(trainX,1)/8, 1),8*ones(size(trainX,2)/8,1));
for i=1:size(input2,2)
	for j=1:size(input2,1)
		a=input2{j,i}';
		input=[input; a(:)'];
	end
end

output=input;
input=[input ones(size(input,1),1)];
%input=[];
%output=trainX;
%input=[trainX ones(size(input,1),1)];

paras=[0.3, 0.02,1, 100];
[w,v,test, train, out]=BPlearn(100000, 15, input,output, testinput, testoutput, paras);


figure;
hold on;
plot(train/2, 'r');
plot(test/2);
legend('train data','test data');
title('percentage error rate');
xlabel('x (steps x 100)');
ylabel('y (percent error rate)');

[build, out2]=rebuild(w,v,15, input,output, paras);
[build, out2]=rebuild(w,v,15, testX,testX, paras);
figure;
image((out2+1).*(maxi-mini)./2 +mini);
%rec=(build+1).*(maxi-mini)./2 +mini;



%P2.
read-mermaid;
[w, his]=gha(x2,2000,4,0.001);




%BPrecall

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



%gha

function [W, history]=gha(P,steps,m,mu)
history=[];
[row col]=size(P);	
W=rand(m,col)*(max(max(P)))
for step=1:steps,
   cc=clock;
   ind=rand(1,row);
	[y inds]=sort(ind); 
	P=P(inds,:);
   for j=1:row,
	  dw = zeros(size(W));
      x = P(j,:); 
      y(1) = dot(W(1,:),x);
      dw(1,:) = mu*y(1)*(x-y(1)*W(1,:));
      for h=2:m,
	 	y(h) = dot(W(h,:),x);
	 	temp = 0; 
	 	for k=1:h, 
	 	temp=temp+W(k,:)*y(k); 
	 	end
	 	dw(h,:)=mu*y(h)*(x-temp);    
      end
      W=W+dw;
   end

	if rem(step,1000)==0
   		showW=W;
   		myi=showW*showW';
   		diff=myi-eye(m);
   		diff=sum(sum(abs(diff)));
   		history=[history diff];
   		str = [ num2str(step) '       ' num2str(diff)]; 
		disp(str);
	end


end

W=W';

end


