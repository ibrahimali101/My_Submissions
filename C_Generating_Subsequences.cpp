#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <utility>
#include <bitset>
#define Venom                         \
    std::ios::sync_with_stdio(false); \
    ios_base::sync_with_stdio(false); \
    cout.tie(nullptr);                \
    cin.tie(nullptr);
#define ll long long
#define mod 1000000007
#define li endl
#define sp " "
#define outmap(_)                                    \
    for (auto it = _.begin(); it != _.end(); ++it)   \
    {                                                \
        cout << it->first << sp << it->second << li; \
    }
#define pi 3.14159265359
#define sor(_) sort(_.begin(), _.end())
#define rsor(_) sort(_.rbegin(), _.rend())
#define all(_) _.begin(), _.end()
#define rall(_) _.rbegin(), _.rend()
#define uni(_) _.erase(unique(all(_)), _.end())
#define input(_)      \
    for (auto &i : _) \
        cin >> i;
#define output(_)    \
    for (auto i : _) \
        cout << i << sp;
#define tcs   \
    ll t;     \
    cin >> t; \
    while (t--)
using namespace std;
void InOut()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
string s;
int sz;
string res;
vector<string>ans;
void rec(int i)
{
    if (i == sz)
    {
        ans.emplace_back(res);
        return;
    } 
    rec(i+1);
    res.push_back(s[i]);
    rec(i+1);
    res.pop_back();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    // InOut();
    cin>>s;
    sz=s.size();
    rec(0);
    sor(ans);
    for(auto i:ans){
        if (i!="") cout << i << '\n';
    }
}