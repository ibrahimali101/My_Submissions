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
    string number;
    cin >> number;
    int map[10];
    for (int i=1;i<=9;++i) {
        int x;
        cin >> x;
        map[i] = x;
    }
    int frq[n+1];
    clr(frq,0);
    bool fg = true;
    int ff = -1;
    for (int i=0;i<n;++i) {
        int num = number[i] - '0';
        if (map[num] > num) {
            frq[i] = 1;
            if (ff==-1) ff = i;
        }
        else if (map[num] == num) frq[i] = 2;
    }
    if (ff == -1) {
        cout << number;
        return;
    }
    // for (auto i : frq) cout << i << ' ';
    while(frq[ff] != 0) {
        number[ff] = '0' + map[number[ff]-'0'];
        ff++;
    }
    cout << number;
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
