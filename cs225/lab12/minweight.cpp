/*
    Lab 12: Minimum Weight
    Written by Sean Massung for CS 225 Spring 2011
*/

#include "minweight.h"
using std::cout;


int minWeight(Graph & g){

    // your code here
   /* int w;
    int s;
    EdgeData temp;

    vector<EdgeData> ret;
    ret=g.getEdges();
    
    temp=ret[0];
	 s=ret.size();
	 for(int i=0; i<s; i++)
  {
	 if(ret[i]<temp) temp=ret[i];
  }
*/
   
  // vector<string> name;
	
  /* SCHashTable<string, EdgeList>::iterator it;
   for(it = data.begin(); it!=data.end(); ++it)
  {
   if(it)
	BFS(*g);
  }
*/
  
  vector<string> ver;
  ver=g.getVertices();
  
  for(int j=0; j<ver.size(); j++)
 {
	g.setVertexMark(ver[j],"UNEXPLORED" );
	
 }
  
  int wei=40000;
  int  W;
  int weigh=50000;
  string x, y;
  string xx,yy;
  
  for(int i=0; i<ver.size(); i++)
 {
	if(g.getVertexMark(ver[i])=="UNEXPLORED")
	{
	W=BFS(g, ver[i], x, y);
   //if(W<wei) {wei=W;
		xx=x;
		yy=y;
	}
 }
 // name.getAdjacent(it);
   g.setEdgeMark(xx, yy, "MIN");
   return W;
}


int BFS(Graph & g, string vertex, string &x, string & y )
{
  int wei=50000;

  int W;

  vector<string> adj;
  queue<string> Q;
  Q.push(vertex);
  string temp;
   g.setVertexMark(temp, "VISITED"); 
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
    W=g.getEdgeWeight(temp, adj[i]);
    if(W<wei) {wei=W;
		x=temp;
		y=adj[i];}
	 g.setEdgeMark(temp, adj[i], "DISCOVERY");
     g.setVertexMark(adj[i], "VISITED"); 
    Q.push(adj[i]);
	}

  else if(g.getEdgeMark(temp, adj[i])=="UNEXPLORED")
	{
   
	 W=g.getEdgeWeight(temp, adj[i]);
    if(W<wei) {wei=W;
		x=temp;
		y=adj[i];}
	g.setEdgeMark(temp, adj[i], "CROSS");
  // cout<<"here"<<endl;
	}
 }
 }

return wei;
}




int DFS(Graph & g, string vertex, string &x, string & y, int & weigh )
{
g.setVertexMark(vertex, "VISITED"); 
vector<string> adj;
adj=g.getAdjacent(vertex);
int ww, W;

int comp;

 for(int i=0; i< adj.size();i++)
{
 if(g.getVertexMark(adj[i])=="UNEXPLORED")
 {
  W=g.getEdgeWeight(vertex, adj[i]);
  g.setEdgeMark(vertex, adj[i], "DISCOVERY");
  ww=DFS(g, adj[i], x, y, weigh);
  comp=W<ww?W:ww;
  if(weigh>comp) {
  weigh=comp; 
  x=vertex;
  y=adj[i];
  }
 }

 else if(g.getEdgeMark(vertex, adj[i])=="UNEXPLORED")
 {
comp=g.getEdgeWeight(vertex, adj[i]);
 if(weigh>comp) {
  weigh=comp; 
  x=vertex;
  y=adj[i];
  }
 
 g.setEdgeMark(vertex, adj[i], "CROSS");
 }


}
return weigh;

}





