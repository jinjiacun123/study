
#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;

class Solution {
private:
        //dictionary
        map<string, int> dictionary{
            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000}
        };

        map<string, int> specialDic{
            {"IV", 4},
            {"IX", 9},
            {"XL", 40},
            {"XC", 90},
            {"CD", 400},
            {"CM", 900}
        };

public:
    int romanToInt(string s) {
        int value = 0;
        int strLen = s.size();
        string key;

        //deal special
        /*if((value = specialDic[s]) > 0)
            return value;
        */

        for(int i = 0; i < strLen; i++){
            //check is special
            if((s[i] == 'I'
            ||  s[i] == 'X'
            ||  s[i] == 'C') &&(
                i < strLen -1
            )
            ){
                string specialKey;
                specialKey.push_back(s[i]);
                specialKey.push_back(s[i+1]);
                if(specialDic[specialKey] > 0){
                    value += specialDic[specialKey];
                    i++;
                    continue;
                }
            }

            key.assign(1, s[i]);
            value += dictionary[key];
        }

        return value;
    }
};

void test1(Solution s, vector<string> a){
    a.push_back("III");
    a.push_back("IV");
    a.push_back("IX");
    a.push_back("LVIII");
    a.push_back("MCMXCIV");

    int value = 0;
    int len = a.size();

    for(int i = 0; i < len; i++){
        value= s.romanToInt(a[i]);
        cout << value << "\n";
        cout<<"-------------"<<endl;
    }
    cout<<endl;
}


int
main(){
    Solution s;
    vector<string> a;

    test1(s, a);

    return 0;
}


