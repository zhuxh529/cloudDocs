function drawpic(m)
	m=reshape(m,12, 12);
	m(m>0)=1;
	m(m<=0)=0;
	figure(1), imshow(m);
end
