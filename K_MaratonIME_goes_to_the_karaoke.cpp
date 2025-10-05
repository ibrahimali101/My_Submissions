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

void solve()
{
	string s;
    cin >> s;
    int n = s.size();
    int idx = 0;
    string ans;
    for (int i=1;i<n;++i) {
        if (s[idx] != s[i]) {
            ans.pb(s[idx]);
            ans.pb('0'+(i-idx));
            idx = i;
        }
    }
    ans.pb(s[idx]);
    ans+= to_string(n-idx);
    cout << ans;
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