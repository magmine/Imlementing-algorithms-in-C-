//UVA_11503 virtual friends : Disjoint sets and graphs

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;
 
class d_sets{
	protected:
		vector<int> parent;
		vector<int> rank;
		vector<int> size;
		int forests;
	public:
		d_sets(int n){
			rank.resize(n, 1);
			parent.resize(n);
			size.resize(n, 1);
			forests = n;
			for(int i=0;i<n;i++)
				parent[i] = i;
		}
		int find_parent(int i){
			if(parent[i] == i)
				return (i);
			parent[i] = find_parent(parent[i]);
			return (parent[i]);
		}
		bool union_e(int i, int j){
			if(i == j)
				return false;
			int ipar = find_parent(i);
			int jpar = find_parent(j);
			if(ipar == jpar)
				return false;
			if(rank[ipar] > rank[jpar])
				parent[jpar] = ipar;
			else if(rank[ipar] < rank[jpar])
				parent[ipar] = jpar;
			else{
				parent[jpar] = parent[ipar];
				rank[ipar]++;
			}
			size[ipar] += size[jpar];
			size[jpar] = size[ipar];
		}
		int net_size(int i){
			return (size[find_parent(i)]);
		}
};
 
int main(){
	int t;
	int n;
	cin>>t;
	while(t--){
		cin>>n;
		cin.ignore();
		d_sets *ds = new d_sets(2*n);
		int pos = 0;
		map<string, int> *mp = new map<string, int>();
		for(int i=0;i<n;i++){
			string s;
			getline(cin, s);
			string s1 = s.substr(0, s.find(" "));
			string s2 = s.substr(s.find(" ") + 1);
			if(mp->find(s1) == mp->end()){
				(*mp)[s1] = pos;
				pos++;
			}
			if(mp->find(s2) == mp->end()){
				(*mp)[s2] = pos;
				pos++;
			}
			ds->union_e((*mp)[s1], (*mp)[s2]);
			cout<<ds->net_size((*mp)[s1])<<"\n";
			//cout<<ds.net_size(mp[s2])<<"\n";
		}
		delete ds;
		mp->clear();
	}
	return(0);
}
