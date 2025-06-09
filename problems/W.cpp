// Problem: W - Hard problem
// Contest: Virtual Judge - Sheet  ( DP Basics , styles ( 0/1 , Knapsack  , LIS , LCS ,CC) [2022]
// URL: https://vjudge.net/contest/463551#problem/W
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define ll long long
#define input(v) for(auto&i : v) cin >> i;
#define output(v) for(auto i : v) cout << i << ' ';
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define clr(v,d) memset(v,d,sizeof(v));
#define cceil(a,b) (a+b-1)/b
#define inf INT_MAX
using namespace std;
int n;
vector<ll>c;
vector<string>s;
ll mem[int(1e5+9)][2];
ll dp(int i,bool rev)
{
	if (i == n) 
	{
		return 0;
	}
	ll &ret = mem[i][rev];
	if (~ret) return ret;
	ret = 1e16+1;
	string ns = s[i-1],nss = s[i];
	reverse(all(nss));
	if (rev) reverse(all(ns));
	if (nss >= ns) ret = min(ret,c[i] + dp(i+1,1));
	if (s[i] >= ns) ret = min(ret, dp(i+1,0));
	return ret;
}
 
void solve()
{
	clr(mem,-1);
	cin >> n;
	c.resize(n);
	for (auto &i : c) cin >> i;
	s.resize(n);
	for (auto &i : s) cin >> i;
	cout << (min(dp(1,0),c[0] + dp(1,1)) >= (ll)(1e16+1) ? -1 : min(dp(1,0),c[0] + dp(1,1)));
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}