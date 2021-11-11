//Program to solve the M-Coloring problem using backtracking/
#include<bits/stdc++.h>
using namespace std;

//Template of the graph
class graph
{
	public:
		int n;
		int m;
		int adj[20][20];
};

//Function block to display the graph
void display(graph g)
{
	cout<<"\nNumber of vertices of the graph:";
	cout<<g.n<<endl;

	cout<<"\nAdjacency Matrix representation of the graph -"<<endl;
	for(int i=0;i<g.n;i++)
	{
	 	for(int j=0;j<g.n;j++)
	 		cout<<g.adj[i][j]<<"\t";

	 	cout<<endl;
	}
}

//Function block to display the possible solution
void print(int solution[],int k,int c)
{
	int used_color[c+1]={0},sum=0,i;

	//Loop block to find how many distinct colours have been used
	for(i=0;i<k;i++)
	{
		if(!used_color[solution[i]])
		{
			used_color[solution[i]]=1;
			sum++;
		}
	}

	//Condition when all given colours are used
	if(sum==c)
	{
		solution[k]++;
		cout<<endl;
		for(i=0;i<k;i++)
			cout<<solution[i]<<"\t";
		cout<<endl;
	}

}

//Function block to check if a graph can be coloured
int colourable(graph g,int v,int solution[])
{
	int flag=1;

	while(flag)
	{
		solution[v]=(solution[v]+1)%(g.m+1);
		//Condition when the current vertex can't be coloured with any of the colours
		if(solution[v]==0)
			return 0;

		int i;

		//Loop block to check if any of the adjacent vertices of the current vertex have same coulur as it
		for(i=0;i<v;i++)
			if(g.adj[v][i]==1 && solution[v]==solution[i])
				break;
		//Condition when the graph can be coloured with the current colour
		if(i==v)
			flag=0;
	}

	return 1;

}

//Function block to display all solutions of the problem
void MColoring(graph g,int solution[],int v)
{
	int flag=1;

	while(flag)
	{
		//Condition when the vertex can be coloured
		if(colourable(g,v,solution))
		{
			//Condition when all vertices have been coloured
			if(v==g.n-1)
				print(solution,g.n,g.m);

			//If all vertices are not coloured , recursive call takes place to colour the next vertex
			else
				MColoring(g,solution,v+1);
		}

		//Condition of no more colour remaining to colour the current vetex
		else
			flag=0;
	}
}

//Driver Code
int main (void)
{
	graph g;   //Graph type object
	fstream f; //File type object
	int i,j;

	//File opened in readable form
	f.open("input.txt",ios::in);

	//Probem encountered while opening file
	while(!f)
	{
		cout<<"\nFile can't be opened!!";
		return 1;
	}

	f>>g.n;     //User input for number of vertices rear from file

	for(i=0;i<g.n;i++)
		for(j=0;j<g.n;j++)
			f>>g.adj[i][j];   //Userinput for Adjacency Matrix read from file

	cout<<"\nDetails of the graph entered are-";
	display(g);

	cout<<"\nEnter the number of colors:";
	cin>>g.m;

	int solution[g.n+1]={0};

	cout<<"\nPossible number solutions of for the graph with "<<g.n<<" vertices and "<<g.m<<"colours..............."<<endl;
	MColoring(g,solution,0); //Function called to find all the possible solutions(if any)



	if(!solution[g.n])
		cout<<"\nSorry!!!The graph can not be coloured with "<<g.m<<" colour(s).";

	else
		cout<<"\nTotal number of solutions is:"<<solution[g.n]<<endl;

	return 0;
}
