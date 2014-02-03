#include "maze.h"





void SquareMaze::makeMaze(int width, int height)
{

Node A;
DisjointSets set;
int r1, r2, r3, ra;

int unionsize;
int count=0;
int x,y;

int direction;
bool goon;

kuan=width;
gao=height;


S=width*height;
if(!mazebody.empty()) mazebody.clear(); // clear the vector

mazebody.resize(S);
for(int i=0; i<S; i++)
{
mazebody[i]=A;
}

set.addelements(S);
unionsize=S-1; 
srand(time(NULL));



while(count<unionsize)
{

for(int i=0; i<S; i++)
 {

	r1=rand()%10;
	if(r1<5) continue; // if go into this cell?
	//srand(time(NULL));
	r2=rand()%10;
   if(r2<5)  direction=0;
   else direction=1;// rondomly select direction to go
	
	

// to see if go to next cycle
  if(direction==0 && ifBottom(i)) continue;
  if(direction==1 && ifRight(i)) continue;

  int r, d;
  r=rightcell(i);
  d=downcell(i);
  if(direction==0 && set.find(i)==set.find(d)) continue;
  if(direction==1 && set.find(i)==set.find(r)) continue;

	 
//setunion

  if(direction==0) {
 
  set.setunion(i, d);
	}  

	if(direction==1) {

  set.setunion(i, r);
	}  
   x=getx(i);
   y=gety(i);
  
   setWall(x,y, direction, false);
   
   count++;
   
  if(count>=unionsize) return;
 }
}
}





bool SquareMaze::canTravel(int x, int y, int dir)
{
bool can;
int i=y*kuan+x;

if(dir==0)
{
if(mazebody[i].rightwall==false) can=true;
else can=false;
return can;
}

if(dir==1)
{
if(mazebody[i].downwall==false) can=true;
else can=false;
return can;
}

if(dir==2)
{
if(x==0) return false;

if(mazebody[i-1].rightwall==false) can=true;
else can=false;
return can;

}

if(dir==3)
{
if(y==0) return false;

if(mazebody[i-kuan].downwall==false) can=true;
else can=false;
return can;

}
else return can;

}




void SquareMaze::setWall(int x, int y, int dir, bool exists)
{
  int i=y*kuan+x;
  if(dir==0) {
  mazebody[i].downwall=exists;
	}  

	if(dir==1) {
  mazebody[i].rightwall=exists;
   }
}



///////////////////////////////////////    solve maze
void SquareMaze::solveMaze()
{
int max, temp;
int i;
int d;

if(!solution.empty()) solution.clear(); 
//assign distance to every node;

alldis(0);
i=(kuan)*(gao-1);
max=mazebody[i].dis;

for(int ii=(kuan)*(gao-1); ii<S; ii++)
{
temp=mazebody[ii].dis;
if(max<temp){
max=temp;
i=ii;
}

}
exit=i;

d=max;
getpath(i);

}











BMP* SquareMaze::drawMaze()
{
BMP* ret=new BMP;
ret->setSize(kuan*10+1, gao*10+1);

RGBApixel black;
black.Red=0;
black.Green=0;
black.Blue=0;

int a,b;
for(a=10; a<kuan*10+1; a++)
{
(*ret)(a,0)->Red=black.Red;
(*ret)(a,0)->Green=black.Green;
(*ret)(a,0)->Blue=black.Blue;
}

for(b=0;b<gao*10+1; b++)
{
(*ret)(0,b)->Red=black.Red;
(*ret)(0,b)->Green=black.Green;
(*ret)(0,b)->Blue=black.Blue;
}



//drawcells!!!!111

int x,y;
for(int i=0; i<S; i++)
{
x=getx(i);
y=gety(i);
 if(mazebody[i].downwall==true)
 {
   for(int k=0;k<11;k++)
	{ 

	(*ret)(x*10+k,(y+1)*10)->Red=black.Red;
	(*ret)(x*10+k,(y+1)*10)->Green=black.Green;
	(*ret)(x*10+k,(y+1)*10)->Blue=black.Blue;
	
	}
 }


if(mazebody[i].rightwall==true)
 {
   for(int k=0;k<11;k++)
	{

	(*ret)((x+1)*10,y*10+k)->Red=black.Red;
	(*ret)((x+1)*10,y*10+k)->Green=black.Green;
	(*ret)((x+1)*10,y*10+k)->Blue=black.Blue;
	
	}
 }

}


return ret;
}




