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
int cbits(int n)
{
    int count = 0;
    while (n>0) {
        count += (n & 1LL);
        n >>= 1LL;
    }
    return count;
}
void solve()
{
	int n,k;
    cin >> n >> k;
    vector<int>v(n);
    for (auto &i : v) cin >> i;
    for (int i=0;i<63;++i) {
        for (int j=0;j<n;++j) {
            if (v[j] & (1LL<<i)) {
                continue;
            }
            else{
                if (k >= (1LL<<i))
                    k-=(1LL<<i),v[j]+=(1LL<<i);
                else break;
            }
        }
    }
    int ans = 0;
    for (auto i : v) {
        ans+= __builtin_popcountll(i);
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