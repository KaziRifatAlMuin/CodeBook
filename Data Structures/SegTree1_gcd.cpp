#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SegTlazy {
public:
    #define lc (nd << 1)
    #define rc (lc | 1)

    struct node {
        ll val;
        node() {};
        node(ll v) {
            val = v;
        }
    };

    vector<int> a;
    vector<ll> lazy;
    vector<node> t;
    int n;

    SegTlazy() {
        a.clear();
        t.clear();
        lazy.clear();
        n = 0;
    }   

    SegTlazy(int n) {
        this -> n = n;
        a.resize(n + 1, 0);
        t.resize(4*n + 1, node());
        lazy.resize(4*n + 1, 0);
    }

    void takeInput() {
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        build(1, 1, n);
    }

    inline void merge(node &ND, node L, node R) {
        ND.val = gcd(L.val, R.val);
    } 

    void push(int nd, int b, int e) {
        // Lazy propagation is not used in this specific problem.
    }

    void build(int nd, int b, int e) {
        lazy[nd] = 0;
        if(b == e) {
            t[nd].val = a[b];
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        merge(t[nd], t[lc], t[rc]);
    }

    node query(int nd, int b, int e, int i, int j) {
        if(j < b || e < i) return node(0);
        if(i <= b && e <= j) {
            return t[nd];
        }
        int mid = (b + e) >> 1;
        auto left = query(lc, b, mid, i, j);
        auto right = query(rc, mid + 1, e, i, j);
        node res;
        merge(res, left, right);
        return res;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    SegTlazy segTree(n);
    segTree.takeInput();
    while(q--) {
        int L, R;
        cin >> L >> R;
        cout << segTree.query(1, 1, n, L, R).val << endl;
    }
    return 0;
}
