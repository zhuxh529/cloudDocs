%Mermaid PCA with GHA
% Import the training data
nrow=248; % 248 rows in each image band
ncol=256; % 256 columns in each image band
datalen = nrow*ncol;
dim = 8; % 8 image bands
%read data file
fid =fopen('mermaid.xv','r','b'); 
%           'b' is needed if you work on a PC, because
%            the 'Mermaid image' was created on  
%            a unix machine and data bytes are flipped between 
%            the two machines;                           
%            use default (type nothing or 'l') if you work on a unix machine 
%         for your reference, the data range of this image is between 0 and 
%         5000, across all bands 
fid =fopen('mermaid.xv','r','b'); 

[a,count]=fread(fid,1024); % file has a 1024-byte header
x = zeros(datalen,dim); 
%            Reading into a datalen x 8 array for easy handling
%           (making each image band into one continuous string of
%            pixel values)
%            This format is just like the 'iris' 
for i=1:dim
   [x(:,i),count]=fread(fid,datalen,'int16');%'int16'); % short integer data
end
%Create smaller subset: extract first 4 bands
for i=1:nrow
    for k=1:ncol
        band1(i,k)=x((i-1)*ncol+k,1);
        band2(i,k)=x((i-1)*ncol+k,2);
        band3(i,k)=x((i-1)*ncol+k,3);
        band4(i,k)=x((i-1)*ncol+k,4);
    end
end
%Extract spatial subimage, upper left quarter
nrow2=nrow/2;
ncol2=ncol/2;
%          Put upper left quarter of image into 2-D array x2
for i=1:nrow2
    for k=1:ncol2
        x2((i-1)*ncol2+k,1)=band1(i,k);
        x2((i-1)*ncol2+k,2)=band2(i,k);
        x2((i-1)*ncol2+k,3)=band3(i,k);
        x2((i-1)*ncol2+k,4)=band4(i,k);
    end
end
%          Reformat 2-D array x2 into separate subimage bands 
%          containing the upper left quarter of the original image
for i=1:nrow2
    for k=1:ncol2
        band12(i,k)=x2((i-1)*ncol2+k,1);
        band22(i,k)=x2((i-1)*ncol2+k,2);
        band32(i,k)=x2((i-1)*ncol2+k,3);
        band42(i,k)=x2((i-1)*ncol2+k,4);
    end
end
%





%BPlearn


function [w1,v1, mytest, mytrain, y2]=BPlearn(n,s2,x,D, testX, testY, paras)
    
    mytest=[];
    mytrain=[];


    alpha=paras(1); % momentum term constant
    rate=paras(2); % learning rate
    slope=paras(3); % tanh slope
    epoch=paras(4); 


    m=6000;

    s1=size(x,2);
    s3=size(D,2);


    w=initWeights(s1,s2-1,0.01)
    v=initWeights(s2,s3,0.01)

    dw_prev=zeros(s1,s2-1);
    dv_prev=zeros(s2,s3);


for i=1:n

    no=randi(size(x,1));
    input =x(no, :);
    y1=input*w;
    y1=tanh(slope*y1);
    y1=[1 y1];
    y2=tanh(slope*y1*v);
    %size(y1)
    err2=(D(no,:) -y2).*(1-y2.^2);
    err1=v(2:s2,:)*err2'.*(1-y1(2:s2)'.^2);

    dv=rate*y1'*err2;
    dv_prev=dv;


    dw=rate*repmat(x(no,:)', [1,s2-1]).*repmat(err1',[s1,1]);
    dw_prev=dw;

    if rem(i,epoch)==0
        w=w+dw;
        v=v+dv;
        wtemp=w;
        vtemp=v;
        [err_train, o1]=BPrecall(wtemp,vtemp,10,D,x,paras);
        %disp(err_train);
        wtemp1=w;
        vtemp1=v;
        [err_test,o2]=BPrecall(wtemp1,vtemp1,10,testY,testX,paras);
        %str=[num2str(err_train) '       ' num2str(err_test)];
        %disp(str);
        mytest=[mytest err_test];
        mytrain=[mytrain err_train];
    end

    if rem(i,m)==0
        str = [ num2str(i) '       ' num2str( sum(D(no,:)-y2))]; 
        disp(str);
        
    end


end
    w1=w;
    v1=v;


end



%
