#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = int;

ll merge(ll a , ll b, ll l, ll r)
{
    return ((((ll)log2(r - l + 1)) & 1)? a | b : a ^ b);
}

class segmentTree{
    private:
        #define left    (2 * node + 1)
        #define right   (2 * node + 2)
        #define mid     ((l + r) >> 1)
        #define nullVal        0       // nullVal depends on operation of problem
        ll sz ;
        vector<ll> seg;

        void build(ll l , ll r , ll node, vector<ll>&arr)
        {
            if(l == r) // now we reach leaf node
            {
                if(l < arr.size()) seg[node] = arr[l]; // it's assign the arr values to the leafs level
                return;
            }
            build(l, mid, left, arr);
            build(mid+1, r, right, arr);
            seg[node] = merge(seg[left] , seg[right] , l , r);
        }

        void update(ll l, ll r, ll node, ll ind, ll val) // remember that you only update the arr elements
        {
            if(l == r)
            {
                seg[node] = val;
                return;
            }
            ind > mid ? update(mid+1, r, right, ind, val) : update(l, mid, left, ind, val) ;
            seg[node] = merge(seg[left] , seg[right] , l , r);
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

        ll getSegment(ll ind)
        {
            return seg[ind];
        }

    #undef left
    #undef right
    #undef mid
};


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n , q;
    cin >> n >> q;

    vector<ll> arr(1ULL << n);
    for(ll &x : arr) cin >> x;

    segmentTree tree(arr);

    while(q--)
    {
        ll x , y;
        cin >> x >> y;
        tree.update(x-1 , y);
        cout << tree.getSegment(0) << '\n';
    }
}
