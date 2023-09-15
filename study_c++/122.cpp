#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int middle = 0;
        int len = prices.size();
        int i,j;
        int value;
        int old;
        stack<int> rest;

        for(i=0; i < len - 1; i++){
            //cout<<"--------------------"<<endl;
            //cout<<"i:"<<i<<endl;
            old = i;
            rest.push(i + 1);
            while(rest.size()>0){
                middle = 0;
                for(j = rest.top(); j < len; j++){
                    rest.pop();
                    //cout<<"i:"<<i<<"->j:"<<j
                    //    <<" value:"<<prices[i]<<" value:"<<prices[j]<<endl;
                    if(prices[j] > prices[i]
                    && (value = prices[j] - prices[i]) > 0){
                      //  cout<<"i:"<<i<<",j:"<<j<<","<<prices[i]<<","<<prices[j]<<endl;
                      //  cout<<"rest.size:"<<rest.size()<<endl;
                        middle += value;
                        //i reposition to after j
                        if(j < len -1){
                        //    cout<<"ttt"<<endl;
                            i = j+1;j++;
                            rest.push(i);
                           // if(i == len -1){if(!rest.empty())rest.pop();break;}
                          //  cout<<i<<"-,-"<<j<<endl;
                        }
                    }
                    if(rest.empty())break;
                }
                if(max < middle) max = middle;
                i = old;
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
    a.push_back(1);a.push_back(2);
    a.push_back(3);a.push_back(4);a.push_back(5);

    int value = s.maxProfit(a);
    cout<<value;
    cout<<endl;
}

void test3(Solution s, vector<int> a){
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
    test3(s, a);

    return 0;
}

