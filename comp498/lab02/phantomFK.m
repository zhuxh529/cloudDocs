function m=phantomFK(joint_angles,gimbal_angles)
	%i am not pretty sure what gimbal_angles is..
	m1=screwDH(0,0,82.6,0);
	m2=screwDH(0,0,82.6,0)*screwDH(0,pi/2,0,0);
	m3=screwDH(0,0,82.6,0)*screwDH(0,pi/2,0,0)*screwDH(141.75,0,0,-pi/2);
	m4=screwDH(0,0,82.6,0)*screwDH(0,pi/2,0,0)*screwDH(141.75,0,0,-pi/2)*screwDH(66,0,0,pi/2);
	m5=screwDH(0,0,82.6,0)*screwDH(0,pi/2,0,0)*screwDH(141.75,0,0,-pi/2)*screwDH(66,0,0,pi/2)*screwDH(0,-pi/2,0,-pi/2);

	m={m1,m2,m3,m4,m5};
end