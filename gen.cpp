#include<bits/stdc++.h>
using namespace std;

int randint(int a, int b){
    return a + rand() % (b - a + 1);
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

    // not to create a diff tree. just rename the vertices.
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

int main(int argc, char* argv[]){
    srand(atoi(argv[1]));

    int n = randint(1,20);
    vector<pair<int,int>> edges = gen_graph(n,n + 10,0);
    print_edges(edges,n, n + 10,0);

    return 0;
}
