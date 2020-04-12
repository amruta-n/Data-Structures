#include<iostream>
using namespace std;


class Node
{
private:
    Node* right;
    Node* left;
    string key;
    string mean;
    friend class BST;
    friend class Queue;
};

class BST
{
    Node* root;
  public:
    BST()
    {
        root = NULL;
    }
    void create( );
    void pre(Node*root);
    void display_pre();
    void mirror_img( Node*root);
    void mirror_img_d( );
    Node* cop(Node *root);
    void del();
    void display();
    void cop_d();
    friend class Queue;
};

class Queue
{
public:
    int front = -1;
    int rear = -1;
    Node *ele[50];
    bool isEmpty();
    void insert(Node *a);
    Node *del();
};

bool Queue :: isEmpty()
{
        if(rear == front)
            return 1;
        else
            return 0;
}

void Queue :: insert(Node *a)
{
    
}

Node* Queue :: del()
{
    return ele[front++];
}

void BST :: create()
{
    root = new Node();
    char ch;
    cout<<"Enter root key:";
    cin>>root->key;
    cout<<"Enter it's meaning:";
    cin>>root->mean;
    root->left = root->right = NULL;
    Node* temp;
    do{
        
        temp = root;
        bool flag = 0;
        Node* curr = new Node();
        cout<<"Enter key:";
        cin>>curr->key;
        cout<<"Enter it's meaning:";
        cin>>curr->mean;
        //curr->left=curr->right= NULL;
        while(flag==0)
        {
            if(curr->key<temp->key)
            {
                if(temp->left == NULL)
                {
                    temp->left = curr;flag = 1;
                }
                else{
                    temp = temp->left;
                }
            }
            else
            {
                if(temp->right == NULL)
                {
                    temp->right = curr;flag = 1;
                }
                else{
                    temp = temp->right;
                }
            }
        }
        cout<<"Do you want to continue?(Y/N)";
        cin>>ch;
    }while(ch=='y'|| ch=='Y');
}


void BST :: pre(Node *root)
{
    if(root != NULL)
    {
        cout<<"\t"<<root->key<<":"<<root->mean;
        pre(root->left);
        pre(root->right);
    }
}

void BST :: display_pre()
{
    cout<<"\nPre-order:";
    pre(root);
}

void BST :: del()
{
    string key;
    cout<<"Enter the key to delete:";
    cin>>key;
    Node *par;
    Node *temp;
    Node *curr;
    temp = root;
    //search for key
    while(temp!=NULL)// && key!=temp->key)
    {
        if(key == temp->key)
        {
           // curr = temp;
            break;
        }
        else if(key<temp->key)
        {
            par = temp;
            temp = temp->left;
        }
        else
        {
            par = temp;
            temp = temp->right;
        }
            
  }//end of while
//KEY Found & stored in temp
   
//Deletion
    
    //Case1: Root deletion
    if (temp == root)
    {
        if(root->left == NULL)
        {
            root = root->right;
        }
        else if(root->right == NULL)
        {
            root = root->left;
        }
        else if(root->right!=NULL && root->left!=NULL)
        {
            curr = root->left;
            root = root->right;
            if(root->left == NULL)
            {
                root->left = curr;
            }
            else if(root->left!=NULL)
            {
                Node *temp1 = root->left;
                while(temp1!=NULL)
                {
                    temp1 = temp1->left;
                }
                temp1->left = curr;
            }
        }
    }
    else
    {
        //Case2 : Leaf deletion
        if(temp->left == NULL && temp->right == NULL)
        {
            if(temp == par->left)
            {
                par->left = NULL;
            }
            else if(temp == par->right)
            {
                par->right = NULL;
            }
        }
        
        //Case3: One child
        else if(temp->left != NULL && temp->right == NULL)
        {
            if(temp == par->left)
            {
                par->left = temp->left;
            }
            else if(temp == par->right)
            {
                par->right = temp->left;
            }
        }
        
        else if(temp->left == NULL && temp->right != NULL)
        {
            if(temp == par->left)
            {
                par->left = temp->right;
            }
            else if(temp == par->right)
            {
                par->right = temp->right;
            }
        }
        
        //Case4: Two children
        else if(temp->left != NULL && temp->right != NULL)
        {
            Node *tl, *tr;
            tl = temp->left;
            tr = temp->right;
            while(tr->left!=NULL)
            {
                tr = tr->left;
            }
            tr->right = tl;
            if(temp == par->left)
            {
                par->left = tr;
            }
            else if(temp == par->right)
            {
                par->right = tr;
            }
        }
        
    }//end of else
}

void BST :: mirror_img( Node*root)
{
    Node *curr;
    if(root!=NULL)
    {
        curr = root->left;
        root->left = root->right;
        root->right = curr;
        mirror_img(root->left);
        mirror_img(root->right);
    }
}

void BST :: mirror_img_d()
{
    cout<<"\nMirror:";
    mirror_img(root);
    pre(root);
}

Node* BST :: cop(Node *root)
{
    Node* temp = NULL;
    if(root!= NULL)
    {
        temp = new Node();
        temp->key = root->key;
        temp->mean = root->mean;
        temp->left = cop(root->left);
        temp->right = cop(root->right);
    }
    return temp;
}

void BST :: cop_d()
{
    cout<<"\nCopy:";
    Node* temp1 = cop(root);
    pre(temp1);
}

int main()
{
    BST tree;
    tree.create();
    tree.del();
    tree.display_pre();
    tree.mirror_img_d();
    tree.cop_d();
    
    return 0;
}
