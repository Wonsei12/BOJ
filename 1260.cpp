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
	int n,m,s; cin >> n >> m >> s; s--;
	vector<vector<int>> G(n);
	for(int i=0 ; i<m ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0 ; i<n ; i++) {
		sort(G[i].begin(),G[i].end());
	}
	vector<bool> vis(n);
	vector<int> dfsans;
	function<void(int)> dfs = [&](int c) {
		vis[c] = 1;
		dfsans.push_back(c+1);
		for(int nxt : G[c]) {
			if(vis[nxt])
				continue;
			dfs(nxt);
		}
	};
	dfs(s);
	vector<int> bfsans;
	vector<bool> vis2(n);
	queue<int> q;
	q.push(s); vis2[s]=1;
	while(!q.empty()) {
		int c = q.front(); q.pop();
		bfsans.push_back(c+1);
		for(int nxt : G[c]) {
			if(vis2[nxt])
				continue;
			q.push(nxt); vis2[nxt] = 1;
		}
	}
	for(auto x : dfsans) 
		cout << x << " ";
	cout << "\n";
	for(auto x : bfsans)
		cout << x << " ";
	cout << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}