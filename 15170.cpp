#include <bits/stdc++.h>
using namespace std;

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

int main() {
	IOS;
	double cX = 0, cY = 0;
	int n; cin >> n;
	vector<Point2D> infected, noninfected;
	for(int i=0 ; i<n ; i++) {
		double x, y; cin >> x >> y; 
		char c; cin >> c;
		if(c == 'I') {
			infected.push_back({x,y});
			cX += x;
			cY += y;
		} else {
			noninfected.push_back({x,y});
		}
	}
	if(sz(noninfected) == 0 || sz(infected) <= 2) {
		cout << "No\n";
		return 0;
	}
	int T = 300000;
	double ratio = 0.1f;
	auto dis = [](Point2D a, Point2D b) -> double {
		double dx = a.x - b.x;
		double dy = a.y - b.y;
		return sqrt(dx*dx + dy*dy);
	};
	while(T--) {
		double mx = 0, mxIdx;
		for(int i=0 ; i<sz(infected) ; i++) {
			double cur = dis(infected[i], {cX,cY});
			if(mx < cur) {
				mx = cur;
				mxIdx = i;
			}
		}
		cX += (infected[mxIdx].x - cX) * ratio;
		cY += (infected[mxIdx].y - cY) * ratio;
		ratio*= 0.999;
	}
	double R = 0;
	for(int i=0 ; i<sz(infected) ; i++) {
		R = max(R, dis({cX,cY}, infected[i]));
	}
	for(int i=0 ; i<sz(noninfected) ; i++) {
		if(R > dis({cX,cY},noninfected[i]) + 1e-9) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}	