#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

//maximum no. of people
#define N 100
int graph[N][N];
string people[N];
int n;

//returns index of minimum value in a[]
int get_min(int a[])
{
    int min_ind = 0;
    for(int i=1; i<n; i++)
        if (a[i] < a[min_ind])
            min_ind = i;
    return min_ind;
}

//returns index of maximum value in a[]
int get_max(int a[])
{
    int max_ind = 0;
    for(int i=1; i<n; i++)
        if (a[i] > a[max_ind])
            max_ind = i;
    return max_ind;
}

// amt[p] indicates the net amount to be credited/debited
// to/from person 'p'
// If amt[p] is positive, then i'th person will amt[i]
// If amt[p] is negative, then i'th person will give  -amt[i]
void min_cashflow_rec(int amt[])
{
    int mcr = get_max(amt), mdb = get_min(amt);
    if(amt[mcr] == 0 && amt[mdb] == 0)
        return;
    int minval = min(-amt[mdb], amt[mcr]);
    amt[mcr] -= minval;
    amt[mdb] += minval;
    cout<<"\n"<<people[mdb]<<" will pay "<<minval<<" to "<<people[mcr]<<endl;
    min_cashflow_rec(amt);
}

// Given a set of persons as graph[] where graph[i][j] indicates
// the amount that person i needs to pay person j, this function
// finds and prints the minimum cash flow to settle all debts.
void min_cashflow(int graph[][N])
{
    int amt[n]={0};
    //for(int i=0; i<n; i++)
      //  amt[i] = 0;
    for(int p=0; p<n; p++)
    {
      for(int i=0; i<n; i++)
        amt[p] += (graph[i][p] -  graph[p][i]);
    }
    min_cashflow_rec(amt);
}

int main()
{
    cout<<"*****"<<"Welcome to Cashflow minimizer - settle debts with less."<<"*****"<<endl;
    cout<<"\nEnter no. of people: ";
    cin>>n;
    //initialize the graph to 0
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            graph[i][j] = 0;
    cout<<"Enter names of people"<<endl;
    //accept names of people who owe each other
    for(int i=0; i<n; i++)
    {
        cout<<"Enter name#"<<i+1<<": ";
        cin>>people[i];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i == j)
                continue;
            cout<<"How much "<<people[i]<<" has to pay "<<people[j]<<"?   ";
            cin>>graph[i][j];
        }
    }
    min_cashflow(graph);
    //exit
    cout<<"\nPress any key to exit...";
  
    exit(0);
    return 0;
}
