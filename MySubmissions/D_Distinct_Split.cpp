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
    string s;
    cin >> s;
    vector<int>frq(27);
    vector<int>suf(n),pre(n);
    int a = 0;
	for (int i=0;i<n;++i) // building for prefex
    {
        if (frq[s[i]-'a'] == 0) {
            frq[s[i]-'a']++;
            a++;
        }
        pre[i] = a;
    }
    frq = vector<int>(27,0);
    a=0;
    for (int i=n-1;i>-1;--i)
    {
        if (frq[s[i]-'a'] == 0) {
            frq[s[i]-'a']++;
            a++;
        }
        suf[i] = a;
    }
    // for (auto i : pre) cout << i << ' ';
    // cout << el;
    // for (auto i : suf) cout << i << ' ';
    int ans = 0;
    for (int i=0;i<n-1;++i){
        ans = max({ans,suf[i+1]+pre[i]});
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