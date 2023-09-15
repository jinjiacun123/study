#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> diffNum;
        int len = nums.size();
        int i,j, elem;

        for(i = 0; i < len; i++){
            elem = nums[i];
            //cout<< elem << ","<< diffNum[elem] << endl;
            if(diffNum[elem] == 0){
                diffNum[elem] = 1;
            }else{//greate one time and over it
                for(j = i; j < len - 1; j++){
                    nums[j] = nums[j+1];
                }
                len --;i--;
            }
        }

        return len;
    }
};

void test1(Solution s, vector<int> a){
    a.push_back(1);
    a.push_back(1);
    a.push_back(2);

    int len = s.removeDuplicates(a);

    for(int i = 0; i < len; i++){
        cout << a[i] << " ";
    }
    cout<<endl;
}

void test2(Solution s, vector<int> a){
    //0,0,1,1,1,2,2,3,3,4
    a.push_back(0);a.push_back(0);
    a.push_back(1);a.push_back(1);a.push_back(1);
    a.push_back(2);a.push_back(2);
    a.push_back(3);a.push_back(3);
    a.push_back(4);

    int len = s.removeDuplicates(a);

    for(int i = 0; i < len; i++){
        cout << a[i] << " ";
    }
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
