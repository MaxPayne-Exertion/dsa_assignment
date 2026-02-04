#include <iostream>
#include <stack>
#include <stdexcept>
#include <cmath>

using namespace std;

class ExpressionConverter{
    private:
        bool isOperator(char c){
            return c=='+'||c=='-'||c=='/'||c=='*'||c=='^';
        }
    
        int precedence(char opt){
            if (opt=='^') return 3;
            if (opt=='*'|| opt=='/') return 2;
            if (opt=='+'|| opt=='-') return 1;
            return 0;
        }
    
        double useopt(double a, double b, char opt){
            switch (opt){
                case '+': return a+b;
                case '-': return a-b;
                case '*': return a*b;
                case '/':
                 if (b==0) throw runtime_error("div zero");
                 return a/b;
                case '^':return pow(a,b);
                default: throw runtime_error("unknown");
            }
        }
    
        public:
    
        string toPostfix(const string& infix){
            stack<char> s;
            string postfix="";
    
            for (int i=0;i<infix.length();i++){
                char c=infix[i];
                if (c==' ')continue;
    
                if (isdigit(c)||c=='.'){
                    while(i<infix.length() && (isdigit(infix[i]))|| infix[i]=='.'){
                        postfix+= infix[i];
                        i++;
                    }
                    postfix+=' ';
                    i--;
    
                }
                else if (c=='('){
                    s.push(c);
    
                }
                else if (c == ')'){
                    while(!s.empty() && s.top() !='('){
                        postfix +=s.top();
                        postfix+=' ';
                        s.pop();
                    }
                    s.pop();
                }
                else if (isOperator(c)){
                    while (!s.empty() && precedence(s.top())>= precedence(c)){
                        postfix += s.top();
                        postfix+=' ';
                        s.pop();
                    }
                    s.push(c);
                }
    
            }
    
            while (!s.empty()){
                postfix+= s.top();
                postfix+= ' ';
                s.pop();
    
            }
                return postfix;
            }
            double evaluate(const string& postfix) {
            stack<double> values;
            string num = "";
            
            for (int i = 0; i< postfix.length(); i++) {
                char c = postfix[ i]; 
                
                if (c == ' ') {
                    if (!num.empty()) {
                        values.push(stod( num));
                        num = "";
                    }
                    continue; 
                }
                
                if (isdigit(c)|| c == '.') {
                    num += c;
                }
                
                else if (isOperator(c)) {
                    if (values.size() <2) {
                        throw runtime_error("Invalid exp");
                    }
                    double b = values.top(); values.pop();
                    double a = values.top(); values.pop();
                    values.push(useopt(a, b, c));
                }
            }
            
            if (values.size() != 1) {
                throw runtime_error("Invalid exp ");
            }
            
            return values.top();
        }
        
        double evaluateInfix(const string& infix) {
            string postfix = toPostfix( infix);
            return evaluate(postfix);  
        }
};


int main(){
    ExpressionConverter cvtr;

    string exp1="3+4-1";
    string exp2="(4*4)/3";
    string exp3 ="(2^7)*9";


        try{
        string postfix =cvtr.toPostfix(exp1);
        double result =cvtr.evaluateInfix(exp1);
        cout<<"Expression \n"<< exp1<<" postfix:"<<postfix<<" result:"<<result<< endl;


    }
    catch (const exception& e){
        cout<<e.what();

    }
    return 0;


}