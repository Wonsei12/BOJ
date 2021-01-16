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
	vector<int> a(n);
	for(int i=0 ; i<n ; i++)
		cin >> a[i];
	if(n==1) {
		cout << a[0] << "\n";
		return;
	}
	vector<vector<int>> dp(n, vector<int>(2));
	dp[0][0]=a[0];
	dp[1][0]=a[1];
	dp[1][1]=a[0]+a[1];
	for(int i=2 ; i<n ; i++) {
		dp[i][0]=max(dp[i-2][0],dp[i-2][1]) + a[i];
		dp[i][1]=dp[i-1][0] + a[i]; 
	}
	cout << max(dp[n-1][0],dp[n-1][1]) << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}