#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n){
	map<int,int> mp;
	for(int i=0;i<n;i++){
		mp[arr[i]]++;
	}
	int j=0;
	for(auto var: mp){
		for(int x=0;x<var.second;x++){
			arr[j] = var.first;
			j++;
		}
	}
}

int main(){
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the array: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	countSort(arr,n);
	cout<<"Sorted Array: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
