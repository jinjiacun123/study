#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int curLen = nums.size();
        int i,k;

        for(i = 0; i < curLen; i++){
            if(nums[i] == val){
                //if not last move and end curLen --
                if(i != curLen -1){
                    for(k = i; k < curLen -1; k++){
                        nums[k] = nums[k+1];
                    }
                }

                //is end curLen --

                curLen --;
                i--;
            }
        }


        return curLen;
    }
};

void
test1(vector<int> a,
      Solution s)
{
    a.push_back(3);a.push_back(2);
    a.push_back(2);a.push_back(3);
    int len = s.removeElement(a, 3);
    cout<<"len:"<<len<<endl;
    for(int i = 0; i < len; i++){
        cout << a[i] << " ";
    }
    cout<<endl;
}

void
test2(vector<int> a,
      Solution s){
    a.push_back(0);a.push_back(1);
    a.push_back(2);a.push_back(2);
    a.push_back(3);a.push_back(0);
    a.push_back(4);a.push_back(2);
    int len = s.removeElement(a, 2);
    cout<<"len:"<<len<<endl;
    for(int i = 0; i < len; i++){
        cout << a[i] << " ";
    }
    cout<<endl;
}

int
main(){
    vector<int> a;
    Solution s;
    int i;

    test1(a, s);
    test2(a, s);
}
