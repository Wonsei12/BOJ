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
	vector<int> a(n);
	vector<int> cnt(10000);
	ll sum = 0;
	int mxcnt = 0;
	int mx=-6000,mn=6000;
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
		sum += a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
		cnt[a[i]+4000] += 1;
		mxcnt=max(mxcnt,cnt[a[i]+4000]);
	}
	bool vis=0;
	int freq = -1;
	for(int i=0 ; i<10000 ; i++) {
		if(cnt[i]==mxcnt&&!vis) {
			freq=i-4000;
			vis=1;
		} else if(cnt[i]==mxcnt&&vis) {
			freq=i-4000;
			break;
		} 
	}
	sort(a.begin(),a.end());
	cout << fixed << setprecision(0);
	cout << (double)sum / n << "\n";
	cout << a[n / 2] << "\n";
	cout << freq << "\n";
	cout << mx-mn << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}