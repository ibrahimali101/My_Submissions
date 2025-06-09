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
#define inf (1<<31)-1
#define int ll
#define fix(a,b) (a%b+b)%b
using namespace std;
const int mod = 1e9+7;
// state i,pos
// base i == n
/*
trans:
    
*/
int n,m;
int dp[5006][5006];
vector<int>v;
int rec(int i,int pos)
{
    if (i == n) return 0;
    int &ret = dp[i][pos];
    if (~ret) return ret;
    ret = 5006;
    if (v[i] == pos) ret = min(ret,rec(i+1,pos));
    else if (v[i] > pos) ret = min({ret,1 + rec(i+1,pos),rec(i+1,v[i])});
    else ret = min(ret,1 + rec(i+1,pos));
    return ret;
}

void solve()
{
    clr(dp,-1);
	cin >> n >> m;
    v = vector<int>(n);
    double x;
    for (auto &i : v) cin >> i >> x;
    cout << rec(0,1);
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