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
#define fix(a,b) (a%b+b)%b
#define ishowspeed ios_base::sync_with_stdio(false);    cin.tie();    cout.tie();
using int64 = ll;
using namespace std;
const ll mod = 1e9+7, OO = 0x3f3f3f3f3f3f3f;
int n;
const int N= 109, MAX = 1e5+9;
bool dp[N][MAX];

void solve()
{
    cin >> n;
    vector<int>v(n);
    int mx = 0;
    for (auto &i : v) cin >> i,mx+=i;
    for (int i=0;i<n;++i) {
        // dp[i][0] = 1;
        dp[i][v[i]] = 1;
    }
    for (int sum=1;sum<=mx;++sum) {
        for (int j=0;j<n;++j) {
            if (j) dp[j][sum] |= dp[j-1][sum];
            if (sum-v[j] > -1 && j) dp[j][sum] |= dp[j-1][sum-v[j]];
        }
    }
    set<ll>s;
    for (int i=1;i<=mx;++i) {
        if (dp[n-1][i]) s.insert(i);
    }
    cout << s.size() << el;
    for (auto i : s) cout << i << ' ';
}

int main()
{
    ishowspeed
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}
