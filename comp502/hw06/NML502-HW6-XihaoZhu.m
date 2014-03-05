%part1
test=dlmread ('testData.txt');
testx=test(:,1:4);
[x,y,z]=princomp(zscore(testx));
x*x'





%part2
test=dlmread ('testData.txt');
testx=test(:,1:4);

[w, his]=gha(zscore(testx),15000,4,0.0005);
plot(his);
title('difference history of P*P and I');
xlabel('x(2000 steps)');
ylabel('difference');


