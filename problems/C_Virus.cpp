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
	int n,m;
    cin >>n >> m;
    vector<int>v(m),seq;
    for(auto &i:v) cin >>i;
    sort(all(v));
    for (int i=0;i<m-1;++i)
    {
        seq.pb(v[i+1]-v[i]-1);
    }
    seq.pb(v[0]-1 + n-v[m-1]);
    sort(rall(seq));
    int val=0,ans=0;
    for (auto i : seq)
    {
        if (max(0LL,i - 2*val) == 1)
        {
            val++;
            ans++;
        }
        else if (max(0LL,i - 2*val) == 2)
        {
            ans += max(1LL,i - 2*val)-1;
            val++;
        }
        else if (max(0LL,i - 2*val) > 2)
        {
            ans += max(1LL,i - 2*val)-1;
            val+=2;
        }
    }
    cout << n-ans;
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