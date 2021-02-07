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
	vector<vector<ll>> dp(n, vector<ll>(pw(n), INF));
	vector<vector<ll>> dis(n, vector<ll>(n));
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<n ; j++) {
			cin >> dis[i][j];
			if(dis[i][j] == 0) dis[i][j] = INF;
		}
	}
	int fullmask = pw(n) - 1;
	ll ans = LLINF;
	for(int fi = 0 ; fi < n ; fi++) {
		dp = vector<vector<ll>>(n, vector<ll>(pw(n), INF));
		dp[fi][pw(fi)] = 0;
		for(int mask = 1 ; mask < pw(n) ; mask++) {
			for(int cur = 0 ; cur < n ; cur++) {
				if(dp[cur][mask] == INF) continue;
				for(int nxt = 0 ; nxt < n ; nxt++) {
					if(mask & pw(nxt)) continue;
					int nxtmask = mask|pw(nxt);
					dp[nxt][nxtmask] = min(dp[nxt][nxtmask], dp[cur][mask] + dis[cur][nxt]);
				}
			}
		}
		for(int i=0 ; i<n ; i++) {
			ans = min(ans, dp[i][fullmask] + dis[i][fi]);
		}
	}
	cout << ans << "\n";
}