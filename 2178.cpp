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
	vector<string> G(n);
	for(int i=0 ; i<n ; i++)
		cin >> G[i];
	queue<pii> q;
	vector<vector<int>> ans(n, vector<int>(m));
	ans[0][0] = 1;
	q.push({0,0});
	vector<int> dx={0,1,0,-1}, dy={1,0,-1,0};
	auto isRange = [&](int x, int y) -> bool {
		return x>=0&&x<n&&y>=0&&y<m;
	};
	while(!q.empty()) {
		int curX = q.front().ff; int curY = q.front().ss; q.pop();
		for(int i=0 ; i<4 ; i++) {
			int nxtX = curX + dx[i], nxtY = curY + dy[i];
			if(isRange(nxtX,nxtY)&&G[nxtX][nxtY]=='1'&&ans[nxtX][nxtY]==0) {
				ans[nxtX][nxtY] = ans[curX][curY] + 1;
				q.push({nxtX,nxtY});
			}
		}
	}
	cout << ans[n-1][m-1] << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}