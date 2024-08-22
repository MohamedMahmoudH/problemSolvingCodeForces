#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
using ll = long long;

ll merge(ll a , ll b)
{
    return a + b;
}

class segmentTree{
    private:
        #define left    (2 * node + 1)
        #define right   (2 * node + 2)
        #define mid     ((l + r) >> 1)
        #define nullVal        0       // nullVal depends on operation of problem
        ll sz ;
        vector<ll>seg;

        void build(ll l , ll r , ll node, vector<ll>&arr)
        {
            if(l == r) // now we reach leaf node
            {
                if(l < arr.size()) seg[node] = arr[l]; // it's assign the arr values to the leafs level
                return;
            }
            build(l, mid, left, arr);
            build(mid+1, r, right, arr);
            seg[node] = merge(seg[left] , seg[right]);
        }

        void update(ll l, ll r, ll node, ll ind, ll val) // remember that you only update the arr elements
        {
            if(l == r)
            {
                seg[node] = val;
                return;
            }
            ind > mid ? update(mid+1, r, right, ind, val) : update(l, mid, left, ind, val);
            seg[node] = merge(seg[left] , seg[right]); // that's update all levels above the arr level
        }

        ll query(ll l, ll r, ll node, ll lq, ll rq) // 1, 2, 3, 4
        {
            if( l > rq || r < lq ) return nullVal;
            if(l >= lq && r <= rq) return seg[node];
            return merge(query(l, mid, left, lq, rq) , query(mid+1, r, right, lq, rq));
        }

    public:
        segmentTree(vector<ll> &arr) // 1, 2, 3, 4 --> 100 -> 111
        {
            ll n = arr.size();
            sz = 1;
            while(sz < n)sz <<= 1;
            seg = vector<ll>(2 * sz , nullVal);
            build(0, sz-1, 0, arr);
        }

        void update (ll ind , ll val)
        {
            update(0, sz-1, 0, ind, val);
        }

        ll query(ll lq , ll rq)
        {
            return query(0, sz-1, 0, lq, rq);
        }

    #undef left
    #undef right
    #undef mid
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
