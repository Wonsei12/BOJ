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

struct Point2D {
	double x;
	double y;
};

int ccw(Point2D p1, Point2D p2, Point2D p3) {
	// p1p2 -> p2p3 
	// returns 1 if CCW, 0 if straight, -1 if CW 
	double CCW = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;
	if(CCW > 0)
		return 1;
	else if(CCW == 0)
		return 0;
	else if(CCW < 0)
		return -1;
}

void solve() {
	Point2D p[3];
	for(int i=0 ; i<3 ; i++) {
		cin >> p[i].x >> p[i].y;
	}
	cout << ccw(p[0],p[1],p[2]) << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}