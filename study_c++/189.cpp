#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int lastElem;
        int len = nums.size();

        for(int i = 1; i <= k; i++){
            lastElem = nums[len - 1];
            for(int j = len -1; j > 0; j--)
                nums[j] = nums[j-1];
            nums[0] = lastElem;
        }
    }
};


void test1(Solution s, vector<int> a){
    a.push_back(1);a.push_back(2);a.push_back(3);
    a.push_back(4);a.push_back(5);a.push_back(6);
    a.push_back(7);

    s.rotate(a, 3);
    int len = a.size();
    for(int i = 0; i < len; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void test2(Solution s, vector<int> a){
    a.push_back(-1);a.push_back(-100);
    a.push_back(3);a.push_back(99);

    s.rotate(a, 2);
    int len = a.size();
    for(int i = 0; i < len; i++)
        cout<<a[i]<<" ";
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
