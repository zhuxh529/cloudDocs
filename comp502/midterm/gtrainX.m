function [r]=trainX(x,y, trainX)
	r=reshape(trainX(8*x-7: 8*x, 8*y-7: 8*y), [8 8]);

end