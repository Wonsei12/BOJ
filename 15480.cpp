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
	vector<vector<int>> G(n);
	for(int i=0 ; i<n-1 ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<vector<int>> par(n, vector<int>(21));
	vector<int> dep(n);
	function<void(int, int, int)> dfs = [&](int v, int d, int p) {
		par[v][0] = p;
		dep[v] = d;
		for(int nxt : G[v]) {
			if(nxt == p) continue;
			dfs(nxt, d+1, v);
		}
	};
	dfs(0,0,0);
	for(int x=1 ; x<21 ; x++) {
		for(int v=0 ; v<n ; v++) {
			par[v][x] = par[par[v][x-1]][x-1];
		}
	}
	function<int(int, int)> LCA = [&](int x, int y) {
		if(dep[x] > dep[y]) 
			swap(x,y);
		for(int i=20 ; i>=0 ; i--) {
			if(dep[y]-dep[x] >= pw(i))
				y = par[y][i];
		}
		if(x==y)
			return x;
		for(int i=20 ; i>=0 ; i--) {
			if(par[x][i] != par[y][i]) {
				x = par[x][i];
				y = par[y][i];
			}
		}
		return par[x][0];
	};
	int q; cin >> q; 
	while(q--) {
		int r, u, v; cin >> r >> u >> v; r--, u--, v--;
		int lca1 = LCA(r,u), lca2 = LCA(u,v), lca3 = LCA(r,v);
		int ans;
		int mx = max({dep[lca1],dep[lca2],dep[lca3]});
		if(mx == dep[lca1]) 
			ans = lca1;
		else if(mx == dep[lca2])
			ans = lca2;
		else
			ans = lca3;
		cout << ans + 1 << "\n";
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}