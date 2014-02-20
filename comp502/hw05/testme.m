	testX=0.9*rand(100,1)+0.1;
	testY=1./testX;
	testX=2.*testX.-1.1;
	testY=testY.*2/9-11/9;
	testX=[ones(size(testX)(1),1) testX];


	xx=0.9*rand(200,1)+0.1;
	DD=1./xx;
	x=2.*xx.-1.1;
	D=DD.*2/9-11/9;


 	

 	paras=[0.8, 0.07,1, 200];

 	[w,v,test, train]=BPlearn(50000, 10, x,D,testX, testY, paras);
 	figure;
 	hold on;
 	plot(train*4.5); % scaling back to real abs err by muliplying 4.5
 	plot(test*4.5, 'r');  % scaling back to real abs err by muliplying 4.5
 	legend('train err','test err');
 	title('P1, best result no3, real absoulte error');
 	xlabel('x 200 steps');
	ylabel('y (real number)');

 	hold off;





