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
	int z;
};

void solve() {
	int n, m, h; cin >> n >> m >> h;
	vector<vector<vector<int>>>G(h,vector<vector<int>>(m,vector<int>(n)));
	vector<vector<vector<int>>>vis(h,vector<vector<int>>(m,vector<int>(n,-1)));
	queue<point> q;	

	for(int i=0 ; i<h ; i++) {
		for(int j=0 ; j<m ; j++) {
			for(int k=0 ; k<n ; k++) {
				cin >> G[i][j][k];
				if(G[i][j][k]==1) {
					vis[i][j][k]=0;
					q.push({i,j,k});
				}
			}
		}
	}
	int ans=0;
	auto isRange = [&](int x,int y,int z) -> bool {
		return x>=0&&y>=0&&z>=0&&x<h&&y<m&&z<n;
	};
	vector<int> dx={1,0,0,-1,0,0},dy={0,1,0,0,-1,0},dz={0,0,1,0,0,-1};
	while(!q.empty()) {
		point cur = q.front(); q.pop();
		for(int d=0 ; d<6 ; d++) {
			int nX=cur.x+dx[d];
			int nY=cur.y+dy[d];
			int nZ=cur.z+dz[d];
			if(isRange(nX,nY,nZ)&&G[nX][nY][nZ]==0&&vis[nX][nY][nZ]==-1) {
				vis[nX][nY][nZ]=vis[cur.x][cur.y][cur.z]+1;
				ans=max(ans,vis[nX][nY][nZ]);
				q.push({nX,nY,nZ});
			}
		}
	}
	for(int i=0 ; i<h ; i++) 
		for(int j=0 ; j<m ; j++)
			for(int k=0 ; k<n ; k++)
				if(G[i][j][k]==0&&vis[i][j][k]==-1) {
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