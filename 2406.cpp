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

struct cmp {
	bool operator() (pii a, pii b) {
		return a.ff > b.ff;
	}
};

void solve() {
	int n, m; cin >> n >> m;
	vector<pii> q(m);
	vector<vector<int>> G(n, vector<int>(n));
	for(int i=0 ; i<m ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		q[i] = {u,v};
	}
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<n ; j++) {
			cin >> G[i][j];
		}
	}
	for(int i=0 ; i<m ; i++) {
		G[q[i].ff][q[i].ss] = 0;
		G[q[i].ss][q[i].ff] = 0;
	}
	vector<bool> vis(n);
	vis[0] = 1;
	priority_queue<pii, vector<pii>, cmp> pq;
	for(int i=1 ; i<n ; i++) {
		pq.push({i,G[0][i]});
	}
	while(!pq.empty()) {
		int cur = pq.top().ff, int 
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}