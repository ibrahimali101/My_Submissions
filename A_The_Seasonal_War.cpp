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

void solve()
{
    
}


/*
0 1
0 -1
1 0
-1 0
1 1
1 -1
-1 1
-1 -1
*/
bool vis[27][27];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int n;
char grid[27][27];
bool valid(int i,int j) {
    return (i>=0&&j>=0&&i<n&&j<n);
}

void dfs(int i,int j) {
    vis[i][j] = true;
    for (int k=0;k<8;++k) {
        int nX = dx[k] + i;
        int nY = dy[k] + j;
        if (valid(nX,nY) && grid[nX][nY] == '1' && !vis[nX][nY]) {
            dfs(nX,nY);
        }
    }
}
int main()
{
    ishowspeed
    int img = 1;
    while(cin >> n)
    {
        if (n == 0) return 0;
        clr(vis,false);
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) 
                cin >> grid[i][j];
        }
        int eagle_war = 0;
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) 
            {
                if (!vis[i][j] && grid[i][j] == '1') {
                    eagle_war++;
                    dfs(i,j);
                }
            }
        }
        cout << "Image number " << img << " contains " << eagle_war << " war eagles." <<el;
        img++;
    }
}
