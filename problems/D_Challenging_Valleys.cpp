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
    int ans = 0;
    vector<int>v(n);
    input(v);
    int l=0;
    int i=0,j=0;
    if (n<=2) {
        cout << "YES";
        return;
    }
    for(;j<n;++j) {
        if (v[j] != v[i]) {
            --j;
            if ((i==0 || v[i] < v[i-1]) && (j==n-1 || v[j] < v[j+1]))
                ans++;
            j++;
            i=j;
        }
    }
    j--;
    if ((i==0 || v[i] < v[i-1]) && (j==n-1 || v[j] < v[j+1]))
        ans++;
    if (ans == 1) cout <<"YES";
    else cout << "NO";
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