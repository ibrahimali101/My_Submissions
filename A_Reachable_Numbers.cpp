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

unordered_set<int>nums;

void solve()
{
    ll n;
    cin >> n;
    int x = n;
    while(!nums.count(x)) {
        nums.insert(x);
        x++;
        int j = 0;
        int temp = 0;
        bool flag = true;
        while(x > 0) {
            temp+= x%10 * pow(10,j);
            if (x%10 != 0) flag = false;
            x/=10;
            if (flag) {
                continue;
            }
            j++;
        }
        x = temp;
    }
    cout << nums.size();
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
