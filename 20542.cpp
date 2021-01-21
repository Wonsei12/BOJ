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
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

	auto right = [&](int i1, int i2) -> bool{
		if(s[i1]=='i'&&(t[i2]=='j'||t[i2]=='l'))
			return true;
		if(s[i1]=='v'&&t[i2]=='w')
			return true;
		return false;
	};

	function<int(int, int)> dfs = [&](int idx1, int idx2) {
		int& ret = dp[idx1][idx2];
		if(ret != -1)
			return ret;
		if(idx1==n) {
			return ret = abs(m-idx2);
		}
		if(idx2==m) {
			return ret = abs(n-idx1);
		}
		ret = min({1+dfs(idx1+1,idx2+1),1+dfs(idx1+1,idx2),1+dfs(idx1,idx2+1)});
		if(s[idx1]==t[idx2]||right(idx1,idx2)) 
			ret = min(ret,dfs(idx1+1,idx2+1));
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