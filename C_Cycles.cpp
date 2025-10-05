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
long long nC3(long long n) {
    return n * (n - 1) * (n - 2) / 6;
}
void solve()
{
    int k;
    cin >> k;
    int adjMat[102][102];
    int l=3,r=100;
    ll n = 0;
    while(l<=r) {
        int md = (l+r)/2;
        if (nC3(md) >= k) {
            n= md;
            r = md-1;
        }else l = md+1;
    }
    for (int i=0;i<n-1;++i) {
        for (int j=0;j<n;++j) {
            adjMat[i][j] = 1;
        }
    }
    for (int i=0;i<n;++i) {
        adjMat[i][i] = 0;
    }
    int rem = k - nC3(n-1);
    int i=0;
    for (;i<n-1&&(rem+1);++i) {
        adjMat[n-1][i] = 1;
        adjMat[i][n-1] = 1;
        rem--;
    }
    for (;i<n;++i) {
        adjMat[n-1][i] = 0;
        adjMat[i][n-1] = 0;
    }
    cout << n << el;
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            cout << adjMat[i][j];
        }
        cout << el;
    }
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
