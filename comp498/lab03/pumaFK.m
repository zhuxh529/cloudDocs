function [T,puma_T] = pumaFK(joint_angles,puma)
	t1=dhtf(0,0,0,joint_angles(1));
	t2=dhtf(0,puma.parameters.a_1,0,joint_angles(2));
	t3=dhtf(puma.parameters.L_3,0,puma.parameters.L_4,joint_angles(3));
	t4=dhtf(puma.parameters.L_5,puma.parameters.a_2,puma.parameters.L_6,joint_angles(4));
	t5=dhtf(0,puma.parameters.a_3,0,joint_angles(5));
	t6=dhtf(0,puma.parameters.a_4,0,joint_angles(6));
	T=t1*t2*t3*t4*t5*t6;
	puma_T={t1,t2,t3,t4,t5,t6};
end
