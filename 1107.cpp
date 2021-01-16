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
	int k; cin >> k;
	vector<bool> ban(10);
	if(k==10) {
		cout << abs(n-100) << "\n";
		return;
	}
	while(k--) {
		int a; cin >> a; ban[a]=1;
	}
	int ans = abs(n-100);
	int mn = -1;
	auto allowed = [&](int x) -> bool {
		if(x==0) {
			if(ban[0])
				return false;
			else
				return true;
		}
		while(x>0) {
			if(ban[x%10])
				return false;
			x/=10;
		}
		return true;
	};
	auto len = [&](int x) -> int {
		int cnt = 0;
		if(x==0) {
			return 1;
		}
		while(x>0) {
			x/=10; cnt += 1;
		}
		return cnt;
	};
	for(int i=n ; i>=0 ; i--) {
		if(allowed(i)) {
			ans=min(ans,len(i)+abs(i-n));
		}
	}
	for(int i=n ; i<=10000000 ; i++) {
		if(abs(i-n)>ans)
			break;
		if(allowed(i)) {
			ans=min(ans,len(i)+abs(n-i));
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