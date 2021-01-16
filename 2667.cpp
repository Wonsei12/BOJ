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
	vector<vector<bool>> vis(n, vector<bool>(n));
	vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
	auto isRange = [&](int x, int y) -> bool {
		return x>=0&&x<n&&y>=0&&y<n;
	};
	vector<int> ans;
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<n ; j++) {
			if(G[i][j]=='0'||vis[i][j])
				continue;
			vis[i][j]=1;
			int cnt=1;
			queue<pii> q; q.push({i,j});
			while(!q.empty()) {
				int cX=q.front().ff,cY=q.front().ss;q.pop();
				for(int d=0 ; d<4 ; d++) {
					int nX=cX+dx[d],nY=cY+dy[d];
					if(isRange(nX,nY)&&!vis[nX][nY]&&G[nX][nY]=='1') {
						vis[nX][nY]=1;q.push({nX,nY});
						cnt+=1;
					}
				}
			}
			ans.push_back(cnt);
		}
	}
	sort(ans.begin(),ans.end());
	cout << sz(ans) << "\n";
	for(auto x : ans) {
		cout << x << "\n";
	}
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}