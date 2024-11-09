#include<bits/stdc++.h>
using namespace std;
int main()
{

    // 1) file create and write
    ofstream obj;
    obj.open("input.txt");

    obj << "My name is Nimisha kumari, I am in Sadaybigha ";
    obj<< "I am enjoying the chath";

    obj.close();

    // 2) file read and do some operation like mapping

    map<string , int>mp;

    ifstream obj1;
    obj1.open("input.txt");

    while(obj1)
    {
        string s;
        obj1>>s;

        if(s!="")
        {
            mp[s]++;
        }

    }

    for(auto it: mp)
    {
        cout<<it.first<<" "<<it.second;
        cout<<endl;
    }

    obj1.close();






}