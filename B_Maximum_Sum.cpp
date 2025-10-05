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
	int n,k;
    cin >> n >> k;
    vector<int>v(n);
    for (auto &i : v) cin >> i;
    sort(all(v));
    for (int i=1;i<n;++i) v[i] += v[i-1];
    int sum = v[n-1];
    int i=-1,j=k;
    int ans = 0;
    int t= k+1;
    while(t--) {
        int v1 = v[n-1]-(n-j? v[n-j-1] : 0);
        int v2 = (i!=-1? v[i] : 0);
        ans = max(ans,sum - (v1+v2));
        j--,i+=2;
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