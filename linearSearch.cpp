/*LINEAR SEARCH
Time Complexity: O(N)
Algorithm Logic:
Traverse sequentially through array to find the key and return 
its index else return -1.*/

//CODE
#include<iostream>
using namespace std;

int linearSearch(int a[], int n, int key){
	for(int i=0; i<n; i++){
		if(a[i]==key){
			return i;
		}
	}
	return -1;
}

int main(){
	int n=10, a[10], key, index;
	cout<<"\nEnter elements of array:\n";
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<"\nEnter the key:";
	cin>>key;
	index=linearSearch(a, n, key);
	if(index==-1){
		cout<<"\nElement does not exist in the array!\n";
	}else{
		cout<<"\nThe index of the key is "<<index<<endl;
	}
	return 0;
}

//OUTPUT
/*
---Case1:
Enter elements of array:
1
2
3
4
5
6
7
8
9
12

Enter the key:12

The index of the key is 9

---Case2:
Enter elements of array:
1
2
2
3
4
5
5
6
7
8

Enter the key:9

Element does not exist in the array!

*/