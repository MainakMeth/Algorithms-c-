#include<bits/stdc++.h>
using namespace std;


struct edge{
	int vertex;
	int value;
};

class MinHeap{
	edge *ptr;
	int max_size;
	int n;

	public:
	MinHeap(int size){

		max_size=size;
		n=0;
		ptr = new edge [max_size];

	}
	void heapify(int i);
	int parent(int i);
	int l_child(int i);
	int r_child(int i);
	int extractMin();
	void decreaseKey(int i,int newVal);
	int getMin();
	void deleteKey(int i);
	void insertKey(int ver,int val);
	bool isEmpty();

};


	bool MinHeap::isEmpty(){
		if(n == 0){
			return true;
		}

		else{
			return false;
		}
	}

	int MinHeap::parent(int i){
		return (i-1)/2;
	}

	int MinHeap::l_child(int i){
		return (2*i+1);
	}

	int MinHeap::r_child(int i){
		return (2*i+2);
	}

	int MinHeap::getMin(){
		return ptr[0].vertex;
	}

	void MinHeap::heapify(int i){

		int smallest = i;
		int l = l_child(i);
		int r = r_child(i);

		if(l < n && ptr[l].value < ptr[smallest].value)
			smallest = l;

		if(r < n && ptr[r].value < ptr[smallest].value)
			smallest = r;

		if(smallest != i){
			swap(ptr[smallest],ptr[i]);
			heapify(smallest);
		}

	}

	void MinHeap::insertKey(int ver,int val){

		if(n == max_size){
			cout<<"over flow"<<endl;
			return;
		}

		n++;
		int i = n-1;
		ptr[i].vertex=ver;
		ptr[i].value=val;

		while(i != 0 && ptr[parent(i)].value > ptr[i].value){

			swap(ptr[i],ptr[parent(i)]);
			i = parent(i);
		}

	}

	void MinHeap::decreaseKey(int i,int newval){

		ptr[i].value=newval;

		while(i !=0 && ptr[parent(i)].value > ptr[i].value){

			swap(ptr[i],ptr[parent(i)]);
			i = parent(i);
		}
	}

	int MinHeap::extractMin(){

		if(n <= 0)
			return INT_MAX;

		if(n == 1){
			n--;
			return ptr[0].vertex;
		}

		int root = ptr[0].vertex;
		ptr[0].vertex = ptr[n-1].vertex;
		ptr[0].value=ptr[n-1].value;
		n--;
		heapify(0);

		return root;
	}

	void MinHeap::deleteKey(int i){

		decreaseKey(i,INT_MIN);
		extractMin();
	}




/* int main(){
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);

	cout<<h.extractMin()<<" ";
	cout<<h.getMin()<<" ";
	h.decreaseKey(2,1);
	cout<<h.getMin();

	return 0;
}*/
