// Problem: Building Roads
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1666
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
using namespace std;
int n,m;
vector<vector<int>>adj;
vector<bool>vis;
vector<int>lead;

void dfs(int i)
{
	vis[i] = true;
	for (auto j : adj[i])
	{
		if (!vis[j])
		{
			dfs(j);
		}
	}
}

void solve()
{
	int cc = 0;
	cin >> n >> m;
	adj.resize(n+1);
	vis.resize(n+1);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	/*
	my list:
	1 : {2}
	2 : {1}
	3 : {4}
	4 : {3}
	*/
	for (int i=1;i<=n;++i)
	{
		if (!vis[i])
		{
			cc++;
			lead.push_back(i);
			dfs(i);
		}
	}
	// cout << cc-1 << el;
	// if (cc > 1)
	// {
		// int u = lead[0],v;
		// for (int i = 1;i<cc;++i)
		// {
			// v = lead[i];
			// cout << u << ' ' << v << el;
			// u = v;
		// }
	// }
	for (auto i : lead) cout << i << ' ';
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