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

struct LCA {
	vector<int> height, euler, first, seg;
	vector<bool> vis;
	int n;

	LCA(vector<vector<int>> &G, int root = 0) {
		n = sz(G);
		height = vector<int> (n);
		first = vector<int> (n);
		euler.reserve(n*2);
		vis = vector<bool>(n,0);
		dfs(G,root);
		int m = sz(euler);
		seg = vector<int>(4*m);
		build(1,0,m-1);
	}

	void dfs(vector<vector<int>> &G, int node, int h=0) {
		vis[node] = true;
		height[node] = h;
		first[node] = sz(euler);
		euler.push_back(node);
		for(int to : G[node]) {
			if(!vis[to]) {
				dfs(G,to,h+1);
				euler.push_back(node);
			}
		}
	}

	void build(int node, int b, int e) {
		if(b==e) {
			seg[node] = euler[b];
		} else {
			int mid = (b + e) / 2;
			build(node << 1, b, mid);
			build(node << 1 + 1, mid + 1, e);
			int l = seg[node << 1];
			int r = seg[node << 1 + 1];
			seg[node] = (height[l] < height[r]) ? l : r;
		}
	}

	int query(int node, int b, int e, int L, int R) {
		if(b > R || e < L)
			return -1;
		if(b >= L && e <= R)
			return seg[node];
		int mid = (b + e) / 2;
		int left = query(node << 1, b, mid, L, R);
		int right = query(node << 1 + 1, mid + 1, e, L, R);
		if(left == -1) return right;
		if(right == -1) return left;
		return height[left] < height[right] ? left : right;
	}

	int lca(int u, int v) {
		int left = first[u], right = first[v];
		if(left > right)
			swap(left, right);
		return query(1,0,sz(euler)-1,left,right);
	}
};

void solve() {
	int n; cin >> n;
	vector<vector<int>> G(n);
	for(int i=0 ; i<n-1 ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	LCA t = LCA(G,0);
	int q; cin >> q;
	while(q--) {
		int u, v; cin >> u >> v; u--, v--;
		cout << t.lca(u,v) << "\n";
	}
}

int main() {
	IOS;
	int t; t=1;
	while(t--)
		solve();
}