
#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;

class Solution {
public:
    /**
    * a. find last comment child and place a candy to him;
    * b. to left child, if exists and comment is great and place two candy
    * c. to right child, if exists and comment is great and place two candy
    * d. continue to left child, if his command great and place plus candy, place one candy if equal
    * e. continue to right child, like step d.
    * f. all child is have candy, game is over, and calculation amount of candy place to child.
    */
    int candy(vector<int>& ratings) {
        int value = 0;
        int amount = 0;
        vector<int> candyPlace;
        int len = ratings.size();
        int lowestCommandPosition = 0;
        int placePosition = 0;
        int prePlacePosition = 0;

        //init
        for(int i = 0; i < len; i++){
            candyPlace.push_back(0);
        }

        //find lowest
        for(int i = 1; i < len; i++){
            if(ratings[i] < ratings[lowestCommandPosition]){
                lowestCommandPosition = i;
            }
        }

        //place candy
        candyPlace[lowestCommandPosition] = 1;

        placePosition = lowestCommandPosition -1;
        prePlacePosition = lowestCommandPosition;
        //left
        while(placePosition >= 0){
            if(ratings[placePosition] > ratings[prePlacePosition]){
                candyPlace[placePosition] = candyPlace[prePlacePosition] + 1;
            }else if(ratings[placePosition] == ratings[prePlacePosition]
            &&   ratings[prePlacePosition] > 1){
                candyPlace[placePosition] = ratings[prePlacePosition] -1;
            }
            prePlacePosition  = placePosition;
            placePosition = placePosition -1;
        }

        placePosition = lowestCommandPosition + 1;
        prePlacePosition = lowestCommandPosition;
        //right
        while(placePosition < len){
            if(ratings[placePosition] > ratings[prePlacePosition]){
                candyPlace[placePosition] = candyPlace[prePlacePosition] + 1;
            }else if(ratings[placePosition] == ratings[prePlacePosition]
            &&   ratings[prePlacePosition] > 1){
                candyPlace[placePosition] = ratings[prePlacePosition] -1;
            }
            prePlacePosition  = placePosition;
            placePosition = placePosition + 1;
        }


        //calculation all candy
        for(int i = 0; i < len; i++){
            value += candyPlace[i];
        }

        return value;
    }
};

void test1(Solution s, vector<int> a){
    a.push_back(1);
    a.push_back(0);
    a.push_back(2);

    int value= s.candy(a);
    cout<<value;
    cout<<endl;
}

void test2(Solution s, vector<int> a){
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);

    int value = s.candy(a);
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

