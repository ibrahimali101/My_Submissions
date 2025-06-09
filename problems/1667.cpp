// Problem: Message Route
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1667
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
vector<vector<int>>g;
vector<bool>vis;
vector<int>parent;
int n,m;
void printing()
{
	int cur = n;
	stack<int>s;
	if (parent[n] == -1) return void(cout << "IMPOSSIBLE");
	while( cur != -1)
	{
		s.push(cur);
		cur = parent[cur];
	}
	cout << s.size() << endl;
	while(!s.empty()){
		cout << s.top() << ' ';
		s.pop();
	}
}

void bfs()
{
	vis[1] = true;
	queue<int>q;
	q.push(1);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto v : g[u])
		{
			if (!vis[v])
			{
				vis[v] = true;
				parent[v] = u;
				q.push(v);
			}
		}
	}
}
void solve()
{
	cin >> n >> m;
	g.resize(n+2);
	vis.resize(n+2);
	parent.resize(n+2,-1);
	for (int i=0;i<m;++i)
	{
		int u,v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	bfs();
	printing();
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