function [w1,v1]=crossValid(n,s2,x,D, testX, testY, paras)

TrainIn  = x;
TrainOut = D;

TestIn   = testX;
TestOut  = testY;



FoldCount = 4;
trainSize=size(TrainIn)(1)/FoldCount;
testSize=size(TestIn)(1)/FoldCount;


for k=1:FoldCount
K = 200;
CurrentFold = k;

seqTrain=round(rand(1,trainSize)*size(TrainIn)(1));
seqTest=round(rand(1,testSize)*size(TestIn)(1));




TrainFoldIn = TrainIn(seqTrain, :);
TestFoldIn  = TestIn(seqTest, :);

TrainFoldOut = TrainOut(seqTrain, :);
TestFoldOut  = TestOut(seqTest, :);

TrainFoldIn



[w,v, mytest, mytrain]=BPlearn(n,s2,TrainFoldIn,TrainFoldOut, TestFoldIn, TestFoldOut, paras)


figure;
   hold on;
   plot(mytrain*1.21/2); % scaling back to real abs err by muliplying 4.5
   plot(mytest*1.21/2, 'r');  % scaling back to real abs err by muliplying 4.5
   legend('train err','test err');
   title(['P1(b), fold #',num2str(k),', real absoulte error of my trained ANN']);
   xlabel('x 200 steps');
   ylabel('y (real error)');

   hold off;



   [err1, out]=BPrecall(w,v, 10, TrainFoldOut, TrainFoldIn, paras);
   figure;
   hold on;
   plot(TrainFoldIn*5+5,(out+1)*1.21/2-0.21);
   plot(TrainFoldIn*5+5,(TrainFoldOut+1)*1.21/2-0.21,'r');
   legend('actual output','desired output');
   title(['P1(b), fold #',num2str(k),', actual output VS desired output']);
   xlabel('x (real number)');
   ylabel('y (real number)');
   hold off;

    hold off;

   [err1, out]=BPrecall(w,v, 10, TestFoldOut, TestFoldIn, paras);
   figure;
   hold on;
   plot(TestFoldIn*5+5,(out+1)*1.21/2-0.21);
   plot(TestFoldIn*5+5,(TestFoldOut+1)*1.21/2-0.21,'r');
   legend('actual output','desired output');
   title('P1, actual output VS desired output');
   xlabel('x (real number)');
   ylabel('y (real number)');


   hold off;


end



end