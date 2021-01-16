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
	queue<pii> q;
	vector<bool> vis(n+1);
	vis[n]=1;
	q.push({n,0});
	while(!q.empty()) {
		int cur = q.front().ff; int cnt = q.front().ss; q.pop();
		if(cur==1) {
			cout << cnt << "\n";
			return;
		}
		if(cur%3==0&&!vis[cur/3]) {
			vis[cur/3]=1;
			q.push({cur/3,cnt+1});
		}
		if(cur%2==0&&!vis[cur/2]) {
			vis[cur/2]=1;
			q.push({cur/2,cnt+1});
		}
		if(!vis[cur-1]) {
			vis[cur-1]=1;
			q.push({cur-1,cnt+1});
		}
	}
	assert(false);
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}