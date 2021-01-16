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
	vector<int> G[n];
	int m; cin >> m;
	while(m--) {
		int u, v; cin >> u >> v; u--, v--;
		G[u].push_back(v), G[v].push_back(u);
	}
	queue<int> q;
	q.push(0);
	vector<bool> vis(n);
	vis[0] = 1;
	int cnt = 0;
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		for(int nxt : G[cur]) {
			if(vis[nxt])
				continue;
			vis[nxt] = 1;
			cnt += 1;
			q.push(nxt);
		}
	}
	cout << cnt << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}