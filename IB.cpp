
#include <bits/stdc++.h>
using namespace std;

int maxArr(vector<int> &A) {
    int mxElem = -100000;
    int mxIdx;
    int mnElem =  100000;
    int mnIdx;
    
    vector<pair<int,int>>vv;
    
    for(int i=0;i<A.size();i++){
        vv.push_back(make_pair(A[i],i));
    }
    
    sort(vv.begin(),vv.end());
    
    int i=0,j=vv.size()-1;
    
    int mx = -1000000;

    while(i<=j){
        int psum = abs(vv[i].first-vv[j].first) + abs(vv[i].second+1 - (vv[j].second+1));
        if(psum>mx){
            mx = max(mx,psum);
           cout<<vv[i].first<<" "<<vv[i].second<<endl;
           cout<<vv[j].first<<" "<<vv[j].second<<endl;
        }
        if(abs(vv[i].first) > abs(vv[j].first))
            j--;
        else
            i++;
    }
    
    
    return mx;
    
}



int maxArr2(vector<int> &A) {
    int mxElem = -100000;
    int mxIdx;
    int mnElem =  100000;
    int mnIdx;
    
    vector<pair<int,int>>vv;
    
    for(int i=0;i<A.size();i++){
        vv.push_back(make_pair(A[i],i));
    }
    
    sort(vv.begin(),vv.end());
    
    int i=0,j=vv.size()-1;
    
    int mx = -1000000;

    for(int i = 0;i<A.size();i++){
        for(int j = 0;j<A.size();j++){
            int tmp = abs(A[i]-A[j])+abs(i-j);
            if(tmp>mx){
                cout<<i<<" "<<j<<endl;
                cout<<A[i]<<" "<<A[j]<<endl;
                mx = tmp;
            }
        }
    }
    
    
    return mx;
    
}



vector<int> maxset(vector<int> &A) {
    vector<pair<vector<int>,pair<int,long long> > >vv;
    long long mxSumSofar = A[0];
    int curSt = 0;
    vector<int>tmp;
    tmp.push_back(A[0]);
    
    for(int i = 1; i<A.size();i++){
        cout<<A[i]<<endl;
        if(mxSumSofar+A[i] >= mxSumSofar){
            if(mxSumSofar+A[i]<A[i]){ //making new array from A[i] is better
                vv.push_back(make_pair(tmp,make_pair(curSt,mxSumSofar)));
                mxSumSofar = A[i];
                curSt = i;
                tmp.clear();
                tmp.push_back(A[i]);
            }
            else{
                mxSumSofar+=A[i];
                tmp.push_back(A[i]);
            }
        }
        else{
            vv.push_back(make_pair(tmp,make_pair(curSt,mxSumSofar)));
            mxSumSofar = A[i];
            curSt = i;
            tmp.clear();
            tmp.push_back(A[i]);
        }
    }
    vv.push_back(make_pair(tmp,make_pair(curSt,mxSumSofar)));



    long long mxSum = -1000000000000LL;
    int mxFirst = 0;

    for(int i = 0; i<vv.size(); i++){
        if(vv[i].second.second>mxSum){
            mxSum = vv[i].second.second;
            tmp = vv[i].first;
            mxFirst = vv[i].second.first;
        }
        else if(vv[i].second.second==mxSum){
            if(tmp.size()<vv[i].first.size()){
                tmp = vv[i].first;
                mxFirst = vv[i].second.first;
                mxSum = vv[i].second.second;
            }
            else if(tmp.size() == vv[i].first.size()){
                if(vv[i].second.first < mxFirst){
                    tmp = vv[i].first;
                    mxFirst = vv[i].second.first;
                    mxSum = vv[i].second.second;
                }
            }
        }
    }


    // for(int j = 0;j<vv.size();j++){
    //     for(int i=0;i<vv[j].first.size();i++)
    //         cout<<vv[j].first[i]<<" ";
    //     cout<<"--->"<<vv[j].second.second<<endl;
    // }

    if(mxSum<0)
        tmp.clear();

    // for(int i=0;i<tmp.size();i++)
    //     cout<<tmp[i]<<" ";
    // cout<<endl;

    return tmp;
}

