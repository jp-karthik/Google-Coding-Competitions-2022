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
string rec(vector<string> v, int start, int end) {
    //base case
    if (start == end) {
        return v[start];
    }
    for (int i=start; i<end; i++) {
        string s1 = rec(v, start, i);
        string s2 = rec(v, i+1, end);
        if (s1.size() && s2.size()) {
            //valid solution
            ll count = 0;
            ll count2;

            for (int i=0; i<s1.size(); i++) {
                for (int j=0; j<s2.size(); j++) {
                    if (s1[i] == s2[j]) {
                        count++;
                    }
                }
            }

            count2 = count;

            if (s1[s1.size()-1] != s2[0] || s1[0] != s2[s2.size()-1]) {
                if (count) continue; //no ans here
            }

            if (!count) {
                s1 += s2;
                return s1; 
            }

            //1st case
            if (s1[s1.size()-1] == s2[0]) {
                int j1 = s1.size()-1;
                int j2 = 0;
                while (j1>=0 && s1[j1] == s1[s1.size()-1]) {
                    if (s1[j1] == s1[s1.size()-1]) {
                        count--;
                        j1--;
                    }
                }
                while (j2<=s2.size()-1 && s2[j2] == s2[0]) {
                    if (s2[j2] == s2[0]) {
                        count--;
                        j2++;
                    }
                }
                if (count > 0) {
                    continue;
                } else {
                    s1 += s2;
                    return s1; 
                }
            }
            
            //2nd case 
            if (s1[0] == s2[s2.size()-1]) {
                int j1 = 1;
                int j2 = s2.size()-1;
                while (j1<=s1.size()-1 && s1[j1] == s1[0]) {
                    if (s1[j1] == s1[0]) {
                        count2--;
                        j1++;
                    }
                }
                while (j2>=0 && s2[j2] == s2[s2.size()-1]) {
                    if (s2[j2] == s2[s2.size()-1]) {
                        count2--;
                        j2--;
                    }
                }
                if (count2 > 0) {
                    continue;
                } else {
                    s2 += s1;
                    return s2; 
                }
            }
        }

    }
    return "";
}
void solve(int arg) {
    int n;
    cin>>n;
    vector<string> v(n);
    REP(i, 0, n-1) cin>>v[i];
    //internal check
    for (int i=0; i<n; i++) {
        ll lc = 1;
        for (int j=0; j<v[i].length(); j++) {
            for (int k=j+1; k<v[i].length(); k++) {
                if (v[i][j] == v[i][k]) {
                    lc++;
                }
            }
        }
        ll fc = 1;
        ll bc = 1;
        for (int j=0; j<v[i].length()-1; j++) {
            if (v[i][j] == v[i][j+1]) {
                fc++;
            } else {
                break;
            }
        }
        for (int j=v[i].length()-1; j>0; j--) {
            if (v[i][j] == v[i][j-1]) {
                bc++;
            } else {
                break;
            }
        }
        cout<<lc<<" "<<fc<<" "<<bc<<endl;
    }
    cout<<endl;
    // cout<<rec(v, 0, n-1)<<endl;
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