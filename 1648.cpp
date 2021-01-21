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
const ll MOD = 9901LL;
const long double PI = acos(-1.0);

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> dp(n*m+1, vector<int>(1<<m, -1));
	function<int(int,int)> dfs = [&](int x, int st) -> int {
		if(x==n*m && st==0)
			return 1;
		if(x>=n*m)
			return 0;
		int& ret = dp[x][st];
		if(ret != -1)
			return ret;
		ret = 0;
		if(st&1)
			return ret = dfs(x+1,st>>1);
		ret += dfs(x+1, (st|pw(m))>>1);
		if((st&1)==0&&(st&2)==0&&(x+1)%m!=0) {
			ret += dfs(x+2, (st>>2));
		}
		ret %= MOD;
		return ret;
	};
	cout << dfs(0, 0);
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}