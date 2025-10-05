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
int n,m;
vector<vector<bool>> vis;
vector<vector<pair<int,int>>> path;
 
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
char k[] = {'L','R','D','U'};
vector<vector<char>>grid;
bool valid(int x,int y) {
    return (x<n && y < m && x >= 0 && y >= 0 && !vis[x][y] && grid[x][y] != '#');
}
string ans="NO";
void bfs(int stx,int sty,int enx,int eny) {
    queue<pair<int,int>>q;
    q.push({stx,sty});
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        vis[p.fi][p.se] = true;
        if (p.fi == enx && p.se == eny) {
            ans = "YES";
            return;
        }
        for (int i = 0;i<4;++i) {
            int nx=p.fi+dx[i],ny=p.se+dy[i];
            if (valid(nx,ny)) { // L r d u
                q.push({nx,ny});
                path[nx][ny] = {dx[i],dy[i]};
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(),cout.tie();
    cin >> n >> m;
    grid = vector<vector<char>>(n,vector<char>(m));
    path = vector<vector<pair<int,int>>>(n,vector<pair<int,int>>(m));
    vis = vector<vector<bool>>(n,vector<bool>(m));
    int stx,sty,eny,enx;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j){
        	path[i][j] = {-1,-1};
        	char c;
            cin >> c;
            if (c == 'A') stx=i,sty=j;
            else if (c == 'B') enx=i,eny=j;
            else if (c == '#') vis[i][j]=true;
        }
    }
    vector<pair<int,int>>ansr;
    // ansr.pb({1,1});
    pair<int,int>end={enx,eny};
    bfs(stx,sty,enx,eny);
    // cout << ans << el;
    if (ans == "NO") return 0;
    // cout << ansr.size();
    // cout << path[end.fi][end.se].fi << ' ' << path[end.fi][end.se].se << el;
    while(end.fi != stx or end.se != sty)
    {
    	ansr.pb(path[end.fi][end.se]);
    	// cout << path[]
    	end.fi -=ansr.back().fi;
    	end.se -=ansr.back().se;
    }
    reverse(all(ansr));
    cout << ansr.size() << '\n';
    for (auto i : ansr)
    {
    	if (i.fi == 1 and i.se == 0)	cout << 'D';
    	else if (i.fi == -1 and i.se == 0) cout << 'U';
    	else if (i.fi == 0 and i.se == 1) cout << 'R';
    	else if (i.fi == 0 and i.se == -1) cout << 'L';
    }
}