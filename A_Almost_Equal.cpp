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
    int n;
    cin >> n;
    vector<int>v(2*n);
    int val = 1;
    bool k = true;
    for (int i=0;i<2*n;++i) {
        if (v[i] && v[(i+n) % (2*n)]) {
            continue;
        }
        if (k) {
            v[i] = val++;
            v[(i+n)%(2*n)] = val++;
            k=!k;
        }
        else {
            v[(i+n)%(2*n)] = val++;
            v[i] = val++;
            k = !k;
        }
    }
    int sum = 0;
    for (int i=0;i<n;++i) sum+=v[i];
    int l=0,r=n;
    set<int>s;
    s.insert(sum);
    for (;r<4*n;++r,++l) {
        sum-=v[l%(2*n)];
        sum+=v[r%(2*n)];
        s.insert(sum);
    }
    if (s.size() <= 2){
        cout << "YES\n";
        for (auto i : v) cout << i << ' ';
    }
    else cout << "NO";
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
