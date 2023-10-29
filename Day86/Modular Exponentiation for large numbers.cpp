class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		  //  // Code here
		  //  if(n==0) return 1;
		  //  int ni =2;
		    
		    long long ans = 1;
		    
		    while(n>0){
		        if(n&1) ans =( ans*x)%M;
		        
		        x=(x*x)%M;
		        n>>=1;
		    }
		    return ans%M;
		    
		  //  if(n==1) return x%M;
		    
		  //  while(ni<n){
		  //      ni*=2;
		  //      x*=x;
		  //  }
		  //  return x%M;
		}
};