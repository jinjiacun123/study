#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int len = prices.size();
        int i,j;
        int value;

        for(i = 0; i < len; i++){
            for(j= i; j< len; j++){
                if(prices[j] > prices[i]
                && (value = prices[j] - prices[i]) > max)
                    max = value;
            }
        }


        return max;
    }
};

void test1(Solution s, vector<int> a){
    a.push_back(7);a.push_back(1);a.push_back(5);
    a.push_back(3);a.push_back(6);a.push_back(4);

    int value = s.maxProfit(a);
    cout<<value;
    cout<<endl;
}

void test2(Solution s, vector<int> a){
    a.push_back(7);a.push_back(6);
    a.push_back(4);a.push_back(3);a.push_back(1);

    int value = s.maxProfit(a);
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

