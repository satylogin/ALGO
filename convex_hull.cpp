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

class Point {
	public:
		ll x, y;
		bool operator < (Point b) {
			if (y != b.y) return y < b.y;
			return x < b.x;
		}
};

Point hull[2000001], A[2000001], pivot;
int len, N;

int compare(Point a, Point b, Point c) {
	ll area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (area > 0) return -1;
	if (area < 0) return 1;
	return 0;
}

ll dist(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool polar_order(Point a, Point b) {
	int order = compare(pivot, a, b);
	if (order == 0) return dist(pivot, a) < dist(pivot, b);
	return (order == -1);
}

void convex_hull() {
	if (N < 3) return;
	int ans = 0;
	for (int i = 1; i < N; ++i) {
		if (A[i] < A[ans]) ans = i;
	}
	swap(A[ans], A[0]);
	pivot = A[0];
	sort(A+1, A+N, polar_order);
	hull[len++] = A[0];
	hull[len++] = A[1];
	hull[len++] = A[2];
	for (int i = 3; i < N; ++i) {
		while (len > 2 && compare(hull[len-2], hull[len-1], A[i]) != -1) len--;
		hull[len++] = A[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	return 0;
}
