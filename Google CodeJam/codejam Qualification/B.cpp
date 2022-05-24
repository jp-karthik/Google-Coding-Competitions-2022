#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
#define PB push_back;
#define REP(i, a, b) for(int i=a; i<=b; i++)
//------------------
bool dec(int x, int y) {
    return x>y;
}
bool inc(int x, int y) {
    return x<y;
}
//-----------------
void solve(int arg) {
    vector<vector<int>> v(3, vector<int>(4)) ;
    vector<int> res(4);
    REP(i, 0, 2) {
        REP(j, 0, 3) {
            cin>>v[i][j];
        }
    }
    int minSum = 0;
    for (int i=0; i<4; i++) {
        int curr = min(v[0][i], min(v[1][i], v[2][i]));
        minSum += curr;
        res[i] = curr;
    }
    if (minSum >= 1000000) {
        cout<<"Case #"<<arg<<": ";
        int sum = 0;
        for (int i=0; i<4; i++) {
            if (sum + res[i] <= 1000000) {
                sum += res[i];
                cout<<res[i]<<" ";
            } else {
                cout<<1000000-sum<<" ";
                sum = 1000000;
                for (int j=0; j<3-i; j++) {
                    cout<<0<<" ";
                }
                break;
            }
            if (sum == 1000000) {
                for (int j=0; j<3-i; j++) {
                    cout<<0<<" ";
                }
                break;
            }
        }
        cout<<endl;
    } else {
        cout<<"Case #"<<arg<<": "<<"IMPOSSIBLE"<<endl;
    }
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
        arg++;
        t--;
    };
    return 0;
}