BMP* SquareMaze::drawMazeWithSolution()
{
BMP* ret;
ret=drawMaze();

int SS;
SS=solution.size();


RGBApixel red;
red.Red=255;
red.Green=0;
red.Blue=0;



int px=5;
int py=5; 

 for(int i=0; i<SS; i++)
 {
 // redline(solution[x]);
//11111111111111111111111111111111111111111111111111111111111111
  if(solution[i]==0) 
{
for(int k=px;k<=px+10;k++)
{
   (*ret)(k, py)->Red=red.Red;
	(*ret)(k, py)->Green=red.Green;
	(*ret)(k, py)->Blue=red.Blue;
}
px=px+10;

}

//2222222222222222222222222222222222222222222222222222222222222222

  if(solution[i]==1)
{
for(int k=py;k<=py+10;k++)
{
   (*ret)(px, k)->Red=red.Red;
	(*ret)(px, k)->Green=red.Green;
	(*ret)(px, k)->Blue=red.Blue;
}
py=py+10;

}


//33333333333333333333333333333333333333333333333333333333333333333333
  if(solution[i]==2)
{
for(int k=px;k>=px-10;k--)
{
   (*ret)(k, py)->Red=red.Red;
	(*ret)(k, py)->Green=red.Green;
	(*ret)(k, py)->Blue=red.Blue;
}
px=px-10;

}




  if(solution[i]==3)
{
for(int k=py;k>=py-10;k--)
{
   (*ret)(px, k)->Red=red.Red;
	(*ret)(px, k)->Green=red.Green;
	(*ret)(px, k)->Blue=red.Blue;
}
py=py-10;

}

 } 


int xxx, yyy;
xxx=getx(exit);
yyy=gety(exit);

for(int k=1; k<10;k++)
{
  (*ret)(xxx*10+k, (yyy+1)*10)->Red=255;
(*ret)(xxx*10+k, (yyy+1)*10)->Green=255;
(*ret)(xxx*10+k, (yyy+1)*10)->Blue=255;
}

return ret;
}





///////////////////////////////////////////////////////////////////////
//helper functions

int SquareMaze::rightcell(int i)
{
return (i+1);

}



int SquareMaze::downcell(int i)
{
return (i+kuan);

}


int SquareMaze::upcell(int i)
{
return (i-kuan);

}


int SquareMaze::leftcell(int i)
{
return(i-1);
}




bool SquareMaze::ifBottom(int i)
{
if(i>=((gao-1)*kuan)) return true;
else return false;

}

bool SquareMaze::ifRight(int i)
{
if((i+1)%kuan==0) return true;
else return false;

}

int SquareMaze::getx(int i)
{
return (i%kuan);
}

int SquareMaze::gety(int i)
{
int k;
k=(i/kuan);
return k;
}




void SquareMaze::alldis(int initial)
{
queue<int> q;
mazebody[initial].dis=0;

q.push(initial);
int temp;
int x, y;

int r, d, l, u;
int Di;


while(!q.empty())
 {
 temp=q.front();
 x=getx(temp);
 y=gety(temp);
 q.pop();
 Di=mazebody[temp].dis;
 
 if(canTravel(x, y, 0) && mazebody[rightcell(temp)].dis==-1)
 {
 r=rightcell(temp);
 mazebody[r].dis=Di+1;
 q.push(r);
 }

 if(canTravel(x, y, 1) && mazebody[downcell(temp)].dis==-1)
 {
	d=downcell(temp);
   mazebody[d].dis=Di+1;
    q.push(d);
 }
 
 if(canTravel(x, y, 2) && mazebody[leftcell(temp)].dis==-1)
 {
	l=leftcell(temp);
   mazebody[l].dis=Di+1;
    q.push(l);
 }

 if(canTravel(x, y, 3) && mazebody[upcell(temp)].dis==-1)
 {
	u=upcell(temp);
   mazebody[u].dis=Di+1;
    q.push(u);
 } 
 }

}


void SquareMaze::getpath(int i)
{
vector<int> reverse;
int ii=i;
int nei;
int dir;
int d;
int temp;

d=mazebody[i].dis;

while(i!=0)
 {
  dir=neighbour(i);
  reverse.push_back(dir);
  if(dir==0) i=rightcell(i);
  if(dir==1) i=downcell(i);
  if(dir==2) i=leftcell(i);
  if(dir==3) i=upcell(i);
 
}


while(!reverse.empty())
{
dir=reverse.back();
reverse.pop_back();

  if(dir==0) temp=2;
  if(dir==1) temp=3;
  if(dir==2) temp=0;
  if(dir==3) temp=1;
  solution.push_back(temp);

}
nei=nei+1;
}



int SquareMaze::neighbour(int i)
{
int di=mazebody[i].dis;
int x, y;
x=getx(i);
y=gety(i);
int r, d, l, u;


if(canTravel(x, y, 0))
 {
 r=rightcell(i);
 if(mazebody[r].dis==(di-1)) return 0;

 }

if(canTravel(x, y, 1))
 {
	d=downcell(i);
  if( mazebody[d].dis==di-1) return 1;

 }
 
if(canTravel(x, y, 2) )
 {
	l=leftcell(i);
   if(mazebody[l].dis==di-1) return 2;

 }

if(canTravel(x, y, 3) )
 {
	u=upcell(i);
   if(mazebody[u].dis==di-1) return 3;
 } 

return -1;

}



