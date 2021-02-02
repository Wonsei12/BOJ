#include <bits/stdc++.h>
using namespace std;

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
	set<int> ban;
	vector<vector<int>> dp(n, vector<int>(n*2, -1));
	for(int i=0 ; i<m ; i++) {
		int x; cin >> x; x--;
		ban.insert(x);
	}
	function<int(int,int)> dfs = [&](int cur, int coupon) {
		if(cur >= n) return 0;
		int& ret = dp[cur][coupon];
		if(ret != -1) return ret;
		ret = INF;
		if(coupon >= 3)
			ret = min(ret, dfs(cur+1, coupon-3));
		ret = min(ret, dfs(cur+1, coupon) + 10000);
		ret = min(ret, dfs(cur+3, coupon+1) + 25000);
		ret = min(ret, dfs(cur+5, coupon+2) + 37000);
		if(ban.count(cur)) 
			ret = min(ret, dfs(cur+1, coupon));
		return ret;
	};
	cout << dfs(0,0) << "\n";
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}