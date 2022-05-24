#include <bits/stdc++.h>
using namespace std;
// -------------------
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<long, long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<long long, long long>> vpll;
// --------------------
#define PB push_back
#define REP(i, a, b) for(int i=a; i<=b; i++)
#define sort(v) sort(v.begin(), v.end())
//------------------
bool dec(int x, int y) {
    return x>y;
}
bool inc(int x, int y) {
    return x<y;
}
//-----------------
void solve(int arg) {
    ll R, C;
    cin>>R>>C;
    vector<vector<char>> v(2*R, vector<char>(2*C));
    vector<vector<bool>> b(2*R, vector<bool>(2*C, false));
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            char x;
            cin>>x;
            v[2*i][2*j] = v[2*i+1][2*j+1] = v[2*i][2*j+1] = v[2*i+1][2*j] = x;
        }
    }

    //S => down
    //N => up
    //E => right
    //W => left
    ll x = 0;
    ll y = 0;
    cout<<"Case #"<<arg<<": ";
    while (1) {
        while (x < 2*R-1 && v[x+1][y] == '*'  && b[x+1][y] == 0) {
            b[x+1][y] = 1;
            cout<<"S";
            x++;
        } 


        while (y < 2*C-1 && v[x][y+1] == '*' && b[x][y+1] == 0) {
            b[x][y+1] = 1;
            y++;
            cout<<"E";
        }

        if ( x > 0 && v[x-1][y] == '*' && b[x-1][y] == 0) {
            x--; //up
            cout<<"N";
            b[x][y] = 1;
        }
       
        while (y > 0 && v[x][y-1] == '*' && b[x][y-1] == 0) {
            if (x == 0 && y == 1) {
                cout<<"W"<<endl;
                return;
            }
            b[x][y] = 1;
            y--;
            cout<<"W";
        }

        //highlighting
        if (x == 0 && y-1 == 0) {
            cout<<" Goal"<<endl;
            return;
        }

        if ( x > 0 && v[x-1][y] == '*' && b[x-1][y] == 0) {
            x--; //up
            cout<<"N";
            b[x][y] = 1;
        }
       

        while (y < 2*C-1 && v[x][y+1] == '*' && b[x][y+1] == 0) {
            b[x][y] = 1;
            y++;
            cout<<"E";
        }
    }
    

    cout<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    int arg = 1;
    cin>>t;
    while(t > 0) {
        solve(arg);
        t--;
        arg++;
    };
    return 0;
}