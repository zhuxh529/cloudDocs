function out=getclass(m)
	out=[]
	for i=1:size(m)(1)
		if m(i,:)==[1, -1, -1]
			out=[out; 1];
		elseif m(i,:)==[-1, 1, -1]
			out=[out;2];
		elseif m(i,:)==[-1, -1, 1]
			out =[out;3]
		else
			out=[out;0];
		end
	end

end