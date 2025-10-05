// Good. That's one less loose end.
#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define watch(x) cerr << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << "\n"
#define ll long long
#define input(v) for(auto&i : v) cin >> i;
#define output(v) for(auto i : v) cout << i << ' ';
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define clr(v,d) memset(v,d,sizeof(v));
#define cceil(a,b) (a+b-1)/b
#define fix(a,b) (a%b+b)%b
#define ishowspeed ios_base::sync_with_stdio(false);    cin.tie();    cout.tie();
using int64 = ll;
using namespace std;
const ll mod = 1e9+7, OO = 0x3f3f3f3f3f3f3f;
const int N = 1e1+3;
char grid[N][N];
bool vis[N][N];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int n = 9;
bool valid(int i,int j) {
    return (i>=0&&j>=0&&i<n&&j<n);
}

char x;
int ans = 0;
set<char>s;
void dfs(int i,int j) {
    if (grid[i][j] != '.') {
        s.insert(grid[i][j]);
        return;
    }
    vis[i][j] = true;
    ans++;
    for (int k=0;k<4;++k) {
        int nX = i + dx[k];
        int nY = j + dy[k];
        if (!vis[nX][nY] && valid(nX,nY)) {
            dfs(nX,nY);
        }
    }
}


int main()
{
    ishowspeed
    int tc;
    cin >> tc;
    while(tc--) {
        clr(vis,false);
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                cin >> grid[i][j];
            }
        }
        map<char,int>mp;
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                s.clear();
                ans = 0;
                if (grid[i][j] != '.') mp[grid[i][j]]++;
                else if (!vis[i][j] && grid[i][j] == '.') 
                    dfs(i,j);
                if (s.size() == 1) mp[*s.begin()] += ans;
            }
        }
        cout << "Black " <<  mp['X'] << " White " << mp['O'] << el;
    }
    
}
