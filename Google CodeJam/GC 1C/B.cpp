#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<long, long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<long long, long long>> vpll;

#define PB push_back
#define REP(i, a, b) for(int i=a; i<=b; i++)
#define sort(v) sort(v.begin(), v.end())

bool dec(int x, int y) {
    return x>y;
}
bool inc(int x, int y) {
    return x<y;
}

void solve(int arg) {
    int n, k;
    cin>>n>>k;
    vll v(n);
    REP(i, 0, n-1) cin>>v[i];
    ll s0 = 0;
    ll s1 = 0;
    for (int i=0; i<v.size(); i++) {
        s0 += v[i];
        s1 += v[i]*v[i];
    }
    if (s0 == 0 && s1 == 0) {
        cout<<"Case #"<<arg<<": ";
        cout<<1<<endl;
        return;
    } else if (s0 == 0 && s1 != 0) {
         cout<<"Case #"<<arg<<": ";
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    if ((s1-s0*s0)%(2*s0) == 0) {
        cout<<"Case #"<<arg<<": ";
        cout<<(s1-s0*s0)/(2*s0)<<endl;
        return;
    } else {
        cout<<"Case #"<<arg<<": ";
        cout<<"IMPOSSIBLE"<<endl;
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