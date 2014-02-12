w=initWeights(3,2,0.01);
v=initWeights(3,1,0.01);
x=[1 1 1; 1 1 0; 1 0 1; 1 0 0];
D=[-1 ;1 ;1 ;-1];
rate=0.001;

no=randi(4);
input=x(no,:);
y1=input*w;
y1=tanh(y1);
y1=[1 y1];
y2=tanh(y1*v);

err2=(D(no,1)-y2)*(1-y2^2);
err1=err2*v(2:3).*(1-y1(2:3)'.^2);
dv=rate*err2*y1;

dw=[x(no,:)', x(no,:)'].*repmat(err1',[3,1]);
w=w+dw;
v=v+dv';




