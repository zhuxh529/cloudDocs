/*
    Lab 12: Minimum Path
    Written by Sean Massung for CS 225 Spring 2011
*/


#include "minpath.h"



 //  SCHashTable<string, pair<string, int> >  dad(256, hasher);


int minPath(Graph & g, string start, string end){

    // your code here

 
  vector<string> ver;
  ver=g.getVertices();

  for(int j=0; j<ver.size(); j++)
 {
	g.setVertexMark(ver[j],"UNEXPLORED" );
	
 }

   int num;
   int n=1;
   int m=1000;
   
	searchpath(g, start, end, n, m);


   draw(g, start, end, m);

	return m;


}







void searchpath(Graph & g, string start, string end, int n, int & m)
{
  
  
  
  

  string temp;
  vector<string> adj;
  pair<string, int> nima, niba, ninainai;

  
  adj=g.getAdjacent(start);

  queue< pair<string, int> > Q;
	nima.first=start;
  nima.second=n;

  Q.push(nima);






  while(!Q.empty()){
  
   temp=(Q.front()).first;
   n=(Q.front()).second;
   
   g.setVertexMark(temp, "VISITED"); 
	Q.pop();
   adj=g.getAdjacent(temp);
  

  for(int i=0; i< adj.size();i++)
 {
 //if(g.getEdgeMark(temp, adj[i])=="UNEXPLORED")


 
  if(g.getVertexMark(adj[i])=="UNEXPLORED")
	{
  	  if(adj[i]==end) {
		if(m>n) m=n;
    /*    ninainai.first=temp;
     ninainai.second=n;
     
     dad.insert(adj[i], ninainai);*/
	
		break;
		}

     
	  g.setEdgeMark(temp, adj[i], "DISCOVERY"); 
     niba.second=n+1;
     niba.first=adj[i];
     Q.push(niba);
    

	  
	}


  else if(g.getEdgeMark(temp, adj[i])=="UNEXPLORED")
  {
	if(adj[i]==end) {
		if(m>n) m=n;
	   
		break;
		
		}
	   g.setEdgeMark(temp, adj[i], "CROSS"); 
    //  searchpath(g, adj[i], end, n+1, m);
     //searchpath(g, adj[i], end, n+1, m);
  } 

 }

 }


return;

}

void draw(Graph & g, string start, string end, int & m)
{
  vector<string> ver;
  ver=g.getVertices();

string temp;
temp=end;
for(int i=m; i>=1; i--)
{

 for(int j=0; j<ver.size(); j++)
 {
	g.setVertexMark(ver[j],"UNEXPLORED" );
	
 }
temp=drawit(g, start, temp, 1,1000, i);

}
}





string drawit(Graph & g, string start, string end, int n, int m, int MM)
{
  

  string temp;
  vector<string> adj;
  vector<string> out;
  pair<string, int> nima, niba, ninainai;

  adj=g.getAdjacent(start);

  queue< pair<string, int> > Q;

	nima.first=start;
  nima.second=n;
  Q.push(nima);


  while(!Q.empty()){
  
   temp=(Q.front()).first;
   n=(Q.front()).second;
   
   g.setVertexMark(temp, "VISITED"); 
	Q.pop();
   adj=g.getAdjacent(temp);
  

  for(int i=0; i< adj.size();i++)
 {
 //if(g.getEdgeMark(temp, adj[i])=="UNEXPLORED")


 
  if(g.getVertexMark(adj[i])=="UNEXPLORED")
	{
  	  if(adj[i]==end) {
		if(m>n) m=n;
    /*    ninainai.first=temp;
     ninainai.second=n;
     
     dad.insert(adj[i], ninainai);*/
	  if(MM==m) 
 	{
		g.setEdgeMark(temp, adj[i], "MIN");
		return temp;
 	}	
		
		}

     
	  g.setEdgeMark(temp, adj[i], "DISCOVERY"); 
     niba.second=n+1;
     niba.first=adj[i];
     Q.push(niba);
    

	  
	}


  else if(g.getEdgeMark(temp, adj[i])=="UNEXPLORED")
  {
	if(adj[i]==end) {
		if(m>n) m=n;
	     if(MM==m) 
 	{
		g.setEdgeMark(temp, adj[i], "MIN");
		return temp;
 	}	
	
		
		}
	   g.setEdgeMark(temp, adj[i], "CROSS"); 
    //  searchpath(g, adj[i], end, n+1, m);
     //searchpath(g, adj[i], end, n+1, m);
  } 

 }

 }



}


/*
int searchpath(Graph & g, string start, string end)
{
  vector<string> adj;
  queue<string> Q;
  Q.push(start);
    string temp;
   int counter=0;
   int cao;
   bool kai=true;
     g.setVertexMark(start, "VISITED"); 

    while(!Q.empty())
 {
   temp=Q.front();

	Q.pop();
   adj=g.getAdjacent(temp);
  

//go to adjacent
   for(int i=0; i< adj.size();i++)
 {
	if(g.getVertexMark(adj[i])=="UNEXPLORED")
   {
   // W=g.getEdgeWeight(temp, adj[i]);
    if(adj[i]==end) {
		return counter;}
	 //g.setEdgeMark(temp, adj[i], "DISCOVERY");
     Q.push(adj[i]);
    g.setVertexMark(adj[i], "VISITED"); 
	}
   cao--;
  

/*  else if(g.getEdgeMark(temp, adj[i])=="UNEXPLORED")
	{
	 W=g.getEdgeWeight(temp, adj[i]);
    if(W<wei) {wei=W;
		x=temp;
		y=adj[i];}
	g.setEdgeMark(temp, adj[i], "CROSS");
	}
*/
 

/*
int BFS(Graph & g, string vertex, string &x, string & y )
{
  int wei=50000;
  int W;
  vector<string> adj;
  queue<string> Q;
  Q.push(vertex);
  string temp;
  while(!Q.empty())
 {
   temp=Q.front();
   g.setVertexMark(temp, "VISITED"); 
	Q.pop();
   adj=g.getAdjacent(temp);

//go to adjacent
   for(int i=0; i< adj.size();i++)
 {
	if(g.getVertexMark(adj[i])=="UNEXPLORED")
   {
    W=g.getEdgeWeight(temp, adj[i]);
    if(W<wei) {wei=W;
		x=temp;
		y=adj[i];}
	 g.setEdgeMark(temp, adj[i], "DISCOVERY");
    Q.push(adj[i]);
	}

  else if(g.getEdgeMark(temp, adj[i])=="UNEXPLORED")
	{
	 W=g.getEdgeWeight(temp, adj[i]);
    if(W<wei) {wei=W;
		x=temp;
		y=adj[i];}
	g.setEdgeMark(temp, adj[i], "CROSS");
	}
 }
 }
return wei;
}







string temp;

 vector<string> mama;

	//doing=dad.find(end);

SCHashTable<string, pair<string, int> >::iterator it;


for(it=dad.begin(); it!=dad.end(); it++)
{
if((it->second).second==m)
 {
	 g.setEdgeMark(end, (it->second).first, "MIN");
    cout<<" i am here"<< end;
 }
}
   

//while()
{



}
*/

