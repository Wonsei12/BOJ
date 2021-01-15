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
	for(int i=0 ; i<n ; i++) {
		cin >> G[i];
	}
	int ans = INF;
	for(int i=0 ; i+8<=n ; i++) 
		for(int j=0 ; j+8<=m ; j++) 
			for(int k=0 ; k<2 ; k++) {
				int tmp=0;
				for(int x=i ; x<i+8 ; x++) 
					for(int y=j ; y<j+8 ; y++) 
						if((x+y+k)%2==(G[x][y]=='W'))
							tmp += 1;	
				ans=min(ans,tmp);
			}
	cout << ans << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}