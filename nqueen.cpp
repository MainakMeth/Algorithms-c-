#include<bits/stdc++.h>
using namespace std;
#define MAX 20

int x[MAX];

bool place(int k,int i){

	for(int j=1;j<k;j++){

		if(x[j] == i || abs(j-k) == abs(x[j] - i)){

			return false;
		}

	}

	return true;
}

void nQueen(int n,int k){


	for(int i=1;i<=n;i++){

		if(place(k,i) == true){
			x[k] = i;


			if(k == n){

				for(int j=1;j<=n;j++){
					cout<<x[j]<<" ";
				}
				cout<<endl;

				//return ;
			}

			else{
				nQueen(n,k+1);
			}
		}

	}


}

int main(){



	int n;
	cout<<"Enter the no of queens"<<endl;
	cin>>n;

	if(n == 2 || n == 3){

		cout<<"No possible solutions are there"<<endl;
		return 0;
	}

	for(int i=1;i<=n;i++){

		x[i] = -1;
	}

	cout<<"The possible solutions are "<<endl;
	nQueen(n,1);

	return 0;
}
