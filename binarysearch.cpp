/*BINARY SEARCH
Time Complexity: O(logN)
Algorithm Logic:
Assign beginning, middle and end element of array. If key==mid then return mid,
if key <mid then search in first half by assigning mid-1 as end and calculate mid again.
If key is in second half of the array then begining=mid+1 and repeat. Keep doing this till
key is found or beg<=end. If not found return -1.*/

//CODE
#include<iostream>
using namespace std;

int binarySearch(int a[], int n, int key){
	int beg=0;
	int mid;
	int end=n-1;
	while(beg<=end){
		mid= beg+(end-beg)/2;
		if(a[mid]==key){
			return mid;
		}else if(a[mid]>key){
			end=mid-1;
		}else if(a[mid]<key){
			beg=mid+1;
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
	index=binarySearch(a, n, key);
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
11

Enter the key:11

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