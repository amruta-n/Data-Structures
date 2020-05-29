#include <iostream>
using namespace std;
#define max 30

class Heap
{
public:
    int a[max], b[max], n;
    void accept();
    void insert(int array[max], int index);
    void display();
    void sort();
    void adjust(int array[max], int size, int i);
    Heap()
    {
        cout<<"\nEnter number of students:";
        cin>>n;
        a[0]=999;
        for(int i = 1; i<=n; i++)
        {
            a[i] = 0;
        }
    };
};

void Heap::accept()//accepts student's marks
{
    for(int i=1; i<=n; i++)
    {
        cout<<"\nEnter the marks:";
        cin>>a[i];
        insert(a, i);
    }
}

void Heap::insert(int a[max], int i)//inserts the marks in the max heap
{
    //int j=i;
    int ele=a[i];
    while(ele>a[i/2] && i>1)
    {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=ele;
}

void Heap::sort()//function to obtain the marks in descending order
{
    int temp;
    cout<<"\nThe marks of the students in decreasing order:";
    b[1]=a[1];
    while(n>1)
    {
        temp = a[n];
        a[n]=a[1];
        a[1]=temp;
        cout<<"\n"<<a[n];
        n--;
        adjust(a, n, 1);
    }
    cout<<"\n"<<a[n];
    b[0]=a[n];
}

void Heap::adjust(int a[max], int n, int i)//make adjustments to keep max heap even after deletion of node
{
    int j;
    while(2*i <= n)//to reduce iterations by not comparing leaf nodes
    {
        j = 2*i;
        if((j+1)<=n && a[j]<a[j+1])//to prevent comparison with garbage values when child not present
        {
            j = j+1;
        }
        if(a[i] > a[j])
        {
            break;
        }
        if(a[i] < a[j])
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i=j;//to repeat the comparison for further nodes
        }
    }
}


void Heap::display()
{
    cout<<"\nThe highest score is:"<<b[1];
    cout<<"\nThe lowest score is:"<<b[0];
}



int main()
{
    Heap heap;
    heap.accept();
    heap.sort();
    heap.display();
    return 0;
}

/*OUTPUT:
 Enter number of students:6
 
 Enter the marks:36
 
 Enter the marks:19
 
 Enter the marks:49
 
 Enter the marks:3
 
 Enter the marks:33
 
 Enter the marks:25
 
 The marks of the students in decreasing order:
 49
 36
 33
 25
 19
 3
 The highest score is:49
 The lowest score is:3
 */
