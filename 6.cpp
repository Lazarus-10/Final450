#include <iostream>
#include <string>

using namespace std;

void reverseItr(string &str){
    int i=0, j = str.length() - 1;
    while(i < j){
        swap(str[i++], str[j--]);
    }
}

void helperRec(string &str, int s, int e){
    if(s >= e)return;
    swap(str[s++], str[e--]);
    helperRec(str, s, e);
}
void reverseRec(string &str){
    helperRec(str, 0, str.length()- 1);
}

int main(){
    string str = "saif Khan";
    reverseRec(str);
    cout << str << endl;
    return 0;
}