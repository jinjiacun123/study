#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
      int reValue = 0;
      int strLen = s.size();
      int curPosition = strLen -1;
      int match = 0;

      while(true){
	if(match == 1
	   && s[curPosition] == ' '){
	  break;
	}
	
	if(s[curPosition] == ' '
	&& match == 0){
	  curPosition--;
	  continue;
	}

	//match and accumulate
	if(s[curPosition] != ' '){
	  match = 1;
	  reValue++;
	  curPosition--;
	  continue;
	}
	
      }
      
      return reValue;
    }
};


void
test(Solution s,
     vector<string> a){
  a.push_back("Hello World");
  a.push_back("   fly me   to   the moon  ");
  a.push_back("luffy is still joyboy");
  
  int len = a.size();
  for(int i = 0; i < len; i++){
    int value = s.lengthOfLastWord(a[i]);
    cout<<value<<"\t"<<endl;
  }
  cout<<endl;
  
}

int
main(){
	Solution s;
	vector<string> a;

	test(s, a);

	return 0;	
}
