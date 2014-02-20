function [w,v,out, D, x]=testp1()
	testX=0.9*rand(100,1)+0.1;
	testY=1./testX;
	testX=2.*testX.-1.1;
	testY=testY.*2/9-11/9;
	testX=[ones(size(testX)(1),1) testX];





	xx=0.9*rand(500,1)+0.1;
	DD=1./xx;
	DD2=[(2:0.07:3)';(3:0.05:4)';(4:0.04:5)';(5:0.025:7)'; (7:0.02:8)'; (8:0.01:10)'];
	%DD2=[(8:0.007:10)'];
	xx2=1./DD2;
	xx=[xx; xx2];
	DD=[DD; DD2];

	x=2.*xx.-1.1;
	D=DD.*2/9-11/9;

	paras=[0.9, 0.05,1, 500];

 	[w,v,test, train]=BPlearn(100000, 15, x,D,testX, testY, paras);
 	figure;
 	hold on;
 	plot(train*4.5); % scaling back to real abs err by muliplying 4.5
 	plot(test*4.5, 'r');  % scaling back to real abs err by muliplying 4.5
 	legend('train err','test err');
 	title('P1, best result no1, real absoulte error');
 	xlabel('x 200 steps');
	ylabel('y (real number)');

 	hold off;


 		x=[ones(size(x)(1),1) x];
 

 	[err1,out]=BPrecall(w,v,15,D, x, paras);
 	figure;
 	hold on;
	scatter(x(:,2), out, 'r');
	scatter(x(:,2), D, 'b');

 	hold off;

 	%[err1, out]=BPrecall(w,v, 10, D, x, paras);
 	%plot(out)

 	pause;
 	disp("press enter to continue");
 end