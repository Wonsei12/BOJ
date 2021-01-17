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
const ll MOD = 1e4 + 7;
const long double PI = acos(-1.0);

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> G(n, vector<int>(m));
	for(int i=0 ; i<n ; i++) 
		for(int j=0 ; j<m ; j++)
			cin >> G[i][j];
	int mx = 0;
	vector<vector<int>> vis(n,vector<int>(m));
	vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
	auto isRange = [&](int x, int y) {
		return x>=0&&x<n&&y>=0&&y<m;
	};
	function<int(int,int,int)> dfs = [&](int x, int y, int d) -> int {
		if(d==4)
			return 0;
		int mx2 = 0;
		vis[x][y] = 1;
		for(int i=0 ; i<4 ; i++) {
			int nX = x+dx[i], nY = y+dy[i];
			if(isRange(nX,nY)&&!vis[nX][nY]) {
				mx2 = max(mx2, dfs(nX,nY,d+1));
			}
		}
		vis[x][y] = 0;
		return G[x][y] + mx2;
	};
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<m ; j++) {
			mx = max(mx, dfs(i,j,0));
		}
	}
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<m ; j++) {
			if(i>0&&i<n-1&&j<m-1) {
				mx = max(mx, G[i][j] + G[i-1][j] + G[i+1][j] + G[i][j+1]);
			}
			if(i>0&&i<n-1&&j>0) {
				mx = max(mx, G[i][j] + G[i-1][j] + G[i+1][j] + G[i][j-1]);
			}
			if(j>0&&j<m-1&&i<n-1) {
				mx = max(mx, G[i][j] + G[i][j-1] + G[i][j+1] + G[i+1][j]);
			}
			if(j>0&&j<m-1&&i>0) {
				mx = max(mx, G[i][j] + G[i][j-1] + G[i][j+1] + G[i-1][j]);
			}
		}
	}
	cout << mx << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}