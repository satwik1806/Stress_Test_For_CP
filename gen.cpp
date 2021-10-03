#include<bits/stdc++.h>
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifndef ONLINE_JUDGE
    ~debug() { cerr << endl; }
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair < b, c > d) {
        ris << "(" << d.first << ", " << d.second << ")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
            *this << ", " + 2 * (it == d.b) << *it;
        ris << "]";
    }
#else
    sim dor(const c&) { ris; }
#endif
};
#define print(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b){
    uniform_int_distribution<int> uid(a,b);
    return uid(rng);
}

char randchar(char a, char b){
    return (char) a + randint(0,b-a);
}

class DSU {
private:
    vector<int> comp, siz, sta;
public:
    DSU(int n) : comp(n), siz(n, 1) {
        for (int i = 0; i < n; ++i) comp[i] = i;
    }
    int Find(int i) {
        if (comp[i] != i) return comp[i] = Find(comp[i]);
        else return i;
    }
    bool Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (siz[a] < siz[b]) swap(a, b);

        sta.push_back(b);
        if (a == b) return false;

        siz[a] += siz[b];
        comp[b] = a;
        return true;
    }
    void Undo() {
        int b = sta.back();
        int a = comp[b];
        sta.pop_back();

        if (a != b) siz[a] -= siz[b];
        comp[b] = b;
    }
    int compSize(int i) {
        return siz[Find(i)];
    }
};

void print_edges(vector<pair<int,int>> edges, int n, bool weight){
    // printing tree;
    cout << n << endl;
    for(auto [p,q]: edges){
        cout << p + 1 << " " << q + 1;
        if(weight) cout << " " << randint(1,100);
        cout << endl;
    }
}

void print_edges(vector<pair<int,int>> edges, int n, int m, bool weight){
    // printing tree;
    cout << n << " " << m <<endl;
    for(auto [p,q]: edges){
        cout << p + 1 << " " << q + 1;
        if(weight) cout << " " << randint(1,100);
        cout << endl;
    }
}

#define all(a) a.begin(),a.end()
vector<pair<int,int>> gen_tree(int n, bool weight){
    vector<int> par(n);
    // make a tree with 0 as root.
    for(int i=1;i<n;i++) par[i] = randint(0,i-1);

    // now to create a diff tree. just rename the vertices.
    vector<int> rename(n); for(int i=0;i<n;i++) rename[i] = i;
    random_shuffle(all(rename));

    // now create edges.
    vector<pair<int,int>> edges;
    for(int i=1;i<n;i++){
        int u = rename[par[i]]; int v = rename[i];
        if(randint(1,10)%2) swap(u,v);
        edges.push_back({u,v});
    }

    // check if it contains any loops.
    DSU dsu(n + 1);
    for(auto [p,q]: edges){
        assert(dsu.Find(p) != dsu.Find(q));
        dsu.Union(p,q);
    }

    return edges;
}

vector<pair<int,int>> gen_graph(int n, int m, bool weight){
    vector<pair<int,int>> edges = gen_tree(n,weight);

    // just add some new edges to this tree to make it a graph.
    for(int i=0;i<m - edges.size();i++){
        int u = randint(1,n);int v = u;
        while(v == u) v = randint(1,n);
        edges.push_back({u,v});
    }

    return edges;
}

vector<int> dis(int n){
    set<int> temp;
    vector<int> ret;
    while(ret.size() != n){
        int x = randint(1,220);
        while(temp.find(x) != temp.end()) x = randint(1,220);
        ret.push_back(x);
        temp.insert(x);
    }
    return ret;
}

int main(int argc, char* argv[]){
    srand(atoi(argv[1]));

    int n = randint(2,20);
    vector<vector<int>> g(n,vector<int>(5));
    for(int i=0;i<5;i++){
        vector<int> temp = dis(n);
        for(int j=0;j<n;j++){
            g[j][i] = temp[j];
        }
    }

    cout << 1 << endl << n << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
