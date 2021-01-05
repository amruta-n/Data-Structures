#include<iostream>
using namespace std;

void insertionsort(int a[], int n){
	int i, j, key;
	for(i=1; i<n; i++){
		key=arr[i];
		j=i-1;
		while(j>=0 && a[j]>key){
			arr[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}

int main{
	int a[100], n;
	cout<<"Enter number of elements in array:";
	cin>>n;
	cout<<"\nEnter array elements:"<<endl;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	insertionsort(a, n);
	cout<<"\nThe sorted array is:"<<endl;
	for(int i=0; i<n; i++){
		cout<<a[i]<<endl;
	}
}