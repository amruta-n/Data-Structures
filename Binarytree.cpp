#include <iostream>
using namespace std;


//Class Node with a data
class Node
{
private:
    char data;
    Node *left;
    Node *right;
    friend class Tree;
    friend class Stack;
};

class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    void createRoot();
    void createTree_r(Node *root);
    void pre(Node *root);
    void display_pre();
    void in(Node *root);
    void display_in();
    void post(Node *root);
    void display_post();
    void pre_nr(Node *root);
    void display_pre_nr();
    void in_nr(Node *root);
    void display_in_nr();

    friend class Stack;
};
class Stack
{
public:
    int top;
    Node *st[30];
    
    Stack()
    {
        top = -1;
    }
    void push(Node *e);
    Node* pop();
    bool isEmpty();
    friend class Tree;
};

void Stack :: push(Node *e)
{
    if(top == 29)
    {
        cout<<"Stack is full!!!";
    }
    else
    {
        top++;
        st[top]=e;
    }
}

bool Stack :: isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Node* Stack :: pop()
{
    if(isEmpty()==0)
    {
        return st[top--];
    }
    else{
        return NULL;
    }
}

void Tree :: createRoot()
{
    root = new Node();
    char choice;
    cout<<"\nEnter the root data:";
    cin>>root->data;
    root->left = NULL;
    root->right = NULL;
    do
    {
        createTree_r(root);
        cout<<"\nDo you want to enter further data?(Y/N)";
        cin>>choice;
    }while (choice == 'y' || choice == 'Y');
}

void Tree :: createTree_r(Node *root)
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
            curr = new Node;
            temp->right = curr;
            cout<<"\nEnter data:";
            cin>>curr->data;
            curr->right = curr->right =  NULL;
        }
        else{
            createTree_r(temp->right);
        }
    }
    else if(side == 'L' || side == 'l')
    {
        if(temp->left == NULL)
        {
            curr = new Node;
            temp->left = curr;
            cout<<"\nEnter data:";
            cin>>curr->data;
            curr->left = curr->right =  NULL;
        }
        else{
            createTree_r(temp->left);
        }
    }
    else
    {
        cout<<"\nInvalid Entry";
    }
}

void Tree :: pre(Node *root)
{
    if(root != NULL)
    {
        cout<<"\t"<<root->data;
        pre(root->left);
        pre(root->right);
    }
}

void Tree :: display_pre()
{
    cout<<"\nPre-order:";
    pre(root);
}


void Tree :: post(Node *root)
{
    if(root!=NULL)
    {
        post(root->left);
        post(root->right);
        cout<<"\t"<<root->data;
    }
}

void Tree :: display_post()
{
    cout<<"\nPost-order:";
    post(root);
}


void Tree :: in(Node *root)
{
    if(root!=NULL)
    {
        in(root->left);
        cout<<"\t"<< root->data;
        in(root->right);
    }
}

void Tree :: display_in()
{
    cout<<"\nIn-order:";
    in(root);
}

void Tree :: in_nr(Node *root)
{
    Node *temp;
    temp = root;
    Stack st;
    while(1)
    {
        while(temp!=NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        if(st.isEmpty()==1)
        {
            break;
        }
        temp = st.pop();
        cout<<"\t"<<temp->data;
        temp = temp->right;
    }
}

void Tree :: display_in_nr()
{
    cout<<"\nIn-order(Non-Recursive):";
    in_nr(root);
}

void Tree :: pre_nr(Node *root)
{
    Node *temp;
    temp = root;
    Stack st;
    while(1)
    {
        while(temp!=NULL)
        {
            st.push(temp);
            cout<<"\t"<<temp->data;
            temp = temp->left;
        }
        if(st.isEmpty()==1)
        {
            break;
        }
        temp = st.pop();
        
        temp = temp->right;
    }
}

void Tree :: display_pre_nr()
{
    cout<<"\nPre-order(Non-Recursive):";
    pre_nr(root);
}


int main()
{
    Tree t;
    t.createRoot();
    t.display_pre();
    cout<<endl;
    t.display_in();
    cout<<endl;
    t.display_post();
    cout<<endl;
    cout<<"============Non-recursive=========";
    t.display_in_nr();
    cout<<endl;
    t.display_pre_nr();
    cout<<endl;
    return 0;
}

/*Output:
 Enter the root data:R
 
 Where do you want to enter data?(L/R)l
 
 Enter data:l
 
 Do you want to enter further data?(Y/N)y
 
 Where do you want to enter data?(L/R)r
 
 Enter data:r
 
 Do you want to enter further data?(Y/N)n
 
 Pre-order:    R    l    r
 
 In-order:    l    R    r
 
 Post-order:    l    r    R
 ============Non-recursive=========
 In-order(Non-Recursive):    l    R    r
 
 Pre-order(Non-Recursive):    R    l    r
 
 Post-order(Non-Recursive):    l    r    R*/



