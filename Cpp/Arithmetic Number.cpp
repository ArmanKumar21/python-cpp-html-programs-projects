
#include <bits/stdc++.h>
using namespace std;
#define lld long long int

int inSequence(int a, int b, int c)
{
    if (c == 0)
    {
        if (a != b)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    if ((b - a) % c == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()

{

    return 0;
}
