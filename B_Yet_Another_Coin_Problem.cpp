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

// 1 3 6 10 15
// 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
// 1,2,1,2,3,1,2,3,2,3 ,2, 2 ,2 ,3 ,1 

void solve()
{
    int n;
    cin >> n;
    // we will not use more than (1 3 6 10 15)
    /*
    two 1s
    one 3
    four 6s
    two 10s
    */
    ll ans = OO;
    for (int one=0;one<=2;++one) {
        for (int thr=0;thr<=1;++thr) {
            for (int si=0;si<=4;++si) {
                for (int te=0;te<=2;++te) {
                    ll sum = 1*one + thr*3 + si*6 + te*10;
                    if (sum <= n && (n-sum)%15 == 0) {
                        ans = min(ans, one + thr+ si+te + (n-sum)/15);
                    }
                }
            }
        }
    }
    cout << ans;
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
