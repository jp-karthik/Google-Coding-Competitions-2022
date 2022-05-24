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
    int n;
    cin>>n;
    deque<int> v(n);
    REP(i, 0, n-1) cin>>v[i];
    int Min = INT_MIN;
    ll count = 0;
    while(v.size()) {
        if (v.size() == 1) {
            if (v[0] >= Min) {
                count++;
                break;
            }
            break;
        }
        while (v.size() != 0 && v.front() < Min) {
            v.pop_front();
        }
        while (v.size() != 0 && v.back() < Min) {
            v.pop_back();
        }
        if (v.size() == 0) {
            break;
        }
        if (v.front() < v.back()) {
            if (Min < v.front())  Min = v.front();
            v.pop_front();
            count++;
            continue;
        } else {
            if (Min < v.back()) Min = v.back();
            v.pop_back();
            count++;
            continue;
        } 
    }
   cout<<"Case #"<<arg<<": ";
   cout<<count<<endl;
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