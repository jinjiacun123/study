#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int index = 0;
        int len = citations.size();
        int half = len/2;
        int checkValue;
        int i = 0;
        checkValue = citations[i];
        int culculationNum;
        int selectIndex = i;

        while(true){
            if(selectIndex >= len)break;

            culculationNum = 0;
            checkValue = citations[selectIndex];
            //cout<<"selectIndex:"<<selectIndex<<endl;
            //cout<<"checkValue:"<<checkValue<<endl;
            for(i = 0; i < len ; i++){
                //if(i == selectIndex)continue;

                if(citations[i] >= checkValue)
                    culculationNum++;

            }
            //cout<<"culculationNum:"<<culculationNum<<endl;
            if(culculationNum >= half){
                index = checkValue;
                //cout<<"index:"<<index<<endl;
                break;
            }else{
                selectIndex++;
            }
        }

        return index;
    }
};

void test1(Solution s, vector<int> a){
    a.push_back(3);
    a.push_back(0);
    a.push_back(6);
    a.push_back(1);
    a.push_back(5);

    int value= s.hIndex(a);
    cout<<value;
    cout<<endl;
}

void test2(Solution s, vector<int> a){
    a.push_back(1);
    a.push_back(3);
    a.push_back(1);

    int value = s.hIndex(a);
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

