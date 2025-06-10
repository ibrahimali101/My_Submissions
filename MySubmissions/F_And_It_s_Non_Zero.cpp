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
#define inf (1LL<<31)-1
#define int ll
#define fix(a,b) (a%b+b)%b
using namespace std;
const int mod = 1e9+7;

// preprocessing to count all 0-bits for every bits untill 17th bit
void solve()
{
    vector<int> v = {1,4,5,7,8};
    inclusive_scan(all(v),6);
    // cout << v[]
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}