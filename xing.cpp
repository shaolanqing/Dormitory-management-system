#include<cstdio>
#include<string>
#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
#define Max 100
 int total;  
struct edg                                //����ṹ�壬����ѧ����Ϣ�Ľṹ�����飬���е���Ϣ�������֣����᷿���Լ�ѧ�� ��
{
	string name;
	int number;
	int domenumber;
}student[Max];
edg s[Max];
void menu()                                          //���˵��ĺ�������3�����ܣ��½������򣬲�ѯ,��ӡ��
{
	cout<<"\t\t **********************************"<<endl;
	cout<<"\t\t       * ��ӭ�����������ϵͳ*     "<<endl;
	cout<<"\t\t **********************************"<<endl;
	cout<<"\t\t         * 1.�½��������� *        "<<endl;
	cout<<"\t\t         * 2.����������Ϣ *        "<<endl;
	cout<<"\t\t         * 3.��ѯ������Ϣ *        "<<endl;
	cout<<"\t\t         * 4.��ӡ�����ѯ��� *    "<<endl;
	cout<<"\t\t         * 0.�˳�ϵͳ *            "<<endl;
    cout<<"\t\t **********************************"<<endl;
	cout<<endl<<endl;
	cout<<"����������Ҫ���в��������:";
}

void build()                           //�½�ѧ����Ϣ 
{
	int i;
	string a;
	int b,c;
	system("cls");
	ofstream ofs;   //�������
	ofs.open("d:\\my.txt",ios::app);	 //׷�ӽ��ļ���
	cout<<"������Ҫ¼�������:"<<endl;              //¼�������ΪTotal 
	cin>>total;

	if(ofs)
	{
	for(i=1;i<=total;i++)                //Ϊÿ��ͬѧ������Ϣ 
	{
		cout<<"�������"<<i<<"��ͬѧ������:";
		cin>>a;
		student[i].name=a;	
		ofs<<"����:"<<student[i].name<<" ";
		cout<<"�������"<<i<<"��ͬѧ��ѧ��:";
		cin>>b;
	    student[i].number=b;
        ofs<<"ѧ��:"<<student[i].number<<" ";
	    
		cout<<"�������"<<i<<"��ͬѧ�������:";
		cin>>c;
		student[i].domenumber=c;
		ofs<<"����:"<<student[i].domenumber<<endl;
	
		cout<<endl;
		ofs.close();
	}
		
	}
}

int bin_search(int left,int right,int key)      //�ݹ���ַ����۰��ѯ            ���ص��ǹؼ��ֵ��±�
{
	if(left>right)
		return -1;
	int mid=(left+right)/2;
	if(student[mid].number==key)    //�պ�Ҫ���ҵĶ���key��mid���λ�ã����ҳɹ�
		return mid;
	else if(student[mid].number<key)
		//left=mid+1;
		return bin_search(mid+1,right,key);   //���ҷ�Χ��С���Ұ벿��
	else
        return bin_search(left,mid-1,key);     //���ҷ�Χ��С����벿��
}

void sortmenu()               //������ 
{
	string choice;
	int i,j;
	system("cls");
	cout<<"����������ķ�ʽ(1.��ѧ������2.�����Һ�����3.����������):"<<endl;
	while(1)
	{
		cin>>choice;
		break;
	}
    if(choice[0]=='1')                     //������ѧ��Ϊ�ؼ��ֵ����� 
	{
		for(i=1;i<=total;i++)             //��ð�����򷨽������� 
	      for(j=1;j<total-i+1;j++)
			  if(student[j].number>=student[j+1].number)
			  {
				  edg temp;
				  temp=student[j];
				  student[j]=student[j+1];
				  student[j+1]=temp;
			  }
			  cout<<"����\t\tѧ��\t\t�����"<<endl;
			  for(i=1;i<=total;i++)
			  {
				  cout<<student[i].name<<"\t\t"<<student[i].number<<"\t\t"<<student[i].domenumber<<endl;
			  }
		cout<<endl;	  
	}
	
	if(choice[0]=='2')                    //�԰�����ŵĹؼ��ֽ������� 
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
			  cout<<"����\t\tѧ��\t\t�����"<<endl;
			  for(i=1;i<=total;i++)
			  {
				  cout<<student[i].name<<"\t\t"<<student[i].number<<"\t\t"<<student[i].domenumber<<endl;
			  }
			  cout<<endl;
	}

    if(choice[0]=='3')                             //�԰�ѧ�������Ĺؼ��ֽ������� 
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
			  cout<<"����\t\tѧ��\t\t�����"<<endl;
			  for(i=1;i<=total;i++)
			  {
				  cout<<student[i].name<<"\t\t"<<student[i].number<<"\t\t"<<student[i].domenumber<<endl;
			  }
			  cout<<endl;
	}
	
	
}

