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
#define inf (1LL<<31)
#define int ll
#define fix(a,b) (a%b+b)%b
using namespace std;
const int mod = 1e9+7;

void solve()
{
	int n,s;
    cin >> n >> s;
    vector<int>v(n);
    int sum = 0;
    for (auto &i : v) cin >> i;
    for (int i=1;i<n;++i) v[i]+=v[i-1];
    int ans = inf;
    for (int l=0;l<n;++l)
    {
        int r = upper_bound(v.begin()+l,v.end(),(l? v[l-1] : 0) +s) - v.begin() - 1;
        if (v[r] - (l? v[l-1] : 0) == s)
            ans = min(ans,l + n - r - 1);
    }
    cout << (ans==inf? -1 : ans);
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