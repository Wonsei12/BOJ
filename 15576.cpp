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

typedef complex<double> cpx;

void fft(vector<cpx> &a, bool inv){
    int n = sz(a), j = 0;
    vector<cpx> roots(n/2);
    for(int i=1; i<n; i++){
        int bit = (n >> 1);
        while(j >= bit) j -= bit, bit >>= 1;
        j += bit;
        if(i < j) swap(a[i], a[j]);
    }
    double ang = 2 * PI / n * (inv ? -1 : 1);
    for(int i=0; i<n/2; i++) roots[i] = cpx(cos(ang * i), sin(ang * i));
    for(int i=2; i<=n; i<<=1){
        int step = n / i;
        for(int j=0; j<n; j+=i) for(int k=0; k<i/2; k++){
            cpx u = a[j+k], v = a[j+k+i/2] * roots[step * k];
            a[j+k] = u+v; a[j+k+i/2] = u-v;
        }
    }
    if(inv) for(int i=0; i<n; i++) a[i] /= n;
}
vector<ll> multiply(vector<ll> &v, vector<ll> &w){
    vector<cpx> fv(v.begin(), v.end());
    vector<cpx> fw(w.begin(), w.end());
    int n = 2; 
    while(n < sz(v) + sz(w)) 
    	n <<= 1;
    fv.resize(n); fw.resize(n);
    fft(fv, 0); fft(fw, 0);
    for(int i=0; i<n; i++) fv[i] *= fw[i];
    fft(fv, 1);
    vector<ll> ret(n);
    for(int i=0; i<n; i++) ret[i] = (ll)round(fv[i].real());
    return ret;
}

// Copied from Gennady-Korotkevich's template

#define LOCAL

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string)s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}\n";
	return res;
}

template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto& x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}\n";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + "," + to_string(get<4>(p)) + ")";
}

void debug_out() {
	cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "\n[" << #__VA_ARGS__ << "]:\n", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// End of Gennady-Korotkevich's template 

void solve() {
	string s1, s2; cin >> s1 >> s2;
	if(s1=="0"||s2=="0") {
		cout << 0 << "\n";
		return;
	}
	reverse(all(s1)); reverse(all(s2));
	vector<ll> a, b;
	for(int i=0 ; i<sz(s1) ; i++)
		a.push_back(s1[i]-'0');
	for(int i=0 ; i<sz(s2) ; i++) 
		b.push_back(s2[i]-'0');
	vector<ll> res = multiply(a,b);
	int last;
	for(int i=0 ; i<sz(res) ; i++) {
		if(res[i]!=0) last=i;	
	}
	vector<ll> ans;
	for(int i=0 ; i<last ; i++) {
		ans.push_back(res[i]%10);
		res[i+1]+=res[i]/10;
	}
	if(res[last] != 0) {
		cout << res[last];
	}
	reverse(all(ans));
	for(auto x : ans) 
		cout << x;
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}