#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define fi first
#define sc second
#define deb 0

int orientation(pii a, pii b, pii c)
{
	int x = (b.sc - a.sc) * (c.fi - b.fi)-
		(b.fi - a.fi) * (c.sc - b.sc);

	if (x < 0) return -1;
	if (x > 0) return 1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
