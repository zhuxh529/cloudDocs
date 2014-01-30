function Mret= transp(anymat)
	[y,x]=size(anymat);
	Mret=ones(x,y);

	for i=1:x
		for j=1:y
			Mret(i,j)=anymat(j,i);
		end
	end
end