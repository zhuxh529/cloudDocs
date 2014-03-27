test=dlmread ('testData.txt');
testx=test(:,1:4);
testy=test(:, 5:7);
testy(testy==0)=-1;


aa=dlmread('trainData.txt');
y=aa(:,5:7);
x=aa(:,1:4);
y(y==0)=-1;

	maxi=repmat(max(x), [size(x)(1),1]);
	mini=repmat(min(x), [size(x)(1),1]);
	x= (x-mini).*2 ./(maxi-mini) -1;

	maxi=repmat(max(testx), [size(testx)(1),1]);
	mini=repmat(min(testx), [size(testx)(1),1]);
	testx= (testx-mini).*2 ./(maxi-mini) -1;

testx=[ones(size(testx)(1),1) testx];
x=[ones(size(x)(1),1) x];


	paras=[0.7, 0.03,1, 200];

	
	seq=unidrnd(size(testx)(1), [size(testx)(1)/3,1]);

 	[w,v,test, train]=BPlearn(100000, 10, x(seq',:),y(seq',:),testx(seq',:), testy(seq',:), paras);
	figure;
 	hold on;
 	plot(train); % scaling back to real abs err by muliplying 4.5
 	plot(test, 'r');  % scaling back to real abs err by muliplying 4.5
 	legend('train err','test err');
 	title('P3, fold 1 absolute average error');
 	xlabel('x 200 steps');
	ylabel('y (real absulute error)');

 	hold off;
 	
   	[err1, out]=BPrecall(w,v, 10, y(seq',:), x(seq',:), paras);
   	actual=getclass(out);
   	desire=getclass(y(seq',:));
   	figure;
 	hold on;
 	plot([1:25],actual,'ro');
 	plot([1:25],desire,'+');
 	title('fold 1 actual VS desired output');
 	xlabel('x');
	ylabel('class');
 	hold off;






 	seq=unidrnd(size(testx)(1), [size(testx)(1)/3,1]);

 	[w,v,test, train]=BPlearn(100000, 10, x(seq',:),y(seq',:),testx(seq',:), testy(seq',:), paras);
	figure;
 	hold on;
 	plot(train); % scaling back to real abs err by muliplying 4.5
 	plot(test, 'r');  % scaling back to real abs err by muliplying 4.5
 	legend('train err','test err');
 	title('P3, fold 2 absolute average error');
 	xlabel('x 200 steps');
	ylabel('y (real absulute error)');

 	hold off;

 	
   	[err1, out]=BPrecall(w,v, 10, y(seq',:), x(seq',:), paras);
   	actual=getclass(out);
   	desire=getclass(y(seq',:));
   	figure;
 	hold on;
 	plot([1:25],actual,'ro');
 	plot([1:25],desire,'+');
 	title('fold 2 actual VS desired output');
 	xlabel('x');
	ylabel('class');
 	hold off;


 	seq=unidrnd(size(testx)(1), [size(testx)(1)/3,1]);

 	[w,v,test, train]=BPlearn(100000, 10, x(seq',:),y(seq',:),testx(seq',:), testy(seq',:), paras);
	figure;
 	hold on;
 	plot(train); % scaling back to real abs err by muliplying 4.5
 	plot(test, 'r');  % scaling back to real abs err by muliplying 4.5
 	legend('train err','test err');
 	title('P3, fold 3 absolute average error');
 	xlabel('x 200 steps');
	ylabel('y (real absulute error)');

 	hold off;


   	[err1, out]=BPrecall(w,v, 10, y(seq',:), x(seq',:), paras);
   	actual=getclass(out);
   	desire=getclass(y(seq',:));
   	figure;
 	hold on;
 	plot([1:25],actual,'ro');
 	plot([1:25],desire,'+');
 	title('fold 3 actual VS desired output');
 	xlabel('x');
	ylabel('class');
 	hold off;