edg query()    //��ѯ
{
	string choice;
	int i;
	string a,choice1;       //a��ʾname
	int b,c;                //b,c��ʾѧ�ź����᷿��
	system("cls");
	cout<<"�������ѯ�ķ�ʽ(1.��������ѯ��2.��ѧ�Ų�ѯ��3.�����Ų�ѯ):"<<endl;

	while(1)
	{	
	
		
    	while(1)                       
	{
		cin>>choice;
	   break;
	}
		
	if(choice[0]=='1')
	{
		cout<<"��������Ҫ���ҵ�ѧ������:";               //�԰� ����Ϊ�ؼ��ֽ��в��� 
		cin>>a;
		for(i=1;i<=total;i++)
		{
			if(strcmp(student[i].name.c_str(),a.c_str())==0)   //c_str���ص�ǰ���ַ������׵�ַ��c_str()��string����ת����c�е��ַ�����ʽ
				s[i]=student[i];
			  break;
		}
	     if(i!=total+1)
		{
			cout<<"Ҫ���ҵ�ѧ����ѧ��:"<<student[i].number<<"\t\t"<<"�����:"<<student[i].domenumber<<endl;
			cout<<"�Ƿ�������д˲�����(������s,��������b)";
			cin>>choice1;
			if(choice1[0]=='s')
			{
				cout<<"������Ҫ���ҵķ�ʽ(1.��������ѯ��2.��ѧ�Ų�ѯ��3.�����Ų�ѯ):"<<endl;
				continue;
			}
			else
				break;
		}
		else
		{
			cout<<"��Ҫ���ҵ�ѧ�����������У��Ƿ�������д˲�����(������s,��������b)";
				cin>>choice1;
			if(choice1[0]=='s')
			{
				cout<<"������Ҫ���ҵķ�ʽ(1.��������ѯ��2.��ѧ�Ų�ѯ��3.�����Ų�ѯ):"<<endl;
				continue;
			}
			else
				break;
		}
	   			
		
	}
	if(choice[0]=='2')
	{
		cout<<"��������Ҫ���ҵ�ѧ����ѧ��:";              //�԰� ѧ��Ϊ�ؼ��ֽ��в��� 
		cin>>b;
		//int len=b.size();    //b.lengthΪ�ַ���b�ĳ��ȣ�b.size()Ϊ�ַ���b��Ԫ�ظ���
		if(bin_search(1,total,b)!=-1)             //bΪ�ؼ���   //ʹ�ö��ֵķ������ҵ�λ�ã���return���Ϊ-1���ʾѧ��û��¼��ϵͳ�� 
		{
             s[i]=student[bin_search(1,total,b)];
			cout<<"Ҫ���ҵ�ѧ������Ϊ:"<<student[bin_search(1,total,b)].name<<"\t\t"<<"�����Ϊ:"<<student[bin_search(1,total,b)].domenumber<<endl;
			cout<<"�Ƿ�������д˲�����(������s,��������b)";
			cin>>choice1;
			if(choice1[0]=='s')
			{
				cout<<"������Ҫ���ҵķ�ʽ(1.��������ѯ��2.��ѧ�Ų�ѯ��3.�����Ų�ѯ):"<<endl;
				continue;
			}
			else
				break;
		}
		else
		{
			cout<<"��Ҫ���ҵ�ѧ������������,�Ƿ�������д˲�����(������s,��������b)";
			cin>>choice1;
			if(choice1[0]=='s')
			{
				cout<<"������Ҫ���ҵķ�ʽ(1.��������ѯ��2.��ѧ�Ų�ѯ��3.�����Ų�ѯ):"<<endl;
				continue;
			}
	    	else
				break;
		}
	}
	if(choice[0]=='3')                            //�԰� �����Ϊ�ؼ��ֽ��в��� 
	{
		cout<<"��������Ҫ���ҵ�ѧ���ķ���:";
		cin>>c;
		for(i=1;i<=total;i++)
		{
			if(c==student[i].domenumber)
			{
				s[i]=student[i];
				cout<<"ѧ������:"<<student[i].name<<"\t"<<"ѧ�ţ�"<<student[i].number<<"\t"<<"���Һ�:"<<student[i].domenumber<<endl;
			}
	   
		}
		       cout<<endl;
			   cout<<"�Ƿ�������д˲�����(������s,��������b)";
			   cin>>choice1;
		       if(choice1[0]=='s')
			   {
				  cout<<"������Ҫ���ҵķ�ʽ(1.��������ѯ��2.��ѧ�Ų�ѯ��3.�����Ų�ѯ):"<<endl;
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
		cout<<"����Ѳ�ѯ����ѧ����Ϣ��"<<endl;
		cout<<"ѧ������:"<<s[i].name<<"\t"<<"ѧ�ţ�"<<s[i].number<<"\t"<<"���Һ�:"<<s[i].domenumber<<endl;
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
		cout<<"�½�ѧ����Ϣ�ɹ����Ƿ������һ��(����s,������b)";
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
		cout<<"ѧ����Ϣ����ɹ�,�Ƿ������һ��(����s,������b)";
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
		cout<<"ѧ����Ϣ��ѯ�ɹ�,�Ƿ������һ��(����s,������b)";
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
		cout<<"ѧ����Ϣ��ӡ�ɹ�,�Ƿ������һ��(����s,������b)";
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
		cout<<"�˳�ϵͳ!"<<endl;
		break;
	}
	}
	return 0;
}


































