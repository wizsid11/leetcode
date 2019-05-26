class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        if(n==1)return 1;
        vector<int>t1(n,1);
        vector<int>t2(n,1);
        int ans = 1;
        for(int i=1; i<n; i++){
            if(i%2==0 && A[i]<A[i-1])t1[i]=t1[i-1]+1;
            else if(i%2==1 && A[i]>A[i-1])t1[i]=t1[i-1]+1;
            if(i%2==0 && A[i]>A[i-1])t2[i]=t2[i-1]+1;
            else if(i%2==1 && A[i]<A[i-1])t2[i]=t2[i-1]+1;
            ans = max(max(ans,t1[i]),t2[i]);
        }
        return ans;
    }
};