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
const ll mod = 1e9+7, OO = 0x3f3f3f3f;
const int N = 5e1+9;
int n,m;
char grid[N][N];
bool movable[N][N];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
bool valid(int i,int j) {
    return (i>=0&&j>=0&&i<n&&j<m);
}

int ans = 0;
void dfs(int i,int j) {
    if (grid[i][j] == '#') return;
    if (grid[i][j] == 'G') ans++;
    grid[i][j] = '#';
    if (movable[i][j])  {
        for (int k=0;k<4;++k) {
            int nX = i + dx[k];
            int nY = j + dy[k];
            if (valid(nX,nY)) {
                dfs(nX,nY);
            }
        }
    }
    
}

int main()
{
    ishowspeed
    while(cin >> n >> m)
    {
        clr(movable,true);
        swap(n,m);
        pair<int,int> player;
        for (int i=0;i<n;++i) {
            for (int j=0;j<m;++j) {
                cin >> grid[i][j];
                if (grid[i][j] == 'P') player = {i,j};
            }
        }
        for (int i=0;i<n;++i) {
            for (int j=0;j<m;++j) {
                if (grid[i][j] == 'T') {
                    for (int k=0;k<4;++k) {
                        int nR = i + dx[k];
                        int nC = j + dy[k];
                        if (valid(nR,nC)) movable[nR][nC] = false; 
                    }
                    grid[i][j] = '#';
                }
            }
        }
        for (int i=0;i<n;++i) {
            for (int j=0;j<m;++j) {
                cout << grid[i][j];
            }
            cout << el;
        }
        for (int i=0;i<n;++i) {
            for (int j=0;j<m;++j) {
                cout << movable[i][j];
            }
            cout << el;
        }
        ans = 0;
        dfs(player.fi,player.se);
        cout << ans << el;
    }
}