#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int lastJump = 0;

        int curPosition = 0;
        int len = nums.size();
        int tryPosition, tryStep;

        while(true){
            //check current position is or not 0 step and not last element
            //if true, will die
            if(nums[curPosition] == 0
            && curPosition != len -1)
                return 0;

            //current position max step is may reach to end of array
            if(curPosition + nums[curPosition] == len -1){
                lastJump += 1;
                //jump end of array
                break;
            }

            //jump from one step to current position max step to try
            tryPosition  = curPosition;

            tryStep = 1;
            lastJump = 1;
            curPosition += tryStep;
        }

        return lastJump;
    }
};

void test1(Solution s, vector<int> a){
    a.push_back(2);a.push_back(3);a.push_back(1);
    a.push_back(1);a.push_back(4);

    int value= s.jump(a);
    cout<<value;
    cout<<endl;
}

void test2(Solution s, vector<int> a){
    a.push_back(2);a.push_back(3);
    a.push_back(0);a.push_back(1);a.push_back(4);

    int value = s.jump(a);
    cout<<value;
    cout<<endl;
}


int
main(){
    Solution s;
    vector<int> a;

    test1(s, a);
    test2(s, a);

    return 0;
}

