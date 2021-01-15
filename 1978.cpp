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
	vector<int> sieve(1010);
	for(int i=2 ; i<1010 ; i++) if(sieve[i]==0) {
		sieve[i]=-1;
		for(int j=i*2 ; j<1010 ; j+=i) {
			sieve[j]=1;
		}
	}
	int n; cin >> n;
	int cnt = 0;
	while(n--) {
		int a; cin >> a;
		if(sieve[a]==-1)
			cnt += 1;
	}
	cout << cnt << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}