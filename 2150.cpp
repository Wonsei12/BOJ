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
	vector<vector<int>> rG(n);

	while(e--) {
		int u, v; cin >> u >> v; u--, v--;
		G[u].push_back(v);
		rG[v].push_back(u);
	}

	vector<bool> vis(n);
	stack<int> st;
	function<void(int, int)> dfs = [&](int v, int p) {
		vis[v] = 1;
		for(int nxt : G[v]) {
			if(nxt == p || vis[nxt])
				continue;
			dfs(nxt, v);
		}
		st.push(v);
	};	

	for(int i=0 ; i<n ; i++) {
		if(vis[i])
			continue;
		dfs(i,-1);	
	}

	vis = vector<bool>(n);
	vector<vector<int>> ans(n);	
	int cnt = 0;

	function<void(int, int)> dfs2 = [&](int v, int p) {
		vis[v] = 1;
		ans[cnt].push_back(v);
		for(int nxt : rG[v]) {
			if(nxt == p || vis[nxt])
				continue;
			dfs2(nxt, v);
		}
	};

	for(int i=0 ; i<n ; i++) {
		int cur = st.top(); st.pop();
		if(vis[cur]) 
			continue;
		dfs2(cur, -1);
		cnt ++;
	}

	for(int i=0 ; i<cnt ; i++) {
		sort(ans[i].begin(),ans[i].end());
	}
	vector<int> p;
	for(int i=0 ; i<cnt ; i++)
		p.push_back(i);

	auto cmp = [&](int a, int b) {
		return ans[a][0] < ans[b][0];
	};
	sort(p.begin(),p.end(),cmp);

	cout << cnt << "\n";
	for(int i=0 ; i<cnt ; i++) {
		for(int j=0 ; j<sz(ans[p[i]]) ; j++) {
			cout << ans[p[i]][j] + 1 << " ";
		}
		cout << "-1\n";
	}
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}