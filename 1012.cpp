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
	int m, n; cin >> m >> n;
	int k; cin >> k; 
	vector<vector<int>> a(m,vector<int>(n));
	while(k--) {
		int x,y; cin >> x >> y;
		a[x][y]=1;
	}
	vector<vector<bool>> vis(m,vector<bool>(n));
	vector<int> dx={1,0,-1,0}, dy={0,1,0,-1};
	auto isRange = [&](int x, int y) -> bool {
		return x>=0&&x<=m-1&&y>=0&&y<=n-1;
	};
	int ans = 0;
	for(int i=0 ; i<m ; i++) {
		for(int j=0 ; j<n ; j++) {
			if(a[i][j]==0||vis[i][j]) 
				continue;
			ans += 1;
			vis[i][j] = 1;
			queue<pii> q;
			q.push({i,j});
			while(!q.empty()) {
				pii cur = q.front(); q.pop();
				for(int d=0 ; d<4 ; d++) {
					if(isRange(cur.ff+dx[d],cur.ss+dy[d])&&!vis[cur.ff+dx[d]][cur.ss+dy[d]]&&a[cur.ff+dx[d]][cur.ss+dy[d]]==1) {
						vis[cur.ff+dx[d]][cur.ss+dy[d]] = 1;
						q.push({cur.ff+dx[d],cur.ss+dy[d]});
					}
				}
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}