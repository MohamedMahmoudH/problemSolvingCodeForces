#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
using ll = int;
#define tk(x) ll x;cin >> x
#define take(x,y)  ll x;ll y;cin >> x >> y
#define psh(x) cout << x << '\n'
#define push(x,y) cout << x << ' ' << y << '\n'

struct Node{
    ll nod;
    ll num;
};

Node merge(Node a, Node b){
    return {min(a.nod , b.nod), (a.nod == b.nod)? a.num + b.num : (a.nod < b.nod ? a.num : b.num)};
}

class segmentTree{
private:
    #define left  (2 * node + 1)
    #define right (2 * node + 2)
    #define mid   ((l + r) >> 1)
    #define skip  0x3f3f3f3f
    ll sz;vector<Node> seg;

    void build(ll l, ll r, ll node, vector<ll>&arr)
    {
        if (l == r)
        {
            if(l < arr.size()){seg[node].nod = arr[l]; seg[node].num = 1;}
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
            seg[node].nod = val;
            return;
        }
        ind <= mid ? update(l, mid, left, ind, val) : update(mid+1, r, right, ind, val);
        seg[node] = merge(seg[left] , seg[right]);
    }

    Node query(ll l, ll r, ll node, ll lq, ll rq)
    {
        if(l > rq  || r < lq ) return {skip ,0};
        if(l >= lq && r <= rq) return seg[node];
        return merge(query(l, mid, left, lq, rq) , query(mid+1, r, right, lq, rq));
    }


public:
    segmentTree(vector<ll> &arr){
        ll n = arr.size();
        sz = 1;
        while(sz < n) sz <<= 1;
        seg = vector<Node>(2 * sz,{skip,0});
        build(0, sz-1, 0, arr);
    }

    void update(ll ind, ll val){
        update(0, sz-1, 0, ind, val);
    }

    Node query(ll lq, ll rq)
    {
        return query(0, sz-1, 0, lq, rq);
    }
};

signed main()
{
    ByMohamedMahmoud
    take(n,m);
    vector<ll> arr(n);
    for(ll &in : arr)cin >> in;
    segmentTree tree(arr);
    while(m--)
    {
        tk(op);
        if(1 == op)
        {
            take(i, v);
            tree.update(i , v);
        }
        else
        {
            take(l, r);
            push(tree.query(l, r-1).nod , tree.query(l, r-1).num);
        }
    }

}
