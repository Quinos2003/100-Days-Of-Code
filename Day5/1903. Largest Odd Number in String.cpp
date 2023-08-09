// class Solution {
// public:
//     string largestOddNumber(string num) {
//         int last=-1;
//         for(int i=0;i<num.length();i++)
//         {
//             if(num[i]%2!=0)
//             {
//                 last=i;
//             }
//         }
//         if(last!=-1)
//         {
//             return num.substr(0,last+1);
//         }
//         else return "";
//     }
// };

class Solution {
public:
    string largestOddNumber(string num) {
        int end=-1;
        for(int i=0;i<num.length();i++)
        {
            if(num[i]%2!=0)
            {
                end=i;
            }
        }
        if(end!=-1)
        {
            return num.substr(0,end+1);
        }
        else return "";
    }
};