/*
Implementation of MST-kruskal algorithm using disjoint sets datastructure to solve
hackerran Kruskal (MST): Really Special Subtree problem
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class disjoint_set{
    protected:
        vector<int> parent;
        vector<int> rank;
        int size;
    public:
        disjoint_set(int n){
            size = n;
            parent.resize(n);
            rank.resize(n, 1);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        int find_parent(int i){
            if(parent[i] == i)
                return (i);
            parent[i] = find_parent(parent[i]);
            return (parent[i]);
        }
        bool union_t(int x, int y){
            if(x == y)
                return(false);
            int xpar= find_parent(x);
            int ypar = find_parent(y);
            if(xpar == ypar)
                return (false);
            if(rank[xpar] > rank[ypar])
                parent[ypar] = xpar;
            else if(rank[ypar] > rank[xpar])
                parent[xpar] = ypar;
            else{
                parent[ypar] = xpar;
                rank[xpar]++;
            }
            return (true);
        }
};

struct edges{
    int from, to, we;
    edges(int f, int t, int w):from(f), to(t), we(w){};
    bool operator < (const edges &e) const{
        if(we > e.we) return true;
        if(we < e.we) return false;
        if(from + to + we > e.from + e.to + e.we)
            return true;
        return false;
    }
};

int mst_kruskal(vector<edges> &all_edges, int n){
    priority_queue<edges> pq;
    disjoint_set ds(n);
    int sum = 0;
    int g_edges = all_edges.size();
    for(int i=0; i < all_edges.size(); i++){
        pq.push(all_edges[i]);
    }
    while(!pq.empty()){
        edges e(0,0,0);
        e = pq.top();
        pq.pop();
        if(ds.union_t(e.from, e.to)){
            sum+= e.we;
        }
    }
    return sum;
}

int main() {
    edges e(0,0,0);
    int g_nodes, g_edges;
    cin>>g_nodes>>g_edges;
    vector<edges> all_edges;
    for(int i=0;i<g_edges; i++){
        cin>>e.from>>e.to>>e.we;
        e.from--;    e.to--;
        all_edges.push_back(e);
    }
    int sum_mst = mst_kruskal(all_edges, g_nodes);
    cout<<sum_mst;
    return 0;
}
