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
	int n, m; cin >> n >> m;
	vector<vector<int>> G(n), rG(n);

	while(m--) {
		int u, v; cin >> u >> v; u--, v--;
		G[u].push_back(v);
		rG[v].push_back(u);
	}

	stack<int> st;
	vector<bool> vis(n);

	function<void(int)> dfs = [&](int v) {
		vis[v] = 1;
		for(int nxt : G[v]) {
			if(vis[nxt]) continue;
			dfs(nxt);
		}
		st.push(v);
	};

	for(int i=0 ; i<n ; i++) {
		if(vis[i]) continue;
		dfs(i);
	}

	vis = vector<bool>(n);
	vector<int> scc(n);
	vector<vector<int>> SCC(n);
	int cnt = 0;

	function<void(int)> dfs2 = [&](int v) {
		vis[v] = 1;
		scc[v] = cnt;
		SCC[cnt].push_back(v);
		for(int nxt : rG[v]) {
			if(vis[nxt]) continue;
			dfs2(nxt);
		}
	};

	for(int i=0 ; i<n ; i++) {
		int c = st.top(); st.pop();
		if(vis[c]) continue;
		dfs2(c); cnt ++;
	}
	
	int ans = 0;
	for(int i=0 ; i<cnt ; i++) {
		bool fail = false;
		for(int j : SCC[i]) {
			for(int k : rG[j]) {
				if(scc[j] == scc[k])
					continue;
				fail = true;
			}
		}
		if(!fail)
			ans += 1;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}