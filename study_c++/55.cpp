#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;

class Solution {
public:
    /***
    * 0. setting current position is zero
    * a. from current position,check is zero step and not last postion ,this condition will die;
    *    if not, use max step ,if or not reach last
    * b. if may reach ,and jump
    * c. not b. and jump 1 step to position two, and then go a.
    *
    *
    */
    bool canJump(vector<int>& nums) {
        bool status = true;
        int curPosition = 0;
        int len = nums.size();
        int tryPosition, tryStep;

        while(true){
            //check current position is or not 0 step and not last element
            //if true, will die
            if(nums[curPosition] == 0
            && curPosition != len -1)
                return false;

            //current position max step is may reach to end of array
            if(curPosition + nums[curPosition] == len -1){
                //jump end of array
                return true;
            }

            //jump from one step to current position max step to try
            tryPosition  = curPosition;

            tryStep = 1;
            curPosition += tryStep;
        }


        return status;
    }
};

void test1(Solution s, vector<int> a){
    a.push_back(2);a.push_back(3);a.push_back(1);
    a.push_back(1);a.push_back(4);

    bool status= s.canJump(a);
    cout<<status;
    cout<<endl;
}

void test2(Solution s, vector<int> a){
    a.push_back(3);a.push_back(2);
    a.push_back(1);a.push_back(0);a.push_back(4);

    bool status = s.canJump(a);
    cout<<status;
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

