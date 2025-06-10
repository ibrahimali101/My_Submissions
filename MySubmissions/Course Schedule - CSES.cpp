// Problem: Course Schedule
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1679
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define ll long long
#define input(v) for(auto&i : v) cin >> i;
#define output(v) for(auto i : v) cout << i << ' ';
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
using namespace std;
 vector<vector<int>>adj;
 vector<bool>vis;
 vector<int>cnt;
 int n,m;
 vector<int>ans;
 void dfs(int node)
 {
 	vis[node] = true;
 	ans.pb(node);
 	for (auto i : adj[node])
 	{
 		if (!(--cnt[i]) && !vis[i])
 		{
 			dfs(i);
 		}
 	}
 }
 
void solve()
{
	cin >> n >> m;
	adj.resize(n+2);
	vis.resize(n+2);
	cnt.resize(n+2,0);
	for (int i=0;i<m;++i)
	{
		int a,b;
		cin >> a >> b;
		adj[a].pb(b);
		cnt[b]++;
	}
	for (int i=1;i<=n;++i)
	{
		if (!vis[i] && !cnt[i]) dfs(i);
	}
	for (auto i : ans) cout << i << ' ';
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