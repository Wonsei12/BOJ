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
		int u, v, w; cin >> u >> v >> w; u--, v--;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	vector<int> dep(n), dep2(n); // real , 단계
	vector<vector<int>> par(n, vector<int>(21));
	function<void(int, int, int, int)> dfs = [&](int v, int d, int d2, int p) {
		dep[v] = d;
		dep2[v] = d2;
		par[v][0] = p;
		for(pii nxt : G[v]) {
			if(nxt.ff == p) continue;
			dfs(nxt.ff, d + nxt.ss, d2 + 1, v);
		}
	};
	dfs(0,0,0,0);
	for(int x=1 ; x<21 ; x++) {
		for(int v=0 ; v<n ; v++) {
			par[v][x] = par[par[v][x-1]][x-1];
		}
	}
	function<int(int, int)> LCA = [&](int x, int y) {
		if(dep2[x] > dep2[y]) 
			swap(x,y);
		for(int i=20 ; i>=0 ; i--) {
			if(dep2[y]-dep2[x] >= pw(i))
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
		int u, v; cin >> u >> v; u--, v--;
		int p = LCA(u,v);
		cout << dep[u] + dep[v] - 2 * dep[p] << "\n";
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}