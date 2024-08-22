#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
using ll = int;

ll merge(ll a , ll b){
    return min(a , b);
}

class segmentTree{
private:
    #define left  (2 * node + 1)
    #define right (2 * node + 2)
    #define mid   ((l + r) >> 1)
    #define skip  0x3f3f3f3f
    ll sz;
    vector<ll> seg;

    void build(ll l, ll r, ll node, vector<ll>&arr)
    {
        if (l == r)
        {
            if(l < arr.size())seg[node] = arr[l];
            return;
        }
        build(l, mid, left, arr);
        build(mid+1, r, right, arr);
        seg[node] = merge(seg[left] , seg[right]);
    }

    void update(ll l, ll r, ll node, ll ind, ll val)
    {
        if(l == r)
        {
            seg[node] = val;
            return;
        }
        ind <= mid ? update(l, mid, left, ind, val) : update(mid+1, r, right, ind, val);
        seg[node] = merge(seg[left] , seg[right]);
    }

    ll query(ll l, ll r, ll node, ll lq, ll rq)
    {
        if(l > rq  || r < lq ) return skip;
        if(l >= lq && r <= rq) return seg[node];
        return merge(query(l, mid, left, lq, rq) , query(mid+1, r, right, lq, rq));
    }


public:
    segmentTree(vector<ll> &arr){
        ll n = arr.size();
        sz = 1;
        while(sz < n) sz <<= 1;
        seg = vector<ll>(2 * sz , skip);
        build(0, sz-1, 0, arr);
    }

    void update(ll ind, ll val){
        update(0, sz-1, 0, ind, val);
    }

    ll query(ll lq, ll rq)
    {
        return query(0, sz-1, 0, lq, rq);
    }

    void printTree()
    {
        ll x = 0 , y = 2*sz-1 , newLine = 1;
        while(y--)
        {
            cout << seg[x++] << "  ";
            if (x == (1ULL << newLine) - 1)
            {
                newLine++;
                cout << '\n';
            }
        }
    }
};

int main()
{
    ByMohamedMahmoud
    ll n ,m ;
    cin >> n >> m;

    vector<ll> arr(n);
    for(ll &in : arr)cin >> in;

    segmentTree tree(arr);

    while(m--)
    {
        ll op;
        cin >> op;
        if(1 == op)
        {
            ll i , v;
            cin >> i >> v;
            tree.update(i , v);
        }
        else
        {
            ll l , r;
            cin >> l >> r;
            cout << tree.query(l , r-1) << '\n';
        }
    }
}
