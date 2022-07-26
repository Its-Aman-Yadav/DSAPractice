//https://leetcode.com/submissions/detail/701155176/
//https://leetcode.com/submissions/detail/701152333/
class Solution {
public:
    //this function will return count of elements less than or equals to K
    int countSmallerOrEqual(vector<int>& A, int k){
        int ans=0;
        for(int a:A){
            if(a<=k) ans++;
        }
        return ans;
    }
    int findKthLargest(vector<int>& A, int k) {
        k= A.size()-k+1; //kth smallest
        //code smallest number such that number of elements in less than or equal to that number >= k
        int low= -10000, high= 10000;
        int ans=low;
        while(low<=high){
            int mid= (low+high)/2;
            int count= countSmallerOrEqual(A,mid);
            if(count<k){
                low= mid+1;
            }
            if(count>=k){
               ans = mid; 
               high = mid-1; 
            }
        }
        //actual answer is maxnumber <= an
        return ans;
    }
    //5th smalles
    //[3,2,1,5,6,4]  mid=3 => count 3
};
