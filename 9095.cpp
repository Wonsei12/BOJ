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

int main() {
	IOS;
	int n = 12;
	vector<int> dp(n); 
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	for(int i=3 ; i<n ; i++) {
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
	int t; cin >> t;
	while(t--) {
		int a; cin >> a;
		cout << dp[a] << "\n";
	}
}