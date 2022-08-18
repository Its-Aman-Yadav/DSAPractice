#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int fib(int n){
	if(n<2) return n;
	cout<<"calculating fib: "<<n<<"\n";
	return fib(n-1)+fib(n-2);
}


// 0, 1, 1, 2, 3, 5, 8
//store already calculated values
unordered_map<int,int>mp;
int optimised_fib_using_map(int n){
	if(n<=1) return n;
	if(mp.find(n)!=mp.end()) return mp[n];
	cout<<"optimised using map calculating fib: "<<n<<"\n";
	mp[n] = optimised_fib_using_map(n-1)+optimised_fib_using_map(n-2);
	return mp[n];
}

vector<int>A(1e6,-1);
int optimised_fib_using_array(int n){
	if(n<2) return n;
	//A[i]==-1 means it hasn't been calculated
	if(A[n]!=-1) return A[n];
	cout<<"oprimsied using array calculating fib: "<<n<<"\n";
	A[n]= optimised_fib_using_array(n-1) + optimised_fib_using_array(n-2);
	return A[n];
 
}
int main() {
	cout<<fib(10)<<"\n\n\n\n";
	cout<<optimised_fib_using_map(10)<<"\n\n\n\n";
	cout<<optimised_fib_using_array(10)<<"\n\n\n\n";
	return 0;
}
