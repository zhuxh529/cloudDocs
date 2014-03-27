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


