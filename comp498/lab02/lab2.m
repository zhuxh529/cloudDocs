% xihao zhu,  xz36 lab2
clf;



%PROBLEM 1
% rollr a-c
angle=pi/4;
m=rollr(angle);
figure;
hold on;
plot3([0 m(1,1)],[0 m(2,1)],[0 m(3,1)],"linewidth", 1, "-@");
plot3([0 m(1,2)],[0 m(2,2)],[0 m(3,2)],"linewidth", 1, "-@");
plot3([0 m(1,3)],[0 m(2,3)],[0 m(3,3)],"linewidth", 1, "-@");
axis([-1 1 -1 1 -1 1]);
title('roll (a)');
grid on;
hold off;
pause;
disp("press enter to continue");


%(b)
%translate by [-0.1,0.2,0.3], rotate roll bu pi/4

vec=[1,1,1];
translate=[-0.1,0.2,0.3];
newVec=[m translate';0 0 0 1]*[vec';1];
figure;
hold on;
plot3([0 vec(1)],[0 vec(2)],[0 vec(3)],"linewidth", 1, "-@");
plot3([translate(1) newVec(1)],[translate(2) newVec(2)],[translate(3) newVec(3)],"linewidth", 1, "-@",'color','red');
title('roll (b), translate by [-0.1,0.2,0.3], rotate roll by pi/4');
xlabel('x');
ylabel('y');
zlabel('z');
grid on;
hold off;
pause;
disp("press enter to continue");


%(c)
% connecting end points of two vectors together

vec=[1,1,1];
translate=[0 0 0];
newVec=[m translate';0 0 0 1]*[vec';1];
figure;
hold on;
plot3([0 vec(1)],[0 vec(2)],[0 vec(3)],"linewidth", 1, "-@");
plot3([translate(1) newVec(1)],[translate(2) newVec(2)],[translate(3) newVec(3)],"linewidth", 1, "-@");
plot3([vec(1) newVec(1)],[vec(2) newVec(2)],[vec(3) newVec(3)],"linewidth", 1, "-@",'color','red');

title('roll (c), rotate roll by pi/4');
xlabel('x');
ylabel('y');
zlabel('z');
grid on;
hold off;
pause;
disp("press enter to continue");




% pitchr
angle=pi/18;
m=pitchr(angle);
figure;
hold on;
plot3([0 m(1,1)],[0 m(2,1)],[0 m(3,1)],"linewidth", 1, "-@");
plot3([0 m(1,2)],[0 m(2,2)],[0 m(3,2)],"linewidth", 1, "-@");
plot3([0 m(1,3)],[0 m(2,3)],[0 m(3,3)],"linewidth", 1, "-@");
axis([-1 1 -1 1 -1 1]);
grid on;
title('pitch (a)');

hold off;
pause;
disp("press enter to continue");


%(b)
%translate by [0.2,0.2,-0.1], rotate pitch by pi/18

vec=[1,1,1];
translate=[0.2,0.2,-0.1];
newVec=[m translate';0 0 0 1]*[vec';1];
figure;
hold on;
plot3([0 vec(1)],[0 vec(2)],[0 vec(3)],"linewidth", 1, "-@");
plot3([translate(1) newVec(1)],[translate(2) newVec(2)],[translate(3) newVec(3)],"linewidth", 1, "-@",'color','red');
title('pitch (b), translate by [0.2,0.2,-0.1], rotate pitch by pi/18');
xlabel('x');
ylabel('y');
zlabel('z');
grid on;
hold off;
pause;
disp("press enter to continue");

%(c)
% connecting end points of two vectors together

vec=[1,0.6,1.5];
translate=[0 0 0];
newVec=[m translate';0 0 0 1]*[vec';1];
figure;
hold on;
plot3([0 vec(1)],[0 vec(2)],[0 vec(3)],"linewidth", 1, "-@");
plot3([translate(1) newVec(1)],[translate(2) newVec(2)],[translate(3) newVec(3)],"linewidth", 1, "-@");
plot3([vec(1) newVec(1)],[vec(2) newVec(2)],[vec(3) newVec(3)],"linewidth", 1, "-@",'color','red');

