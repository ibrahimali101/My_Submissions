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
	int n,m,k;
    cin >> n >> m >> k;
    int f = m;
    vector<int>v(n);
    iota(all(v),1);
    set<int>s1;
    set<int>s2;
    vector<vector<int>>vv;
    do {
        if (s1.count(v[0]) || s2.count(v[n-1])) continue;
        vv.pb(v);
        s1.insert(v[0]);
        s2.insert(v[n-1]);
        f--;
    } while( next_permutation(all(v)) && f);
    for (int i=0;i<vv.size();++i){
        for (auto j : vv[i]) cout << j << ' ';
        if (i!=vv.size()-1) cout << el;
    }
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