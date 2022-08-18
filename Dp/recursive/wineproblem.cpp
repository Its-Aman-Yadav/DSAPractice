/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/tutorial/
[2,3,5,1,4] => y year later price will be pi*y
*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



/*
y => sell min of (left,right) first
 sell min(left, right) first 2 + 2*3 + 3*4 + 4*1 + 5*5 = 2 + 6 + 12+4 +25 = 49
  greedy geive the wrong answer
  
  Time Complexity : O(n)
  Space Complexity: O(1)
*/
int greedy(vector<int>&P){
	int left =0, right = P.size()-1;
	int year=1;
	int ans=0;
	while(left<=right){
		if(P[left]<P[right]){
			ans+=year*P[left];
			left++;
		}
		else{
			ans+=year*P[right];
			right--;
		}
		year++;
	}
	return ans;
}


/*actual answer
  p1, p5, p4, p2, p3
  1* 2 + 2*4 + 3*1 + 4*3 + 5*5 = 2 + 8+3 + 12 + 25 = 50
  make all the combinations and pick best out of those
  Time Complexity : 2^n //at each place we have two choices
  Space Complexity : 2^n (recursion calls takes space
*/
int recur(vector<int>&P, int left, int right, int year){
	if(left>right) return 0;
	cout<<"normal calculating: "<<left<<" "<<right<<"\n"; // year = P.size()-(right-left)
	//pick left
	int ans_left= year*P[left]+ recur(P,left+1,right, year+1);
	
	//pick right
	int ans_right = year*P[right] + recur(P,left,right-1, year+1);
	
	return max(ans_left, ans_right);
}


/*
  store the calculated values in above approach to reuse them, (variable year is dependent upon left, right)

  Time Complexity: O(n^2) //each value is calculated only once
  Space Comlexity: O(n^2) // an array of n*n is created
*/

int dp[1000][1000];
int optimised_recur(vector<int>&P, int left, int right, int year){
	if(left>right) return 0;
	//if calculated before then return 
	if (dp[left][right]!=-1) return dp[left][right];
	
	cout<<"optimised calculating: "<<left<<" "<<right<<"\n"; // year = P.size()-(right-left)

	//pick left
	int ans_left= year*P[left]+ optimised_recur(P,left+1,right, year+1);
	
	//pick right
	int ans_right = year*P[right] + optimised_recur(P,left,right-1, year+1);
	
	dp[left][right] = max(ans_left, ans_right);
	return dp[left][right];
}

/*
  we can also use the map to store, but we have to make string out of left and right
  Time Complexity: O(n^2) //each value is calculated only once
  Space Comlexity: O(n^2) // map will take same space as the array, as we are calculating all the combinations.

*/
unordered_map<string, int>mp;
int optimised_recur_using_map(vector<int>&P, int left, int right, int year){
	if(left>right) return 0;
	//if calculated before then return 
	string s = to_string(left) +"|" + to_string(right);
	
	if (mp.find(s)!=mp.end()) return mp[s];
	
	cout<<"optimised using map calculating: "<<left<<" "<<right<<"\n"; // year = P.size()-(right-left)

	//pick left
	int ans_left= year*P[left]+ optimised_recur_using_map(P,left+1,right, year+1);
	
	//pick right
	int ans_right = year*P[right] + optimised_recur_using_map(P,left,right-1, year+1);
	
	mp[s] = max(ans_left, ans_right);
	return mp[s];
}

int main() {
	vector<int>P={2,3,5,1,4};
	cout<<"greedy: "<<greedy(P)<<"\n";
	cout<<"recur(making all combinations) : "<<recur(P,0, P.size()-1, 1);
	cout<<"\n \n \n";
	
	//fill the dp array with -1, so that we can identify that it is not calculated
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			dp[i][j]=-1;
		}
	}
	
	cout<<"optimised_recur(making all combinations) : "<<optimised_recur(P,0, P.size()-1, 1);
	cout<<"\n \n \n";
	
	cout<<"optimised_recur_using_map(making all combinations) : "<<optimised_recur_using_map(P,0, P.size()-1, 1);
	return 0;
}
