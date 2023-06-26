
#include <bits/stdc++.h>
using namespace std;

class Solution{
    int minEle;
    stack<pair<int, int>> s;
public:
    // returns min element from stack
    int getMin(){
        if (s.empty()) {
            return -1;  // or throw an exception, depending on the requirements
        }
        return s.top().second;
    }
    
    // returns popped element from stack
    int pop(){
        if (s.empty()) {
            return -1;  
        }
        pair<int, int> ele = s.top();   //storing popped elements
        s.pop();
        return ele.first;
    }
    
    // push element x into the stack
    void push(int x){
        if (s.empty()){
            s.push({x, x});
        }
        else{
            s.push({x, min(x, s.top().second)});    //maintain minimum element
        }
    }
}; 

int main()
 {
    long long t;
    //Testcases
    cout<<"Enter number of testcases\n";
    cin>>t;
    while(t--)
    {
        int q;
        cout<<"Enter number of queries\n";
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<"\nPopped element:"<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<"\nMinimum Element:"<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}