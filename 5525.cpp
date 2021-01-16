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
	int m; cin >> m;
	string s; cin >> s;
	vector<int> dp(m+1);
	dp[0]=(s[0]=='I');
	dp[1]=(s[1]=='I');
	int cnt=0;
	for(int i=2 ; i<m ; i++) {
		if(s[i]=='O')
			continue;
		if(s[i-1]=='O')
			dp[i]=dp[i-2] + 1;
		else
			dp[i]=1;
		//cout << dp[i] << " ";
		if(dp[i]>=n+1)
			cnt += 1;
	}	
	cout << cnt << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}