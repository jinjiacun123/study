#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int half = len/2;
        map<int, int> m;
        int elem;

        //find time greate halfNum
        for(int i=0; i < len; i++){
            elem = nums[i];
            m[elem] += 1;
            if(m[elem] > half)
                break;
        }

        return elem;
    }
};

void test1(Solution s, vector<int> a){
    a.push_back(3);a.push_back(2);a.push_back(3);

    int value = s.majorityElement(a);
    cout<<value<<endl;
}

void test2(Solution s, vector<int> a){
    a.push_back(2);a.push_back(2);
    a.push_back(1);a.push_back(1);a.push_back(1);
    a.push_back(2);a.push_back(2);

    int value = s.majorityElement(a);
    cout<<value<<endl;
}

int
main(){
    Solution s;
    vector<int> a;

    test1(s, a);
    test2(s, a);

    return 0;
}

