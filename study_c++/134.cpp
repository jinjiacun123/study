#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;

class Solution {
public:
    /**
    *  a. find a station as start point, from current point althought path to next station
    *  b. has navigate gas when reach a station , start position is fault, realert a new station, and to a.
    *  c. find a path and reback to start station and gas is great or equal zero, start position is ok
    *  d. try every station is fail, have no path may reach.
    */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int value = -1;

        int len = gas.size();
        int tryTimes = 1;//max time is len
        int startStation = 0;
        int pathLen = 0;
        int curRestGas = 0;
        int curStation = startStation;
        int needConsumption = 0;

        curRestGas = gas[curStation];
        while(tryTimes < len + 1){

            //find next path and calculation consumption,
            //if gas of the rest great zero and cotinue to next station
            /*
            cout<<"start:"<<startStation<<endl;
            cout<<"path:"<<curStation<<endl;
            cout<<"curRestGas:"<<curRestGas<<endl;
            */
            needConsumption = cost[curStation];
            curRestGas = curRestGas - needConsumption;
            if(curRestGas < 0){
                /*
                cout<<"failt stattion:"<<startStation<<endl;
                cout<<"-----------------------------"<<endl;
                */
                startStation++;
                curStation = startStation;
                curRestGas = gas[curStation];
                tryTimes++;
                pathLen = 0;
                continue;
            }
            curStation++;
            curStation = curStation % len;
            curRestGas += gas[curStation];
            pathLen++;
            //cout<<"pathLen:"<<pathLen<<endl;
            if(curRestGas < 0
            && pathLen < len){//failt
                /*
                cout<<"failt stattion:"<<startStation<<endl;
                cout<<"-----------------------------"<<endl;
                */
                startStation++;
                curStation = startStation;
                tryTimes++;
                pathLen = 0;
                continue;
            }



            if(curRestGas >= 0
            && curStation == startStation
            && pathLen == len ){
                value = startStation;
                /*
                cout<<"curRestGat:"<<curRestGas
                    <<",value:"<<value
                    <<",pathLen:"<<pathLen
                    <<endl;
                */
                break;
            }

        }


        return value;
    }
};

void test1(Solution s, vector<int> a, vector<int> b){
    a.push_back(1);b.push_back(3);
    a.push_back(2);b.push_back(4);
    a.push_back(3);b.push_back(5);
    a.push_back(4);b.push_back(1);
    a.push_back(5);b.push_back(2);

    int value= s.canCompleteCircuit(a,b);
    cout<<value;
    cout<<endl;
}

void test2(Solution s, vector<int> a, vector<int> b){
    a.push_back(2);b.push_back(3);
    a.push_back(3);b.push_back(4);
    a.push_back(4);b.push_back(3);

    int value = s.canCompleteCircuit(a,b);
    cout<<value;
    cout<<endl;
}


int
main(){
    Solution s;
    vector<int> a;
    vector<int> b;

    test1(s, a, b);
    test2(s, a, b);

    return 0;
}

