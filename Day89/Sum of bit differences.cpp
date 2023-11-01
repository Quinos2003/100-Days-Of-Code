class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    long long ans = 0;
	    for(int bit=0;bit<32;bit++) {
	        long long countOne = 0, countZer = 0;
	        for(int i=0;i<n;i++) {
	            if(arr[i]%2) countOne++;
	            else countZer++;
	            arr[i] = arr[i]/2;
	        }
	        ans += countOne*countZer*2;
	    }
	    return ans;
	}
};