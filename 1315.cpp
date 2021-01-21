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
	vector<int> str(n), dex(n), pts(n);
	for(int i=0 ; i<n ; i++) {
		cin >> str[i] >> dex[i] >> pts[i];
	}
	vector<vector<int>> dp(1001,vector<int>(1001,-1));
	vector<bool> vis(n);
	function<int(int, int)> dfs = [&](int STR, int DEX) {
		int& ret = dp[STR][DEX];
		if(ret != -1) return ret;
		int PTS = 0; 
		vector<int> ad;
		ret = 0;
		for(int i=0 ; i<n ; i++) {
			if(vis[i]) {
				ret += 1;
				continue;
			}
			if(STR >= str[i] || DEX >= dex[i]) {
				ret++; PTS += pts[i];
				ad.push_back(i); vis[i]=1;
			}
		}
		for(int i=0 ; i<=PTS ; i++) {
			ret = max(ret, dfs(min(STR+i,1000),min(DEX+PTS-i,1000)));
		}
		for(int x : ad)
			vis[x] = 0; 
		return ret;
	};
	cout << dfs(1,1) << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}