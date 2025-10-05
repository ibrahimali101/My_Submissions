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

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int>v(n);
    for (auto &i : v) cin >> i;
    int cnt = 0;
    for (int i=0;i<n;++i) {
        if (cnt == k || v[i] == 1) {
            v[i] = 1;
            cnt = 0;
            continue;
        }
        if (v[i] == 0) cnt++;
    }
    int x = 0;
    cnt = 0;
    for (auto i : v) { 
        if (i == 0) cnt++;
        else {
            if (cnt == k) x++;
            cnt = 0;
        }
    }
    if (cnt == k) x++;
    cout << x;
}

int main()
{
    ishowspeed
    int tc = 1;
    cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}
