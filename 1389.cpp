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
	vector<vector<int>> G(n);
	while(m--) {
		int u, v; cin >> u >> v; u--, v--;
		G[u].push_back(v); G[v].push_back(u);
	}
	vector<int> ans(n);
	for(int i=0 ; i<n ; i++) {
		vector<int> dis(n,-1);
		queue<pii> q;
		q.push({i,0}); dis[i]=0;
		while(!q.empty()) {
			int cur = q.front().ff; int curdis = q.front().ss; q.pop();
			for(int nxt : G[cur]) {
				if(dis[nxt]!=-1)
					continue;
				dis[nxt]=curdis+1;
				q.push({nxt,dis[nxt]});
			}
		}
		int tot = accumulate(dis.begin(),dis.end(), 0);
		ans[i] = tot;
	}
	int mn = *min_element(ans.begin(),ans.end());
	for(int i=0 ; i<n ; i++) {
		if(mn == ans[i]) {
			cout << i+1 << "\n";
			return;
		}
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}