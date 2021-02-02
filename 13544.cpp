#include <bits/stdc++.h>
using namespace std;

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

#define LOCAL

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

int n;
vector<ll> a;

class SegmentTree {
public:
	vector<vector<ll>> seg;
	int n;
	SegmentTree(int n) {
		seg.resize(4 * n + 5);
		this->n = n;
		build_(1,0,n-1);
		for(int i=0 ; i<sz(seg) ; i++) {
			sort(all(seg[i]));
		}
	}
	void build_(int idx, int l, int r) {
		for(int i=l ; i<=r ; i++) {
			seg[idx].push_back(a[i]);
		}
		if(l==r) return;
		int mid = (l+r) / 2;
		build_(idx * 2, l, mid);
		build_(idx * 2 + 1, mid + 1, r);
		return;
	}
	ll calc_(int idx, int l, int r, int tl, int tr, int val) {
		if (tl > tr) return 0;
		if (tl == l && tr == r) {
			int tot = r - l + 1;
			int small = lower_bound(seg[idx].begin(),seg[idx].end(),val) - seg[idx].begin();
			return tot - small;
		}
		int mid = (l + r) / 2;
		return calc_(idx * 2, l, mid, tl, min(tr, mid), val) +
			calc_(idx * 2 + 1, mid + 1, r, max(mid + 1, tl), tr, val);
	}
	ll calc(int l, int r, int val) {
		return calc_(1, 0, n - 1, l, r, val+1);
	} 
};

int main() {
	IOS;
	cin >> n;
	a = vector<ll>(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
	}
	SegmentTree st(n);
	int q; cin >> q;
	int ans = 0;
	while(q--) {
		int l, r, x; cin >> l >> r >> x;
		l = (l^ans);
		r = (r^ans);
		x = (x^ans);
		l--, r--;
		ans = st.calc(l,r,x);
		cout << ans << "\n"; 
	}
}