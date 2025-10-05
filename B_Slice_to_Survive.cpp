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

/*
suppose 2 7 1 4
then you should take slices and those areas are gonna be
2 4
2 7
2 4
1 7
if one of them matches then its 
*/

void solve()
{
	int n,m,a,b;
    cin >> n >> m >> a >> b;
    vector<pair<int,int>>v;
    v.pb({n,m+1-b});
    v.pb({n+1-a,m});
    v.pb({n,b});
    v.pb({a,m});
    int ans = INT_MAX;
    for (auto i : v) 
    {
        int k=1;
        int x = i.fi, y = i.se;
        while (x>1) x-= x/2,k++;
        while (y>1) y-= y/2,k++;
        ans = min(ans,k);
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int tc = 1;
    cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}