#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int numStates,numAlphabets;
int states[MAX];
char alphabet[MAX],transition[MAX][MAX];
string store[MAX][MAX][MAX];


void takeDFA()
{

    cout<<"Number of states:";
    cin>>numStates;
    cout<<"states"<<endl;
    for(int i=0; i<numStates; i++)
    {
        cin>>states[i];
    }
    cout<<"Number of alphabets:";
    cin>>numAlphabets;
    cout<<"alphabets"<<endl;
    for(int i=0; i<numAlphabets; i++)
    {
        cin>>alphabet[i];
    }

     for(int i=0; i<numStates; i++){
        for(int j=0; j<numAlphabets; j++){
            cout<<"From: "<<states[i]<<" Via: "<<alphabet[j]<<" to(which?): ";
            cin>>transition[i][j];

        }
    }
    cout<<endl;



}

void initiate(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<3; k++){
                store[i][j][k] = "\0";
            }
        }
    }
}

string RE(int i, int j, int k){
    if( k==0 ){
        if(i==1 && j==1)
         return " e + 1 ";
        else if((i == 2 && j == 2) )
            return " e ";
        else if(i==3 && j==3)
         return " e + 0 ";
        else if((i==1 && j==2) || (i==2 && j==3))
         return " 0 ";
        else if((i==2 && j==1) || (i==3 && j ==2))
         return " 1 ";
        else return " NULL ";
    }

    if(store[i][j][k] != "\0")
        return store[i][j][k];

    store[i][j][k] = (RE(i, j, k-1) + " + (" + RE(i, k, k-1) + ") (" + RE(k, k, k-1) + ")*(" + RE(k, j, k-1) + ")");
    return store[i][j][k];

}




int main()
{
    freopen("untitled2.c", "r", stdin);

    takeDFA();

    initiate();

    for(int k=0; k<3; k++){
        for(int i=1; i<4; i++){
            for(int j=1; j<4; j++){
                cout<<"RE("<<i<<", "<<j<<", "<<k<<") = "<<RE(i, j, k)<<endl;
            }
        }
    }

}
