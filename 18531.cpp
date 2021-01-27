
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
	string s1, s2, s3; cin >> s1 >> s2 >> s3;
	int n = sz(s1);
	vector<vector<bool>> ok(3, vector<bool>(n, true)); // 0 = s1, s2  1 = s2. s3. 2 = s1. s3
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<n ; j++) {
			if(s1[j]==s2[(i+j)%n]) ok[0][i] = false;
			if(s2[j]==s3[(i+j)%n]) ok[1][i] = false;
			if(s3[j]==s1[(i+j)%n]) ok[2][i] = false;
		}
	}
	int ans = INF;
	for(int i=0 ; i<n ; i++) if(ok[0][i]) {
		for(int j=0 ; j<n ; j++) if(ok[2][j]) {
			if(!ok[1][(2*n-(i+j))%n]) continue;
			int cost = min(i,n-i)+min(j,n-j);
			ans = min(ans, cost);
		}
	}
	for(int i=0 ; i<n ; i++) if(ok[1][i]) {
		for(int j=0 ; j<n ; j++) if(ok[2][j]) {
			if(!ok[0][(2*n-(i+j))%n]) continue;
			int cost = min(i,n-i)+min(j,n-j);
			ans = min(ans, cost);
		}
	}
	for(int i=0 ; i<n ; i++) if(ok[0][i]) {
		for(int j=0 ; j<n ; j++) if(ok[1][j]) {
			if(!ok[2][(n*2-(i+j))%n]) continue;
			int cost = min(i,n-i)+min(j,n-j);
			ans = min(ans, cost);
		}
	}
	if(ans==INF) ans = -1;
	cout << ans << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}