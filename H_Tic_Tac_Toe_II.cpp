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
#define ishowspeed ios_base::sync_with_stdio(false);
using int64 = ll;
using namespace std;
const int mod = 1e9+7, OO = 0x3f3f3f3f;
const int N = 1e4 + 8;
string dest_board;
bool win(string board) {
    if (board[2] == board[4] && board[4] == board[6] && board[6] != '.') return true;
    if (board[0] == board[4] && board[4] == board[8] && board[8] != '.') return true;
    
    if (board[0] == board[1] && board[1] == board[2] && board[2] != '.') return true;
    if (board[3] == board[4] && board[4] == board[5] && board[5] != '.') return true;
    if (board[6] == board[7] && board[7] == board[8] && board[8] != '.') return true;

    if (board[2] == board[5] && board[5] == board[8] && board[8] != '.') return true;
    if (board[1] == board[4] && board[4] == board[7] && board[7] != '.') return true;
    if (board[0] == board[3] && board[3] == board[6] && board[6] != '.') return true;

    return false;
}

bool bfs() {
    string start = ".........";
    pair<string,bool> node = {start,0};
    queue<pair<string,bool>> q;
    q.push(node);
    while(!q.empty()) {
        pair<string,bool> Node = q.front();
        q.pop();
        if (dest_board == Node.fi) return true;
        if (win(Node.fi)) continue;
        for (int i=0;i<9;++i) {
            if (Node.fi[i] == '.') {
                Node.fi[i] = Node.se ? 'O' : 'X';
                if (dest_board[i] == Node.fi[i]) q.push({Node.fi,!Node.se});
                Node.fi[i] = '.';
            }
        }
    }
    return false;
}

int main()
{
    ishowspeed
    while(true)
    {
        cin >> dest_board;
        if (dest_board == "end") return 0;
        bool fg = bfs();
        if (!win(dest_board)) {
            for (auto i : dest_board) if (i == '.') fg&=0; 
        }
        cout << (fg ? "valid" : "invalid");
        cout << el;
    }
}