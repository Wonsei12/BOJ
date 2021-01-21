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

void solve() {
	int n; cin >> n;
	vector<vector<pii>> G(n);
	for(int i=0 ; i<n-1 ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		int w; cin >> w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	vector<int> t;
	vector<int> f(n,-1);
	vector<int> dis(n);
	function<void(int,int)> dfs = [&](int v, int p) {
		t.push_back(v);
		for(auto nxt : G[v]) {
			if(nxt.ff==p)
				continue;
			dis[nxt.ff]=dis[v]+nxt.ss;
			dfs(nxt.ff,v);
			t.push_back(v);
		}
	};
	dfs(0,-1);
	for(int i=0 ; i<sz(t) ; i++) 
		if(f[t[i]]==-1)
			f[t[i]]=i;
	vector<vector<int>> sparse_table(sz(t), vector<int>(25));
	for(int i=0 ; i<sz(t) ; i++) {
		sparse_table[i][0] = t[i];
	}
	for(int pw=1 ; pw<25 ; pw++) {
		for(int i=0 ; i+(1LL<<(pw-1))<sz(t) ; i++) {
			sparse_table[i][pw] = min(sparse_table[i][pw-1], sparse_table[i+(1LL<<(pw-1))][pw-1]);
		}
	}
	vector<int> log(n+1);
	log[1] = 0;
	for(int i=2 ; i<=n ; i++)
		log[i] = log[i/2] + 1;
	int q; cin >> q;
	while(q--) {
		int s, e; cin >> s >> e;
		int lg = log[e-s+1];
		cout << min(sparse_table[s][lg],sparse_table[e-(1<<lg)+1][lg]) << "\n";
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}