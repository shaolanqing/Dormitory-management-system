#include<cstdio>
#include<string>
#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
#define Max 100
 int total;  
struct edg                                //构造结构体，创建学生信息的结构体数组，其中的信息包含名字，宿舍房号以及学号 。
{
	string name;
	int number;
	int domenumber;
}student[Max];
edg s[Max];
void menu()                                          //主菜单的函数包含3个功能（新建，排序，查询,打印）
{
	cout<<"\t\t **********************************"<<endl;
	cout<<"\t\t       * 欢迎进入宿舍管理系统*     "<<endl;
	cout<<"\t\t **********************************"<<endl;
	cout<<"\t\t         * 1.新建宿舍名单 *        "<<endl;
	cout<<"\t\t         * 2.排序宿舍信息 *        "<<endl;
	cout<<"\t\t         * 3.查询宿舍信息 *        "<<endl;
	cout<<"\t\t         * 4.打印任意查询结果 *    "<<endl;
	cout<<"\t\t         * 0.退出系统 *            "<<endl;
    cout<<"\t\t **********************************"<<endl;
	cout<<endl<<endl;
	cout<<"请输入你想要进行操作的序号:";
}

void build()                           //新建学生信息 
{
	int i;
	string a;
	int b,c;
	system("cls");
	ofstream ofs;   //定义对象
	ofs.open("d:\\my.txt",ios::app);	 //追加进文件中
	cout<<"请输入要录入的人数:"<<endl;              //录入的人数为Total 
	cin>>total;

	if(ofs)
	{
	for(i=1;i<=total;i++)                //为每个同学输入信息 
	{
		cout<<"请输入第"<<i<<"个同学的姓名:";
		cin>>a;
		student[i].name=a;	
		ofs<<"姓名:"<<student[i].name<<" ";
		cout<<"请输入第"<<i<<"个同学的学号:";
		cin>>b;
	    student[i].number=b;
        ofs<<"学号:"<<student[i].number<<" ";
	    
		cout<<"请输入第"<<i<<"个同学的宿舍号:";
		cin>>c;
		student[i].domenumber=c;
		ofs<<"房号:"<<student[i].domenumber<<endl;
	
		cout<<endl;
		ofs.close();
	}
		
	}
}

int bin_search(int left,int right,int key)      //递归二分法，折半查询            返回的是关键字的下标
{
	if(left>right)
		return -1;
	int mid=(left+right)/2;
	if(student[mid].number==key)    //刚好要查找的对象key在mid这个位置，查找成功
		return mid;
	else if(student[mid].number<key)
		//left=mid+1;
		return bin_search(mid+1,right,key);   //查找范围缩小到右半部分
	else
        return bin_search(left,mid-1,key);     //查找范围缩小到左半部分
}

void sortmenu()               //排序函数 
{
	string choice;
	int i,j;
	system("cls");
	cout<<"请输入排序的方式(1.按学号排序，2.按寝室号排序，3.按姓名排序):"<<endl;
	while(1)
	{
		cin>>choice;
		break;
	}
    if(choice[0]=='1')                     //进行以学号为关键字的排序 
	{
		for(i=1;i<=total;i++)             //用冒泡排序法进行排序 
	      for(j=1;j<total-i+1;j++)
			  if(student[j].number>=student[j+1].number)
			  {
				  edg temp;
				  temp=student[j];
				  student[j]=student[j+1];
				  student[j+1]=temp;
			  }
			  cout<<"姓名\t\t学号\t\t宿舍号"<<endl;
			  for(i=1;i<=total;i++)
			  {
				  cout<<student[i].name<<"\t\t"<<student[i].number<<"\t\t"<<student[i].domenumber<<endl;
			  }
		cout<<endl;	  
	}
	
	if(choice[0]=='2')                    //以按宿舍号的关键字进行排序 
	{
    	for(i=1;i<=total;i++)
	      for(j=1;j<total-i+1;j++) 
			  if(student[j].domenumber>=student[j+1].domenumber)
			  {
				  edg temp;
				  temp=student[j];
				  student[j]=student[j+1];
				  student[j+1]=temp;
			  }
			  cout<<"姓名\t\t学号\t\t宿舍号"<<endl;
			  for(i=1;i<=total;i++)
			  {
				  cout<<student[i].name<<"\t\t"<<student[i].number<<"\t\t"<<student[i].domenumber<<endl;
			  }
			  cout<<endl;
	}

    if(choice[0]=='3')                             //以按学生姓名的关键字进行排序 
	{
		for(i=1;i<=total;i++)
	      for(j=1;j<total-i+1;j++)
			  if(student[j].name>=student[j+1].name)
			  {
				  edg temp;
				  temp=student[j];
				  student[j]=student[j+1];
				  student[j+1]=temp;
			  }
			  cout<<"姓名\t\t学号\t\t宿舍号"<<endl;
			  for(i=1;i<=total;i++)
			  {
				  cout<<student[i].name<<"\t\t"<<student[i].number<<"\t\t"<<student[i].domenumber<<endl;
			  }
			  cout<<endl;
	}
	
	
}

