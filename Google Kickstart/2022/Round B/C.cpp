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
    int n, d;
    cin>>n>>d;
    vll v(n);
    REP(i, 0, n-1) cin>>v[i];
    ll c0 = 0;
    ll c1 = 0;
    for (int i=0; i<n; i++) {
        if (v[i] == 0) {
            c0++;
            int j = i;
            while (j < n && v[j] == 0) {
                j++;
            }
            if (j == n) {
                break;
            }
            i = j-1;
            continue;
        } 
        if (v[i] == 1) {
            c1++;
            int j = i;
            while (j < n && v[j] == 1) {
                j++;
            }
            if (j == n) {
                break;
            }
            i = j-1;
            continue;
        }
    }
    if (c1 == 0) {
        cout<<"Case #"<<arg<<": "<<0<<endl;
        return;
    }
    if (c0 == 0) {
        cout<<"Case #"<<arg<<": "<<1<<endl;
        return;
    }
    if (c1 > c0) {
        cout<<"Case #"<<arg<<": "<<c0+1<<endl;
        return;
    }
    if (c0 > c1) {
        cout<<"Case #"<<arg<<": "<<c1<<endl;
        return;
    }
    if (c0 == c1) {
        cout<<"Case #"<<arg<<": "<<c0<<endl;
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
        t--;
        arg++;
    };
    return 0;
}