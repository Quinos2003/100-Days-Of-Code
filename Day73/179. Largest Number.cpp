// class Solution {
// public:
//     string largestNumber(vector<int>& nums) {
//         vector<string> vs;
//         string s="";

//         for(int &num:nums)  vs.push_back(to_string(num));

//         sort(vs.begin(),vs.end(),[](string a,string b){return a+b>b+a;});

//         if(vs[0][0]=='0') return "0"; 

//         for(string & ss:vs)  s+=ss;

//         return s;
//     }
// };

bool compare(string a,string b){
    return a+b > b+a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
	
        vector<string> container;
		
        for(int i : nums)  container.push_back(to_string(i));
        
        sort(container.begin(),container.end(),compare);
        
        string result;
        
        for(int i=0;i<container.size();i++)  result+=container[i];
        
        return result[0]=='0'? "0" : result;
    }
};