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

struct point {
	int x;
	int y;
};

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> G(m,vector<int>(n));
	vector<vector<int>> vis(m,vector<int>(n,-1));
	queue<point> q;	

	for(int j=0 ; j<m ; j++) {
		for(int k=0 ; k<n ; k++) {
			cin >> G[j][k];
			if(G[j][k]==1) {
				vis[j][k]=0;
				q.push({j,k});
			}
		}
	}

	int ans=0;
	auto isRange = [&](int y,int z) -> bool {
		return y>=0&&z>=0&&y<m&&z<n;
	};
	vector<int> dx={1,0,-1,0,},dy={0,1,0,-1};
	while(!q.empty()) {
		point cur = q.front(); q.pop();
		for(int d=0 ; d<4 ; d++) {
			int nX=cur.x+dx[d];
			int nY=cur.y+dy[d];
			if(isRange(nX,nY)&&G[nX][nY]==0&&vis[nX][nY]==-1) {
				vis[nX][nY]=vis[cur.x][cur.y]+1;
				ans=max(ans,vis[nX][nY]);
				q.push({nX,nY});
			}
		}
	}
	for(int j=0 ; j<m ; j++)
		for(int k=0 ; k<n ; k++)
			if(G[j][k]==0&&vis[j][k]==-1) {
				cout << -1 << "\n";
				return;
			}
	cout << ans << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}