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
vector<vector<char>>v;
void bin(int k,vector<char>&vec) { // 
    if (k == n) {
        v.pb(vec);
        return;
    }
    vec.pb('0');
    bin(k+1,vec); // 0
    vec.pop_back();
    vec.pb('1');
    bin(k+1,vec); // 1
    vec.pop_back();
}

void solve()
{
    v.clear();
    cin >> n;
    vector<char>temp;
    bin(0,temp);
    for (auto j : v) {
        for (auto i : j) cout << i;
        cout << el;
    }
}

int main()
{
    ishowspeed
    int tc = 1;
    cin >> tc;
    while(tc--)
    {
        solve();
        // cout << el;
    }
}
