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
    int R, C;
    cin>>R>>C; 
    cout<<"Case #"<<arg<<":"<<endl;
    for (int i=1; i<=2*R+1; i++) {
        for (int j=1; j<=2*C+1; j++) {
            if ((i == 1 && j== 1 )|| (i == 1 && j == 2) || (i == 2 && j == 1) || (i == 2 && j == 2)) {
                cout<<'.';
                continue;
            }
            if (i%2 == 0) {
                if (j%2 == 0) {
                    cout<<'.';
                } else {
                    cout<<'|';
                }
            } else {
                if (j%2 == 0) {
                    cout<<'-';
                } else {
                    cout<<'+';
                }
            }
        }
        cout<<endl;
    }
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    int arg = 1;
    while(t > 0) {
        solve(arg);
        arg++; 
        t--;
    };
    return 0;
}