title('pitch (c), rotate pitch by pi/18');
xlabel('x');
ylabel('y');
zlabel('z');
grid on;
hold off;
pause;
disp("press enter to continue");




% yawr
angle=pi/6;
m=yawr(angle);
figure;
hold on;
plot3([0 m(1,1)],[0 m(2,1)],[0 m(3,1)],"linewidth", 1, "-@");
plot3([0 m(1,2)],[0 m(2,2)],[0 m(3,2)],"linewidth", 1, "-@");
plot3([0 m(1,3)],[0 m(2,3)],[0 m(3,3)],"linewidth", 1, "-@");
axis([-1 1 -1 1 -1 1]);
grid on;
title('yaw (a)');


hold off;
pause;
disp("press enter to continue");



%(b)
%translate by [-0,-0.1,1], rotate yaw bu pi/6

vec=[1,1,1];
translate=[-0,-0.1,1];
newVec=[m translate';0 0 0 1]*[vec';1];
figure;
hold on;
plot3([0 vec(1)],[0 vec(2)],[0 vec(3)],"linewidth", 1, "-@");
plot3([translate(1) newVec(1)],[translate(2) newVec(2)],[translate(3) newVec(3)],"linewidth", 1, "-@",'color','red');
title('yaw (b), translate by [-0,-0.1,1], rotate yaw by pi/6');
xlabel('x');
ylabel('y');
zlabel('z');
grid on;
hold off;
pause;
disp("press enter to continue");


%(c)
% connecting end points of two vectors together

vec=[1,2,1];
translate=[0 0 0];
newVec=[m translate';0 0 0 1]*[vec';1];
figure;
hold on;
plot3([0 vec(1)],[0 vec(2)],[0 vec(3)],"linewidth", 1, "-@");
plot3([translate(1) newVec(1)],[translate(2) newVec(2)],[translate(3) newVec(3)],"linewidth", 1, "-@");
plot3([vec(1) newVec(1)],[vec(2) newVec(2)],[vec(3) newVec(3)],"linewidth", 1, "-@",'color','red');

title('yaw (c), rotate yaw by pi/6');
xlabel('x');
ylabel('y');
zlabel('z');
grid on;
hold off;
pause;
disp("press enter to continue");










%PROBLEM 2
%
vec=[1,2,1];

m=rpyr([pi/2, 0, 0]);
translate=[0 0 0];
newVec=[m translate';0 0 0 1]*[vec';1];
figure;
hold on;
plot3([0 vec(1)],[0 vec(2)],[0 vec(3)],"linewidth", 1, "-@");
plot3([translate(1) newVec(1)],[translate(2) newVec(2)],[translate(3) newVec(3)],"linewidth", 1, "-@",'color','red');
m=rpyr([pi/2, 0, pi/18]);
newVec=[m translate';0 0 0 1]*[vec';1];
plot3([translate(1) newVec(1)],[translate(2) newVec(2)],[translate(3) newVec(3)],"linewidth", 1, "-@",'color','green');
m=rpyr([pi/2, pi/4, pi/18]);
newVec=[m translate';0 0 0 1]*[vec';1];
plot3([translate(1) newVec(1)],[translate(2) newVec(2)],[translate(3) newVec(3)],"linewidth", 1, "-@",'color','black');



title('P2, blue is original vector [1,2,1], red with angle [pi/2, 0, 0],green [pi/2, 0, pi/18], black [pi/2, pi/4, pi/18]');
xlabel('x');
ylabel('y');
zlabel('z');
grid on;
hold off;
pause;
disp("press enter to continue");



%PROBLEM 3
m=rpytr([ 0.5, 0.6, -0.2,pi/2, pi/4, pi/18]);
drawFrame(m, [ 1 1 1]);

%PROBLEM 4
drawScrew(0.3, pi/6, [0;1;0],color = [0,0,1]);

%PROBLEM 5
m=screwDH(1.1,0.9,0.4,0.2);

%PROBLEM 6
drawPhantom([0,0,-pi/2], [0 0 0])






