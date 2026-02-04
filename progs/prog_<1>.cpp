#include <iostream>
#include <string>
#include <stack>
using namespace std;



bool Balanced(string expression){
    stack<char> bracketstk;
    for (char cr: expression){
        if(cr =='(' || cr== '{' || cr=='['){
            bracketstk.push(cr);
        }
        else if (cr ==')' || cr== '}' || cr==']'){

            if (bracketstk.empty()){
                return false;
            }
            char top = bracketstk.top();
            bracketstk.pop();

             if ((cr == ')' && top != '(') ||(cr == ']' && top != '[') ||(cr == '}' && top != '{')) {
                return false;}

        }
    }
    return bracketstk.empty();



}

int main(){
    string ex1="a+(b-c)*(d";
    string ex2="m+[a-b*(c+d*{)]";
    string ex3="a+(b-c)";

    cout<<ex1;
    if (Balanced(ex1)){
        cout<< "\n IS BALANCED";
    } else{cout<<"\n NOT BALANCED \n"; }

   cout<<ex2;
    if (Balanced(ex2)){
        cout<< "\n IS BALANCED";
    } else{cout<<"\n NOT BALANCED \n"; }
    

   cout<<ex3;
    if (Balanced(ex3)){
        cout<< "\n IS BALANCED";
    } else{cout<<"\n NOT BALANCED \n"; }
    



    return 0;
}