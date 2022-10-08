#include<bits/stdc++.h>
using namespace std;
#define lld long long int 

void sort012(int arr[],int n)
{
   int temp[3]={0};//we will apply count sort so its the storing array

//traversing over the array and will increase the suitable index value
   for(int i=0;i<n;i++)
   {
    if(arr[i]==1)
    {
       temp[1]++;
    }
    else if(arr[i]==0)
    {
        temp[0]++;
    }
    else
    {
        temp[2]++;
    }
   }
   int i=0;
   while(arr[0]>0&&i<n)
   {
      arr[i]=0;
      arr[0]--;
      i++;
   }
   
   while(arr[1]>0&&i<n)
   {
      arr[i]=1;
      arr[1]--;
      i++;
   }

   while(arr[2]>0&&i<n)
   {
      arr[i]=2;
      arr[2]--;
      i++;
   }






}





int main()
{
    return 0;
}