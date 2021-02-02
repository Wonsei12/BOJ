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
const long double PI = acos(-1.0);

void solve() {
	int n; cin >> n;
	ll MOD; cin >> MOD;
	vector<ll> primes;

	vector<bool> sieve(n+1);
	for(int i=2 ; i<=n ; i++) {
		if(sieve[i]) continue;
		primes.push_back(i);
		for(int j=i ; j<=n ; j+=i) {
			sieve[j] = 1;
		}
	}

	vector<vector<ll>> dp(n+1, vector<ll>(sz(primes)+1, -1));
	function<ll(int, int)> dfs = [&](int cur, int idx) -> ll {
		if(idx < 0) return 1;
		ll& ret = dp[cur][idx];
		if(ret != -1) return ret;
		ret = 0;
		ret += dfs(cur, idx-1);
		for(ll i=primes[idx] ; i<=cur ; i*=primes[idx]) {
			ret += dfs(cur - i, idx - 1) * i;
			ret %= MOD;
		}
		return ret;
	};

	dfs(n, sz(primes)-1);
	cout << dp[n][sz(primes)-1];

}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}