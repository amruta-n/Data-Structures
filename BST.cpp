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
    void mirror_img( Node*root);
    void mirror_img_d( );
    Node* cop(Node *root);
    void del();
    void display();
    void cop_d();
    void search();
    void disp(Node *root);
    void d_disp();
    void pre(Node *root);
    void display_pre();
    void in(Node *root);
    void display_in();
    void post(Node *root);
    void display_post();
    friend class Queue;
};

class Queue
{
public:
    int front = -1;
    int rear = 0;
    Node *ele[50];
    bool isEmpty();
    void insert(Node *a);
    Node *dele();
};

bool Queue :: isEmpty()
{
    if(front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Queue :: insert(Node *a)
{
    if(front==49)
    {
        cout<<"Queue full!";
    }else
    {
        front++;
        ele[front] = a;
    }
    
    
}

Node* Queue :: dele()
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

void BST :: search()
{
    string key;
    cout<<"Enter the key to search:";
    cin>>key;
    Node *par;
    Node *temp;
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
    }
    cout<<temp->key<<":"<<temp->mean;
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


void BST :: disp(Node *root)
{
    Node *temp;
    Queue Q;
    Q.insert(root);
    while(!Q.isEmpty())
    {
        temp = Q.dele();
        cout<<"\t"<<temp->key<<":"<<temp->mean;
        if(temp->left!=NULL)
        {
            Q.insert(temp->left);
        }
        else if(temp->right!=NULL)
        {
            Q.insert(temp->right);
        }
    }
}

void BST :: d_disp()
{
    cout<<"\nLevel-wise display: ";
    disp(root);
}

void BST :: pre(Node *root)
{
    if(root != NULL)
    {
        cout<<"\t"<< root->key<<":"<<root->mean;
        pre(root->left);
        pre(root->right);
    }
}

void BST :: display_pre()
{
    cout<<"\nPre-order:";
    pre(root);
}


void BST :: post(Node *root)
{
    if(root!=NULL)
    {
        post(root->left);
        post(root->right);
        cout<<"\t"<< root->key<<":"<<root->mean;
    }
}

void BST :: display_post()
{
    cout<<"\nPost-order:";
    post(root);
}


void BST :: in(Node *root)
{
    if(root!=NULL)
    {
        in(root->left);
        cout<<"\t"<< root->key<<":"<<root->mean;
        in(root->right);
    }
}

void BST :: display_in()
{
    cout<<"\nIn-order:";
    in(root);
}


int main()
{   int c;
    BST tree;
    tree.create();
    do{
    cout<<"\n1>Level-wise Display\n2>Display Inorder, Preorder and postorder \n3>Mirror Image\n4>Copy\n5>Delete\n6>Search\n7>Exit";
    cout<<"\nEnter choice:";
    cin>>c;
    
    switch(c)
    {
            case 1 :
            tree.d_disp();
            break;
            
        case 2 :
            tree.display_pre();
            cout<<endl;
            tree.display_in();
            cout<<endl;
            tree.display_post();
            cout<<endl;
            
            break;
            
        case 3 :
            tree.mirror_img_d();
            break;
            
        case 4 :
            tree.cop_d();
            break;
            
        case 5 :
            tree.del();
            break;
            
        case 6 :
            tree.search();
            break;
    }
    }while(c==1 || c==2||c==3||c==4|| c==5|| c==6);
    
    
   
    return 0;
}
