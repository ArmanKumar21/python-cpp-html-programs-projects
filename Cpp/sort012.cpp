#include <bits/stdc++.h>

using namespace std;

void sort012(int arr[],int n)
{
    int o=0,t=0,z=0;
    for(int i=0;i<n;i++)  // Counting the number of zeroes, ones and twos
    {
        if(arr[i]==0){
            z++;
        }
        else if(arr[i]==1)
        {
            o++;
        }
        else{
            t++;
        }
    }
    for(int i=0;i<z;i++)  // Updating their positions in array
    {
        arr[i]=0;
    }
    for(int i=z;i<(z+o);i++)
    {
        arr[i]=1;
    }
    for(int i=z+o;i<n;i++)
    {
        arr[i]=2;
    }
}
int main()
{
    //To check
    // int a[7]={0,1,0,2,1,0,1};
    // sort012(a,7);
    // for(auto x:a)
    // {
    //     cout<<x<<" ";
    // }  
    
    return 0;
}