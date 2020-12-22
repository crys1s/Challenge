#include<iostream>
using namespace std;
int main(){
//declaration of input
int data[60],n;
input:
cout<<"Enter the number of inputs\n";
cin>>n;
if(n>60)
{
	cout<<"Input too large, Enter a number less than or equal to 60\n\n";
	goto input;
	
}
cout<<"Enter the inputs for the graph\n";
int num;
for(int i=0;i<n;i++)
{
data:
cin>>num;
if(num==0||num>15)
{
	cout<<"Invalid entry, Enter the value again please (Range 1-15)\n";
	goto data;
}
data[i]=num;
}

char mainarr[40][350];
int j,k,count=0;
//calculation of maximum value
int temp=0,maxval=0,width=0,lowval=0;
for(int i=0;i<n;i++)
{
 	if(i%2==0)
 	temp=temp+data[i];
 	else
 	temp=temp-data[i];
 	if(temp>maxval)
 	maxval=temp;
 	width=width+data[i];
 	if(i==0)
 	lowval=temp;
 	if(i%2==0 && temp<lowval)
	lowval=temp;
	 if((maxval>16) || (temp<-19) || width > 349){
 		cout<<"\nUnable to plot graph using current set of inputs as scope is too large\n";
        goto input;
	}			
}

for(int p=0;p<40;p++)
{
	for(int q=0;q<350;q++)
	mainarr[p][q]=32;
}
j=19;
k=0;
int top=20-maxval,mark,bot=0;

bot=20-lowval;


//main logic function
temp=0;
for(int i=0;i<n;i++)
{
/*	if(j==top)
    k++;
*/	
	if(temp==lowval)
    k++;
	if(i%2==0)
 	temp=temp+data[i];
 	else
 	temp=temp-data[i];
	count=data[i];
	if(i%2==0){
	for(int l=0;l<count;l++)
	{
			mainarr[j][k]='/';
	     	j--;
		    k++;	    
	}
    } 
    else{
    		for(int l=0;l<count;l++)
		{      
			mainarr[j][k]=92;
			j++;
			k++;
		
		}
	}
	//condition while changing from / to \ or viceversa
	if(i%2==0)
	j++;
    else
    j--;
}

//printing top man
/*for(int p=top;p<top+1;p++)
{
	for(int q=0;q<350;q++)
	{
		if(mainarr[top][q]=='/')
		{
			mainarr[top-1][q]='<';
			mainarr[top-1][q+2]='>';
			mainarr[top-2][q+2]=92;
			mainarr[top-2][q]='/';
			mainarr[top-2][q+1]='|';
			mainarr[top-3][q+1]='o';
			mark=q;
		}
	}
}*/
//
for(int p=bot;p<bot+1;p++)
{
	for(int q=0;q<350;q++)
	{
		if((mainarr[bot][q]=='/' && mainarr[bot][q+1]==92 ) || (mainarr[bot][q]=='/' && mainarr[bot-1][q+1]==32 ))
		{
			mainarr[bot-1][q]='<';
			mainarr[bot-1][q+2]='>';
			mainarr[bot-2][q+2]=92;
			mainarr[bot-2][q]='/';
			mainarr[bot-2][q+1]='|';
			mainarr[bot-3][q+1]='o';
			mark=q;
		}
	}
}
//printing the array
for(int p=0;p<40;p++)
{
	for(int q=0;q<350;q++)
	cout<<mainarr[p][q];
	cout<<"\n";
}
cin>>j;                                                    //here j is just a random input, used in place getch() as <conio.h> is not used
}
