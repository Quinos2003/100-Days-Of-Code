class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();

        // if(n<=2)
        // return n;
        // int p = 0;

        // for(int i =2 ; i< n;i++){
        //     if(nums[i]!=nums[p]){
        //         nums[p+2] = nums[i];
        //         p++;
        //     }
        // }
        // return p+2;

        int x = nums[0];
        int count = 0, rep = 0;
        for (int i = 0; i < n - 1; i++)
        {
            x = nums[i];
            if (x == nums[i + 1])
            {
                rep++;
                if (rep >= 2)
                {
                    continue;
                }
                count++;
                nums[count] = nums[i + 1];
                // nums[i];
            }
            else
            {
                rep = 0;
                count++;
                nums[count] = nums[i + 1];
            }
        }
        return count + 1;
    }
};