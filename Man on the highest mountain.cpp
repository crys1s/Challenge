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
if(num==0||num>45)
{
	cout<<"Invalid entry, Enter the value again please (Range 1-45)\n";
	goto data;
}
data[i]=num;
}

char mainarr[100][350];
int j,k,count=0;
//calculation of maximum value
int temp=0,maxval=0;
for(int i=0;i<n;i++)
{
 	if(i%2==0)
 	temp=temp+data[i];
 	else
 	temp=temp-data[i];
 	if(temp>maxval)
 	maxval=temp;
 	if((maxval>45) || (temp<-45)){
 		cout<<"\nUnable to plot graph using current set of inputs as scope is too large\n";
        goto input;
	 }
}


for(int p=0;p<50;p++)
{
	for(int q=0;q<350;q++)
	mainarr[p][q]=32;
}
j=49;
k=0;
int top=50-maxval,mark;
//main logic function
for(int i=0;i<n;i++)
{
	if(j==top)
    k++;
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
for(int p=top;p<top+1;p++)
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
}
//printing the array
for(int p=0;p<50;p++)
{
	for(int q=0;q<350;q++)
	cout<<mainarr[p][q];
	cout<<"\n";
}
cin>>j;                                                    //here j is just a random input, used in place getch() as <conio.h> is not used
}
