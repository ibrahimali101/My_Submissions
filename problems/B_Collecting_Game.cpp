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

void solve()
{
	int n;
    cin >> n;
    vector<pair<int,int>>v;
    for (int i=0;i<n;++i) {
        int x;
        cin >> x;
        v.pb({x,i});
    }
    sort(all(v));
    vector<int>pref(n);
    pref[0] = v[0].fi;
    for (int i=1;i<n;++i) {
        pref[i] = pref[i-1] + v[i].fi;
    }
    vector<int>ans(n);
    ans[n-1] = n-1;
    for (int i=n-2;i>=0;--i) {
        if (pref[i] >= v[i+1].fi) ans[i] = ans[i+1];
        else ans[i] = i;
    }
    vector<int>frs(n);
    for (int i=0;i<n;++i) {
        frs[v[i].se] = ans[i];
    }
    for (auto i : frs) cout << i << ' ';
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