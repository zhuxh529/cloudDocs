	testX=0.9*rand(100,1)+0.1;
	testY=1./testX;
	testX=2.*testX.-1.1;
	testY=testY.*2/9-11/9;
	testX=[ones(size(testX)(1),1) testX];


	xx=0.9*rand(200,1)+0.1;
	DD=1./xx;
	x=2.*xx.-1.1;
	D=DD.*2/9-11/9;

	paras=[0.8, 0.05, 1,200];

 	[w,v,test, train]=BPlearn(50000, 10, x,D,testX, testY, paras);
 	figure;
 	hold on;
 	plot((train.+11/9).*4.5);
 	plot((test.+11/9).*4.5, 'r');
 	legend('train err','test err');
 	title('P1, best result no1, error rate');

 	hold off;