vector<vector<int> > generateMatrix(int A) {
    vector<vector<int> >ret;
    
    for(int i=0;i<A;i++){
        vector <int> tmp;
        for(int j=0;j<A;j++)
            tmp.push_back(0);
        ret.push_back(tmp);
    }

    int curVal = 1;
    
    int limiter = 0;
    
    int i = 0, j = 0;
    
    while(limiter <= A-limiter-1){
        
        while(j<=A-limiter-1){
            ret[i][j] = curVal++;
            j++;
        }
        j--;
        i++;
        while(i<=A-limiter-1){
            ret[i][j] = curVal++;
            i++;
        }
        i--;
        j--;
        while(j>=limiter){
            ret[i][j] = curVal++;
            j--;
        }
        j++;
        i--;
        limiter++;
        while(i>=limiter){
            ret[i][j] = curVal++;
            i--;
        }
        i++;
        j++;
    }
    
    for(int i=0;i<A;i++){
        for(int j=0;j<A;j++)
            cout<<ret[i][j]<<" ";
        cout<<endl;
    }


    return ret;
}

vector<vector<int> > pascal_solve(int A) {
    vector<vector<int> >vct;

    vector<int>vv;
    vv.push_back(1);
    vct.push_back(vv);


    for(int i = 1; i<A;i++){
        vector<int>tmp;
        for(int j=0;j<=i;j++){
            if(j==0){
                tmp.push_back(vct[i-1][j]);
            }
            else if(j==i){
                tmp.push_back(vct[i-1][vct[i-1].size()-1]);
            }
            else{
                tmp.push_back(vct[i-1][j]+vct[i-1][j-1]);
            }
        }
        vct.push_back(tmp);
    }

    for(int i=0;i<A;i++){
        for(int j=0;j<vct[i].size();j++)
            cout<<vct[i][j]<<" ";
        cout<<endl;
    }

    return vct;
}



int noble_integer(vector<int> &A) {
    sort(A.begin(),A.end());
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<" ";
    cout<<endl;
    for(int i = A.size()-1;i>=0;i--){
        if(A[i] == A.size()-i-1 && i+1<A.size() && A[i]!=A[i+1]){
            //cout<<i<<" "<<A[i]<<endl;
            return true;
        }
        else if(i==A.size()-1 && A[i] == A.size()-i-1)
            return true;
    }
    return false;

}

int triplets(vector<string>A){
    vector<double>AA;
    for(int i=0;i<A.size();i++){
        AA.push_back(stod(A[i]));
    }
    sort(AA.begin(), AA.end());

    int n = AA.size();
    for(int i=0;i<n-2;i++){
        double tmp = 0;
        tmp+=AA[i]+AA[i+1]+AA[i+2];
        cout<<tmp<<endl;
        if(tmp>1 && tmp<2)
            return true;

    }
    return false;
}

int main()
{
   vector<int>A = { -4, 7, 5, 3, 5, -4, 2, -1, -9, -8, -3, 0, 9, -7, -4, -10, -4, 2, 6, 1, -2, -3, -1, -8, 0, -8, -7, -3, 5, -1, -8, -8, 8, -1, -3, 3, 6, 1, -8, -1, 3, -9, 9, -6, 7, 8, -6, 5, 0, 3, -4, 1, -10, 6, 3, -8, 0, 6, -9, -5, -5, -6, -3, 6, -5, -4, -1, 3, 7, -6, 5, -8, -5, 4, -3, 4, -6, -7, 0, -3, -2, 6, 8, -2, -6, -7, 1, 4, 9, 2, -10, 6, -2, 9, 2, -4, -4, 4, 9, 5, 0, 4, 8, -3, -9, 7, -8, 7, 2, 2, 6, -9, -10, -4, -9, -5, -1, -6, 9, -10, -1, 1, 7, 7, 1, -9, 5, -1, -3, -3, 6, 7, 3, -4, -5, -4, -7, 9, -6, -2, 1, 2, -1, -7, 9, 0, -2, -2, 5, -10, -1, 6, -7, 8, -5, -4, 1, -9, 5, 9, -2, -6, -2, -9, 0, 3, -10, 4, -6, -6, 4, -3, 6, -7, 1, -3, -5, 9, 6, 2, 1, 7, -2, 5  };
   vector<int>B = {-1, -2, 0, 0, 0, -3 };
    // int A = 5;
   //cout<<noble_integer(A)<<endl;


   vector<string>BB = {"0.366507", "0.234601", "2.126313", "1.372403", "2.022170", "0.308558", "2.120754", "1.561462" };
   cout<<triplets(BB)<<endl;

}