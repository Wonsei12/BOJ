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

int main() {
	IOS;
	int n; cin >> n;
	vector<int> a(n);
	vector<vector<ll>> dp(n,vector<ll>(25,-1));
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
	}
	int res = a[n-1];
	function<ll(int,int)> dfs = [&](int idx, int sum) -> ll {
		if(idx == n-1) {
			if(res == sum) return 1;
			else return 0;
		}
		ll& ret = dp[idx][sum];
		if(ret != -1) return ret;
		ret = 0;
		if(sum + a[idx] <= 20) {
			ret += dfs(idx + 1, sum + a[idx]);
		}
		if(sum - a[idx] >= 0 && idx != 0) {
			ret += dfs(idx + 1, sum - a[idx]);
		}
		return ret;
	};	
	cout << dfs(0,0) << "\n";
}