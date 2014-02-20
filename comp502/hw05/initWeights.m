function weight=initWeights(row, col, limit)
	weight=(unidrnd(20, [row,col])-10)*limit;
	r=randi(10);
	if r>5
		weight(weight==0)=limit*0.5;
	else 
		weight(weight==0)=-limit*0.5;
	end
end