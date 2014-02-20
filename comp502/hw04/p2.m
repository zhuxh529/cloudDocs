test=dlmread('test.txt');
testx=test(:,1:4);
testy=test(:, 5:7);
testy(testy==0)=-1;


aa=dlmread('irisdata3.txt');
y=aa(:,1:3);
x=aa(:,4:7);

	maxi=repmat(max(x), [size(x)(1),1]);
	mini=repmat(min(x), [size(x)(1),1]);
	x= (x-mini).*2 ./(maxi-mini) -1;

	maxi=repmat(max(testx), [size(testx)(1),1]);
	mini=repmat(min(testx), [size(testx)(1),1]);
	testx= (testx-mini).*2 ./(maxi-mini) -1;
testx=[ones(size(testx)(1),1) testx];

	paras=[0.9, 0.05,1, 200];


 	[w,v,test, train]=BPlearn(200000, 10, x,y,testx, testy, paras);
	figure;
 	hold on;
 	plot(train); % scaling back to real abs err by muliplying 4.5
 	plot(test, 'r');  % scaling back to real abs err by muliplying 4.5
 	legend('train err','test err');
 	title('P2, error');
 	xlabel('x 200 steps');
	ylabel('y (real number)');

 	hold off;
