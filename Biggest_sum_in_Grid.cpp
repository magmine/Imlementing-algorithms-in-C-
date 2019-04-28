/*Given a grid of numbers find the biggest sum possible, you are
allowed to move only down or right, the start is from 0,0 and the
end in n,n*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int> > max_grid;

bool is_valid(int x,int y,int n){
	if(x>=n || y>=n) return false;
	return true;
}

ll sum_grid(vector<vector<int> > &grid,int x,int y){
	int n=grid.size();
	if(!is_valid(x,y,n)) return 0;
	if(max_grid[x][y]!=-1){
		//printf("repeated subtask\n");
		return max_grid[x][y];
		
	} 
	
	max_grid[x][y]= grid[x][y] + max(sum_grid(grid,x+1,y),sum_grid(grid,x,y+1));
	return max_grid[x][y];
}

int main(){
	int n;
	cin>>n;
	ll sum=0;
	vector<vector<int> > grid(n,vector<int>(n));
	max_grid.resize(n,vector<int> (n,-1));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
		}
	}
	sum=sum_grid(grid,0,0);
	cout<<sum;
	
	return 0;
}
