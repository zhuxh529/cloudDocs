function [w]  = som(x, n, tmax)

MU_I        = 0.05;         
MU_F        = 0.005;         
SIGMA_I     =  3.0e0;     
SIGMA_F     =  1.0e-1;     
% seed random-number generator if specified
if nargin > 7
    rand('state', seed)
end

[o(:,1), o(:,2)] = ind2sub([n n], 1:n^2);

w = rand(n^2, size(x,2));

% run SOM learning for specified number of steps
for t = 1:tmax
    w = somlearn(w, o, x, MU_I, MU_F, SIGMA_I, SIGMA_F, t, tmax);
	%if t==1| t==10 | t==30 |t==50 | t==100 | t==200| t==500| t==2000|t==5000| t==10000
	if t==tmax
	figure;
	plot_nodes(w);
	%plot_points(x);
	title(['iteration at step ',num2str(t)]);
	end
end

