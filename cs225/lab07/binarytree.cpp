
// height()
template <typename T>
int BinaryTree<T>::height() const
{
	// Call recursive helper function on root
	return height(root);
}

// height() recursive helper function
template <typename T>
int BinaryTree<T>::height(const Node * subRoot) const
{
	// Base case
	if (subRoot == NULL) return -1;

	// Recursive definition
	return 1 + max(height(subRoot->left), height(subRoot->right));
}



// printLeftToRight()
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
	// Call recursive helper function on the root
	printLeftToRight(root);

	// Finish the line
	cout << endl;
}

// printLeftToRight() recursive helper function
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node * subRoot) const
{
	// Base case - null node
	if (subRoot == NULL)
		return;

	// Print left subtree
	printLeftToRight(subRoot->left);

	// Print this node
	cout << subRoot->elem << ' ';

	// Print right subtree
	printLeftToRight(subRoot->right);
}



// mirror()
template <typename T>
void BinaryTree<T>::mirror()
{
	// Your code here
   mirror(root);
  
}

template <typename T>
void BinaryTree<T>::mirror(Node * subroot)
{
  if(subroot==NULL) return;
  else 
{
	Node *temp;
   mirror(subroot->left);
   mirror(subroot->right);

	temp=subroot->left;
	subroot->left=subroot->right;
	subroot->right=temp;
   
}
}



// isOrdered()
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
	bool x=true;
   bool y;
   queue<T> Q;
	
	Q=Ordered(root);
   
   T a,p;
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
  
return x;

   
	
   
	return x; // Stub: Your code here
}


template <typename T>
queue<T>  BinaryTree<T>::Ordered(const Node * subroot ) const
{
   queue<T> Q;
   if(subroot!=NULL)
{
	Ordered(subroot->left);
   Q.push(subroot->elem);
   Ordered(subroot->right);
}

return Q;
}
 
 

  




// printPaths()
template <typename T>
void BinaryTree<T>::printPaths() const
{
	 T path[500];

   printPaths(root,path,0);

	// Your code here
}




template <typename T>
void BinaryTree<T>::printPaths(const Node * subroot, T path[], int l) const
{

if(subroot==NULL) return;
path[l]=subroot->elem;
l++;
if(subroot->left==NULL && subroot->right==NULL)
{
 cout<<"Path: ";
 for(int i=0; i<l;i++)
 {
  cout<<path[i]<<" ";
 }
  cout<<endl;
}

else{

printPaths(subroot->left, path, l);
printPaths(subroot->right, path, l);

}
}


// sumDistances()
template <typename T>
int BinaryTree<T>::sumDistances() const
{
	int sum=0;
	int a;
   stack<int> K;
	sumDistances(root, 0, 0, K);
   while(!K.empty())
{
a=K.top();
sum=sum+a;
K.pop();
}
	return sum; // Your code here
}

template <typename T>
void BinaryTree<T>::sumDistances(const Node * subroot, int l,int dis, stack<int> &K)const
{
if(subroot==NULL) return;
dis=l;
l++;

K.push(dis);
sumDistances(subroot->left, l, dis, K);
sumDistances(subroot->right, l, dis, K);

}


















