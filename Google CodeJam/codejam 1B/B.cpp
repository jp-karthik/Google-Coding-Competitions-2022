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
    int n, p;
    cin>>n>>p;
    vector<vector<ll>> v(n, vector<ll>(p));
    for (int i=0; i<n; i++) {
        for (int j=0; j<p; j++) {
            cin>>v[i][j];
        }
    }
    vector<pair<ll, ll>> info(n);
    for (int i=0; i<n; i++) {
        info[i].first = *min_element(v[i].begin(), v[i].end());
        info[i].second = *max_element(v[i].begin(), v[i].end());
    }
    vector<vector<ll>> dp(n, vector<ll>(2, -1));
    ll l0 = 0;
    ll l1 = 0;
    for (int i=0; i<n; i++) {
        if (i == 0) {
            dp[i][0] = abs(info[i].first-info[i].second)+info[i].second;
            dp[i][1] = abs(info[i].first-info[i].second)+info[i].first;
            l0 = info[i].first;
            l1 = info[i].second;
            continue;
        }
        dp[i][0] = abs(info[i].first-info[i].second)+ min(dp[i-1][0] + abs(l0-info[i].second), dp[i-1][1] + abs(l1-info[i].second));
        dp[i][1] = abs(info[i].first-info[i].second)+ min(dp[i-1][0] + abs(l0-info[i].first), dp[i-1][1] + abs(l1-info[i].first));
        l0 = info[i].first;
        l1 = info[i].second;
    }
    cout<<min(dp[n-1][0], dp[n-1][1])<<endl;
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