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
	string s,p;
    cin >> s >> p;
    int n = s.size();
    int m = p.size();
    string ans = "YES";
    vector<pair<char,pair<int,int>>>v = {{s[0],{0,0}}},v2;
    v2 = {{p[0],{0,0}}};
    for (int i=1;i<n;++i){
        if (s[i] != v.back().fi) v.push_back({s[i],{0,0}});
    }
    for (int i=1;i<m;++i){
        if (p[i] != v2.back().fi) v2.push_back({p[i],{0,0}});
    }
    if (v != v2) ans = "NO";
    if (s[0] != p[0]) ans = "NO";
    int pt=0;
    for (int i=0;i<n&&pt<v.size();++i)
    {
        if (s[i] != v[pt].fi) pt++,i--;
        else v[pt].se.fi++;
    }
    pt=0;
    for (int i=0;i<m&&pt<v.size();++i)
    {
        if (p[i] != v[pt].fi) pt++,i--;
        else v[pt].se.se++;
    }
    for (auto &i : v){
        if (!i.se.fi) i.se.fi++;
        if (!i.se.se) i.se.se++;
    }
    for (auto i : v)
    {
        if (i.se.se >= i.se.fi && i.se.se <= i.se.fi*2) pt;
        else ans = "NO";
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