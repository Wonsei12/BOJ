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
	vector<int> ans;
	int t=0;
	vector<bool> vis(n),vis2(n);
	vector<int> tin(n),low(n); 
	function<void(int,int)> dfs = [&](int v, int p) {
		int c=0;
		vis[v]=1;
		tin[v]=low[v]=t++;
		for(int nxt : G[v]) {
			if(nxt==p) continue;
			if(vis[nxt]) {
				low[v]=min(low[v],tin[nxt]);
			} else {
				c++;
				dfs(nxt,v);
				low[v]=min(low[v],low[nxt]);
				if(low[nxt]>=tin[v]&&p!=-1&&!vis2[v]) {
					ans.push_back(v);
					vis2[v]=1;
				} 
			}
		}
		if(p==-1&&c>1&&!vis2[v]) { 
			vis2[v]=1;
			ans.push_back(v);
		}
	};
	for(int i=0 ; i<n ; i++) {
		if(vis[i]) continue;
		dfs(i,-1);
	}
	sort(ans.begin(),ans.end());
	cout << sz(ans) << "\n";
	for(auto x : ans)
		cout << x+1 << " ";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}