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

bool prime(int x)
{
    for (int i=2;i<x;++i) {
        if (x%i == 0) return false;
    }
    return true;
}

void solve()
{
	int n;
    cin >> n;
    if (n < 5) cout <<-1;
    else
    {
        for (int i=2;i<=n;i+=2)
        {
            if (i == 4) continue;
            cout << i << ' ';
        }
        cout << 4 << ' ';
        cout << 5 << ' ';
        for (int i=1;i<=n;i+=2) 
        {
            if (i == 5) continue;
            cout << i << ' ';
        }
    }
    
    
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