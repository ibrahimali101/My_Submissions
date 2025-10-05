// Problem: B - Building Teams
// Contest: Virtual Judge - Sheet 2: DFS
// URL: https://vjudge.net/contest/663975#problem/B
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
vector<int>color;
vector<bool>vis;

bool dfs(int v,int c)
{
	vis[v] = true;
	color[v] = c;
	for (auto ch : adj[v])
	{
		if (!vis[ch])
		{
			if (!dfs(ch,(color[v]^3))) return false;
		}
		if (color[v] == color[ch]) return false;
	}
	return true;
}
bool pos()
{
	for (int i=1;i<=n;++i)
	{
		if (!vis[i])
		{
			if (!dfs(i,1)) return false;
		}
	}
	return true;
}
void solve()
{
	int u,v;
	cin >> n >> m;
	color.resize(n+5);
	adj.resize(n+1);
	vis.resize(n+2);
	for (int i=0;i<m;++i)
	{
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	if (pos()) {
		for (int i=1;i<=n;++i) cout << color[i] << ' ';
	}
	else cout << "IMPOSSIBLE";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int tc = 1;
    //cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}