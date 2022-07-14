#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left, *right;

    Node(int value){
        val=value;
        left=right=NULL;
    }
};

    void preorder(Node* root){
        if(!root) return;
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }

        void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }

        void postorder(Node* root){
        if(!root) return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }

//Build Tree from Preorder and Inorder Array

int search(int inorderA[], int s, int e, int curr){
    for(int i=s; i<=e; i++){
        if(inorderA[i]==curr)
            return i;
    }
    return -1;
}

Node* buildTreePreIn(int preorderA[], int inorderA[], int s, int e){
    static int idx=0;
    if(s>e) return NULL;

    int curr=preorderA[idx];
    idx++;
    Node* node = new Node(curr);

    int pos=search(inorderA, s, e, curr);
    node->left = buildTreePreIn(preorderA, inorderA, s, pos-1);
    node->right = buildTreePreIn(preorderA, inorderA, pos+1, e);
    return node;
}
/////////


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //Tree Creation
    // struct Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    // preorder(root);
    // cout<<endl;
    // inorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;

    //Build Tree from Preorder and Inorder array
    int preorderA[] ={1,2,4,3,5};
    int inorderA[] ={4,2,1,5,3};

    Node* node = buildTreePreIn(preorderA, inorderA, 0,4);
    inorder(node);

}