% Specify the target matrix
	A = [ 3 1 1 1 1 2 3 3 3
   	3 3 3 3 3 2 3 3 3
   	3 3 3 3 3 1 2 2 2
   	3 1 1 1 1 1 1 1 1
   	3 1 1 1 2 1 1 1 1
   	3 1 1 2 2 2 1 1 1 
   	3 1 2 2 1 3 2 2 2
   	3 3 3 3 3 3 2 2 2
   	3 3 3 3 3 3 3 3 2];

% Form the input vectors and associated categories
	X = zeros(2,81);
	Cx = zeros(1,81);
	k = 0;
	for i = 1:9
   	for j = 1:9
      	k = k+1;
      	X(1,k) = i-5;
      	X(2,k) = j-5;
      	Cx(k) = A(j, i);
   	end
	end



% Implement the LVQ1 learning here just to see how all of this hangs %together
% Initialize neurons - set the number of neurons, randomly choose 
% their categories    
	Nn = 100;        % I recommend that you make the number of neurons a             % parameter in the canned routine LVQ1 too, and vary that number
	W = 8*rand(2,Nn)-4; % Notice the scaling!
	Cw = ceil(rand(Nn,1)*3);

	mu = 0.15;   
   for iter = 1:2500
		for i = 1:81
   		d = zeros(1,Nn);
   		for j = 1:Nn
      		d(j) = norm(W(:,j)-X(:,i));
   		end
   		[m,I] = min(d);
   		if Cw(I) == Cx(i)
      		W(:,I) = W(:,I) + mu * (X(:,i)-W(:,I));
   		else
      		W(:,I) = W(:,I) - mu * (X(:,i)-W(:,I));
   		end
		end
	end


% Test the classification of the original data 
	Cxhat = zeros(1,81);
	for i = 1:81
   	d = zeros(1,Nn);
   	for j = 1:Nn
      	d(j) = norm(W(:,j)-X(:,i));
   	end
   	[m,I] = min(d);
   	Cxhat(i) = Cw(I);
	end

    input = X;
    
% Plotting the test results
  [m,n] = size(input);
  
  
figure;
imagesc(reshape(Cxhat,9,9))
  %colormap('gray');



% Specify the target matrix
  A = [ 3 1 3 1 2 2 3 3 2
    1 3 1 3 3 2 3 3 3
    1 3 1 1 3 1 2 3 2
    3 1 2 1 2 2 3 3 1
    2 1 3 1 2 1 2 2 1
    3 1 1 2 1 2 3 3 1 
    2 1 2 2 1 3 2 2 2
    3 3 1 1 1 3 2 1 2
    2 3 2 3 1 3 1 3 2];
  figure;
  imagesc(A);
  title('test right one');

% Form the input vectors and associated categories
  X = zeros(2,81);
  Cx = zeros(1,81);
  k = 0;
  for i = 1:9
    for j = 1:9
        k = k+1;
        X(1,k) = i-5;
        X(2,k) = j-5;
        Cx(k) = A(j, i);
    end
  end



% Implement the LVQ1 learning here just to see how all of this hangs %together
% Initialize neurons - set the number of neurons, randomly choose 
% their categories    
  Nn = 100;        % I recommend that you make the number of neurons a             % parameter in the canned routine LVQ1 too, and vary that number
  W = 8*rand(2,Nn)-4; % Notice the scaling!
  Cw = ceil(rand(Nn,1)*3);

  mu = 0.15;   
   for iter = 1:2500
    for i = 1:81
      d = zeros(1,Nn);
      for j = 1:Nn
          d(j) = norm(W(:,j)-X(:,i));
      end
      [m,I] = min(d);
      if Cw(I) == Cx(i)
          W(:,I) = W(:,I) + mu * (X(:,i)-W(:,I));
      else
          W(:,I) = W(:,I) - mu * (X(:,i)-W(:,I));
      end
    end
  end



% Test the classification of the original data 
  Cxhat = zeros(1,81);
  for i = 1:81
    d = zeros(1,Nn);
    for j = 1:Nn
        d(j) = norm(W(:,j)-X(:,i));
    end
    [m,I] = min(d);
    Cxhat(i) = Cw(I);
  end

    input = X;
    
% Plotting the test results
  [m,n] = size(input);
  
  
figure;
imagesc(reshape(Cxhat,9,9));
title('test my one');
  %colormap('gray');




          
  


