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
	int n,k;cin >> n >> k;
    vector<int>v(n);
    for (auto &i : v) cin >> i;
    sort(all(v));
    int ans = 0;
    int val = 0;
    int pres = 0;
    for (int i=0;i<n&&ans<k;++i) {
        v[i]-=val;
        if (v[i] <= 0) pres++;
        else {
            if (ans + (v[i])*(n-i) < k) {
                pres++;
            }
            ans+= (v[i])*(n-i);
        }
        val+= v[i];
    }
    cout << pres+k;
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