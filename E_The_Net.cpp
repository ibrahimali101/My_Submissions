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
const int N = 3e2 + 2;
int Dis[N];
int Par[N];
vector<vector<int>>adj;

void init(int n) {
    adj.resize(n+1);
    for (int i=1;i<=n;++i) {
        adj[i].clear();
    }
}

bool bfs(int st,int en) {
    queue<int>q;
    q.push(st);
    Dis[st] = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto i : adj[node]) {
            if (Dis[i] == -1) {
                Dis[i] = Dis[node]+1, Par[i] = node;
                if (i == en) return true;
                q.push(i);
            }
        }
    }
    return false;
}

int main()
{
    ishowspeed
    int n;
    while(cin >> n)
    {
        init(n);
        for (int j=1;j<=n;++j) {
            string temp;
            cin >> temp;
            int i = 0;
            for (;temp[i]!='-';++i) ;
            for (;i<temp.size();++i) {
                if (i<temp.size()-2 && isdigit(temp[i+2]) && isdigit(temp[i+1]) && isdigit(temp[i])) {
                    adj[j].pb((temp[i]-'0')*100 + (temp[i+1]-'0')*10 + (temp[i]-'0'));
                    i+=2;
                    continue;
                }
                if (i<temp.size()-1 && isdigit(temp[i+1]) && isdigit(temp[i])) {
                    adj[j].pb((temp[i]-'0')*10 + (temp[i+1]-'0'));
                    i++;
                    continue;
                }
                if (isdigit(temp[i])) {
                    adj[j].pb(temp[i]-'0');
                }
            }
        }
        int m;
        cin >> m;
        cout << "-----\n";
        while(m--) {
            clr(Dis,-1);
            clr(Par,-1);
            int u,v;
            cin >> u >> v;
            if (bfs(u,v)) {
                int x = v;
                stack<int>s;
                while(x != -1) {
                    s.push(x);
                    x = Par[x];
                }
                while(!s.empty()) {
                    cout << s.top();
                    if (s.size() != 1) cout << ' ';
                    s.pop();
                }
            }
            else {
                cout << "connection impossible";
            }
            cout << el;
        }
    }
}
