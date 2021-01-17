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
	vector<string> G(n);
	for(int i=0 ; i<n ; i++)
		cin >> G[i];
	vector<vector<int>> vis(n, vector<int>(n));
	auto isRange = [&](int x, int y) -> bool {
		return x>=0&&x<n&&y>=0&&y<n;
	};
	vector<int> dx={0,1,0,-1}, dy={1,0,-1,0};
	int ans =0;
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<n ; j++) {
			if(!vis[i][j]) {
				ans += 1;
				vis[i][j]=1;
				queue<pii> q;
				q.push({i,j});
				while(!q.empty()) {
					int cX = q.front().ff; int cY = q.front().ss; q.pop();
					for(int k=0 ; k<4 ; k++) {
						int nX = cX + dx[k];
						int nY = cY + dy[k];
						if(isRange(nX,nY)&&vis[nX][nY]==0&&G[nX][nY]==G[i][j]) {
							q.push({nX,nY});
							vis[nX][nY]=1;
						}
					}
				}
			}
		}
	}
	cout << ans << " ";
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++) {
			if(G[i][j]=='R')
				G[i][j]='G';
			vis[i][j]=0;
		}
	ans = 0;
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<n ; j++) {
			if(!vis[i][j]) {
				ans += 1;
				vis[i][j]=1;
				queue<pii> q;
				q.push({i,j});
				while(!q.empty()) {
					int cX = q.front().ff; int cY = q.front().ss; q.pop();
					for(int k=0 ; k<4 ; k++) {
						int nX = cX + dx[k];
						int nY = cY + dy[k];
						if(isRange(nX,nY)&&vis[nX][nY]==0&&G[nX][nY]==G[i][j]) {
							q.push({nX,nY});
							vis[nX][nY]=1;
						}
					}
				}
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}