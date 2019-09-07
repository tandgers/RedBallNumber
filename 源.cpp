#include <iostream>  
#include <time.h>  
#include <stdlib.h>  
#include <iomanip>  
using namespace std;  
int main()
{
	int random(double,double);  
	int k=1, RandomNumber0, a, b, temp;
	int (*Data)[6]=new int [k][6];
	int (*Red0)=new int [6];	
	int (*NewRed0)=new int [6];
	Red0[0]=0;Red0[1]=0;Red0[2]=0;Red0[3]=0;Red0[4]=0;Red0[5]=0;
	int (*Box0) [100]=new int [33][100];
	int (*Box) [100]=new int [33][100];

	/*给每个红球赋予初始概率*/


	for(int Number=0;Number!=3300;)
	{
		for(int m=0;m!=33;m++)
		{
			for(int n=0;n!=100;n++)
			{
				Box0[m][n]=Number;
				Box[m][n]=1;                //m对应的有100个可能性
				
				Number++;
			}
		}			
	}
	delete []Box0;

	/*读取往期彩票数据*/
	/*并且让往期出现过的红球号码所对应的可能性减少*/
	
	
	cout<<"要输入几期数据: ";
	cin>>k;	
	cout<<"请检查输入的数据是否小于14!!!"<<endl;
	cout<<"请依次输入红球号码: ";
	for(int m=0; m!=k; m++)
	{
		for(int n=0; n!=6; n++)
		{
			cin>>Data[m][n];
			temp=Data[m][n];
			Box[temp-1][m*6+n]=0;           //该红球所对应的可能性减1
		}
	}


	/*开始激动人心的时刻啦*/

	/*接下来将得出我们梦寐以求的机选红球*/
	
	srand(unsigned(time(0)));
	for(int m=0, n=0; Red0[5]==0;)              
	{
	
		RandomNumber0=random(0,3300);	
		a = RandomNumber0 / 100;	
		b = RandomNumber0 % 100;
		if(Box[a][b]==1)
		{
			Red0[m]=a+1;
			if(m==0)
			{				
				m++; 
				n++;                                     
			}				                          
			else
			{
				for(int i=1;i!=m+1;i++)                   //判断随机选择出的红球号码是否重复
				{				
					if (Red0[m]!=Red0[m-i])
					{	
						n=m+1;
					}
					else				
					{		
						Red0[m]=0;	
						n=m;				
						break;
					}
				}	
	
				m=n;                                     //n值为红球不重复的个数
			}
			
		}
	}

	

	
	/*将得到的红球进行排序*/
		
	for(int i=0;i!=6;i++)
	{	
		for(int m=1;m!=6-i;m++)
		{		
			
			
			if(Red0[m-1]<Red0[m])
			{
			}
			else if(Red0[m-1]>Red0[m])
			{
				temp=Red0[m];
				Red0[m]=Red0[m-1];
				Red0[m-1]=temp;
			}
			else if(Red0[m-1]=Red0[m])
			{
				cout<<"程序出现bug!";
				goto bug1;
			}
			NewRed0[5-i]=Red0[5-i];
		}
	}

	NewRed0[0]=Red0[0];


	/*输出红球号码*/
	/*就静静地等待开奖吧！*/

	cout<<"此次机选的红球号码为：";
	
	for(int i=0;i!=6;i++)		
	{				
		cout<<NewRed0[i]<<"  ";			
	}

bug1:
	return 0;

}



int random(double start, double end)  
{  
    return start+rand()%(int)(end-start);  
	/*随机数的范围为[start,end)中的整数*/
}  