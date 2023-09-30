#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string reStr;
      int len = strs.size();
      int matchTimes = 0;
      int position = 0;
      char preCh = strs[0][0];
      int index = 0;
      int minStrLen = strs[0].size();

      //find min length of the strings array
      for(int i = 1; i < len; i++){
	if(strs[i].size() < minStrLen){
	  minStrLen = strs[i].size();
	}
      }

      while(true){
	if(position > minStrLen - 1)
	  break;
	
	index = 1;
	while(index < len
	&& position < minStrLen
	&& preCh == strs[index][position]){
	  matchTimes++;
	  index++;
	}


	//match
	if(matchTimes == len -1){
	  reStr.push_back(preCh);
	  matchTimes = 0;
	  position++;
	  if(position < minStrLen)
	    preCh = strs[0][position];
	  else
	    break;
	}else{
	  break;
	}
	
      }

      
      return reStr;
    }
};


void
test(Solution s,
     vector<string> a){
  a.push_back("flower");
  a.push_back("flow");
  a.push_back("flight");
  
  int len = a.size();
  //  for(int i = 0; i < len; i++){
    string value = s.longestCommonPrefix(a);
    cout<<value<<"\t"<<endl;
    //}
  cout<<endl;
}

void
test1(Solution s,
     vector<string> a){
  a.push_back("dog");
  a.push_back("racecar");
  a.push_back("car");
  
  int len = a.size();
  //  for(int i = 0; i < len; i++){
    string value = s.longestCommonPrefix(a);
    cout<<value<<"\t"<<endl;
    // }
  cout<<endl;
}

int
main(){
	Solution s;
	vector<string> a;

	test(s, a);
	test1(s, a);

	return 0;	
}
