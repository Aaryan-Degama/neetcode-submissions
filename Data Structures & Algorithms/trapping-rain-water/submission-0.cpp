
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int lar{0},count{0};
        int x{};
        int add{0};
        int Area{0};
        for(int i{0}; i<height.size(); i++){
            if( lar <= height[i]){
                while(!s.empty()){
                    add += s.top();
                    s.pop();
                    count++;
                }
                
                Area += (count*lar)-add;
                lar = height[i];
                add = 0;
                count = 0;
            }
            s.push(height[i]);
        }

        vector<int> A;
        
        while (!s.empty()) {
            A.push_back(s.top());
            s.pop();
        }

        
        lar = 0;count=0;
        add=0;
        for(int i{0}; i<A.size(); i++){
            if( lar <= A[i]){
                while(!s.empty()){
                    add += s.top();s.pop();
                    count++;
                }

                Area += (count*lar)-add;
                lar = A[i];
                add = 0;
                count = 0;
            }
            s.push(A[i]);
        }
        
        return Area;
    }

};