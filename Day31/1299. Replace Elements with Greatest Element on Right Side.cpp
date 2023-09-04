class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int temp,maxx=-1;
        for(int i=arr.size()-1;i>=0;i--){
        temp=arr[i];
        arr[i]=maxx;
        maxx=max(maxx,temp);
        }
        return arr;
    }
};