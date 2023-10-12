// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int> A) {
//         for (int i = 1; i + 1 < A.size(); ++i) if (A[i] > A[i + 1]) return i;
//         return 0;
//     }
// };
class Solution {
public:
    int peakIndexInMountainArray(vector<int> A) {
        int l=0, r = A.size()-1, mid;
        while(l<r){
            mid= l+ (r-l)/2;

            if(A[mid]<A[mid+1]) l= mid +1;

            else r = mid;
        }
        return l;
    }
};