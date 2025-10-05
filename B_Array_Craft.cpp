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
    int n,x,y;
    cin >> n >> x >> y;
    x--,y--;
    vector<int>v(n);
    for (int i=0;i<n;++i){
        if (i<=x && i>=y) v[i] = 1;
    }
    bool alt=0;
    for(int i=y-1;i>=0;--i) {
        if (!alt) v[i] = -1;
        else v[i]=1;
        alt = !alt; 
    }
    alt = 0;
    for(int i=x+1;i<n;++i) {
        if (!alt) v[i] = -1;
        else v[i]=1;
        alt = !alt; 
    }
    for (auto i : v) cout << i << ' ';
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
