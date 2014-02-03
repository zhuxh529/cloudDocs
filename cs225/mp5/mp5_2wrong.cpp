
	void Quadtree::prune(int i)
{
	
   prunehelp(i,root);


}


   void Quadtree::prunehelp(int i, QuadtreeNode* subroot)
{
   if(subroot->nwChild==NULL) return;
   bool tol;
    tol=compare(subroot->nwChild, subroot->neChild, 
          subroot->swChild, subroot->seChild, i);
   if(tol==true) 
   {
clear(subroot->nwChild);
clear(subroot->neChild);
clear(subroot->swChild);
clear(subroot->seChild);

}
	prunehelp(i,subroot->nwChild);
	prunehelp(i,subroot->neChild);
	prunehelp(i,subroot->swChild);
	prunehelp(i,subroot->seChild);

  

}


bool  Quadtree::compare(QuadtreeNode* nw, QuadtreeNode* ne, QuadtreeNode* sw, QuadtreeNode* se, int i)
{
int dnw, dne, dsw, dse ;
RGBApixel total;
total=average(nw, ne, sw, se);

 dnw=getdif(nw->element, total);
 dne=getdif(ne->element, total);
 dsw=getdif(sw->element, total);
 dse=getdif(se->element, total);

 if(dnw<=i && dne<=i && dsw<=i && dse<=i)
return true;
 else return false;

}

//get average
RGBApixel Quadtree::average(QuadtreeNode* nw, QuadtreeNode* ne, QuadtreeNode* sw, QuadtreeNode* se)
{
RGBApixel BBQ;
BBQ.Red=( (nw->element).Red+(ne->element).Red+ (sw->element).Red + (se->element).Red )/4;
BBQ.Green=( (nw->element).Green+(ne->element).Green+ (sw->element).Green + (se->element).Green )/4;
BBQ.Blue=( (nw->element).Blue+(ne->element).Blue+ (sw->element).Blue + (se->element).Blue )/4;
return BBQ;
}


int Quadtree::getdif(RGBApixel ta, RGBApixel total)
{
 int x;
 x=pow(ta.Red-total.Red,2)+pow(ta.Green-total.Green,2)+pow(ta.Blue-total.Blue,2);
 return x;
}




///////////////////////////////////////////////////////////////////////////////////////////






void Quadtree::realbuild(const BMP & source, int d, QuadtreeNode* subroot, int x, int y, RGBApixel & BBQ)
{


 d=d/2;
 subroot->nwChild=new QuadtreeNode;
 subroot->neChild=new QuadtreeNode;
 subroot->swChild=new QuadtreeNode;
 subroot->seChild=new QuadtreeNode;

  
if(d>1)
{
 
 realbuild(source, d, subroot->nwChild, x, y, BBQ);
 (subroot->nwChild->element).Red=BBQ.Red;
 (subroot->nwChild->element).Green=BBQ.Green;
 (subroot->nwChild->element).Blue=BBQ.Blue;
// cout<<BBQ.Red<<"  ";

 realbuild(source, d, subroot->neChild, x+d, y, BBQ);
 (subroot->neChild->element).Red=BBQ.Red;
 (subroot->neChild->element).Green=BBQ.Green;
 (subroot->neChild->element).Blue=BBQ.Blue;
// cout<<BBQ.Red<<"  ";

 realbuild(source, d, subroot->swChild, x, y+d,BBQ);
 (subroot->swChild->element).Red=BBQ.Red;
 (subroot->swChild->element).Green=BBQ.Green;
 (subroot->swChild->element).Blue=BBQ.Blue;
// cout<<BBQ.Red<<"  ";

 realbuild(source, d, subroot->seChild, x+d, y+d,BBQ);
 (subroot->seChild->element).Red=BBQ.Red;
 (subroot->seChild->element).Green=BBQ.Green;
 (subroot->seChild->element).Blue=BBQ.Blue;
 //cout<<BBQ.Red<<endl;


 BBQ.Red=( (subroot->nwChild->element).Red+(subroot->neChild->element).Red+ (subroot->swChild->element).Red + (subroot->seChild->element).Red )/4;

 BBQ.Green=( (subroot->nwChild->element).Green+(subroot->neChild->element).Green+ (subroot->swChild->element).Green + (subroot->seChild->element).Green )/4;
 BBQ.Blue=( (subroot->nwChild->element).Blue+(subroot->neChild->element).Blue+ (subroot->swChild->element).Blue + (subroot->seChild->element).Blue )/4;
 
 }
 if(d<=1)
{
 (subroot->nwChild->element).Red=(*source(x,y)).Red;
(subroot->nwChild->element).Blue=(*source(x,y)).Blue;
(subroot->nwChild->element).Green=(*source(x,y)).Green;
 
 (subroot->neChild->element).Red=(*source(x+d,y)).Red;
 (subroot->neChild->element).Green=(*source(x+d,y)).Green;
 (subroot->neChild->element).Blue=(*source(x+d,y)).Blue;

 (subroot->swChild->element).Red=(*source(x,y+d)).Red;
 (subroot->swChild->element).Green=(*source(x,y+d)).Green;
 (subroot->swChild->element).Blue=(*source(x,y+d)).Blue;


 (subroot->seChild->element).Red=(*source(x+d,y+d)).Red;
 (subroot->seChild->element).Green=(*source(x+d,y+d)).Green;
 (subroot->seChild->element).Blue=(*source(x+d,y+d)).Blue;


 BBQ.Red=( (*source(x,y)).Red+(*source(x+d,y)).Red+ (*source(x,y+d)).Red + (*source(x+d,y+d)).Red )/4;
 BBQ.Green=( (*source(x,y)).Green+(*source(x+d,y)).Green+ (*source(x,y+d)).Green + (*source(x+d,y+d)).Green )/4;
 BBQ.Blue=( (*source(x,y)).Blue+(*source(x+d,y)).Blue+ (*source(x,y+d)).Blue + (*source(x+d,y+d)).Blue )/4;

setchildren0(subroot->nwChild);
setchildren0(subroot->neChild);
setchildren0(subroot->swChild);
setchildren0(subroot->seChild);



}
}





















