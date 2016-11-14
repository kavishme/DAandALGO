//https://www.hackerrank.com/challenges/median
#include <set>
#include <vector>
#include <iostream>
using namespace std;

void median(vector<char> s,vector<int> x) {
    
    std::multiset<int> m;
    std::multiset<int>::iterator it, med;
    
    vector<char>::iterator sit;
    vector<int>::iterator xit;
    
    float median = 0;
    int size = 0;
    //cout<<"loop starts";
    for(sit = s.begin(), xit = x.begin(); sit!= s.end() && xit != x.end(); ++sit, ++xit){
        if(*sit == 'a'){
            m.insert(*xit);
        }
        else if(*sit == 'r'){
            it = m.find(*xit);
            if(it == m.end()){
                cout<<"Wrong!"<<endl;
                continue;
            }
            else{
                m.erase(it);
            }
        }

        size = m.size();
        it = m.begin();
        for (int i = size/2; i > 0; --i)
            ++it;

        if(size && size%2 == 0)
            median = (*it + *(++it))/2;
        else if(size > 1)
            median = *(++it)/2;
        else if(size == 1)
            median = *it;
        cout<<median<<endl;
    }
}
int main(void){

//Helpers for input and output

   int N;
   cin >> N;
   
   vector<char> s;
   vector<int> X;
   char temp;
   int tempint;
   //cout<<"insert data"<<endl;
   for(int i = 0; i < N; i++){
      cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
   }
   //cout<<"data got!!"<<endl;
   
   median(s,X);
   return 0;
}