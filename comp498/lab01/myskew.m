%xihao zhu
function Mret= myskew(vect3)
	Mret=zeros(3,3);
	if size(vect3)(2)==3 & size(vect3)(1)==1

		Mret(1,2)=-vect3(3);
		Mret(2,1)=vect3(3);
		Mret(1,3)=vect3(2);
		Mret(3,1)=-vect3(2);
		Mret(2,3)=-vect3(1);
		Mret(3,2)=vect3(1);
	else 
		disp('input format wrong!!!!!!')
	end
end