#include<iostream>
using namespace std;
#define max 30

//Class containing matrix and all necessary functions for prims algorithm
class Prims
{
public:
    int nv;
    int mat[max][max];
    void create_adjointMatrix();
    void main_prims();
    
    Prims()//Constructor to initialize the matrix
    {
        cout<<"Enter the number of vertices:";
        cin>>nv;//number of vertices in graph
        for(int i=0; i<max; i++)
        {
            for(int j=0; j<max; j++)
            {
                mat[i][j]=-1;
            }
        }
    };
};

//Function that takes input and creates matrix
void Prims::create_adjointMatrix()
{
    
    for(int i=0; i<nv; i++)//entering path values in matrix
    {
        for(int j=0; j<nv; j++)
        {
            if(mat[i][j]==-1)
            {
                cout<<"\nEnter path length between "<<i<<" & "<<j<<" (if path doesnt exist enter 999):";
                cin>>mat[i][j];
                mat[j][i]=mat[i][j];
            }
        }
    }
    cout<<"\nAdjoint Matrix:";
    for(int i=0; i<nv; i++)//Displaying the matrix
    {
        cout<<"\n";
        for(int j=0; j<nv; j++)
        {
            cout<<mat[i][j];
            cout<<"\t";
        }
    }
}



void Prims :: main_prims()
{
    int st, newVisit,cost=0;
    int nearest[nv];//records visited vertices and nearest vertices for non-visited vertices
    cout<<"\nEnter starting vertex:";
    cin>>st;//accept starting vertex
    nearest[st] = -1;//mark visited by -1
    for(int i = 0; i<nv; i++)
    {
        if(i!=st)
        {
            nearest[i]=st;//set nearest vertex as starting vertex for all vertices except stv
        }
    }
    int min;
    for (int i = 0; i<nv-1; i++)//for source vertex
    {
        min=9999;
        for(int j= 0; j<nv; j++)//for destination vertex
        {
            if(nearest[j]!=-1 && mat[i][j]<min)//compares all vertices except for itself
            {
                newVisit=j;//stores newly visited vertex with least cost from source vertex(i)
                min=mat[i][j];
            }
        }
        cout<<"\nedge between "<<nearest[newVisit]<<" & "<<newVisit<<" selected--->cost="<<mat[nearest[newVisit]][newVisit];
        cost = cost + mat[nearest[newVisit]][newVisit];
        nearest[newVisit]=-1;
        for(int k= 0; k<nv; k++)
        {
            if(nearest[k]!=-1 && mat[nearest[k]][k]>mat[newVisit][k])//to update nearest mztrix with new  nearest vertex
            {
                nearest[k]=newVisit;
            }
        }
    }
    cout<<"\nThe minimun cost is: "<<cost;
}

int main ()
{
    Prims prim;
    prim.create_adjointMatrix();
    prim.main_prims();
    return 0;
}

/*OUTPUT:
 Enter the number of vertices:3
 
 Enter path length between 0 & 0 (if path doesnt exist enter 999):999
 
 Enter path length between 0 & 1 (if path doesnt exist enter 999):1
 
 Enter path length between 0 & 2 (if path doesnt exist enter 999):2
 
 Enter path length between 1 & 1 (if path doesnt exist enter 999):999
 
 Enter path length between 1 & 2 (if path doesnt exist enter 999):3
 
 Enter path length between 2 & 2 (if path doesnt exist enter 999):999
 
 Adjoint Matrix:
 999    1    2
 1    999    3
 2    3    999
 Enter starting vertex:0
 
 edge between 0 & 1 selected--->cost=1
 edge between 0 & 2 selected--->cost=2
 The minimun cost is: 3
 */
