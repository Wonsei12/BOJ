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
	vector<string> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
	}
	vector<vector<vector<ll>>> dp(2,vector<vector<ll>>(n, vector<ll>(n)));
	dp[0][0][n-1]=(a[0][0]==a[n-1][n-1]);
	for(int i=0 ; i<n-1 ; i++) {
		// i = sX + sY;
		for(int j=0 ; j<=i ; j++) {
			// j = sX
			for(int k=n-1 ; k>=0 ; k--) {
				int sX = j, sY = i-j, eX = k, eY = 2*n-2-sX-sY-eX;
				if(a[sX][sY] != a[eX][eY]) {
					dp[i%2][j][k] = 0;
					continue;
				}
				if(sX <= eX && sY+1 <= eY-1) {
					dp[1-i%2][j][k] += dp[i%2][j][k];
					dp[1-i%2][j][k] %= MOD;
				}
				if(sX <= eX-1 && sY+1<=eY) {
					dp[1-i%2][j][k-1] += dp[i%2][j][k];
					dp[1-i%2][j][k-1] %= MOD;
				}
				if(sX+1 <= eX && sY<=eY-1) {
					dp[1-i%2][j+1][k] += dp[i%2][j][k];
					dp[1-i%2][j][k-1] %= MOD;
				}
				if(sX+1 <= eX-1 && sY<=eY) {
					dp[1-i%2][j+1][k-1] += dp[i%2][j][k];    
					dp[1-i%2][j+1][k-1] %= MOD;
				}
				dp[i%2][j][k] = 0;
			}
		}
	}
	ll ans = 0;
	for(int sX = 0 ; sX < n ; sX++) {
		ans += dp[1-n%2][sX][sX];
		ans %= MOD;
	}
	cout << ans << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}