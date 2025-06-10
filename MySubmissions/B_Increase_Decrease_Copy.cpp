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
    vector<int>a(n);
    vector<int>b(n+1);
    input(a);
    input(b);
    int x = b[n];
    int op = 0;
    bool done = true;
    for (int i=0;i<n;++i) {
        op+= abs(a[i]-b[i]);
        if (((x >= a[i] && x <= b[i]) || (x <= a[i] && x >= b[i])) && done) {
            op++;
            done = false;
        }
    }
    int f = 1e9+7;
    if (done) {
        for (int i=0;i<n;++i) {
            f = min({f,abs(a[i]-x),abs(b[i]-x)});
        }
        op+= (f+1);
    }
    cout << op;
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