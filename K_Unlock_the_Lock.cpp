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
int st,en,btn;
const int N = 1e5;
int btns[12], Dis[N];

int make(int a) {
    int num[4];
    int k = 3;
    while(k >= 0) {
        num[k] = a%10;
        a/=10;
        k--;
    }
    return (num[0]*1000 + num[1]*100 + num[2]*10 + num[3]);
}

int bfs() {
    queue<int>q;
    q.push(st);
    while(!q.empty()) {
        int node = q.front();
        if (node == en) return Dis[en];
        q.pop();
        for (int i=0;i<btn;++i) {
            int val = make(node+btns[i]);
            if (Dis[val] == -1) {
                Dis[val] = Dis[node] + 1;
                q.push(val);
            }
        }
    }
    return -1;
}

int main()
{
    ishowspeed
    int tc = 1;
    while(cin >> st >> en >> btn && st || en || btn)
    {
        clr(Dis,-1);
        for (int i=0;i<btn;++i)
            cin >> btns[i];
        int ans = bfs();
        cout << "Case " << tc << ": ";
        if (ans != -1) cout << ans+1;
        else cout << "Permanently Locked";
        cout << el;
        tc++;
    }
}
