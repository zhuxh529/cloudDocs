   testX=10*rand(100,1);
   testX=sort(testX);
   testY=sin(testX)./testX;
  
   trainX=10*rand(400,1);
   trainX=sort(trainX);
   trainY=sin(trainX)./trainX;


   maxi=repmat(max(trainX), [size(trainX)(1),1]);
   mini=repmat(min(trainX), [size(trainX)(1),1]);
   trainX= (trainX-mini).*2 ./(maxi-mini) -1;

   maxy=repmat(max(trainY), [size(trainY)(1),1]);
   miny=repmat(min(trainY), [size(trainY)(1),1]);
   trainY= (trainY-miny).*2 ./(maxy-miny) -1;
   
   maxi=repmat(max(testX), [size(testX)(1),1]);
   mini=repmat(min(testX), [size(testX)(1),1]);
   testX= (testX-mini).*2 ./(maxi-mini) -1;

   maxy=repmat(max(testY), [size(testY)(1),1]);
   miny=repmat(min(testY), [size(testY)(1),1]);
   testY= (testY-miny).*2 ./(maxy-miny) -1;


   trainX=[ones(size(trainX)(1),1) trainX];
   testX=[ones(size(testX)(1),1) testX];


   paras=[0.2, 0.12,1, 20];

   [w,v,test, train]=BPlearn(100000, 10, trainX,trainY, testX, testY, paras);
   figure;
   hold on;
   plot(train*1.21/2); % scaling back to real abs err by muliplying 4.5
   plot(test*1.21/2, 'r');  % scaling back to real abs err by muliplying 4.5
   legend('train err','test err');
   title('P1,fold1 real absoulte error of my trained ANN');
   xlabel('x 200 steps');
   ylabel('y (real number)');

   hold off;
   disp("press enter to continue");
   pause;


   [err1, out]=BPrecall(w,v, 10, trainY, trainX, paras);
   figure;
   hold on;
   plot(trainX*5+5,(out+1)*1.21/2-0.21);
   plot(trainX*5+5,(trainY+1)*1.21/2-0.21,'r');
   legend('actual output','desired output');
   title('P1, fold1 actual output VS desired output');
   xlabel('x (real number)');
   ylabel('y (real number)');


   hold off;
   disp("press enter to continue");

   pause;
   figure;
   [err1, out]=BPrecall(w,v, 10, testY, testX, paras);
   




