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

int main() {
	IOS;
	while(1) {
		vector<int> a(3);
		for(int i=0 ; i<3 ; i++) 
			cin >> a[i];
		if(a[0]==0)
			break;
		sort(a.begin(),a.end());
		if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2]) 
			cout << "right\n";
		else
			cout << "wrong\n";
	}
}