edg query()    //查询
{
	string choice;
	int i;
	string a,choice1;       //a表示name
	int b,c;                //b,c表示学号和宿舍房号
	system("cls");
	cout<<"请输入查询的方式(1.按姓名查询，2.按学号查询，3.按房号查询):"<<endl;

	while(1)
	{	
	
		
    	while(1)                       
	{
		cin>>choice;
	   break;
	}
		
	if(choice[0]=='1')
	{
		cout<<"请输入你要查找的学生姓名:";               //以按 姓名为关键字进行查找 
		cin>>a;
		for(i=1;i<=total;i++)
		{
			if(strcmp(student[i].name.c_str(),a.c_str())==0)   //c_str返回当前的字符串的首地址，c_str()把string对象转换成c中的字符串样式
				s[i]=student[i];
			  break;
		}
	     if(i!=total+1)
		{
			cout<<"要查找的学生的学号:"<<student[i].number<<"\t\t"<<"宿舍号:"<<student[i].domenumber<<endl;
			cout<<"是否继续进行此操作？(进行则按s,不进行则按b)";
			cin>>choice1;
			if(choice1[0]=='s')
			{
				cout<<"请输入要查找的方式(1.按姓名查询，2.按学号查询，3.按房号查询):"<<endl;
				continue;
			}
			else
				break;
		}
		else
		{
			cout<<"你要查找的学生不在名单中，是否继续进行此操作？(进行则按s,不进行则按b)";
				cin>>choice1;
			if(choice1[0]=='s')
			{
				cout<<"请输入要查找的方式(1.按姓名查询，2.按学号查询，3.按房号查询):"<<endl;
				continue;
			}
			else
				break;
		}
	   			
		
	}
	if(choice[0]=='2')
	{
		cout<<"请输入你要查找的学生的学号:";              //以按 学号为关键字进行查找 
		cin>>b;
		//int len=b.size();    //b.length为字符串b的长度，b.size()为字符串b的元素个数
		if(bin_search(1,total,b)!=-1)             //b为关键字   //使用二分的方法来找到位置，若return结果为-1则表示学号没有录入系统中 
		{
             s[i]=student[bin_search(1,total,b)];
			cout<<"要查找的学生姓名为:"<<student[bin_search(1,total,b)].name<<"\t\t"<<"宿舍号为:"<<student[bin_search(1,total,b)].domenumber<<endl;
			cout<<"是否继续进行此操作？(进行则按s,不进行则按b)";
			cin>>choice1;
			if(choice1[0]=='s')
			{
				cout<<"请输入要查找的方式(1.按姓名查询，2.按学号查询，3.按房号查询):"<<endl;
				continue;
			}
			else
				break;
		}
		else
		{
			cout<<"你要查找的学生不在名单中,是否继续进行此操作？(进行则按s,不进行则按b)";
			cin>>choice1;
			if(choice1[0]=='s')
			{
				cout<<"请输入要查找的方式(1.按姓名查询，2.按学号查询，3.按房号查询):"<<endl;
				continue;
			}
	    	else
				break;
		}
	}
	if(choice[0]=='3')                            //以按 宿舍号为关键字进行查找 
	{
		cout<<"请输入你要查找的学生的房号:";
		cin>>c;
		for(i=1;i<=total;i++)
		{
			if(c==student[i].domenumber)
			{
				s[i]=student[i];
				cout<<"学生姓名:"<<student[i].name<<"\t"<<"学号："<<student[i].number<<"\t"<<"寝室号:"<<student[i].domenumber<<endl;
			}
	   
		}
		       cout<<endl;
			   cout<<"是否继续进行此操作？(进行则按s,不进行则按b)";
			   cin>>choice1;
		       if(choice1[0]=='s')
			   {
				  cout<<"请输入要查找的方式(1.按姓名查询，2.按学号查询，3.按房号查询):"<<endl;
				  continue;
			   }
			   else
		         break;
	}
	
	}
	return s[i];
}

void print()
{
	int i;
	for(i=1;i<=total;i++)
	{ 
		edg ss[Max];
		ss[i]=query();
		cout<<"输出已查询到的学生信息："<<endl;
		cout<<"学生姓名:"<<s[i].name<<"\t"<<"学号："<<s[i].number<<"\t"<<"寝室号:"<<s[i].domenumber<<endl;
	}
  
}

int main()
{

	string choice,i;
	ofstream ofs;
	ofs.open("d:\\my.txt",ios::out);
	menu();
	while(1)
	{
		cin>>choice;
	if(choice[0]=='1')
	{
		build();
		cout<<"新建学生信息成功，是否进行下一步(是则按s,不是则按b)";
		cin>>choice;
		if(choice[0]=='s')
		{
			system("cls");
			menu();
		}
		else
			break;
	}
	else if(choice[0]=='2')
	{
		sortmenu();
		cout<<"学生信息排序成功,是否进行下一步(是则按s,不是则按b)";
		cin>>choice;
		if(choice[0]=='s')
		{
			system("cls");
			menu();
		}
		else
			break;
	}
	else if(choice[0]=='3')
	{
		query();
		cout<<"学生信息查询成功,是否进行下一步(是则按s,不是则按b)";
		cin>>choice;
		if(choice[0]=='s')
		{
			system("cls");
			menu();
		}
		else
			break;
	}
	else if(choice[0]=='4')
	{
		print();
		cout<<"学生信息打印成功,是否进行下一步(是则按s,不是则按b)";
		cin>>choice;
	    if(choice[0]=='s')
		{
			system("cls");
			menu();
		}
		else
			break;

	}
	else
	{
		cout<<"退出系统!"<<endl;
		break;
	}
	}
	return 0;
}


































