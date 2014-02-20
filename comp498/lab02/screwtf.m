function s=screwtf(translation,rotation,ax)
	v=1-cos(rotation);
	s=sin(rotation);
	c=cos(rotation);
	R=[v*ax(1)^2+c,ax(1)*ax(2)*v-ax(3)*s, ax(1)*ax(3)*v+ax(2)*s;...
		v*ax(1)*ax(2)+s*ax(3),ax(2)*ax(2)*v+c, ax(2)*ax(3)*v-ax(1)*s;...
		v*ax(1)*ax(3)-s*ax(2),ax(2)*ax(3)*v+ax(1)*s, ax(3)*ax(3)*v+c];
	(translation.*ax)'
	size(R)
	s=[R, (translation.*ax); 0 0 0 1];

end