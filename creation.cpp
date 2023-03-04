#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// declearing structure 
class node{
    public:
       int data;
       node *left;
       node *right;

        node(int d) {
           this->data=d;
           this->left=NULL;
           this->right=NULL;
    }

};
node* buildtree(node* root){
    cout<<"Enter data for root node"<<endl;
    cout<<"Enter the data "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data==-1)
        return NULL;
    cout<<"Enter data for inserting in left of "<<data<<endl;  
     root->left = buildtree(root->left);
     cout<<"Enter data for inserting in right of "<<data<<endl;
     root->right = buildtree(root->right);
     return root; 

    
}
void levelorder(node *root){
   queue<node*> q;
   q.push(root);
   q.push(NULL);

   while(!q.empty()){
    node *temp = q.front();
    // cout<<temp->data<<" ";
    q.pop();
    
    if(temp == NULL){// purana wala complete ho chuka hai
    cout<<endl;
    if(!q.empty()){ //queue has still some data
    q.push(NULL);

    }
    }
    else {
        cout<<temp->data<<" ";
        if(temp->left){
        q.push(temp->left);
    }
    if(temp->right)
    {
        q.push(temp->right);
    }

    }

    
   }
}
void inorder(node *root){
    //base case
    if(root==NULL)
       return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
void preorder(node* root){
     //base case
    if(root==NULL)
       return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void postorder(node * root){
     //base case
    if(root==NULL)
       return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
node * buildfromlevelorder(node * root){
    queue<node> q;
    cout<<"Enter data for root node "<<endl;
    int data;
    cin>>data;
    root= new node(data);
    q.push(root);

    while(!q.empty()){
       node * temp= q.front(); 
       
    }

}
int main()
{
   node *root=NULL;
  
   //create a tree
   root = buildtree(root);


   // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    // level order
    // cout<<"Printing levelorder traversal: "<<endl;
    // levelorder(root);
    
    cout<<"Printing inorder"<<endl;
    inorder(root);

    cout<<"\nPrinting preorder"<<endl;
    preorder(root);

    cout<<"\nPrinting postorder"<<endl;
    postorder(root);

// new node = root;

    return 0;
}