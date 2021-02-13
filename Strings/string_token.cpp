#include<bits/stdc++.h>
using namespace std;

char *my_strtok(char *a,char delim)
{
    static char *input=NULL;
    if(a!=NULL){
        //first call of the function
        input=a;
    }
    char *output=new char[strlen(input)+1];
    int i=0;
    for(;input[i]!='\0';i++)
    {
        if(input[i]!=delim)
        {
            output[i]=input[i];
        }
        else
        {
            output[i]='\0';
            input=input+i+1;
            return output;
        }
    }
     output[i]='\0';
     input=NULL;
     return output;
}
int main()
{
    char a[100]="coding is fun, only if, the compiler works, correctly";
    char *t;
    t=my_strtok(a,' ');
    cout<<t<<endl;
    while(t!=0)
    {
        t=my_strtok(NULL,' ');
        cout<<t<<endl;
    }

}