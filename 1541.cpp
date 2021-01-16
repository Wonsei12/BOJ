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
	string s; cin >> s;
	int ans = 0;
	int tmp = 0;
	bool minus = false;
	for(int i=0 ; i<sz(s) ; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			tmp *= 10;
			tmp += s[i]-'0';
		} else {
			if(minus)
				ans -= tmp;
			else
				ans += tmp;
			if(s[i]=='-')
				minus=true;
			tmp = 0;
		}
	}
	if(minus)
		ans -= tmp;
	else
		ans += tmp;
	cout << ans << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}