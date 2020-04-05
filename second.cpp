#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef long double ld;

const ll N = (ll)1e5 + 2;
const ll MOD = 998244353;
const ll inf = (ll)1e18 + 6;

template <class T>
bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template <class T>
bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

ll add(ll x, ll y)
{
	x += y;
	if (x >= MOD)
		return x - MOD;
	return x;
}

ll sub(ll x, ll y)
{
	x -= y;
	if (x < 0)
		return x + MOD;
	return x;
}

ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}

ll bin_pow(ll x, ll p)
{
	if (p == 0)
		return 1;
	if (p & 1)
		return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}

ll rev(ll x)
{
	return bin_pow(x, MOD - 2);
}

vector<string> parse(string s, char delimiter)
{
	vector<string> ans;
	string str = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == delimiter)
		{
			if (str != "")
				ans.pb(str);
			ans.pb(string(1, delimiter));
			str = "";
		}
		else
			str += s[i];
	}
	if (str != "")
		ans.pb(str);
	return ans;
}

string paren(string s, ll depth)
{
	if (s == "")
		return s;
	else
	{
		char ch = *min_element(all(s));
		vector<string> splitt = parse(s, ch);
		string ans = "";
		for (auto i : splitt)
		{
			if (i != string(1, ch))
				ans += paren(i, ch - '0');
			else
				ans += string(1, ch);
		}
		forn(i, ch - '0' - depth)
			ans = '(' + ans + ')';
		return ans;
	}
}

void solve()
{
	string s;
	cin >> s;
	cout << paren(s, 0) << "\n";
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(20);
	cout << fixed;
#ifdef LOCAL_DEFINE
	freopen("input.txt", "rt", stdin);
#endif

	ll t, idx = 0;
	cin >> t;
	while (t--)
	{
		idx++;
		cout << "Case #" << idx << ": ";
		solve();
	}
}