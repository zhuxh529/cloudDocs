function [is_solution,joint_angles] = pumaIK(T,prev_joint_angles,puma)
	joint_angles=[];
	px=T(1,4);
	py=T(2,4);
	pz=T(3,4);

	r11=T(1,1);
	r12=T(1,2);
	r13=T(1,3);
	r21=T(2,1);
	r22=T(2,2);
	r23=T(2,3);
	r31=T(3,1);
	r32=T(3,2);
	r33=T(3,3);

	d3=puma.parameters.L_4;
	a2=puma.parameters.L_3;
	a3=puma.parameters.L_5;
	d4=puma.parameters.L_6;
	in2mm = 25.4;

	if (px<=(2.2+sqrt(34.49^2+5.5^2))*in2mm & px>=-(2.2+sqrt(34.49^2+5.5^2))*in2mm ) & (py<=(2.2+sqrt(34.49^2+5.5^2))*in2mm  & py>=-(2.2+sqrt(34.49^2+5.5^2))*in2mm ) & (px<=34.05*in2mm  & pz>=-34.05*in2mm )
		is_solution=true;
	else
		is_solution=false;
	end


	if is_solution==true

		rou=sqrt(px^2+py^2);

		theta1_1=atan((py)/(px))-atan((d3/rou)/(sqrt(1-d3^2/rou^2)));
		theta1_2=atan((py)/(px))-atan((d3/rou)/(-sqrt(1-d3^2/rou^2)));
		theta1=[];
		if theta1_1<=puma.joint_limits{1}(2) & theta1_1>=puma.joint_limits{1}(1)
			theta1=[theta1, theta1_1];
		end

		if theta1_2<=puma.joint_limits{1}(2) & theta1_2>=puma.joint_limits{1}(1)
			theta1=[theta1, theta1_2];
		end

		theta1=theta1(find(min(abs(theta1-prev_joint_angles(1)))==abs(theta1-prev_joint_angles(1))));



		K=(px^2+py^2+pz^2-a2^2-a3^2-d3^2-d4^2)/(2*a2);
		theta2_1=atan(-pz/(sqrt(px^2+py^2-d3^2)))-atan(sqrt(a3^2+d4^2-K^2)/(K+a2));
		theta2_2=atan(-pz/(sqrt(px^2+py^2-d3^2)))-atan(-sqrt(a3^2+d4^2-K^2)/(K+a2));
		theta2_3=atan(pz/(sqrt(px^2+py^2-d3^2)))-atan(sqrt(a3^2+d4^2-K^2)/(K+a2));
		theta2_4=atan(pz/(sqrt(px^2+py^2-d3^2)))-atan(-sqrt(a3^2+d4^2-K^2)/(K+a2));

		theta2=[];
		if theta2_1<=puma.joint_limits{2}(2) & theta2_1>=puma.joint_limits{2}(1)
			theta2=[theta2, theta2_1];
		end

		if theta2_2<=puma.joint_limits{2}(2) & theta2_2>=puma.joint_limits{2}(1)
			theta2=[theta2, theta2_2];
		end

		if theta2_3<=puma.joint_limits{2}(2) & theta2_3>=puma.joint_limits{2}(1)
			theta2=[theta2, theta2_3];
		end

		if theta2_4<=puma.joint_limits{2}(2) & theta2_4>=puma.joint_limits{2}(1)
			theta2=[theta2, theta2_4];
		end

		theta2=theta2(find(min(abs(theta2-prev_joint_angles(2)))==abs(theta2-prev_joint_angles(2))));



		theta3_1=atan(a3/d4)-atan(K/sqrt(a3^2+d4^2-K^2));
		theta3_2=atan(a3/d4)-atan(-K/sqrt(a3^2+d4^2-K^2));

		theta3=[];
		if theta3_1<=puma.joint_limits{3}(2) & theta3_1>=puma.joint_limits{3}(1)
			theta3=[theta3, theta3_1];
		end

		if theta3_2<=puma.joint_limits{3}(2) & theta3_2>=puma.joint_limits{3}(1)
			theta3=[theta3, theta3_2];
		end

		theta3=theta3(find(min(abs(theta3-prev_joint_angles(3)))==abs(theta3-prev_joint_angles(3))));

		theta2=theta2(1);
		theta1=theta1(1);
		theta3=theta3(1);





		if length(theta1)==0 | length(theta2)==0 | length(theta3)==0 
			is_solution=false;
			joint_angles=[theta1, theta2, theta3, 0,0,0];
			return;
		end


		theta4=atan((-r12*sin(theta1)+r23*cos(theta1))/ ...
			(-r13*cos(theta1)*cos(theta2+theta3)-r23*sin(theta1)*cos(theta2+theta3)...
				+r33*sin(theta2+theta3)));


		s5=-(r13*(cos(theta1)*cos(theta2+theta3)*cos(theta4)+sin(theta1)*sin(theta4))...
			+r23*(sin(theta1)*cos(theta2+theta3)*cos(theta4)-cos(theta1)*sin(theta4))...
			+r33*(sin(theta2+theta3)*cos(theta4)));

		c1=cos(theta1);s23=sin(theta2+theta3);c23=cos(theta2+theta3);
		s1=sin(theta1);s4=sin(theta4);
		c4=cos(theta4);

		c5=r13*(-c1*s23)+r23*(-s1*s23)+r33*(-c23);

		theta5=atan(s5/c5);
		c5=cos(theta5);s5=sin(theta5);


		s6=-r11*(c1*c23*s4-s1*c4)-r21*(s1*c23*s4+c1*c4)+r31*(s23*s4);
		c6=r11*((c1*c23*c4+s1*s4)*c5-c1*s23*s5)+...
			r21*((s1*c23*c4-c1*s4)*c5-s1*s23*s5)-...
			r31*(s23*c4*c5+c23*s5);
		theta6=atan(s6/c6);

		if theta4<=puma.joint_limits{4}(2) & theta4>=puma.joint_limits{4}(1) ...
			& theta5<=puma.joint_limits{5}(2) & theta5>=puma.joint_limits{5}(1)...
			& theta6<=puma.joint_limits{6}(2) & theta6>=puma.joint_limits{6}(1)

			is_solution=true;
			joint_angles=[theta1, theta2, theta3, theta4, theta5, theta6];

		else 
			%disp('theta4-6 fault');
			is_solution=false;
			joint_angles=[theta1, theta2, theta3, theta4, theta5, theta6];

		end







	end

end