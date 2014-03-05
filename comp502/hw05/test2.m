%% generate a sample dataset

TrainIn  = rand(1,200)*10;
TrainOut = sin(TrainIn )./TrainIn;

TestIn   = rand(1,100)*10;
TestOut  = sin(TestIn )./TestIn;

%% Scaling 

TrainIn  = TrainIn - 5;
TrainOut = TrainOut / 1.5;

TestIn   = TestIn - 5;
TestOut  = TestOut / 1.5;
%% permute the data

% set the number of folds
FoldCount = 4;

% collect the total size of the dataset
InSize = length(TrainIn)+length(TestIn);

% combine the test and training data and permute them
Perm    = randsample(InSize,InSize);
InPerm  = [TrainIn ,TestIn ];
OutPerm = [TrainOut,TestOut];
InPerm = InPerm(Perm);
OutPerm = OutPerm(Perm);

% print warning if this will not fold evenly
if mod(InSize,FoldCount) ~= 0
    error('This will not fold evenly');
end

% save memory for the following loop to save computation time
FoldIndex = zeros(FoldCount,InSize);

% set the index of the test and training data
for ii = 0:FoldCount-1
    temp = zeros(1,InSize);
    temp(1,ii*(1/FoldCount*InSize)+1:(ii+1)*(1/FoldCount*InSize)) = 1;
    FoldIndex(ii+1,:) = temp;
end
% 0 - training data
% 1 - test data

for k=1:FoldCount
K = 200;
CurrentFold = k;

TrainFoldIn = InPerm(1,find(FoldIndex(CurrentFold,:)==0));
TestFoldIn  = InPerm(1,find(FoldIndex(CurrentFold,:)==1));

TrainFoldOut = OutPerm(1,find(FoldIndex(CurrentFold,:)==0));
TestFoldOut  = OutPerm(1,find(FoldIndex(CurrentFold,:)==1));

%Insert your backpropogation and recalling routine here using TrainFold as your training data 
%and TestFold as your testing data 

end