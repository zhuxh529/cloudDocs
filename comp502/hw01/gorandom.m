function ret=gorandom(m)
	ran1=unidrnd(12, [2 50]);
	ret=m;
	for j=1:size(ran1)(2)
		x=ran1(1,j);
		y=ran1(2,j);
		if(m(x,y)==1) 
			ret(x,y)=-1;
		else
			ret(x,y)=1;
		end
	end
end
