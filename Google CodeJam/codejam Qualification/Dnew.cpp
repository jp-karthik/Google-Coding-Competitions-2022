#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
#define PB push_back
#define REP(i, a, b) for(int i=a; i<=b; i++)
//------------------
bool dec(int x, int y) {
    return x>y;
}
bool inc(int x, int y) {
    return x<y;
}
//-----------------

unsigned long long getMax(unsigned long long root, vector<unsigned long long>& val, vector<vector<unsigned long long>>& antiMap, vector<unsigned long long>& dp) {
    if (dp[root] != -1) return dp[root];
    unsigned long long max = 0;
    for (unsigned long long i=0; i<antiMap[root].size(); i++) {
        unsigned long long temp = getMax(antiMap[root][i], val, antiMap, dp);
        if (temp > max) {
            max = temp;
        }
    }
    if (max > val[root]) {
        return dp[root] = max;
    } else {
        return dp[root] = val[root];
    }
}
unsigned long long total = 0;
void chainReaction(unsigned long long root, vector<vector<unsigned long long>>& antiMap, vector<unsigned long long>& val, vector<unsigned long long>& dp) {
    //base case
    if (antiMap[root].size() == 0){
        total += val[root];
        return;
    } 
    unsigned long long bestChild = antiMap[root][0];
    unsigned long long min = ULLONG_MAX;
    for (unsigned long long i=0; i<antiMap[root].size(); i++) {
        unsigned long long temp = getMax(antiMap[root][i], val, antiMap, dp);
        if (temp < min) {
            bestChild = antiMap[root][i];
            min = temp;
        }
    }
    if (val[root] >= val[bestChild]) {
        val[bestChild] = val[root];
    }
    for (unsigned long long i=0; i<antiMap[root].size(); i++) {
        chainReaction(antiMap[root][i], antiMap, val, dp);
    }
}
void solve(unsigned long long arg) {
    unsigned long long n;
    cin>>n;
    vector<unsigned long long> val(n+1);
    vector<unsigned long long> map(n+1);
    vector<unsigned long long> roots;
    vector<unsigned long long> visited(n+1);
    vector<vector<unsigned long long>> antiMap(n+1);
    vector<unsigned long long> dp(n+1, -1);
    
    for(unsigned long long i = 1; i<=n; i++) cin>>val[i];
    for(unsigned long long i = 1; i<=n; i++) cin>>map[i];
    for(unsigned long long i = 1; i<=n; i++) {
        if (map[i] == 0) {
            roots.PB(i);
        }
        if (map[i]) antiMap[map[i]].push_back(i);
    }
    dp[n] = val[n];
    for (unsigned long long i=0; i<roots.size(); i++) {
        chainReaction(roots[i], antiMap, val, dp);
    }
    cout<<"Case #"<<arg<<": "<<total<<endl;
    total = 0;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif                          
    unsigned long long t;
    cin>>t;
    unsigned long long arg = 1;
    while(t > 0) {
        solve(arg); 
        t--;
        arg++;
    };
    return 0;
}