#include<bits/stdc++.h>
using namespace std;
int cnt=0;
pair<int,pair<int,int> > playgame(char arr[3][3],int turn)
{

int i,j;
cnt=0;
pair<int,pair<int,int> > answer;
if(turn==0)
{
//cout<<" i came here "<<endl;
    int maxi=-1;
    int pos1=0,pos2=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
    {

        if(arr[i][j]=='_')
        {
                                char temp[3][3];
                                int k,l;

            for(k=0;k<3;k++)
                for(l=0;l<3;l++)
        temp[k][l]=arr[k][l];

        temp[i][j]='0';
        if((temp[0][0]=='0')&&(temp[0][1]=='0')&&(temp[0][2]=='0'))
    answer= {10,{i,j}};
else if((temp[1][0]=='0')&&(temp[1][1]=='0')&&(temp[1][2]=='0'))
    answer= {10,{i,j}};
else if((temp[2][0]=='0')&&(temp[2][1]=='0')&&(temp[2][2]=='0'))
    answer= {10,{i,j}};
else if((temp[0][0]=='0')&&(temp[1][0]=='0')&&(temp[2][0]=='0'))
    answer= {10,{i,j}};
else if((temp[0][1]=='0')&&(temp[1][1]=='0')&&(temp[2][1]=='0'))
answer= {10,{i,j}};
else if((temp[0][2]=='0')&&(temp[1][2]=='0')&&(temp[2][2]=='0'))
    answer={10,{i,j}};
    else if((temp[0][0]=='0')&&(temp[1][1]=='0')&&(temp[2][2]=='0'))
        answer= {10,{i,j}};
    else if((temp[0][2]=='0')&&(temp[1][1]=='0')&&(temp[2][0]=='0'))
        answer= {10,{i,j}};
        else
{
int a,b;
 cnt=0;
for(a=0;a<3;a++)
{
    for(b=0;b<3;b++)
    {
        if(temp[a][b]!='_')
            cnt++;
    }
}
if(cnt==9)
    answer={0,{i,j}};
    else
        answer=playgame(temp,1);
}
             //   cout<<answer.first<<" ";

        if(answer.first>maxi)
        {

            maxi=answer.first;
            pos1=i;
            pos2=j;
        }
    }
    }

    }
    return {maxi,{pos1,pos2}};





}
else
{
   // cout<<"i also came here"<<endl;
    int mini=10000000;
    int pos1=0,pos2=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
    {
                    char temp[3][3];
                                int k,l;
 for(k=0;k<3;k++)
 for(l=0;l<3;l++)
 temp[k][l]=arr[k][l];

        if(arr[i][j]=='_')
        {

            temp[i][j]='1';
 if((temp[0][0]=='1')&&(temp[0][1]=='1')&&(temp[0][2]=='1'))
answer= {(-10),{i,j}};
else if((temp[1][0]=='1')&&(temp[1][1]=='1')&&(temp[1][2]=='1'))
answer={(-10),{i,j}};
else if((temp[2][0]=='1')&&(temp[2][1]=='1')&&(temp[2][2]=='1'))
    answer= {(-10),{i,j}};
else if((temp[0][0]=='1')&&(temp[1][0]=='1')&&(temp[2][0]=='1'))
answer={(-10),{i,j}};
else if((temp[0][1]=='1')&&(temp[1][1]=='1')&&(temp[2][1]=='1'))
answer={(-10),{i,j}};
else if((temp[0][2]=='1')&&(temp[1][2]=='1')&&(temp[2][2]=='1'))
    answer= {(-10),{i,j}};
    else if((temp[0][0]=='1')&&(temp[1][1]=='1')&&(temp[2][2]=='1'))
        answer= {(-10),{i,j}};
    else if((temp[0][2]=='1')&&(temp[1][1]=='1')&&(temp[2][0]=='1'))
        answer={(-10),{i,j}};
        else
        {
int a,b;
cnt=0;
for(a=0;a<3;a++)
{
    for(b=0;b<3;b++)
    {
        if(temp[a][b]!='_')
            cnt++;
    }
}
if(cnt==9)
    answer= {0,{i,j}};
    else
        answer=playgame(temp,0);



        }

        //cout<<answer.first<<" ";
        if(answer.first<mini)
        {
            mini=answer.first;
            pos1=i;
            pos2=j;

        }
        }
    }


    }

return {mini,{pos1,pos2}};



}




}
int main()
{
    cout<<"Lets Play the Game"<<endl;
    cout<<"U make the First move bitch"<<endl;
    int i,j;
        char arr[3][3]={{'_','_','_'},{'_','_','_'},{'_','_','_'}};

          for(i=0;i<3;i++)
    {
    for(j=0;j<3;j++)
    cout<<arr[i][j]<<" ";
    cout<<endl;
    }

    int a,b;
    cin>>a;
    int r;
    if(a%3==0)
        r=(a/3)-1;
    else
        r=a/3;
    int er=a%3;
    er=(er+2)%3;
    arr[r][er]='1';
    for(i=0;i<3;i++)
    {
    for(j=0;j<3;j++)
    cout<<arr[i][j]<<" ";
    cout<<endl;
    }


int yi=0;
int turn=1;
pair<int,pair<int,int> > pi;
while(yi!=1)
{



turn=turn^1;
if(turn==1)
{
    cin>>a;
    if(a%3==0)
        r=(a/3)-1;
    else
        r=a/3;
    er=a%3;
    er=(er+2)%3;
    if(arr[r][er]!='_'){
        cout<<"Invalid move: Please select a different move"<<endl;
     turn=turn^1;
    }
    else
    arr[r][er]='1';
}
else
{
 pi=playgame(arr,turn);

 cout<<"I am making my move now bitch "<<endl;
arr[pi.second.first][pi.second.second]='0';
}

if((arr[0][0]=='0')&&(arr[0][1]=='0')&&(arr[0][2]=='0'))
    yi=1;
else if((arr[1][0]=='0')&&(arr[1][1]=='0')&&(arr[1][2]=='0'))
yi=1;
else if((arr[2][0]=='0')&&(arr[2][1]=='0')&&(arr[2][2]=='0'))
    yi=1;
else if((arr[0][0]=='0')&&(arr[1][0]=='0')&&(arr[2][0]=='0'))
    yi=1;
else if((arr[0][1]=='0')&&(arr[1][1]=='0')&&(arr[2][1]=='0'))
yi=1;
else if((arr[0][2]=='0')&&(arr[1][2]=='0')&&(arr[2][2]=='0'))
    yi=1;
    else if((arr[0][0]=='0')&&(arr[1][1]=='0')&&(arr[2][2]=='0'))
        yi=1;
    else if((arr[0][2]=='0')&&(arr[1][1]=='0')&&(arr[2][0]=='0'))
        yi=1;

for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
        cout<<arr[i][j]<<" ";

    cout<<endl;
}
if(yi==1)
    cout<<"Bitch u loose"<<endl;









}
}
