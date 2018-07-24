//Topological sort;
#include<bits/stdc++.h>
using namespace std;

list<int> *adjList;
void dfs(int start,vector<bool> &isVisited,stack<int> &order){
	//stack<int> order;
	list<int>::iterator it;
	it=adjList[start].begin();
	isVisited[start]=true;
	for(it;it!=adjList[start].end();it++){
		if(!isVisited[(*it)]){
			dfs((*it),isVisited,order);
		}
	}
	order.push(start);
	
}
void addEdge(int V1,int V2){
	adjList[V1].push_back(V2);
}

stack<int> topological_sort(int V){
	stack<int> sorted;
	vector<bool> isVisited(V,false);
	for(int i=0;i<V;i++){
		if(!isVisited[i])
			dfs(i,isVisited,sorted);
	}	
	return sorted;
}

int main(){
	int V;
	V=8;
	adjList=new list<int>[V];
	int V1,V2;
	addEdge(1,5);
	addEdge(2,1);
	addEdge(0,3);
	addEdge(3,5);
	addEdge(2,6);
	addEdge(5,6);
	//addEdge(6,5);
	addEdge(7,6);
	addEdge(2,0);
	addEdge(4,3);
	addEdge(4,7);
	stack<int> order;
	int start;
	cout<<"topological sort: ";
	order=topological_sort(V);
	while(!order.empty()){
		cout<<order.top()<<" ";
		order.pop();
	}
}
