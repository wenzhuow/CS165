// C++ program to insert a node in AVL tree 
#ifndef avltree_best
#define avltree_best
#include<bits/stdc++.h> 
using namespace std; 






// An AVL tree node 
class Node 
{ 
	public: 
	
	int index;
	double remain_cap;
	double best_cap;
	Node *left; 
	Node *right; 
	int height; 

  	// ~Node()
  	// {  
  	// 	Clear();
  	// }

  	// void Clear() 
  	// {
   //  	Clear(left);
  	// 	Clear(right);
  	// }
}; 

void clear_tree(Node *root) 
	{
	if (!root)
  		return;
	if (root->left)
  		clear_tree(root->left);
	if (root->right)
  		clear_tree(root->right);
	delete root;
	root = nullptr;
	}



// A utility function to get maximum 
// of two integers 
int max(int a, int b); 

// A utility function to get the 
// height of the tree 
int height(Node *N)
{ 
  if (N == nullptr) 
    return 0; 
  return N->height; 
} 


void preOrder(Node *root) 
{ 
  	if(root != nullptr) 
  	{ 
    	cout <<"  root " <<root->height<<root->remain_cap;
    	// <<" "<<root->index << " "<<" "; 
    	preOrder(root->left); 
    	preOrder(root->right); 
  	} 
} 


// A utility function to get maximum 
// of two integers 
int max(int a, int b) 
{ 
  return (a > b)? a : b; 
} 

/* Helper function that allocates a 
new node with the given key and 
NULL left and right pointers. */
Node* newNode(int index,double remain_cap) 
{ 
  	Node* node = new Node(); 
  	node->index = index; 
  	node->remain_cap = remain_cap; 
  	// node->best_cap = best_cap; 
  	node->left = nullptr; 
  	node->right = nullptr; 
  	node->height = 1; // new node is initially 
          // added at leaf 
  	return node; 
} 

// A utility function to right 
// rotate subtree rooted with y 
// See the diagram given above. 
Node *rightRotate(Node *y) 
{ 
  	Node *x = y->left; 
  	Node *T2 = x->right; 

  	// Perform rotation 
  	x->right = y; 
  	y->left = T2; 
  	// Update heights 
  	y->height = max(height(y->left), 
          height(y->right)) + 1; 
  	x->height = max(height(x->left), 
          height(x->right)) + 1; 

  	// Return new root 
  	return x; 
} 

// A utility function to left 
// rotate subtree rooted with x 
// See the diagram given above. 
Node *leftRotate(Node *x) 
{ 
  	Node *y = x->right; 
  	Node *T2 = y->left; 
  
  	// Perform rotation 
  	y->left = x; 
  	x->right = T2; 
  	// Update heights 
  	x->height = max(height(x->left),   
          height(x->right)) + 1; 
  	y->height = max(height(y->left), 
          height(y->right)) + 1; 

  	// Return new root 
  	return y; 
} 

// Get Balance factor of node N 
int getBalance(Node *N) 
{ 
  	if (N == nullptr) 
    	return 0; 
  	return height(N->left) - height(N->right); 
} 

// A utility function to print preorder 
// traversal of the tree. 
// The function also prints height 
// of every node 



// Recursive function to insert a key 
// in the subtree rooted with node and 
// returns the new root of the subtree. 
Node* insert(Node*& node, int i,double rc) 
{ 
  /* 1. Perform the normal BST insertion */
	if (node == nullptr) 
    {
    	return newNode(i,rc); 
	}
 	if (rc < node->remain_cap) 
 	{
		node->left = insert(node->left, i,rc); 
  	}
  	else if (rc > node->remain_cap)
  	{
    	node->right = insert(node->right, i,rc); 
  	}
  	else // Equal keys are not allowed in BST 
  	{
    	return node; 
  	}
  	/* 2. Update height of this ancestor node */
  	node->height = 1 + max(height(node->left), 
            height(node->right)); 

  	/* 3. Get the balance factor of this ancestor 
  	node to check whether this node became 
    unbalanced */
  	int balance = getBalance(node); 


  	// If this node becomes unbalanced, then 
  	// there are 4 cases 
  	// Left Left Case 

  	if (balance > 1 && getBalance(node->left)>=0) 
    {
    	return rightRotate(node); 
    }

  	// Right Right Case 
  	if (balance < -1 && getBalance(node->right)<=0) 
   	{
   		return leftRotate(node); 
   	}
  	// Left Right Case 
  	if (balance > 1 && getBalance(node->left)<0) 
  	{ 
    	node->left = leftRotate(node->left);
    	return rightRotate(node); 
  	} 

  	// Right Left Case 
  	if (balance < -1 && getBalance(node->right)>0) 
  	{ 
    	node->right = rightRotate(node->right);
    	return leftRotate(node); 
  	} 
  	// if (balance > 1 && rc < node->left->remain_cap) 
   //  {
   //  	return rightRotate(node); 
   //  }

  	// // Right Right Case 
  	// if (balance < -1 && rc > node->right->remain_cap) 
   // 	{
   // 		return leftRotate(node); 
   // 	}
  	// // Left Right Case 
  	// if (balance > 1 && rc > node->left->remain_cap) 
  	// { 
   //  	node->left = leftRotate(node->left);
   //  	return rightRotate(node); 
  	// } 

  	// // Right Left Case 
  	// if (balance < -1 && rc < node->right->remain_cap) 
  	// { 
   //  	node->right = rightRotate(node->right);
   //  	return leftRotate(node); 
  	// } 
  	/* return the (unchanged) node pointer */
  	return node; 
} 



Node * minValueNode(Node* node) 
{ 
    Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != nullptr) 
        current = current->left; 
  
    return current; 
} 
  


Node* deleteNode(Node* root, double key) 
{ 
    // base case
    if (root == nullptr) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->remain_cap) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->remain_cap) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (!root->left && !root->right)
        {
        	delete root;
            root = nullptr;
        }
        else if (root->left == nullptr) 
        { 
            Node *temp = root;
            root = root->right; 
            delete temp;
            temp=nullptr;
        } 
        else if (root->right == nullptr) 
        { 
            Node *temp = root; 
            root = root->left;
            delete temp;
            temp=nullptr;
        } 
  		else
  		{
	        // node with two children: Get the inorder successor (smallest 
	        // in the right subtree) 
	        Node* temp = minValueNode(root->right); 
	  
	        // Copy the inorder successor's content to this node 
	        root->remain_cap = temp->remain_cap; 
	  
	        // Delete the inorder successor 
	        root->right = deleteNode(root->right, temp->remain_cap); 
    	}
    }
    if (!root)
    	return nullptr;

  	int balance = getBalance(root); 

  	// If this node becomes unbalanced, then 
  	// there are 4 cases 
  	// Left Left Case 
  	if (balance > 1 && getBalance(root->left)>=0) 
    {
    	return rightRotate(root); 
    }

  	// Right Right Case 
  	if (balance < -1 && getBalance(root->right)<=0) 
   	{
   		return leftRotate(root); 
   	}
  	// Left Right Case 
  	if (balance > 1 && getBalance(root->left)<0) 
  	{ 
    	root->left = leftRotate(root->left);
    	return rightRotate(root); 
  	} 

  	// Right Left Case 
  	if (balance < -1 && getBalance(root->right)>0) 
  	{ 
    	root->right = rightRotate(root->right);
    	return leftRotate(root); 
  	} 
  	/* return the (unchanged) node pointer */
  	return root; 
} 



#endif /* avltree_best */