#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    string reverseWords(string s)  {
      string reStr;
      int sLen = s.size();
      vector<string> words;
      int i = 0;

      while(i < sLen){
	//clean black
	while(s[i] == ' ' && i < sLen)i++;
	
	//not black
	string word = "";
	while(s[i] != ' '
	&& i < sLen)
	  word.append(1,s[i++]);

	if(word != "")
	  words.push_back(word);
      }

      int wordsLen = words.size();
      if(wordsLen > 0){
	for(int j = wordsLen -1; j > 0; j--){
	  reStr += words[j] + " ";
	}
	reStr += words[0];
      }
      
      return reStr;
    }
};


void
test(Solution s,
     vector<string> a){
  a.push_back("the sky is blue");
  a.push_back("  hello world  ");
  a.push_back("a good   example");
  
  int len = a.size();
    for(int i = 0; i < len; i++){
    string value = s.reverseWords(a[i]);
    cout<<"|"<<value<<"|"<<endl;
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
