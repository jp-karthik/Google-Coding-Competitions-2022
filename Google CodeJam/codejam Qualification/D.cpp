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
long long getMax(int root, vector<long long>& val, vector<vector<int>>& antiMap) {
    long long max = LLONG_MIN;
    for (int i=0; i<antiMap[root].size(); i++) {
        long long temp = getMax(antiMap[root][i], val, antiMap);
        if (temp > max) {
            max = temp;
        }
    }
    if (max > val[root]) {
        return max;
    } else {
        return val[root];
    }
}
long long total = 0;
void chainReaction(int root, vector<vector<int>>& antiMap, vector<long long>& val, vector<int>& visited) {
    //base case
    if (antiMap[root].size() == 0){
        visited[root] = 1;
        total += val[root];
        return;
    } 
    int bestChild = -1;
    long long min = LLONG_MAX;
    for (int i=0; i<antiMap[root].size(); i++) {
        if (!visited[antiMap[root][i]]) {
            long long temp = getMax(antiMap[root][i], val, antiMap);
            if (temp < min) {
                bestChild = antiMap[root][i];
                min = temp;
            }
        }
    }
    if (val[root] > val[bestChild]) {
        val[bestChild] = val[root];
    }
    for (int i=0; i<antiMap[root].size(); i++) {
        if (!visited[antiMap[root][i]]) {
            visited[antiMap[root][i]] = 1;
            chainReaction(antiMap[root][i], antiMap, val, visited);
        }
    }
}
void solve(int arg) {
    int n;
    cin>>n;
    vector<long long> val(n+1);
    vector<int> map(n+1);
    vector<int> roots;
    vector<int> visited(n+1);
    vector<vector<int>> antiMap(n+1);
    REP(i, 1, n) cin>>val[i];
    REP(i, 1, n) cin>>map[i];
    REP(i, 1, n) {
        if (map[i] == 0) {
            roots.PB(i);
        }
        if (map[i]) antiMap[map[i]].push_back(i);
    }
    for (int i=0; i<roots.size(); i++) {
        chainReaction(roots[i], antiMap, val, visited);
    }
    cout<<"Case #"<<arg<<": "<<total<<endl;
    total = 0;
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
        t--;
        arg++;
    };
    return 0;
}