#include<iostream>
#include<climits>
#define s 10
using namespace std;
int p[s];
int n;
int M[s][s];
int S[s][s];
void input(){
    cout<<"Enter no. of matrices\n";
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cout<<"Enter the dimension of "<<i+1<<" matrix\n";
        cin>>a>>b;
        p[i]=a;
        if(i==n-1)
            p[i+1]=b;
    }
}

void printOptimalParenthesis(int i,int j){
    if(i==j)
        cout<<"A"<<i<<" ";
    else{
        cout<<"(";
        printOptimalParenthesis(i,S[i][j]);
        printOptimalParenthesis(S[i][j]+1,j);
        cout<<")";
    }
}

void display_s() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << S[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixChainMultiplication(){
    int cost=0;
    for(int i=1;i<=n;i++)
        M[i][i]=0;
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            M[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                cost=M[i][k]+M[k+1][j]+p[i-1]*p[k]*p[j];
                if(cost<M[i][j]){
                    M[i][j]=cost;
                    S[i][j]=k;
                }
            }
        }
    }
    cout<<endl<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<M[i][j]<<"  ";
        }
        cout<<endl;
    }

    cout << endl;
    display_s();

    cout<<endl<<endl;
    cout<<" cost = "<<M[1][n]<<endl;
    cout<<" Parenthesization is : \n";
    printOptimalParenthesis(1,n);
}

int main(){
    input();
    matrixChainMultiplication();
}
