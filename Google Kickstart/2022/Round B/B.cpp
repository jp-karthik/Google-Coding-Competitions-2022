#include <bits/stdc++.h>
using namespace std;
// -------------------
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<long, long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<long long, long long>> vpll;
// --------------------
#define PB push_back
#define REP(i, a, b) for(int i=a; i<=b; i++)
#define sort(v) sort(v.begin(), v.end())
//------------------
bool dec(int x, int y) {
    return x>y;
}
bool inc(int x, int y) {
    return x<y;
}
//-----------------
bool palindrome(ll n) {
    ll reversed = 0, remainder, original;
   
    original = n;
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    if (original == reversed)
        return true;
    else
       return false;

}
vector<ll> factors(ll x) {
    vector <ll> result;
    ll i = 1;
    while(i*i <= x) {
        if(x % i == 0) {
            result.push_back(i);
            if(x/i != i) {
                result.push_back(x/i);
            }
        }
        i++;
    }
    return result;
}

void solve(int arg) {
    ll n;
    cin>>n;

    vector<ll> v = factors(n);
    ll res = 0;
    for (int i=0; i<v.size(); i++) {
        if (palindrome(v[i])) {
            res++;
        }
    }
    cout<<"Case #"<<arg<<": "<<res<<endl;
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