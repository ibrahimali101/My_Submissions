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
    int k;
    cin >> k;
    int cy = 1, node = 3;
    vector<vector<int>>Mat(101,vector<int>(101,0));
    Mat[1][2] = Mat[2][1] = 1;
    Mat[2][3] = Mat[3][2] = 1;
    Mat[3][1] = Mat[1][3] = 1;
    while(cy != k) {
        node++;
        int i=1;
        for (int i=1;i<node;++i) {
            int gain = i-1;
            if (cy+gain <= k) {
                cy+=gain;
                for (int j=1;j<=i;++j) {
                    Mat[node][j] = Mat[j][node] = 1;
                }
            }
        }
    }
    cout << node << el;
    for (int i=1;i<=node;++i) {
        for (int j=1;j<=node;++j)
            cout << Mat[i][j];
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
