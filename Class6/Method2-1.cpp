#include<bits/stdc++.h>
using namespace std;

int main() {
    int n=3,m=4;
  
  
  //declare a vector of (vectors of int) of size n and fill it with vector of size m directly;
    vector<vector<int>>A(n, vector<int>(m));
    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           cin>>A[i][j];
       }
    }
    
    cout<<"output ArrayColumn Wise: "<<"\n";
    
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
    std::cout << "Hello World!\n";
}
