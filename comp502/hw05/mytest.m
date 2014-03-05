   testX=(1:2:45)';
   testX=sort(testX);
   testY=sin(testX.*pi./10);
  
   trainX=(1:42)';
   trainX=sort(trainX);
   trainY=sin(trainX.*pi./10);


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


   paras=[0.1, 0.01,1, 200];
   layer=8;

   [w,v,test, train]=BPlearn(70000, layer, trainX,trainY, testX, testY, paras);
   figure;
   hold on;
   plot(train); % scaling back to real abs err by muliplying 4.5
   plot(test, 'r');  % scaling back to real abs err by muliplying 4.5
   legend('train err','test err');
   title('P2(1), real absoulte error of my trained ANN');
   xlabel('x 200 steps');
   ylabel('y (real number)');

   hold off;
   disp("press enter to continue");
   pause;


   [err1, out]=BPrecall(w,v, layer, trainY, trainX, paras);
   figure;
   hold on;
   plot(trainX,out);
   plot(trainX,trainY,'r');
   legend('actual output','desired output');
   title('P2(1),  for train data, actual output VS desired output');
   xlabel('x (real number)');
   ylabel('y (real number)');


   hold off;

   [err1, out]=BPrecall(w,v, layer, testY, testX, paras);
   figure;
   hold on;
   plot(testX,out);
   plot(testX,testY,'r');
   legend('actual output','desired output');
   title('P2(1),  for test data, actual output VS desired output');
   xlabel('x (real number)');
   ylabel('y (real number)');


   hold off;
   disp("press enter to continue");

   pause;



   testX=(1:40)';
   testX=sort(testX);
   testY=0.8*sin(testX.*pi./5)+0.25*cos(testX.*pi./12.5);
  
   trainX=(1:40)';
   trainX=sort(trainX);
   trainY=0.8*sin(trainX.*pi./5)+0.25*cos(trainX.*pi./12.5);


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
   [err1, out]=BPrecall(w,v, layer, testY, testX, paras);
   figure;
   hold on;
   plot(testX,out);
   plot(testX,testY,'r');
   legend('actual output','desired output');
   title('P2(2), for test data, actual output VS desired output');
   xlabel('x (real number)');
   ylabel('y (real number)');


   hold off;


   [err1, out]=BPrecall(w,v, layer, trainY, trainX, paras);
   figure;
   hold on;
   plot(trainX,out);
   plot(trainX,trainY, 'r');
   legend('actual output','desired output');
   title('P2(2), for train data, actual output VS desired output');
   xlabel('x (real number)');
   ylabel('y (real number)');


   hold off;










   



