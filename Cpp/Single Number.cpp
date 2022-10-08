#include<bits/stdc++.h>
using namespace std;
#define lld long long int 


int singlenumber(int arr[],int n)
{
   int ans=0;//we will use the xor property stating that xors of 2 same numbers is 0
   for(int i=0;i<n;i++)
   {
    ans=ans^arr[i];
   }
   return ans;





}




int main()
{
    return 0;
}