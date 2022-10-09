#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> merge(vector<vector<int>>& intervals)
 {
    sort(intervals.begin(),intervals.end()); // sorting the vector first inorder to get intervals in line
    vector<vector<int>> result;
    int a1,a2,c=0;// c variable to keep the track of current smallest interval
    a2 = intervals[c][1]; // here a1 is for starting of the interval whereas a2 is ending of interval
    for (int i = 0; i < intervals.size()-1; i++) // starting linear loop
    {
        a1 = intervals[c][0];// updating a1
        a2 = max(intervals[i][1],a2);// updating a2 if we get even bigger limit
        if(intervals[i+1][0]>a2) // checking if next interval can be merged or not
        {
            c =i+1;// updating new start of interval
            result.push_back({a1,a2});// pushing back the last calculated interval
        }
    }
    a2 = max(a2,intervals[intervals.size()-1][1]);// updating a2 for last time
    result.push_back({intervals[c][0],a2});// pushing last interval
    return result;
    }

int main()
{
    vector<vector<int>> v;
    v.push_back({1,3});
    v.push_back({0,2});
    v.push_back({2,3});
    v.push_back({4,6});
    v.push_back({4,5});
    v.push_back({5,5});
    vector<vector<int>> result = merge(v);
    for (int i = 0; i < result.size(); i++)//printing merged intervals
    {
        cout<<result[i][0]<<" "<<result[i][1]<<endl;
    }
}
