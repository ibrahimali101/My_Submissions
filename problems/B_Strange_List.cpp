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
	int n, x;
    cin >> n >> x;
    vector<int>v(n),clo(n);
    int sum = 0;
    for (int i=0;i<n;++i) {
        cin >> v[i];
        sum+=v[i];
        clo[i]=v[i];
    }
    bool nigga = 1, black=1;
    bool fg =1;
    while(nigga == black ) {
        for (int i=0;i<n;++i) {
            if (clo[i]%x==0) {
                sum+= v[i];
                clo[i]/=x;
            }
            else {
                fg=!fg;
                break;
            }
        }
        if (!fg) break;
    }
    cout << sum;
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