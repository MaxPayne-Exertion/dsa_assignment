#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> bracketstk;

bool Balanced(string expression){
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
    return bracketstk.empty()



}

int main(){
    string ex1="a+(b-c)*(d";
    string ex2="m+[a-b*(c+d*{)]";
    string ex3="a+(b-c)";




    return 0;
}