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
    vector<int>v(n);
    vector<int>val;
    map<int,int>mp;
    bool ok = false;
    int okr = -1;
    int cnt = 0,lst = -1,num = -1;
    for (auto &i : v) {
        cin >> i;
        mp[i]++;
    }
    for (auto i : mp) {
        if (i.se == 4) ok = true,okr=i.fi;
        if (i.se >= 2) val.push_back(i.fi);
    }
    if (ok) return void(cout << okr << ' ' << okr << ' ' << okr << ' ' << okr);
    else {
        if (val.size() >= 2) {
            for (int i=0;i<2;++i) {
                cout << val[i] << ' ' << val[i] << ' ';
            }
            return;
        }
        else if (val.size() == 1) {
            int x = mp[val[0]];
            sort(all(v));
            int prev = (v[0]==val[0] ? -1 : v[0]);
            for (int i=1;i<n;++i) {
                if (v[i]-v[i-1] < val[0]*2) {
                    if (x == 3 && v[i-1] != v[i]) {
                        return void(cout << val[0] << ' '<< val[0] << ' ' << v[i-1] << ' ' << v[i]);
                    }
                }
                if (v[i] == val[0]) continue;
                if (prev != -1 && v[i]-prev < val[0]*2) {
                    return void(cout << val[0] << ' '<< val[0] << ' ' << prev << ' ' << v[i]);
                }
                prev = v[i];
            }
        }
    }
    cout << -1;

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
