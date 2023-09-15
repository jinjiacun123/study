#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle)  {
      int reInt = -1;
      int haystackLen = haystack.size();
      int needleLen = needle.size();
      int matchPosition,i;

      //cout<<"needle:"<<needle<<",haystack:"<<haystack<<endl;
      for(i = 0, matchPosition = 0; i < haystackLen; i++,matchPosition = 0){
	while(matchPosition < needleLen
	&& needle[matchPosition] == haystack[i]){
	  //cout<<"matchPosition:"<<matchPosition<<endl;
	  if(matchPosition == needleLen -1){
	    reInt = matchPosition - needleLen + 1;
	    return reInt;
	  }
	  matchPosition++;
	  i++;
	}	
      }
      
      return reInt;
    }
};

void
test(Solution s,
     map<string,string> a,
     map<string,int> result){
  a["sad"] = "sadbutsad";
  a["leeto"] = "leetcode";

  result["sad"] = 0;
  result["leeto"] = -1;
  
  int len = a.size();
  int i = 0;
  for(auto [k,v]:a){
    int value = s.strStr(v, k);
    cout<<"|"<<value<<"|"<<endl;
    if(value == result[k]){
      cout<<"-->success"<<endl;
    }else{
      cout<<"-->fail"<<endl;
    }
   }
  cout<<endl;
}

int
main(){
	Solution s;
	map<string, string> a;
	map<string,int> result;

	test(s, a, result);

	return 0;	
}
