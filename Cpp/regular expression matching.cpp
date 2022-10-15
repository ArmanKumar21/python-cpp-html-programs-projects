
// Problem ->

// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".

// Example 2:

// Input: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

// Solution in c++ :
#include <bits/stdc++.h>
using namespace std;

int dp[25][35];

bool check(string &s, string &p, int i, int j, int &m, int &n)
{
    if (i == m && j == n)
        return true;
    if (j == n)
        return false;
    if (dp[i][j] != -1)
        return dp[i][j];
    bool valid = (i < m) && (s[i] == p[j] || p[j] == '.');
    if (j + 1 < n && p[j + 1] == '*')
    {
        return dp[i][j] = check(s, p, i, j + 2, m, n) || valid && check(s, p, i + 1, j, m, n);
    }
    if (valid)
    {
        return dp[i][j] = check(s, p, i + 1, j + 1, m, n);
    }
    return dp[i][j] = false;
}
bool isMatch(string s, string p)
{
    int m = s.length(), n = p.length();
    memset(dp, -1, sizeof(dp));
    return check(s, p, 0, 0, m, n);
}

int main()
{
    string s, p;
    cout << "Enter 1st String(s) : ";
    cin >> s;
    cout << "\nEnter 2nd String(p) : ";
    cin >> p;
    if (isMatch(s, p))
        cout << "True";
    else
        cout << "False";
}
