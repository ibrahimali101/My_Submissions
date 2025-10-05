// Problem: Counting Rooms
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1192
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

vector<int> dx = {0,0,-1,1};
vector<int> dy = {1,-1,0,0};
int n,m;
void dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<char>>&grid)
{
	vis[i][j] = true;
	auto va = [&](int x,int y)
	{
		if (x < 0 || y < 0 || x >= n || y >= m)
		return false;
		return true;
	};
	for (int k=0;k<4;++k)
	{
		int x = i+dx[k], y = j+dy[k];
		if (va(x,y) && !vis[x][y] && grid[x][y] != '#')
		{
			dfs(x,y,vis,grid);
		}
	}
}
void solve()
{
	cin >> n >> m;
	int cnt = 0;
	vector<vector<bool>>vis(n,vector<bool>(m));
	vector<vector<char>>grid(n,vector<char>(m));
	for (auto&i : grid)
	{
		for (auto &j : i) cin >> j;
	}
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
		{
			if (!vis[i][j] && grid[i][j] != '#')
			{
				cnt++;
				dfs(i,j,vis,grid);
			}
		}
	}
	cout << cnt;
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