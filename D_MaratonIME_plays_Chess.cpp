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
#define int ll
#define fix(a,b) (a%b+b)%b
using namespace std;
const int mod = 1e9+7, OO = 0x3f3f3f3f3f3f3f;
vector<vector<char>>c;

bool valid(int x,int y) {
    return (x>=0&&y>=0&&y<8&&x<8);
}
bool Pawn(int x,int y) {
    if ((valid(x+1,y+1) && c[x+1][y+1] == 'p') || (valid(x+1,y-1) && c[x+1][y-1] == 'p')) {
        return true;
    }return false;
}
bool Knight(int x,int y) {
    if (valid(x-2,y-1) && c[x-2][y-1] == 'c') return true;
    if (valid(x-2,y+1) && c[x-2][y+1] == 'c') return true;
    if (valid(x+2,y-1) && c[x+2][y-1] == 'c') return true; 
    if (valid(x+2,y+1) && c[x+1][y+1] == 'c') return true; 
    if (valid(x+1,y+2) && c[x+1][y+2] == 'c') return true; 
    if (valid(x+1,y-2) && c[x+1][y-2] == 'c') return true; 
    if (valid(x-1,y+2) && c[x-2][y+2] == 'c') return true; 
    if (valid(x-1,y-2) && c[x-1][y-2] == 'c') return true; 
    return false;
}
bool Bishop(int x,int y){
    for (int i=x+1,j=y+1;valid(i,j);++j,++i) {
        if (c[i][j] == 'b' || c[i][j] == 'r') return true;
        else if (c[i][j] != '.') break;
    }
    for (int i=x+1,j=y-1;valid(i,j);--j,++i) {
        if (c[i][j] == 'b' || c[i][j] == 'r') return true;
        else if (c[i][j] != '.') break;
    }
    for (int i=x-1,j=y+1;valid(i,j);++j,--i) {
        if (c[i][j] == 'b' || c[i][j] == 'r') return true;
        else if (c[i][j] != '.') break;
    }
    for (int i=x-1,j=y-1;valid(i,j);--j,--i) {
        if (c[i][j] == 'b' || c[i][j] == 'r') return true;
        else if (c[i][j] != '.') break;
    }
    return false;
}
bool Rook(int x,int y){
    for (int i=x;valid(i,y);++i) {
        if (c[i][y] == 'r' || c[i][y] == 't') return true;
        else if (c[i][y] != '.') break;
    }
    for (int i=x;valid(i,y);--i) {
        if (c[i][y] == 'r' || c[i][y] == 't') return true;
        else if (c[i][y] != '.') break;
    }
    for (int i=y;valid(x,i);++i) {
        if (c[x][i] == 'r' || c[x][i] == 't') return true;
        else if (c[x][i] != '.') break;
    }
    for (int i=y;valid(x,i);--i) {
        if (c[x][i] == 'r' || c[x][i] == 't') return true;
        else if (c[x][i] != '.') break;
    }
    return false;
}

int X[8] = {-1,1,0,0,1,-1,1,-1};
int Y[8] = {0,0,1,-1,1,1,-1,-1};
bool King(int x,int y) {
    for (int i=0;i<8;++i) {
        if (!valid(x+X[i],y+Y[i])) continue;
        if (c[x+X[i]][y+Y[i]] == 'k') return true;
    }
    return false;
}

void solve()
{
    c.resize(8,vector<char>(8));
	for (auto &i : c) {
        for (auto &j : i)
            cin >> j;
    }
    int x,y;
    char ch;
    cin >> ch >> y;
    x = ch-'a';
    y = 8-y;
    swap(x,y);
    if (Pawn(x,y) || Knight(x,y) || Bishop(x,y) || Rook(x,y) || King(x,y)) cout << "Sim";
    else cout << "Nao";
}

signed main()
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