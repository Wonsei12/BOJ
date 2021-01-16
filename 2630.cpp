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
	vector<vector<int>> G(n, vector<int>(n));
	for(int i=0 ; i<n ; i++) for(int j=0 ; j<n ; j++) cin >> G[i][j];
	vector<int> ans(2);
	function<void(int, int, int)> dfs = [&](int x, int y, int cur) {
		bool fail = false;
		for(int i=0 ; i<cur ; i++) {
			for(int j=0 ; j<cur ; j++) {
				if(G[x][y] != G[x+i][y+j])
					fail = true;
			}
		}
		if(!fail) {
			ans[G[x][y]] += 1;
			return;
		}
		for(int i=0 ; i<2 ; i++)
			for(int j=0 ; j<2 ; j++)
				dfs(x+cur/2*i,y+cur/2*j,cur/2);
	};
	dfs(0,0,n);
	cout << ans[0] << "\n" << ans[1] << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}