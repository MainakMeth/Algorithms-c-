#include<iostream>
using namespace std;
#define MAX 20

int parent[MAX];
int rank_v[MAX];

struct edge{
	int sv;
	int val;
	int ev;
};

int partitionLowPivot(struct edge a[],int low,int high){

   double pivot=a[low].val;
   int left=low;
   int right=high+1;

   while(left<right){

        do{
			left++;
		}while(left<=high && a[left].val<pivot);


		do{
			right--;
		}while(a[right].val>pivot);


      if(left<right){
         swap(a[left],a[right]);
      }
   }



 swap(a[low],a[right]);


   return right;
 }

  void quickSort(struct edge a[],int low,int high){

     if(low<high){
       int j=partitionLowPivot(a,low,high);
        quickSort(a,low,j-1);
        quickSort(a,j+1,high);

     }
  }


int findParent(int i){

	if(i == parent[i]){              //base case
		return i;
	}

	return parent[i] = findParent(parent[i]);             // path compressing step

}

void doUnion(int i,int j){

	i = findParent(i);
	j = findParent(j);

	if(rank_v[i] < rank_v[j]) //making smaller one attached to bigger one
		parent[i] = j;


	else if(rank_v[j] < rank_v[i]) //making samller one attached to bigger one
		parent[j] = i;

	else{                     //if both have same rank make any one and increment rank of parent
		parent[j] = i;
		rank_v[i]++;
	}
}


void kruskalMST(int v,struct edge a[],int e){

	quickSort(a,0,e-1);

	int min_cost=0;
	int min_edges=0;

	for(int i=0;i<v;i++){  // intially each node is a single component and all are having rank 0;

		parent[i]=i;
		rank_v[i]=0;

	}

	for(int i=0;i<e;i++){

		if(min_edges == e/2 - 1){
			break;
		}

		if(findParent(a[i].sv) != findParent(a[i].ev)){
			min_cost+=a[i].val;
			doUnion(a[i].sv,a[i].ev);
			min_edges++;
			cout<<char(a[i].sv+65)<<char(a[i].ev+65)<<" "<<a[i].val<<endl;
		}

	}

	cout<<"The minimum cost is"<<" "<<min_cost<<endl;

	return;


}

int main(){



	freopen("input_krush.txt","r",stdin);

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

	kruskalMST(v,a,e);


	return 0;
}
