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
    Node *root, *dummy;
    TBT()
    {
        root = NULL;
        dummy = NULL;
    }
    void create(Node *root);
    void createTree(Node *root);
};

void TBT :: create(Node *root)
{
    char ch;
    cout<<"Enter root data:";
    cin>>root->data;
    root->left=root->right=NULL;
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
    if(side == 'R' || side == 'r')
    {
        if(temp->right == NULL)
        {
            temp->rb=0;
            curr = new Node;
            temp->right = curr;
            cout<<"\nEnter data:";
            cin>>curr->data;
            curr->left = curr->right =  NULL;
        }
        else{
            createTree(temp->right);
        }
    }
    else if(side == 'L' || side == 'l')
    {
        if(temp->left == NULL)
        {
            temp->lb=0;
            curr = new Node;
            temp->left = curr;
            cout<<"\nEnter data:";
            cin>>curr->data;
            curr->left = curr->right =  NULL;
        }
        else{
            createTree(temp->left);
        }
    }
    else
    {
        cout<<"\nInvalid Entry";
    }
}

