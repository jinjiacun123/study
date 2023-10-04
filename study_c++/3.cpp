#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int value = 0;
        
        return value;
    }
};

void test(Solution s, 
	  map<int, string> a,
	  map<int, int> result){
    int key = 0;
    a[key] = "abcabcbb";
    result[key] = 3;
    //--------------------------
    key++;
    a[key] = "bbbbb";
    result[key] = 1;
    //--------------------------
    key++;
    a[key] = "pwwkew";
    result[key] = 3;

    for(const auto& [key, v]:a){
	int value = s.lengthOfLongestSubstring(a[key]);
	if(value == result[key]){
		cout<<"key:"<<key<<" is success"<<endl;
	} else {
		cout<<"key:"<<key<<" is fail"<<endl;
	}
	cout<<"--------------------"<<endl;	
    }

    cout<<endl;
}


int
main(){
    Solution s;
    map<int, string> a;
    map<int, int> result;

    test(s, a, result);

    return 0;
}


