#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;
 
void copy_graph(vector<vector<int> > &graph, vector<vector<int> > &risid_gr){
    int sz = graph.size();
    for(int i=0;i<sz;i++){
        for(int j=0; j<sz; j++){
            risid_gr[i][j] = graph[i][j];
        }
    }
}
 
bool dfs(vector<vector<int> > &risid_gr, int src, int dest, vector<int>    &parent){
    queue<int> q;
    int sz = risid_gr.size();
    vector<bool> is_visited(sz, false);
    q.push(src);
    is_visited[src] = 0;
    parent[src] = -1;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int i=0; i<sz;i++){
            if(!is_visited[i] && risid_gr[s][i] > 0){
                q.push(i);
                parent[i] = s;
                is_visited[i] = true;
                if(i == dest){
                	printf("path found in dfs function\n");
                    return (true);
                }
            }
        }
    }
    printf("No more paths with dfs\n");
    return (false);
}
 
void	print_graph(vector<vector<int> > &graph){
	int sz = graph.size();
	for(int i=0; i<sz; i++){
		for(int j = 0; j<sz; j++){
			cout<<graph[i][j]<<" | ";
		}
		cout<<"\n";
	}
}
 
int get_min_flow(vector<vector<int> > &risid_gr, vector<int> &parent, int src, int sink){
    int min_flow = 1e9;
    int v = sink;
    while(v != src){
        min_flow = min(min_flow, risid_gr[parent[v]][v]);
        v = parent[v];
        if(v == -1){
            printf("ERROR in function get_min_flow\n");
            return (-1);
        }
    }
    printf("NO ERROR in function get_min_flow\n");
    return (min_flow);
}
 
void    update_risidual_graph(vector<vector<int> > &risid_gr, vector<int> &parent, int src, int sink, int min_flow){
    int v = sink;
    while(v != src){
        risid_gr[parent[v]][v] -= min_flow;
        risid_gr[v][parent[v]] += min_flow;
        v = parent[v];
        if(v == -1){
            printf("ERROR in function update_risidual_graph\n");
            return;
        }
    }
    printf("NO ERROR in function update_risidual_graph\n");
    printf("Printing graph after updating\n");
    print_graph(risid_gr);
}
 
int ford_fulkerson(vector<vector<int> > &graph, int src, int sink){
    int max_flow = 0;
    int sz = graph.size();
    vector<vector<int> > risid_gr(sz, vector<int> (sz));
    copy_graph(graph, risid_gr);
    printf("First risidual Graph\n************************************\n");
    print_graph(risid_gr);
    vector<int> parent(sz, -1);
    while(dfs(risid_gr, src, sink, parent)){
        int min_flow = 0;
        min_flow = get_min_flow(risid_gr, parent, src, sink);
        max_flow += min_flow;
        update_risidual_graph(risid_gr, parent, src, sink, min_flow);
        for(int i = 0; i<sz; i++) parent[i] = -1;
    }
    return (max_flow);
}
 
int main(){
    int ver;//number of vertices
    int edg;//number of edges
    cin>>ver>>edg;
    vector<vector<int> > graph(ver, vector<int> (edg, 0));
    for(int i = 0; i<edg;i++){
        int src, dest, cap; //source, destination, capacity
        cin>>src>>dest>>cap;
        graph[src][dest] = cap;
    }
    printf("Original Graph\n************************************\n");
    print_graph(graph);
    int src, sink;
    cin>>src>>sink;
    int max_flow = ford_fulkerson(graph, src, sink);
    cout<<max_flow<<"\n";
    return (0);
}
