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
int equal(vector<int>& nums, int i, int sum, vector<vector<int>>& dp, vector<int>& res) {
    if (sum == 0) {
        return 1;
    }
    if (dp[i][sum] != -1) {
        return dp[i][sum];
    }
    if (nums[i] <= sum) {
        vector<int> res1;
        int b1 = equal(nums, i+1, sum-nums[i], dp, res1);
        if (b1) {
            for (int i=0; i<res1.size(); i++) {
                res.PB(res1[i]);
            } 
            res.PB(nums[i]);
            return 1;
        }
        vector<int> res2;
        int b2 = equal(nums, i+1, sum, dp, res2);
        if (b2) {
            for (int i=0; i<res2.size(); i++) {
                res.PB(res2[i]);
            } 
            return 1;
        } 
        return 0;
    } else {
        vector<int> res2;
        int b2 = equal(nums, i+1, sum, dp, res2);
        if (b2) {
            for (int i=0; i<res2.size(); i++) {
                res.PB(res2[i]);
            } 
            return 1;
        }
        return 0;
    }
}
void solve() {
    int N;
    cin>>N;
    vector<int> my(N);
    for (int i=0; i<N; i++) {
        my[i] = i+1;
        // cout<<i+1<<" ";
    }
    // cout<<endl;
    for (int i=0; i<N; i++) {
        int temp;
        cin>>temp;
        my.PB(temp);
    }
    int sum = 0;
    for (int i=0; i<2*N; i++) {
        sum += my[i];
    }
    vector<vector<int>> dp(N+1, vector<int>(sum+1,-1));
    for (int i=0; i<=N; i++) {
        dp[i][0] = 1;
    }
    for (int i=1; i<=sum+1; i++) {
        dp[0][i] = 0;
    }
    vector<int> res;
    int resBool = equal(my, 0, sum/2, dp, res);
    if (resBool) {
        for (int i=0; i<res.size(); i++) {
            cout<<res[i]<<" ";
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
    while(t > 0) {
        solve(); 
        t--;
    };
    return 0;
}