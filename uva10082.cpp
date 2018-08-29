#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string num = "`1234567890-=";
    string row1 = "QWERTYUIOP[]\\";
    string row2 = "ASDFGHJKL;'";
    string row3 = "ZXCVBNM,./";

    string input;

    while(getline(cin,input)){
        if(input.size()==0)break;

        for(int i=0;i<input.size();i++){

            if(num.find(input[i])!=string::npos){
                int s = num.find(input[i]);
                input[i] = num[s-1];
            }
            else if(row1.find(input[i])!=string::npos){
                int s = row1.find(input[i]);
                input[i] = row1[s-1];
            }

            else if(row2.find(input[i])!=string::npos){
                int s = row2.find(input[i]);
                input[i] = row2[s-1];
            }

            else if(row3.find(input[i])!=string::npos){
                int s = row3.find(input[i]);
                input[i] = row3[s-1];
            }
        }
        cout<<input<<endl;



    }




}
