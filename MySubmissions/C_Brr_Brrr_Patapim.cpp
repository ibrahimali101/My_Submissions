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

int sum(int x)
{
    return x*(x+1)/2;
}

void solve()
{
    int n;
    cin >> n;
    set<int>s;
	vector<int>v(2*n);
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
        {
            int x;
            cin >> x;
            s.insert(x);
            v[i+j-1] = x;
        }
    }
    int sum1 = 0;
    for(auto i : s) sum1+=i; 
    int lost = sum(2*n) - sum1;
    v[0] = lost;
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