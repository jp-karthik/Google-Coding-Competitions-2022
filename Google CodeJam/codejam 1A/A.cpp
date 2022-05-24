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
        if (s[i] >= s[i+1]) {
            continue;
        } else {
            check = false; 
            break;
        }
    }
    if (check) {
        cout<<"Case #"<<arg<<": "<<s<<endl;
        return;
    }
    vector<pair<char, int>> vec(s.length());
    map<int, char> map;

    for (int i=0; i<s.length(); i++) { //O(N)
        vec[i] = {s[i], i};
    } 

    sort(vec.begin(), vec.end()); //O(NlogN) lexigrahically

    for (int i=0; i<s.length(); i++) { //O(NlogN)
        map[vec[i].second] = vec[i].first;
    }

    string final;
    for (int i=0; i<s.length(); i++) { //O(NlogN)
        if (i == s.length()-1) {
            final.PB(map[i]);
            break;
        }
        if (i < s.length()-1 && s[i+1]>=s[i]) {
            final.PB(map[i]);
            final.PB(map[i]);
        } else {
            final.PB(map[i]);
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