
class Solution {
  public:
    int isPossible(int N, int arr[]) {
        // code here
        string s ="";
        int sm =0;
        for(int i=0; i <N ; i++){
            s+= to_string(arr[i]);
        }
        
        int len = s.length();
        for(int i =0 ; i < len ; i++){
            sm+= s[i] - '0';
        }
        return sm%3==0;
    }
};