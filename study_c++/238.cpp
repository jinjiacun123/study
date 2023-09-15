#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int len = nums.size();
        int curIndex = 0;
        int multi = 1;

        while(true){
            if(curIndex ==  len)
                break;

            multi = 1;
            for(int i = 0; i < len; i++){
                if(i == curIndex)continue;
                multi *= nums[i];
            }

            result.push_back(multi);
            curIndex++;
        }

        return result;
    }
};

void test1(Solution s, vector<int> a){
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);

    vector<int> value= s.productExceptSelf(a);
    int len = value.size();
    for(int i=0; i < len; i++)
        cout<< value[i] << " ";
    cout<<endl;
}

void test2(Solution s, vector<int> a){
    a.push_back(-1);
    a.push_back(1);
    a.push_back(0);
    a.push_back(-3);
    a.push_back(3);

    vector<int> value = s.productExceptSelf(a);
    int len = value.size();
    for(int i=0; i < len; i++)
        cout<< value[i] << " ";
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

