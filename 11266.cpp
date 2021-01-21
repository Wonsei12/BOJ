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
	int n, e; cin >> n >> e;
	vector<vector<int>> G(n);
	while(e--) {
		int u, v; cin >> u >> v; u--, v--;
		G[u].push_back(v); G[v].push_back(u);
	}
	vector<pii> ans;
	int t=0;
	vector<int> tin(n),low(n);
	vector<bool> vis(n);
	function<void(int,int)> dfs = [&](int v, int p) {
		vis[v]=1;
		tin[v]=low[v]=t++;
		for(int nxt : G[v]) {
			if(nxt==p) continue;
			if(vis[nxt]) 
				low[v]=min(low[v], tin[nxt]);
			else {
				dfs(nxt,v);
				low[v]=min(low[v], low[nxt]);
				if(low[nxt] > tin[v]) 
					ans.push_back({min(v,nxt),max(v,nxt)});
			}
		}
	};
	for(int i=0 ; i<n ; i++) {
		if(!vis[i])
			dfs(i,-1);
	}
	sort(ans.begin(),ans.end());
	cout << sz(ans) << "\n";
	for(auto x : ans) {
		cout << x.ff+1 << " " << x.ss+1 << "\n";
	}
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}