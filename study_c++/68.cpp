#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)  {
      vector<string> retVector;
      int wordsLen = words.size();
      int beginPosition;
      int curPosition = 0;
      int maxSpitLength;
      int spaceLength;

      while(curPosition < wordsLen){
	maxSpitLength = 0;
	spaceLength = 0;
      
	beginPosition = curPosition;
	while(curPosition + maxSpitLength < wordsLen
	&& spaceLength <= maxWidth){
	  spaceLength += words[curPosition+maxSpitLength].size() + 1;
	  maxSpitLength++;	  
	}
	//save string group
	if(maxSpitLength > 0){
	  //is over
	  if(spaceLength > maxWidth){
	    maxSpitLength--;	    
	  }
	  string str;
	  for(int i = 0; i < maxSpitLength - 1; i++){
	    str += words[curPosition + i] + " ";
	  }
	  str += words[curPosition + maxSpitLength -1];
	  retVector.push_back(str);
	}

	curPosition += maxSpitLength;
      //next group
      }
	

      
      return retVector;
    }
};

void
test(Solution s,
     map<int,vector<string>> paramA,
     map<int, int> paramB,
     map<int,vector<string>> result){
  int i = 0;
  //---------------------------------------------------------
  paramA[i].push_back("This");
  paramA[i].push_back("is");
  paramA[i].push_back("an");
  paramA[i].push_back("example");
  paramA[i].push_back("of");
  paramA[i].push_back("text");
  paramA[i].push_back("justification.");
  
  paramB[i] = 16;
  
  result[i].push_back("This    is    an");
  result[i].push_back("example  of text");
  result[i].push_back("justification.  ");
  //---------------------------------------------------------
  i++;
  paramA[i].push_back("What");
  paramA[i].push_back("must");
  paramA[i].push_back("be");
  paramA[i].push_back("acknowledgment");
  paramA[i].push_back("shall");
  paramA[i].push_back("be");
  
  paramB[i] = 16;

  result[i].push_back("What   must   be");
  result[i].push_back("acknowledgment  ");
  result[i].push_back("shall be        ");
  //---------------------------------------------------------
  i++;
  paramA[i].push_back("Science");
  paramA[i].push_back("is");
  paramA[i].push_back("what");
  paramA[i].push_back("we");
  paramA[i].push_back("understand");
  paramA[i].push_back("well");
  paramA[i].push_back("enough");
  paramA[i].push_back("to");
  paramA[i].push_back("explain");
  paramA[i].push_back("to");
  paramA[i].push_back("a");
  paramA[i].push_back("computer.");
  paramA[i].push_back("Art");
  paramA[i].push_back("is");
  paramA[i].push_back("everything");
  paramA[i].push_back("else");
  paramA[i].push_back("we");
  paramA[i].push_back("do");

  paramB[i] = 20;

  result[i].push_back("Science  is  what we");
  result[i].push_back("understand      well");
  result[i].push_back("enough to explain to");
  result[i].push_back("a  computer.  Art is");
  result[i].push_back("everything  else  we");
  result[i].push_back("do                  ");
  
 
  for(auto [k,v]:paramA){
    vector<string> value = s.fullJustify(v, paramB[k]);
    if(value.size() <= 0){      
      cout<<k<<"-->fail"<<endl;
      continue;
    }
    cout<<"lab "<<k<<":"<<endl;
    for(int i = 0; i < value.size(); i++){
      cout<<"i:"<<i<<",value:["<<value[i]<<"]"<<endl;
    }
    cout<<"--------------------"<<endl;
    continue;
    int resultLen = result[k].size();
    int okTime = 0;
    for(int i = 0; i < resultLen; i++){
      if(value[i] == result[k][i]){
	okTime++;
      }
    }
    if(okTime == resultLen){
       cout<<"-->success"<<endl;
    }else{
      cout<<"-->fail"<<endl;
    }
    //cout<<"|"<<value<<"|"<<endl;
    /*
    if(value == result[k]){
      cout<<"-->success"<<endl;
    }else{
      cout<<"-->fail"<<endl;
    }
    */
   }
  cout<<endl;
}

int
main(){
	Solution s;
	map<int, vector<string>> a;
	map<int, int> b;
	map<int, vector<string>> result;

	test(s, a, b, result);

	return 0;	
}
