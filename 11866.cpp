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
	int n, k; cin >> n >> k;
	vector<bool> vis(n);
	int idx = 0;
	int yes = 0;
	int cnt = 0;
	vector<int> ans;
	while(1) {
		if(!vis[idx])
			yes += 1;
		if(yes==k) {
			yes=0;
			cnt+=1;
			vis[idx]=1;
			ans.push_back(idx+1);
		}
		if(cnt==n)
			break;
		idx+=1;
		idx%=n;
	}
	cout << "<";
	for(int i=0 ; i<n-1 ; i++) {
		cout << ans[i] << ", ";
	}
	cout << ans[n-1] << ">";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}