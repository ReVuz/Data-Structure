#include<iostream>
using namespace std;


class node {

public:
	int data;
	node* left;
	node* right;
};
node* create_root(int data) {
	node* newNode = new node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;

}
node* insert(node* root, int data) {
	if (root == NULL) {
		root = create_root(data);
	}
	else if (data <= root->data) {
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}
	return root;
	cout << "\nValue added successfully" << endl;
}
bool Search(node* root, int data) {
	if (root == NULL) {
		return false;
	}
	else if (root->data == data) {
		return true;
	}
	else if (data <= root->data) {
		return Search(root->left, data);
	}
	else {
		return Search(root->right, data);
	}
}

node* findMin(node* root) {
	node* current = root;
	if (root == NULL) {
		cout << "Error Caught : Tree is Empty!" << endl;
		return 0;
	}
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

node* findMax(node* root) {
	while (root->right != NULL) {
		root = root->right;
	}
	return root;
}

node* del(node* root, int data) {
	if (root == NULL) {
		return root;
	}
	else if (data < root->data) {
		root->left = del(root->left, data);
	}
	else if (data > root->data) {
		root->right = del(root->right, data);
	}
	else {
		//Case 1 : No Child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2 : One Child
		else if (root->left == NULL) {
			node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			node* temp = root;
			root = root->left;
			delete temp;
		}
		//Case 3 : Two Children
		else {
			node* temp = findMin(root->right);
			root->data = temp->data;
			root->right = del(root->right, temp->data);
		}
	}
	return root;
}
void Preorder(node* root) {
	//DLR
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);


}
void Inorder(node* root) 
{
	//LDR

	if (root == NULL)
		return;
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}
void Postorder(node* root)
{
	//LRD

	if (root == NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << " ";
}

int findHeight(node* root) {
	int leftHeight, rightHeight;
	if (root == NULL) {
		return 0;
	}
 	else {
		leftHeight = findHeight(root->left);
		rightHeight = findHeight(root->right);
	}
	return (max(leftHeight, rightHeight)+ 1);
}

    void print2D(node* r, int space) {
        if (r == NULL) // Base case  1
            return;
        space += 2; // Increase distance between levels   2
        print2D(r->right, space); // Process right child first 3 
        cout << endl;
        for (int i = 2; i < space; i++) // 5 
            cout << " "; // 5.1  
        cout << r->data << "\n"; // 6
        print2D(r->left, space); // Process left child  7
    }

int main() {
	node* root = NULL;	//Empty Tree Created
	int ans,num;
		do {
			cout << "\nBinary Tree Operations "
				"\nChoose any option from Below" << endl;
			cout << "1. Insert Node\n2. Search Node "
				"\n3.Delete Node\n4.Find Minimum and Maximum value"
				"\n5.Find Height of Tree"
				"\n6. Tree Traversal\n0.Exit " << endl;
			cin >> num;
			switch (num)
			{
			case 1:
				int node;
				cout << "Enter a value to insert : ";
				cin >> node;
				root = insert(root, node);
				break;
			case 2:
				int value;
				cout << "Enter a value to search : ";
				cin >> value;
				if (Search(root, value) == true)cout << "Value Found!" << endl;
				else cout << "Value Not Found!" << endl;
				break;
			case 3 :
				cout << "Enter the value to delete : ";
				int var;
				cin >> var;
				if (Search(root, var) == true) {
					root = del(root, var);
					cout << "Value deleted Successfully" << endl;
				}
				else {
					cout << "Value Not Found" << endl;
				}
				
			case 4:
				cout << "Minimum value : " << findMin(root) << endl;
				cout << "Maximum value : " << findMax(root) << endl;
				break;
			case 5 :
				cout << "Height of Tree : " << findHeight(root) << endl;
				break;
			case 6 :
				print2D(root, 2);
				cout << "\n1. Inorder Traversal : ";
				Inorder(root);
				cout << "\n2. Preorder Traversal : ";
				Preorder(root);
				cout << "\n3. Postorder Traversal : ";
				Postorder(root);
				break;
			default:
				break;
			}
			cout << "\nDo you want to continue(1/0) : ";
			cin >> ans;
		} while (ans);
	cout << "Thank you" << endl;
}
