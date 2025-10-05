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
using pii = pair<string,string>;
const int N = 1e1 + 5;
string st,en;
int n;
pii tools[N];
unordered_map<string,int>dist;
int bfs() {
    queue<string>q;
    q.push(st);
    dist[st] = 0;
    while(!q.empty()) {
        string node = q.front();
        q.pop();
        if (node == en) return dist[en];
        for (int i=0;i<n;++i) {
            int sz = tools[i].fi.size();
            int sz2 = tools[i].se.size();
            string temp = node;
            for (int j=0;j<temp.size();++j) {
                if (temp.size() > 10) break;
                string sub = temp.substr(j,sz);
                if (sub == tools[i].fi) {
                    temp.replace(j,sz,tools[i].se);
                    j+=sz2-1;
                }
            }
            if (dist.count(temp) == 0) {
                dist[temp] = dist[node] + 1;
                q.push(temp);
            }
        }
    }
    return -1;
}

int main()
{
    ishowspeed
    while(cin >> n)
    {
        dist.clear();
        if (n==0) return 0;
        string rep,rep2;
        for (int i=0;i<n;++i) {
            cin >> tools[i].fi >> tools[i].se;
        }
        cin >> st >> en;
        cout << bfs() << el;
    }
}
