
// isOrdered()
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
	bool x=true;
	T a,p;
	Ordered(root);
   
	while(!Q.empty())
   {
		a=Q.front();
		Q.pop();
		p=Q.front();
		if(a>=p) {
		x=false;
			}
      if(Q.size()==1) break;
   }
   
	return x; // Stub: Your code here
}


template <typename T>
void BinaryTree<T>::Ordered(const Node * subroot) const
{
   if(subroot!=NULL)
{
	isOrdered(subroot->left);
   Q.push(subroot);
   isOrdered(subroot->right);
}
}
















T e,out;
 queue<T> Q;
 if(subroot!=NULL)
{

 e=subroot->elem;
 Q.push(e);
	
 printPaths(subroot->left);
 printPaths(subroot->right);
}
 else{
 
 while(!Q.empty())
 {
	out=Q.front();
	cout<<out<<" ";
   Q.pop();
 }
}