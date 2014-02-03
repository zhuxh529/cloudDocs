/*
   Binary Search Tree (Lab 08)
   Created by Chase Geigle for CS225, Spring 2011
*/

// include the given functions
#include "bst_given.cpp"

/*
   Dictionary ADT functions and helpers
*/

// insert() - public interface
template <class K, class V>
void BST<K,V>::insert( K const & key, V const & value ) {
    insert(root, key, value);
}

// insert() - private helper
template <class K, class V>
void BST<K,V>::insert( Node * & croot, K const & key, V const & value ) {
    // your code here
    if(croot==NULL)
    croot=new Node(key, value);
    else if(key< (croot->key))
    insert(croot->left,key, value);
    else insert(croot->right,key,value);
}

// find() - public interface
template <class K, class V>
V BST<K,V>::find( K const & key ) const {
    return find( root, key );
}

// find() - private helper
template <class K, class V>
V BST<K,V>::find( Node const*  croot, K  const & key ) const {
    if(croot==NULL)
    return NULL;
    else if(key== (croot->key))
    return croot->value;
    else if (key<(croot->key))
    return find(croot->left, key);
    else
    return find(croot->right, key); // your code here
}

// remove() - public interface
template <class K, class V>
void BST<K,V>::remove( K const & key ) {
    remove( root, key );
}

// remove() - private helper
template <class K, class V>
void BST<K,V>::remove( Node * & croot, K const & key ) {
    if(croot==NULL)
    return ;
    else if(key== (croot->key))
    return doremoval(croot);
    else if (key<(croot->key))
    return remove(croot->left, key);
    else
    return remove(croot->right, key); // your code here
    
    // your code here
}

template <class K, class V>
void BST<K,V>::doremoval(Node*& croot)
{
if(((croot->left)==NULL) && ((croot->right)==NULL))
 nochild(croot);
else if(((croot->left)!=NULL) && ((croot->right)!=NULL))
 twochild(croot);
else
 onechild(croot);
}

template <class K, class V>
void BST<K,V>::nochild(Node *& croot)
{
 delete croot;
 croot=NULL;
}
template <class K, class V>
void BST<K,V>::onechild(Node *& croot)
{
 Node* temp=croot;
 if((croot->left)==NULL) croot=croot->right;
 else croot=croot->left;

 delete temp;

}

template <class K, class V>
void BST<K,V>::twochild(Node*& croot)
{
Node * &iop=IOP(croot);
croot->key=iop->key;
doremoval(iop);

}

template <class K, class V>
typename BST<K,V>::Node * & BST<K,V> ::IOP(Node *& croot)
{
return rightla(croot->left);
}

template <class K, class V>
typename BST<K,V>::Node * & BST<K,V> ::rightla(Node *& croot)
{
 if((croot->right)==NULL) return croot;
 else return  rightla(croot->right);
}

/*
   Additional functions and helpers
*/

// keySort()
template <class K, class V>
vector<V> BST<K,V>::keySort() const {
    vector<V> vec;
	 sort(vec, root);
    return vec; // your code here, helpers are allowed
}

template <class K, class V>
void BST<K,V>::sort(vector<V> &vec, Node *  croot) const{
	if(croot==NULL) return;
   sort(vec, croot->left);
   vec.push_back(croot->value);
   sort(vec, croot->right);
	
}




// levelOrder()
template <class K, class V>
vector<V> BST<K,V>::levelOrder() const {

    vector<V> vec2;
    queue<Node*> que;
    que.push(root);

    while(!que.empty())
   {
   Node* A;
   A=que.front();
   que.pop();
   vec2.push_back(A->value);
   if(A->left!=NULL) que.push(A->left);
   if(A->right!=NULL) que.push(A->right);
   }
    return vec2; // your code here, helpers are allowed



}













