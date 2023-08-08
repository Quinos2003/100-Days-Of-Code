class Solution {
public:
    int maxArea(vector<int>& height) {
        int h = height.size();

    // int a,z;
    // for area to be max breath/ length should be minimum
    // int max=0;
    // int s; // smaller of 2 index
    // int diff;
    // for(int i=0;i<h-1;i++){
    //     for(int j=i+1;j<h;j++){
    //         diff = j-i;
    //         s= giveSmall(height[i],height[j]);
    //         if((diff*s)>max)
    //         max=(diff*s);
    //     }
    // }
    // return max;

    // // APPROACH 2
    // float div;
    // int diffarr[h];
    // int smallarr[h];
    // int divArr[h];
    // for(int i=0;i<h;i++){
    // }

    int p1=0;
    // int s;
    int max=0;
    int p2=h-1;
    while(p1<p2){
        // s=giveSmall(height[p1],height[p2]);
        if(height[p1]<height[p2]){
            int temp= height[p1]*(p2-p1);
            if(max<temp){
                max=temp;
            }
            p1++;
        }
        else{
            int temp= height[p2]*(p2-p1);
            if(max<temp){
                max=temp;
            }
            p2--;
        } 
    }
    return max;
        
    }
};