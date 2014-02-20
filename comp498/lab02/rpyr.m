function m=rpyr(angles)
	m=rollr(angles(1))* pitchr(angles(2))* yawr(angles(3));
end