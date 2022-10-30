#include<bits/stdc++.h>
using namespace std;

class Solution{

    //Function to find the leaders in the array.

    public:

    vector<int> leaders(int a[], int n){

        // Code here
    vector<int> vec;
      int max = a[n-1];
      vec.push_back(max);

        for(int i=n-2;i>=0;i--)
        {

          if(a[i]>=max ) 

         {
             max=a[i];
             vec.push_back(a[i]);
         }

        }

        reverse(vec.begin(), vec.end());

        return vec;
    }
};