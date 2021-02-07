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
	vector<ll> dp(n+1);
	vector<ll> newdp(n+1);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
	}
	if(a[0] != -1 && a[0] != 0) {
		cout << 0 << "\n";
		return 0;
	}
	if(a[n-1] != -1 && a[n-1] != 0) {
		cout << 0 << "\n";
		return 0;
	}
	
	dp[0] = 1;
	int t = n-1;
	for(int idx = 1; idx < n ; idx++) {
		for(int i=0 ; i<n ; i++) {
			newdp[i] += dp[i+1];
			newdp[i] += dp[i];
			if(i>0) newdp[i] += dp[i-1];
			newdp[i] %= MOD;
		}
		if(a[idx] != -1) {
			for(int j=0 ; j<=n ; j++) {
				if(a[idx] == j) continue;
				newdp[j] = 0;
			}
		}
		dp = newdp;
		newdp.clear();
		newdp.resize(n+1);
	}
	cout << dp[0] << "\n";
}