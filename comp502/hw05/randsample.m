function y = randsample(a, n)
%RANDSAMPLE Random sampling, without replacement
%   Y = RANDSAMPLE(N,K) returns K values sampled at random, without
%   replacement, from the integers 1:N.

%   Copyright 1993-2002 The MathWorks, Inc.
%   $Revision: 1.1 $  $Date: 2002/03/13 23:15:54 $

% RANDSAMPLE does not (yet) implement weighted sampling.

if nargin < 2
    error('Requires two input arguments.');
end

 npts = length(a);

    if npts == 1   % We have a scalar argument for a
    npts = a;
    a = [1:a]; % Construct an array 1:a
    end
    
    if npts < n
    error(...
    sprintf('Trying to select %d items from a list of length %d',n, npts));
    end
    
    item = zeros(1,n);
    
    for i = 1:n
    % Generate random value in the appropriate range 
    r = ceil((npts-i+1).*rand);
    item(i) = a(r);       % Select the rth element from the list
    a(r)    = a(end-i+1); % Overwrite selected element
    end                       % ... and repeat


end

% a scalar loop version
%
% x = 1:n;
% n = n:(-1):(n-k+1);
% y = zeros(1,k);
% j = ceil(n .* rand(1,k));
% for i = 1:k
%     y(i) = x(j(i));
%     x(j(i)) = x(n(i));
% end