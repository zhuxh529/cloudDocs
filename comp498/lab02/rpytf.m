function m=rpytr(twist)
	m=rollr(twist(4))* pitchr(twist(5))* yawr(twist(6));
	m=[m twist(1:3)'; 0 0 0 1];
end