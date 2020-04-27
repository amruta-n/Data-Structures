#include<iostream>
using namespace std;
class Node
{
private:
    bool lb=1, rb=1;
    Node *right, *left;
    char data;
    friend class TBT;
};

class TBT
{
public:
    Node *root;
    Node *dummy;
    TBT()
    {
        root = NULL;
        dummy = NULL;
    }
    void create();
    void createTree(Node *root);
    void inOrder();
    Node *inOS(Node *temp);
    void preOrder();
};

void TBT :: create()
{
    char ch;
    root = new Node();
    dummy = new Node();
    dummy->right=dummy;
    dummy->left=root;
    root->right=root->left=dummy;
    cout<<"Enter root data:";
    cin>>root->data;
    dummy->lb=dummy->rb=0;
    root->lb=root->rb=1;
    
    
    do
    {   createTree(root);
        cout<<"Do you want to continue?(Y/N)";
        cin>>ch;
    }while(ch=='y'|ch=='Y');
}

void TBT :: createTree(Node *root)
{
    char side;
    Node *temp, *curr;
    temp = root;
    cout<<"\nWhere do you want to enter data?(L/R)";
    cin>>side;
    while(1){
    if(side == 'R' || side == 'r')
    {
        if(temp->rb==1)
        {
            temp->rb=0;
            curr = new Node;
            temp->right = curr;
            cout<<"\nEnter data:";
            cin>>curr->data;
            curr->right=temp->right;
            temp->right = curr;
            curr->left = temp;
            curr->lb = curr->rb =  1;
            break;
        }
        else{
            temp=temp->right;
        }
    }
    else if(side == 'L' || side == 'l')
    {
        if(temp->lb==1)
        {
            temp->lb=0;
            curr = new Node;
            temp->left = curr;
            cout<<"\nEnter data:";
            cin>>curr->data;
            curr->left= temp->left;
            temp->left=curr;
            curr->right = temp;
            curr->lb = curr->rb = 1;
            break;
        }
        else
        {
            temp=temp->left;
        }
    }
    }
}

void TBT :: inOrder()
{
    Node* temp;
    temp=dummy;
    while(1)
    {
        temp = inOS(temp);
        if(temp == dummy)
        {
            break;
        }
        cout<<"\t"<<temp->data;
    }
}

Node* TBT :: inOS(Node * temp)
{
    Node* t;
    t = temp->right;
    if(temp->rb==0)
    {
        while(t->rb==0)
        {
            t = t->left;
        }
    }
    return t;
}

void TBT :: preOrder()
{
    Node* temp;
    temp=dummy->left;
    while(temp!=dummy)
    {
        cout<<"\t"<<temp->data;
        while(temp->lb==0)
        {
            temp=temp->left;
            cout<<"\t"<<temp->data;

        }
        while(temp->rb==1)
        {
            temp=temp->right;
        }
        if(temp->rb==0)
        {
            temp=temp->right;
            
        }
    }
}

int main()
{
    TBT tree;
    tree.create();
    int c;
    do{
        cout<<"\n1]Pre-Order Display\t2]In-Order Display\t3]Exit\nEnter your choice:";
        cin>>c;
        switch (c)
        {
            case 1:
                cout<<"\nPreOrder Traversal:";
                tree.preOrder();
                break;
                
            case 2:
                cout<<"\nInOrder Traversal:";
                tree.inOrder();
                break;
        }
    }while(c==1||c==2);
    return 0;
}


/*-----------------------------OUTPUT------------------------------------
 
 */
