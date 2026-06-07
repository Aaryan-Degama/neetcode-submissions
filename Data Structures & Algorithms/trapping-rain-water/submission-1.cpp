#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int lar{height[0]},add{height[0]},count{1},Area{0};
        int ptr1{0};
        for(int i{1}; i<height.size(); i++){
            if(height[i]>=lar){
                Area+= (count*lar)-add;
                ptr1 = i;
                lar = height[i];
                add = 0;
                count = 0;
            }else{
                count++;
                add+=height[i];
            }
        }
        int x = ptr1;
        lar = *(height.end()-1);
        add =lar,count=1,ptr1=height.size()-1;

        for (int i = height.size() - 2; i >= max(0, x); i--){
            if(height[i]>=lar){
                Area+= (count*lar)-add;
                ptr1 = i;
                lar = height[i];
                add = 0;
                count = 0;
            }else{
                count++;
                add+=height[i];
            }
        }
        return Area;

    }

};