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
#define int ll
#define fix(a,b) (a%b+b)%b
using namespace std;
const int mod = 1e9+7, OO = 0x3f3f3f3f3f3f3f;

void solve()
{
	int n;
    cin >> n;
    vector<int>a(n),b(n),c(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    for (auto &i : c) cin >> i;
    double dis_f = 0;
    for (int i=0;i<n;++i) {
        dis_f+= (a[i]-b[i])*(a[i]-b[i]);
    }
    dis_f = sqrt(dis_f);
    double dis_c = 0;
    for (int i=0;i<n;++i) {
        dis_c+= (a[i]-c[i])*(a[i]-c[i]);
    }
    dis_c = sqrt(dis_c);
    cout << (dis_c > dis_f ? "Yan" : "MaratonIME");
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