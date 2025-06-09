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
    vector<int>fr(32),v(n);
    for (auto &i : v) 
    {
        cin >>i;
        for (int j=0;j<32;++j)
        {
            if ((1<<j)&i) fr[j]++;
        }
    }
    int ans = -1;
    int val = -1;
    for (int i=0;i<n;++i) 
    {
        int sum=0;
        for (int j=0;j<32;++j)
        {
            if ((1<<j)&v[i]){
                sum += ((n-fr[j])*(1<<j));
            }
            else sum += ((fr[j])*(1<<j));
        }
        ans = max(sum,ans);
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