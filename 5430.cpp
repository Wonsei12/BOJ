#define LOCAL

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define LLINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define uniq(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
#define sz(x) (int)x.size()
#define pw(x) (1LL<<x)

using pii = pair<int, int>;
using ll = long long;
const ll MOD = 1e9 + 7;
const long double PI = acos(-1.0);

// Copied from Gennady-Korotkevich's template

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string)s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}\n";
	return res;
}

template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto& x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}\n";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + "," + to_string(get<4>(p)) + ")";
}

void debug_out() {
	cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "\n[" << #__VA_ARGS__ << "]:\n", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// End of Gennady-Korotkevich's template 


void solve() {
	string m; cin >> m;
	int n; cin >> n;
	string s; cin >> s;
	int tmp = 0;
	vector<int> a;
	for(int i=1 ; i<sz(s)-1 ; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			tmp *= 10;
			tmp += s[i]-'0';
		} else {
			a.push_back(tmp);
			tmp = 0;
		}
	}
	a.push_back(tmp);
	if(n==0) {
		for(int i=0 ; i<sz(m) ; i++) {
			if(m[i]=='D') {
				cout << "error\n";
				return; 
			} 
		}
		cout << "[]\n";
		return;
	}
	bool back = false;
	int st=0,e=sz(a)-1;
	for(int i=0 ; i<sz(m) ; i++) {
		if(m[i]=='R') {
			back=!back;
		}
		else {
			if(back)
				e-=1;
			else
				st+=1;
		}
	}
	if(st>e+1) {
		cout << "error\n";
	} else if(st==e+1) {
		cout << "[]\n";
	} else {
		if(!back) {
			cout << "[";
			for(int i=st ; i<e ; i++) {
				cout << a[i] << ",";
			}
			cout << a[e] << "]";
			cout << "\n";
		} else {
			cout << "[";
			for(int i=e ; i>st ; i--) {
				cout << a[i] << ",";
			}
			cout << a[st] << "]";
			cout << "\n";
		}
	}
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}