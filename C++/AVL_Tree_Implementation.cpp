/**AVL Tree Implementation**/

//T1, T2 and T3 are subtrees of the tree rooted with y (on the left side) or x (on the right side).       
//			 y                               x
//			/ \     Right Rotation          /  \
//		   x   T3   - - - - - - - >        T1   y 
//		  / \       < - - - - - - -            / \
//		 T1  T2     Left Rotation            T2  T3
//Keys in both of the above trees follow the following order: keys(T1) < key(x) < keys(T2) < key(y) < keys(T3).
//So BST property is not violated anywhere.

#include <iostream> 
using namespace std; 

class Node {
	int key, height;
	Node *left, *right;
	
	int getHeight(Node*);
	int getBalance(Node*);
	Node* rightRotate(Node*);
	Node* leftRotate(Node*);
		
public:

	Node(int key) {
		this->key = key;
		this->height = 1;
		this->left = NULL;  
		this->right = NULL;
	}

	Node* insert(Node*, int);
	void inOrder(Node*);
};

int Node::getHeight(Node *root) {  
    if (!root)  
        return 0;  
    return root->height;  
}

int Node::getBalance(Node *root) {  
    if (!root)  
        return 0;  
    return getHeight(root->left) - getHeight(root->right); 
} 
 
Node* Node::rightRotate(Node *y) {  
    Node *x = y->left;  
    Node *T2 = x->right;  

    x->right = y;  
    y->left = T2;  

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
	
    return x;  
}  
  
Node* Node::leftRotate(Node *x) {  
    Node *y = x->right;  
    Node *T2 = y->left;  
  
    y->left = x;  
    x->right = T2;  

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
	y->height = 1 + max(getHeight(y->left), getHeight(y->right));  	
 
    return y;  
}  
 
Node* Node::insert(Node* root, int newKey) {  
    if (!root)  
        return(new Node(newKey));  
  
    if (newKey < root->key)  
        root->left = insert(root->left, newKey);  
    else if (newKey > root->key)  
        root->right = insert(root->right, newKey);  
    else 
        return root;  

    root->height = 1 + max(getHeight(root->left), getHeight(root->right)); 

    int balance = getBalance(root);   

    if (balance > 1 && newKey < root->left->key)  
        return rightRotate(root);  

    if (balance < -1 && newKey > root->right->key)  
        return leftRotate(root);  

    if (balance > 1 && newKey > root->left->key) {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
 
    if (balance < -1 && newKey < root->right->key) {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }

    return root;  
}  

void Node::inOrder(Node *root) {  
    if (root) {
        inOrder(root->left);
		cout << root->key << " ";  		
        inOrder(root->right);  
    }  
}  

int main() {  
    Node *root = NULL;
    root = root->insert(root, 10);  
    root = root->insert(root, 20);  
    root = root->insert(root, 30);  
    root = root->insert(root, 40);  
    root = root->insert(root, 50);  
    root = root->insert(root, 25);  

    cout << "Inorder traversal of the constructed AVL tree is:" << endl;  
    root->inOrder(root);  

    return 0;  
}
