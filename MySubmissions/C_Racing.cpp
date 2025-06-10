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
    vector<int>v(n);
    for (auto &i : v) cin >> i;
    vector<pair<int,int>>vp(n);
    for (auto &i : vp) cin >> i.fi >> i.se;
    stack<int>st;
    int h=0;
    for (int i=0;i<n;++i) {
        if (v[i] == -1) st.push(i);
        if (v[i] == 1) h++;
        while(!st.empty() && h < vp[i].fi) {
            v[st.top()] = 1;
            h++;
            st.pop();
        }
        if (h < vp[i].fi) {
            cout << -1;
            return;
        }
    }
    while(!st.empty()) {
        v[st.top()] = 0;
        st.pop();
    }
    h = 0;
    for (int i=0;i<n;++i) {
        h+= v[i];
        if (vp[i].fi > h || vp[i].se < h) {
            cout << -1;
            return;
        }
    }
    for (auto i : v) cout << i << ' ';
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