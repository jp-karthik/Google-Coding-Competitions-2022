#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<long, long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<long long, long long>> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define rep(a, b) for(ll i=a; i<=b; i++)
#define Sort(v) sort(v.begin(), v.end())
#define revSort(v) sort(v.begin(), v.end(), greater<ll>())
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define PI 3.141592653589793238462
#define MOD 1000000007
#define INF 1e18


#ifndef ONLINE_JUDGE
	#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
	#define debug(x)
#endif 

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void solve(int arg) {
 	int n;
 	string s;
 	cin >> n >> s;
 	bool digit = false, cap = false, small = false, spl = false;
 	for (int i = 0; i < n; i++) {
 		if (s[i] >= 'A' && s[i] <= 'Z') {
 			cap = true;
 		}
 		if (s[i] >= 'a' && s[i] <= 'z') {
 			small = true;
 		}
 		if (s[i] >= '0' && s[i] <= '9') {
 			digit = true;
 		}
 		if (s[i] == '#' || s[i] == '@' || s[i] == '*' || s[i] == '&') {
 			spl = true;
 		}
 	}
 	if (s.length() >= 7) {
 		if (!cap) {
 			s.pb('A');
 		}
 		if (!small) {
 			s.pb('a');
 		}
 		if (!digit) {
 			s.pb('0');
 		}
 		if (!spl) {
 			s.pb('#');
 		}
 		cout << "Case #" << arg << ": " << s << endl;
 	} else {
 		if (!cap) {
 			s.pb('A');
 		}
 		if (!small) {
 			s.pb('a');
 		}
 		if (!digit) {
 			s.pb('0');
 		}
 		if (!spl) {
 			s.pb('#');
 		}
 		if (s.length() < 7) {
 			int rem = 7-s.length();
 			for (int i = 0; i < rem; i++) {
 				s.pb('A');
 			}
 		}
 		cout << "Case #" << arg << ": " << s << endl;
 	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("error.txt", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	int arg = 1;
	cin >> t;
	while(t > 0) {
	    solve(arg);
	    t--;
	    arg++;
	}
	return 0;
}