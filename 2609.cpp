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

int gcd(int a, int b) {
	if(b==0)
		return a;
	return gcd(b, a%b);
}
int lcm(int a, int b) {
	return a * b / gcd(a,b);
}

void solve() {
	int a, b; cin >> a >> b;
	cout << gcd(a,b) << "\n" << lcm(a,b) << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}