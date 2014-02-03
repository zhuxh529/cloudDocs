    h=img[l]->tellHeight();
    w=img[l]->tellWidth(); 
    int aa; 
    int bb;
for(int i=xx[l],aa=xx[l]; i<(aa+w);i++)
     {
		for (int j=yy[l],bb=yy[l];d<(h+bb) ;j++)
        {
			r = operator()(i-aa, j-bb)->Red;
			g = operator()(i-aa, j-bb)->Green;
			b = operator()(i-aa, j-bb)->Blue;
			cao.operator()(i, j)->Red=r;
			cao.operator()(i, j)->Green=g;
			cao.operator()(i, j)->Blue=b;
        }
     }





 for(int i=xx[l],c=0; c<w;i++,c++)
     {
		for (int j=yy[l],d=0;d<h ;j++,d++)
        {
			r = operator()(c, d)->Red;
			g = operator()(c, d)->Green;
			b = operator()(c, d)->Blue;
			cao.operator()(i, j)->Red=r;
			cao.operator()(i, j)->Green=g;
			cao.operator()(i, j)->Blue=b;
        }
     }
