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
	ll x;
	ll y;
};

bool cmp(Point2D p1, Point2D p2) {
	if(p1.y == p2.y)
		return p1.x < p2.x;
	return p1.y < p2.y;
}

bool cmp2(Point2D p1, Point2D p2) {
	if(p1.y * p2.x != p2.y * p1.x)
		return p1.y * p2.x < p2.y * p1.x;
	if(p1.y != p2.y)
		return p1.y < p2.y;
	return p1.x < p2.x;
}

int ccw(Point2D p1, Point2D p2, Point2D p3) {
	// p1p2 -> p2p3 
	// returns 1 if CCW, 0 if straight, -1 if CW 
	ll CCW = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;
	if(CCW > 0)
		return 1;
	else if(CCW == 0)
		return 0;
	else if(CCW < 0)
		return -1;
}

void solve() {
	int n; cin >> n;
	vector<Point2D> p(n);

	for(int i=0 ; i<n ; i++) 
		cin >> p[i].x >> p[i].y;

	sort(p.begin(),p.end(),cmp);
	for(int i=1 ; i<n ; i++) {
		p[i].x -= p[0].x; 
		p[i].y -= p[0].y;
	}
	Point2D orig = p[0];
	p[0].x = 0; p[0].y = 0;
	sort(p.begin()+1,p.end(),cmp2);
	
	vector<Point2D> hull;
	for(int i=0 ; i<n ; i++) {
		while(sz(hull) >= 2 && ccw(hull[sz(hull) - 2], hull.back(), p[i]) <= 0)
			hull.pop_back();
		hull.push_back(p[i]);
	}

	auto dist = [](Point2D p1, Point2D p2) -> ll {
		ll dx = p1.x - p2.x;
		ll dy = p1.y - p2.y;
		return dx*dx + dy*dy;
	};
	
	auto check = [](Point2D s1, Point2D e1, Point2D s2, Point2D e2) {
		Point2D p1 = {e1.x - s1.x, e1.y - s1.y};
		Point2D p2 = {e2.x - s2.x, e2.y - s2.y};
		return ccw({0,0},p1,p2) >= 0;
	};
	
	int t = 0;
	ll ret = 0;
	int idx1, idx2;
	for(int i=0 ; i<sz(hull) ; i++) {
		while(t+1 < sz(hull) && check(hull[i], hull[i+1], hull[t], hull[t+1])) {
			if(ret < dist(hull[i], hull[t])) {
				ret = dist(hull[i], hull[t]);
				idx1 = i, idx2 = t;
			}
			t += 1;
		}
		if(ret < dist(hull[i], hull[t])) {
			ret = dist(hull[i], hull[t]);
			idx1 = i, idx2 = t;
		}
	}
	cout << hull[idx1].x + orig.x << " " << hull[idx1].y + orig.y << " " << hull[idx2].x + orig.x << " " << hull[idx2].y + orig.y << "\n";
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--) 
		solve();
}