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
void solve(int arg) {
    string s;
    cin>>s;
    bool check = true;
    for (int i=0; i<s.length()-1; i++) { //O(N)
        if (s[i] < s[i+1]) {
            check = false;
            break;
        }
    }
    if (check) {
        cout<<"Case #"<<arg<<": "<<s<<endl;
        return;
    }

    string final;
    for (int i=0; i<s.length(); i++) { //O(N)
        if (i == s.length()-1) {
            final.PB((char)s[i]);
            break;
        }
        if (s[i] == s[i+1]) {
            bool check = 1;
            int j = i+1;
            for (; j<s.length(); j++) {
                if (s[j] != s[i]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                final.PB(s[i]);
                continue;
            }
            if (s[j] > s[i]) {
                final.PB(s[i]);
                final.PB(s[i]);
                continue;
            } else {
                final.PB(s[i]);
                continue;
            }
        }
        if (s[i]<=s[i+1]) {
            final.PB((char)s[i]);
            final.PB((char)s[i]);
        } else {
            final.PB((char)s[i]);
        }
    }
    cout<<"Case #"<<arg<<": "<<final<<endl;
    return;
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