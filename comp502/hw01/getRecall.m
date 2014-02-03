function recall=getRecall(m1, m2)
	mis=0;
	if size(m1)==size(m2)
		for i=1:size(m1)(1)
			for j=1:size(m1)(2)
				if m1(i,j)~=m2(i,j)
					mis=mis+1;
				end
			end
		end
	else
		disp("2 matrix size are not the same");
	end
	mis
	recall=mis/length(m1(:));
end
