#include <bits/stdc++.h>
#define el '\n'
using namespace std;
vector<bool>vis;
vector<vector<int>>adj;
vector<int>parns;
bool dfs (int i,int p)
{
	vis[i] = true;
	parns[i] = p;
	for (j : adj[i])
	{
		if (!vis[j])
		{
			dfs(j,i);
		}
		else if (vis[j])
		{
			if (parns[j] != p) return true;
		}
	}
}

bool is_cycle()
{
	for (int i=0;i<n;++i)
	{
		if (!vis[i])
		{
			if (!dfs(i,-1)) return false;
		}
	}
}

int main()
{
	int n,m;
	cin >> n >> m;
	adj.resize(n);
	vis.resize(n);
	for (int i=0;i<m;++i)
	{
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	cout << is_cycle() << el;
	
}