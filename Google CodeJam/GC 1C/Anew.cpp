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
vector<string> per;
void permute(string s, int l, int r)
{
   // Base case
   if (l == r) per.PB(s);
   else
   {
      for (int i = l; i <= r; i++)
      {

          // Function to swap
          swap(s[l], s[i]);

          // Recursion called
          permute(s, l+1, r);

          //backtrack
          swap(s[l], s[i]);
        }
    }
}
bool check(string s) {
    vi nums;
    nums.PB(s[0]);
    for (int i=1; i<s.length(); i++) {
        if (s[i] == s[i-1]) {
            continue;
        }
        if (s[i] != s[i-1]) {
            for (int j=0; j<nums.size(); j++) {
                if (nums[j] == s[i]) {
                    return false;
                }
            }
            nums.PB(s[i]);
        }
    }
    return true;
}
void solve(int arg) {
    int n;
    cin>>n;

    vector<string> v(n);
    REP(i, 0, n-1) cin>>v[i];

    string nums;
    for (int i=0; i<n; i++) {
        nums.push_back(i);
    }
    permute(nums, 0, n-1);

    for (int i=0; i<per.size(); i++) { //each per
        string final;
        int j=0;
        for (; j<n; j++) { //each string
            final.append(v[per[i][j]]);
            bool res = check(final);
            if (check) {
                continue;
            } else {
                break;
            }
        }
        if (j == n) {
            cout<<final<<endl;
            return;
    }
    }
    cout<<"NO"<<endl;
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