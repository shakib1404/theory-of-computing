#include<bits/stdc++.h>
using namespace std;

void leftmost(string s)
{

    string way="S";
    cout<< way << "->";
    if(way=="S"){
        way=way.replace(0,1,"A1B");
        cout<<way<<"->";
    }

    for(int i=0;i<s.size()-1;i++)
    {


    if(s[i]=='0'&& way[i]=='A')
    {
        way=way.replace(i,1,"0A");
         cout<<way<<"->";

    }
      //  if(s[1]=='0'&& way[1]=='A')
    //{
      //  way=way.replace(1,1,"0A");
        // cout<<way<<"->";

   // }

      else  if(s[i]=='1'&& way[i]=='A')
    {
        way=way.replace(i,1,"");
         cout<<way<<"->";

    }

    else if(s[i]=='0'&& way[i]=='B')
    {
        way=way.replace(i,1,"0B");
         cout<<way<<"->";

    }
 else if(s[i]=='1'&& way[i]=='B')
    {
        way=way.replace(i,1,"1B");
         cout<<way<<"->";


    }

    else
        cout<<"error";
    }

    cout<< s <<endl;

}
void rightmost(string s)
{
     string way="S";
    cout<< way << "->";
    if(way=="S"){
        way=way.replace(0,1,"A1B");
        cout<<way<<"->";
    }

    if(way[2]=='B'&&s[3]=='0')
    {
        way=way.replace(2,1,"0B");
        cout<<way<<"->";

    }

    if(way[3]=='B'&&s[4]=='1')
    {
        way=way.replace(3,1,"1B");
        cout<<way<<"->";
    }

     if(way[4]=='B'&&s[5]=='\0')
    {
        way=way.replace(4,1,"");
        cout<<way<<"->";
    }

   if(way[0]=='A'&&s[0]=='0')
    {
        way=way.replace(0,1,"0A");
        cout<<way<<"->";
    }
if(way[1]=='A'&&s[1]=='0')
    {
        way=way.replace(1,1,"0A");
        cout<<way<<"->";
    }
    if(way[2]=='A'&&s[2]=='1')
    {
        way=way.replace(2,1,"");
        cout<<way<<"";
    }










}



int main()
{

    string s;
    cout<< "take the string input:";
    cin>> s;
    leftmost(s);
    rightmost(s);






}
