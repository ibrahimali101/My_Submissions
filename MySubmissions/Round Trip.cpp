#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define ll long long
using namespace std;
vector<bool>vis;
vector<vector<int>>adj;
vector<int>parns;
int sj,ei;
int n,m;
bool dfs(int i,int p)
{
	vis[i] = true;
	parns[i] = p;
	for (auto j : adj[i])
	{
		if (p == j) continue;
		if (!vis[j])
		{
			if (dfs(j,i)) return true;
		}
		else if (vis[j])
		{
			sj = j,ei = i;
			return true;
		}
	}
	return false;
}

bool is_cycle()
{
	for (int i=1;i<=n;++i)
	{
		if (!vis[i])
		{
			if (dfs(i,-1)) return true;
		}
	}
	return false;
}
void solve()
{
	cin >> n >> m;
	adj.resize(n+2);
	vis.resize(n+2);
	parns.resize(n+2);
	for (int i=0;i<m;++i)
	{
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector<int>ans;
	
	if (is_cycle())
	{
		/*
		4 5 3
		5 3 1
		*/
		int cur_p = parns[ei];
		ans.pb(ei);
		while(cur_p != sj)
		{
			ans.pb(cur_p);
			cur_p = parns[cur_p];
		}
		ans.pb(cur_p);
		ans.pb(ei);
		cout << ans.size() << el;
		for (auto i : ans) cout << i << ' ';
	}
	else{
		cout << "IMPOSSIBLE" << el;
		return;
	}
	
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