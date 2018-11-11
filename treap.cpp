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

struct treap {
	struct node {
		int val, prio, size;
		node *l, *r;
	};

	treap() {
		srand((unsigned) time(NULL));
	}

	node* init(int val) {
		node *tmp = (node *)malloc(sizeof(node));
		tmp->val = val;
		tmp->prio = rand();
		tmp->size = 1;
		tmp->l = tmp->r = NULL;
		return tmp;
	}

	inline int sz(node *t) {
		return t ? t->size : 0;
	}

	inline void upd_sz(node *t) {
		if (t) t->size = sz(t->l) + 1 + sz(t->r);
	}

	void split(node *t, node* &l, node* &r, int key) {
		if (!t) {
			l = r = NULL;
		} else if (t->val <= key) {
			split(t->r, t->r, r, key);
			l = t;
		} else {
			split(t->l, l, t->l, key);
			r = t;
		}
		upd_sz(t);
	}

	void merge(node* &t, node *l, node *r) {
		if (!l || !r) {
			t = l ? l : r;
		} else if (l->prio > r->prio) {
			merge(l->r, l->r, r);
			t = l;
		} else {
			merge(r->l, l, r->l);
			t = r;
		}
		upd_sz(t);
	}

	bool search(node *t, int key) {
		if (!t) {
			return false;
		} else if (t->val == key) {
			return true;
		} else {
			return search(key <= t->val ? t->l : t->r, key);
		}
	}

	void insert(node* &t, node *it) {
		if (!t) {
			t = it;
		} else if (t->prio < it->prio) {
			split(t, it->l, it->r, it->val);
			t = it;
		} else {
			insert(it->val <= t->val? t->l : t->r, it);
		}
		upd_sz(t);
	}

	void erase(node* &t, int key) {
		if (!t) {
			return;
		} else if (t->val == key) {
			node *tmp = t;
			merge(t, t->l, t->r);
			free(tmp);
		} else {
			erase(key < t->val? t->l : t->r, key);
		}
		upd_sz(t);
	}
};

int main()
{

	return 0;
}
