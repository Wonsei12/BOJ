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
	vector<int> cnt(26);
	int ans = 0;
	char cx;
	bool yep = false;
	for(char c : s) {
		if(c>='a') {
			if(ans<++cnt[c-'a']) {
				ans=cnt[c-'a'],yep=false;
				cx=c-'a'+'A';
			}
			else if(ans==cnt[c-'a'])
				yep=true;
		} else {
			if(ans<++cnt[c-'A']) {
				ans=cnt[c-'A'],yep=false;
				cx=c;
			}
			else if(ans==cnt[c-'A'])
				yep=true;
		}
	}
	if(yep) 
		cout << "?" << "\n";
	else
		cout << cx << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}