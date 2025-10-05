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
const int mod = 1e9+7;
/*
base case i ==n ;
state int i,int pos
transition: 
    take: pos+1,last+1;
    else pos+1,last
*/
int n,m,p;
vector<int>em;
vector<int>keys;
const ll inf = 1e17;
int dp[2001][1001];
int rec(int i,int j) // i for keys, j for persons
{
    if (j == n) return 0; // if persons is done, then all keys has been distributed
    if (i == m) return inf;// if keys is done, then its not a solution
    int &ret = dp[i][j];
    if (~ret) return ret;
    ret = inf;
    ret = min(ret, max( abs(em[j] - keys[i]) + abs(keys[i] - p) ,rec(i+1,j+1))); // taking person
    ret = min(ret, rec(i+1,j)); // skipping person
    return ret;
}

void solve()
{
    clr(dp,-1);
    cin >> n >> m >> p;
    em.resize(n);
    keys.resize(m);
    for (auto &i : em) cin >>i ;
    for (auto &i : keys) cin >> i;
    sort(all(em));
    sort(all(keys));
    cout << rec(0,0);
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