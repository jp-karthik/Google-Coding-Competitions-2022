#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
#define PB push_back;
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
    int n;
    cin>>n;
    vector<int> v(n);
    REP(i, 0, n-1) cin>>v[i];
    sort(v.begin(), v.end());
    int length =  0;
    for (int i=0; i<v.size();) {
        if (v[i] <= length) {
            i++;
            continue;
        }
        if (v[i] > length) {
            if (i+v[i]-length-1 < v.size()) {
                int temp = v[i]-length;
                length += v[i]-length;
                i += temp;
            } else {
                length += v.size()-i;
                break;
            }
        } 
    }
    cout<<"Case #"<<arg<<": "<<length<<endl;
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