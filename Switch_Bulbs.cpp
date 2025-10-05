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
// 2
// 3 3
// 3 0 1 2
// 2 1 2
// 1 2
// 3
// 101
// 010
// 111
// 4 5
// 1 0
// 1 1
// 2 2 3
// 3 0 1 3
// 2 2 3
// 3
// 1111
// 1010
// 0101
int Bulbs,Switches;
const int N = 4e1+5;
vector<vector<int>> Switch(N);
string res;
unordered_map<string,int>Dis;

void bfs() {
    string str;
    for (int i=0;i<Bulbs;++i) {
        str+='0';
    }
    queue<string>q;
    Dis[str] = 0;
    q.push(str);
    while(!q.empty()) {
        string node = q.front();
        q.pop();
        for (int i=0;i<Switches;++i) {
            string temp = node;
            for (auto j : Switch[i]) {
                temp[Bulbs-j-1] = temp[Bulbs-j-1] == '1'? '0' : '1';
            }
            if (Dis.count(temp) == 0) {
                Dis[temp] = Dis[node]+1;
                q.push(temp);
            }
        }
    }
}

void solve(int tc)
{
    cin >> Bulbs >> Switches;
    for (int i=0;i<Switches;++i) {
        int n;
        cin >> n;
        for (int j=0;j<n;++j) {
            int x;
            cin >> x;
            Switch[i].pb(x);
        }
    }
    int q;
    cin >> q;
    cout << "Case " << tc << ":" << el;
    bfs();
    while(q--) {
        cin >> res;
        if (Dis.count(res)== 0) cout << -1;
        else cout << Dis[res];
        cout << el;
    }
}

int main()
{
    ishowspeed
    int tc = 1;
    cin >> tc;
    for (int i=1;i<=tc;++i)
    {
        solve(i);
        Dis.clear();
        for (int i=0;i<Switches;++i) {
            Switch[i].clear();
        }
        cout << el;
    }
}
