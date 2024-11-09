#include<bits/stdc++.h>
using namespace std;

class tree
{
   public:
   int freq;
   string name;
   tree*right;
   tree*left;

   tree()
   {
      right=NULL;
      name="";
      left=NULL;
      freq=0;
   }

   tree(string a,int f)
   {
      name=a;
      freq=f;
      left=NULL;
      right=NULL;
   }

};
class custom
{
  public:
   bool operator()(pair<tree*,int>a,pair<tree*,int>b)
   {
        if(a.second>b.second)
        {
            return true;
        }
        else{
          return false;
        }
   }

};

int main()
{
    ifstream nimoo;

    nimoo.open("pro.txt");

    unordered_map<string, int>sto;

    while(nimoo)
    {
        string s;
        nimoo>>s;

        if(s!="")
        {
            sto[s]++;
        }
    }

   //  for(auto it: sto)
   //  {
   //      cout<<it.first<<" "<<it.second;
   //      cout<<endl;
   //  }


   priority_queue< pair<tree*,int>, vector<pair<tree*,int>>,custom>sto1;

   auto i=sto.begin();

   while(i!=sto.end())
   {  
      tree *root =new tree(i->first,i->second);
    
      sto1.push(make_pair(root,i->second));
      
      i++;
   };

   tree* ans;



   while(sto1.size()!=1)
   {

    pair<tree*,int> a =sto1.top(); // a.first(node)
    sto1.pop();

    pair<tree*,int>b=sto1.top(); //b.first(node)
    sto1.pop();
    
    tree*root=new tree; //empty internal node

    ans=root;

    //empty internal node se dono node connect ho gya

    if(a.second<b.second)
    {
       root->left=a.first;
       root->right=b.first;

    }
    else{
      
       root->right=a.first;
       root->left=b.first;
      
    }


    // internal nde me nahi string store kr the , nahi freuncy (frequenct hm pair me hi store kr le rhe , whi se use kr le rhe)

    sto1.push(make_pair(root,a.second+b.second));

    ans=root;

   }

   unordered_map<string,string>sto3;

   stack< pair<tree*,string> >sto2;

   sto2.push(make_pair(ans,""));

   while(!sto2.empty())
   {  
      pair<tree*,string> a = sto2.top();
      sto2.pop();
      
      if(a.first->name.length()!=0)
      {   
         sto3[a.first->name]=a.second;
      }else{
       
         sto2.push(make_pair(a.first->left,a.second+'0'));
         sto2.push(make_pair(a.first->right,a.second+'1'));
      }
   }

   //  for(auto it: sto3)
   //  {
   //      cout<<it.first<<" "<<it.second;
   //      cout<<endl;
   //  }



    ofstream com;
    com.open("com.txt");

    for(auto it: sto3)
    {
        com<<it.first;
        com<<" ";
        com<<it.second;
        com<<" ";
        // cout<<endl;
    }

     com<<"khatm"<<" ";
     

     ifstream file_read;

     file_read.open("pro.txt");

     while(file_read)
    {
        string s;
        file_read>>s;

        com<<sto3[s];
    }

}