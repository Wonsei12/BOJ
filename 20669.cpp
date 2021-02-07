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

vector<vector<ll>> mult(vector<vector<ll>> x, vector<vector<ll>> y) {
	int n = sz(x);
	vector<vector<ll>> ret(n, vector<ll>(n));
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<n ; j++) {
			ll sum = 0;
			for(int k=0 ; k<n ; k++) {
				sum += x[i][k] * y[k][j];
				sum %= MOD;
			}
			ret[i][j] = sum;
		}
	}
	return ret;
}

int main() {
	IOS;
	int n, m, k; cin >> n >> m >> k; k++;
	vector<vector<vector<ll>>> G(23, vector<vector<ll>>(n + 3, vector<ll>(n + 3)));
	while(m--) {
		int u, v; cin >> u >> v; u--, v--;
		G[0][u][v] += 1; G[0][v][u] += 1;
	}
	int pp, qq; cin >> pp >> qq;
	set<int> st;
	int cnt = 0;
	while(pp--) {
	 	int z; cin >> z; z--;
	 	G[0][n+2][z] = 1;
	 	st.insert(z);
	}
	while(qq--) {
		int z; cin >> z; z--;
		if(st.count(z)) cnt ++;
		G[0][z][n+1] = 1;
		G[0][n+1][n+1] = 1;
	}
	for(int i=1 ; i<21 ; i++) {
		G[i] = mult(G[i-1], G[i-1]);
	}
	ll ans = 0;
	vector<vector<ll>> x = G[0];
	int idx = 0;
	while(k > 0) {
		if(k & 1) {
			x = mult(G[idx], x);
		}
		idx ++;
		k /= 2;
	}
	ans = x[n+2][n+1];
	ans -= cnt;
	ans += MOD;
	ans %= MOD;
	cout << ans << "\n";
}