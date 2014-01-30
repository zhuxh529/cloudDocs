%xihao zhu

%alpha ,position vectors
a=[ 10   20   30];
p =[1   2   3];

[T1, T_inv1]=euler2ht(a,p);
disp('T1 is:');
disp(T1);

a=[ 0   20   0];
p =[3   0   1];
[T2, T_inv2]=euler2ht(a,p);
disp('T2 is:');
disp(T2);


fprintf('p4 (a) finished. Program paused. Press enter to continue to part b.\n');
pause;


Pp=T2*[1;0;1;1];
Pa=Pp(1:3);
disp('pa is :');
disp(Pa);


printf('p4 (b) finished. Program paused. Press enter to continue to part c.\n');
pause;
disp('for a.i, T_inv is:');
disp(T_inv1);

disp('for a.i, T1*T_inv1=');
disp(T1*T_inv1);
disp("It's I4, correct!");


disp("");
disp('for a.ii, T_inv is:');
disp(T_inv2);

disp('for a.ii, T2*T_inv2=');
disp(T2*T_inv2);
disp("It's I4, correct!");


printf('p4 (c) finished. Program paused. Press enter to continue to part d.\n');
pause;

disp("p4.i:");
disp("T(C->A)=T(B->A)*T(C->B)=");
Tca=T1*T2;
disp(Tca);
Tac=T_inv2*T_inv1;

disp("T(A->C)=T(B->C)*T(A->B) where the later 2 T are T_inv of a.i and a.ii");
disp(Tac);


disp("");
disp("p4.ii:");
disp("T(B->A)=T(C->A)*T(B->C), where T(C->A) is Tca, T(B->C) is T_inv2, btw i dont think its necessary to calculate agian T(B->C). I already got it and the process to get it is in euler2ht.m line 17-line 18");
disp(Tca*T_inv2);
disp("same result!")


disp("");
disp("p4.iii:");
disp("T(C->B)=T(A->B)*T(C->A), where T(A->B) is T_inv1, T(C->A) is Tca");
disp(T_inv1* Tca);







