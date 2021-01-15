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
	auto x = [](int a) -> int {
		int s = a;
		while(a>0) {
			s+=a%10;
			a/=10;
		}
		return s;
	};
	for(int i=1 ; i<=n ; i++) {
		if(x(i)==n) {
			cout << i << "\n";
			return;
		}
	}
	cout << 0 << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}