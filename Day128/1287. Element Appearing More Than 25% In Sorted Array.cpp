// class Solution {
// public:
// 	int findSpecialInteger(vector<int>& arr) {
// 		unordered_map<int, int> m;
// 		for(int i = 0; i < arr.size(); i++){
// 			m[arr[i]]++;
// 		}
// 		for(auto i : m){
// 			if(i.second > arr.size() / 4){
// 				return i.first;
// 			}
// 		}
// 		return arr[0];
// 	}
// };
// class Solution {
// public:
// 	int findSpecialInteger(vector<int>& arr) {
// 		int c = 0;
// 		for(int i = 1; i < arr.size(); i++){
// 			if(arr[i] == arr[i - 1]){
// 				c++;
// 			}
// 			else{
// 				c = 1;
// 			}
// 			if(c > arr.size() / 4){
// 				return arr[i];
// 			}
// 		}
// 		return arr[0];
// 	}
// };
class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {
		for(int i = 0; i <= (arr.size() * 3) / 4; i++){
			if(arr[i] == arr[i + arr.size() / 4]){
				return arr[i];
			}
		}
		return arr[0];
	}
};