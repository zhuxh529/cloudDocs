load ocelot;

trainX=ocelot;
maxi=repmat(max(max(trainX)), [size(trainX,1),size(trainX,2)]);
mini=repmat(min(min(trainX)), [size(trainX,1),size(trainX,2)]);
trainX= (trainX-mini).*2 ./(maxi-mini) -1;

