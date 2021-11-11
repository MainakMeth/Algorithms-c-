#include<bits/stdc++.h>
using namespace std;
#define MAX 20

int dist[MAX];
int parent[MAX];

void shortestPath(int i,int j){

	if(i == j){
		cout<<char(i+65)<<" ";
		return;
	}

	shortestPath(i,parent[j]);
	cout<<char(j+65)<<" ";
}

struct edge{
	int sv;
	int val;
	int ev;
};


void bellmanFord(int v,struct edge a[],int e,int start_vertex){

	for(int i=0;i<v;i++){
		dist[i] = INT_MAX;
		parent[i] = -1;
	}

	dist[start_vertex] = 0;

	for(int i=0;i<v-1;i++){
		for(int ed=0;ed < e;ed++){
			if(dist[a[ed].sv] + a[ed].val < dist[a[ed].ev]){
				dist[a[ed].ev] = dist[a[ed].sv] + a[ed].val;
				parent[a[ed].ev] = a[ed].sv;
			}
		}
	}

	bool neg_cycle = false;

	for(int ed=0;ed < e;ed++){
		if(dist[a[ed].sv] + a[ed].val < dist[a[ed].ev]){
				dist[a[ed].ev] = dist[a[ed].sv] + a[ed].val;
				neg_cycle = true;
				break;
		}
	}

	if(neg_cycle){
		cout<<"Negative cycle is present"<<endl;
	}

	else{
		cout<<"No negative cycle"<<endl;
		for(int i=0;i<v;i++){
			cout<<char(start_vertex+65)<<" "<<char(i+65)<<" "<<dist[i]<<endl;
			shortestPath(start_vertex,i);
			cout<<endl<<endl;
		}
	}

}

int main(){



	freopen("input_bell.txt","r",stdin);

	int v;
	cin>>v;

	int adj_mat[MAX][MAX];

	int e=0;

	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){

			cin>>adj_mat[i][j];

			if(i != j &&  adj_mat[i][j] != 0){ // for finding total edges;
				e++;
			}

		}
	}

	int start_vertex;
	cin>>start_vertex;

	struct edge a[e];
	int k=0;
	for(int i=0;i<v;i++){                   //storing all edges in edges structure
		for(int j=0;j<v;j++){

			if(i != j && adj_mat[i][j]!=0){
				a[k].sv=i;
				a[k].ev=j;
				a[k].val=adj_mat[i][j];
				k++;
			}
		}
	}
	cout<<"The Adjacency Matrix is"<<endl;
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			cout<<adj_mat[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;

	bellmanFord(v,a,e,start_vertex);

	return 0;
}
