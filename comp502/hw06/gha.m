function [W, history]=gha(P,steps,m,mu)
history=[];
[row col]=size(P);	
W=rand(m,col)*(max(max(P)))
for step=1:steps,
   cc=clock;
   ind=rand(1,row);
	[y inds]=sort(ind); 
	P=P(inds,:);
   for j=1:row,
	  dw = zeros(size(W));
      x = P(j,:); 
      y(1) = dot(W(1,:),x);
      dw(1,:) = mu*y(1)*(x-y(1)*W(1,:));
      for h=2:m,
	 	y(h) = dot(W(h,:),x);
	 	temp = 0; 
	 	for k=1:h, 
	 	temp=temp+W(k,:)*y(k); 
	 	end
	 	dw(h,:)=mu*y(h)*(x-temp);    
      end
      W=W+dw;
   end

	if rem(step,1000)==0
   		showW=W;
   		myi=showW*showW';
   		diff=myi-eye(m);
   		diff=sum(sum(abs(diff)));
   		history=[history diff];
   		str = [ num2str(step) '       ' num2str(diff)]; 
		disp(str);
	end


end

W=W';

end