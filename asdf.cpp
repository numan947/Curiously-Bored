#include<bits/stdc++.h>
using namespace std;



class UnionFind{

private:
	
	//keeps parents of different nodes, parent[i] = x => parent of node x, is node i
	vector<int>parent; 

	//contains all the parents, initially all nodes are inside it
	unordered_set<int>allParents;

	//contains rank, i.e. approximate height of different nodes
	vector<int>rank;

	// contains size of different node's sets
	vector<int>size;

	//contains totalDisjointSets in the forest
	int totalDisjointSets;

	// contains number of nodes in the whole forest
	int N;


	//contains if a node is to be removed from it's parent set,
	// if, rm[i] = true,
	//then node i will be removed from it's parent set, and will become an independent set
	//as it was in the beginning
	bool *rm;

public:

	UnionFind(){
		N=0;
		totalDisjointSets=0;
		allParents.clear();
		parent.clear();
		rank.clear();
		size.clear();
	}

	UnionFind(int N) //N elements Union Find
	{
		//initial params
		rank.assign(N,0);
		parent.assign(N,0);
		size.assign(N,1); //every set is initially of size 1

		totalDisjointSets = N; //totalDisjointSets is the number of sets in the disjoint forest
		this->N = N; // N is number of nodes in the disjoint forest

		//initially every one is everyone's parent and so...
		for(int i=0;i<N;i++){
			parent[i]=i;
			allParents.insert(i);
		}

		//for disunion
		rm = new bool[N];
		for(int i=0;i<N;i++)
			rm[i]=0;
	}

	//if we want to add new node in the set
	void incrementSet()
	{
		//initialize the new element as a new set
		rank.push_back(0);
		size.push_back(1);
		totalDisjointSets++;
		parent.push_back(N);
		parent[N]=N;
		allParents.insert(N);
		N++;

		//update rm[] array size
		bool* tmp = new bool[N];
		for(int i=0;i<N-1;i++)
			tmp[i] = rm[i];
		tmp[N-1] = 0;

		delete[] rm;
		rm = tmp;
	}

	//normal findSet with path compression
	int findSet(int j)
	{
		if(parent[j]==j)return j;
		//path compression heuristic
		parent[j] = findSet(parent[j]);
		return parent[j];
	}

	//check if two elements are in the same set
	bool isSameSet(int i, int j)
	{
		return findSet(i)==findSet(j);
	}

	//unions two sets
	void unionSet(int i, int j)
	{
		if(!isSameSet(i,j)){
			int ip = findSet(i);
			int jp = findSet(j);

			//remove from parent list
			allParents.erase(ip);
			allParents.erase(jp);

			//rank heuristic
			if(rank[ip]>rank[jp]){
				parent[jp]=ip;
				size[ip]+=size[jp];
				allParents.insert(ip);
			}
			else{
				parent[ip]=jp;
				size[jp]+=size[ip];
				if(rank[ip]==rank[jp])
					rank[jp]++;
				allParents.insert(jp);
			}
			totalDisjointSets--;
		}
	}

	//returns total disjoint sets in the forest
	int numDisjointSets()
	{
		return totalDisjointSets;
	}

	//returns the size of a node's set
	int sizeOfSet(int i)
	{
		return size[findSet(i)];
	}

	//marks node i for disunion
	void setDisunion(int i)
	{
		if(i<0||i>=N){
			printf("WRONG INDEX\n");
			return;
		}
		rm[i]=1;
	}

	//disunions the marked sets
	void disunionSet() //disunions all the sets that have rm[i]=true
	{	
		//compress path for all nodes
		for(int i=0;i<N;i++)
			findSet(i);
		

		for(int i=0;i<N;i++){
			int p = findSet(i);
			if(rm[p]&&!rm[i]){ 
			//if i's parent is being removed but not i itself, set i as the new parent and make p the child
				parent[p]=i;
				parent[i]=i;
				
			//update the size and allParents
				size[i]=size[p]; 
				allParents.erase(p);
				allParents.insert(i);
			}
		}
		
		
		//compress again
		for(int i=0;i<N;i++) 
			findSet(i);
		

		//as the parent are changed before, now there should be no problem removing element
		for(int i=0;i<N;i++)
			if(rm[i]){
				parent[i] = i;
				rm[i]=0;
				allParents.insert(i);
			}

		//now update rank, parent
		rank.clear();
		rank.assign(N,0);

		for(int i=0;i<N;i++){
			int p = findSet(i);
			if(i!=p)
				rank[p]=1; //all sets are atmost of height 2, so we can blindly set rank = 1 
		}
	}

	void clear()
	{
		N=0;
		totalDisjointSets=0;
		allParents.clear();
		parent.clear();
		rank.clear();
		size.clear();
	}


	void printAllSets()
	{
		for(auto it = allParents.begin();it!=allParents.end();it++){
			int curP = *it;
			cout<<curP<<": ";
			for(int i=0;i<N;i++){
				if(findSet(i)==curP)
					cout<<" "<<i;
			}
			cout<<endl;
		}
	}
};


int main()
{
	UnionFind u(10);

	u.unionSet(1,2);
	u.unionSet(2,3);
	u.unionSet(3,4);
	u.printAllSets();

	cout<<endl;
	cout<<endl;

	u.setDisunion(1);
	u.setDisunion(2);
	u.setDisunion(5);
	u.disunionSet();
	u.printAllSets();
}