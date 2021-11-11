#include<bits/stdc++.h>
using namespace std;
#include "priority_queue.cpp"
#define MAX 20

int dist[MAX];
//bool spt[MAX];
int parent[MAX];

void shortestPath(int i,int j){

	if(i == j){
		cout<<char(i+65)<<" ";
		return;
	}

	shortestPath(i,parent[j]);
	cout<<char(j+65)<<" ";
}

void dijkstrasAlgo(int adj_mat[MAX][MAX],int v,int start_vertex){

	for(int i=0;i<v;i++){
		dist[i] = INT_MAX;
		//spt[i] = false;
		parent[i]=-1;
	}

	dist[start_vertex] = 0;


	MinHeap h(MAX);

	h.insertKey(start_vertex,0);
	//int min_cost=0;

	for(int i=0;i<v;i++){

		int min_vertex = h.extractMin();
		//spt[min_vertex] = true;
		//min_cost+=dist[min_vertex];

		for(int j=0;j<v;j++){

			if(adj_mat[min_vertex][j] > 0){

				if(dist[min_vertex]+adj_mat[min_vertex][j] < dist[j]){

					dist[j] = dist[min_vertex]+adj_mat[min_vertex][j];
					h.insertKey(j,dist[j]);
					parent[j] = min_vertex;
				}
			}
		}
	}

	for(int i=0;i<v;i++){
		//min_cost+=dist[i];
		cout<<char(start_vertex+65)<<" "<<char(i+65)<<"  "<<dist[i]<<endl;
		shortestPath(start_vertex,i);
		cout<<endl<<endl;
	}
	//cout<<"Min cost "<<min_cost<<endl;
}

int main(){


	freopen("input_dijs.txt","r",stdin);

	int v;
	cin>>v;

	int adj_mat[MAX][MAX];

	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){

			cin>>adj_mat[i][j];

		}
	}

	int start_vertex;
	cin>>start_vertex;

	cout<<"The Adjacency Matrix is"<<endl;

	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			cout<<adj_mat[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;




	dijkstrasAlgo(adj_mat,v,start_vertex);


	return 0;
}
