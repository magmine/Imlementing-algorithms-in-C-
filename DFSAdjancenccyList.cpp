#include<bits/stdc++.h>
using namespace std;

list<int> *adjList;

void dfs(int start,vector<bool> &isVisited,stack<int> &order){
	//stack<int> order;
	list<int>::iterator it;
	it=adjList[start].begin();
	order.push((start));
	isVisited[start]=true;
	for(it;it!=adjList[start].end();it++){
		if(!isVisited[(*it)]){
			dfs((*it),isVisited,order);
		}
	}
	
}
void addEdge(int V1,int V2){
	adjList[V1].push_back(V2);
}

int main(){
	int V;
	cin>>V;
	adjList=new list<int>[V];
	int V1,V2;
	/*while(cin>>V1){
		cin>>V2;
		if(V1<0 || V2<0) break;
		addEdge(V1,V2);
	}*/
	addEdge(1,5);
	addEdge(2,1);
	addEdge(0,3);
	addEdge(3,5);
	addEdge(2,6);
	addEdge(5,6);
	addEdge(6,5);
	addEdge(7,6);
	addEdge(2,0);
	vector<bool> isVisited(V,false);
	stack<int> order;
	int start;
	cout<<"Give the start Node: ";
	cin>>start;
	cout<<"\n";
	dfs(start,isVisited,order);
	while(!order.empty()){
		cout<<order.top()<<" ";
		order.pop();
	}
}
