#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solution(int N, vector<int>& A, vector<int>& B){
    vector<vector<int>>graph(N);
    vector<int>degree(N,0);
    for(int i=0; i<A.size(); i++){
        graph[A[i]].push_back(B[i]);
        graph[B[i]].push_back(A[i]);
        degree[A[i]]++;
        degree[B[i]]++;
    }

    int res = 0;
    while(true){
        int flag = 2;
        vector<int>tmp = degree;
        for(int i=0; i<N; i++){
            if(degree[i] == 0 && res == 0){
                flag = 0;
                tmp[i]--;
            }
            if(degree[i] == 1){
                flag = 1;
                tmp[i]--;
                for(auto v: graph[i]){
                    tmp[v]--;
                }
            }
        }
 
        if(flag== 2)break;
        degree= tmp;
        res++;
    }
    return res;
}

int main(){
    int N = 7;
    vector<int>A = {0,1,2,1,4,4};
    vector<int>B = {1,2,0,4,5,6};
    int res = solution(N, A, B);
    std::cout <<res;
    return 0;
}
