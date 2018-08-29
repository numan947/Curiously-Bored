#include<bits/stdc++.h>
using namespace std;



class UnionFind{
private:
	vector<int>parents;
	unordered_set<int>parentList;
	vector<int>ranks;
	vector<int>sizes;
	int totalDisjointSets;
	int N;
	bool *rm;
public:

	UnionFind(){
		N=0;
		totalDisjointSets=0;
		parentList.clear();
		parents.clear();
		ranks.clear();
		sizes.clear();
	}

	UnionFind(int N) //N elements Union Find
	{
		ranks.assign(N,0);
		parents.assign(N,0);

		sizes.assign(N,1);
		totalDisjointSets = N;
		this->N = N;
		for(int i=0;i<N;i++){
			parents[i]=i;
			parentList.insert(i);
		}

		//for disunion
		rm = new bool[N];
		for(int i=0;i<N;i++)
			rm[i]=0;
	}

	void incrementSet()
	{
		ranks.push_back(0);
		sizes.push_back(1);
		totalDisjointSets++;
		parents.push_back(N);
		parents[N]=N;
		parentList.insert(N);
		N++;


		bool* tmp = new bool[N];
		for(int i=0;i<N-1;i++)
			tmp[i] = rm[i];
		tmp[N-1] = 0;

		delete[] rm;
		rm = tmp;
	}

	int findSet(int j)
	{
		if(parents[j]==j)return j;
		//path compression heuristic
		parents[j] = findSet(parents[j]);
		return parents[j];
	}

	bool isSameSet(int i, int j)
	{
		return findSet(i)==findSet(j);
	}

	void unionSet(int i, int j)
	{
		if(!isSameSet(i,j)){
			int ip = findSet(i);
			int jp = findSet(j);

			parentList.erase(ip);
			parentList.erase(jp);

			//rank heuristic
			if(ranks[ip]>ranks[jp]){
				parents[jp]=ip;
				sizes[ip]+=sizes[jp];
				parentList.insert(ip);
			}
			else{
				parents[ip]=jp;
				sizes[jp]+=sizes[ip];
				if(ranks[ip]==ranks[jp])
					ranks[jp]++;
				parentList.insert(jp);
			}
			totalDisjointSets--;
		}
	}

	int numDisjointSets()
	{
		return totalDisjointSets;
	}

	int sizeOfSet(int i)
	{
		return sizes[findSet(i)];
	}

	void setDisunion(int i)
	{
		if(i<0||i>=N){
			printf("WRONG INDEX\n");
			return;
		}
		rm[i]=1;
	}

	void disunionSet() //disunions all the sets that have rm[i]=true
	{	
		//compress path for all nodes
		for(int i=0;i<N;i++)
			findSet(i);
		for(int i=0;i<N;i++){
			int p = findSet(i);
			if(rm[p]&&!rm[i]){ //if i's parent is being removed but not i itself, set i as the new parent and make p the child
				parents[p]=i;
				parents[i]=i;
				sizes[i]=sizes[p]; //update the size and parentList
				parentList.erase(p);
				parentList.insert(i);
			}
		}

		for(int i=0;i<N;i++) //compress again
			findSet(i);

		for(int i=0;i<N;i++)
			if(rm[i]){ //as the parents are changed before, now there should be no problem removing element
				parents[i] = i;
				rm[i]=0;
				parentList.insert(i);
			}

		//now update ranks, parents
		ranks.clear();
		ranks.assign(N,0);

		for(int i=0;i<N;i++){
			int p = findSet(i);
			if(i!=p)
				ranks[p]=1;
		}
	}

	void clear()
	{
		N=0;
		totalDisjointSets=0;
		parentList.clear();
		parents.clear();
		ranks.clear();
		sizes.clear();
	}


	void printAllSet()
	{
		FORall(it,parentList){
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