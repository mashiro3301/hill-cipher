#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define N 4//Ĭ����֪�ĸ�������ĸ�����Ӧ�İ�����ĸ�������ĸ������Ը��࣬Ȼ��ÿ�ĸ�Ϊһ�飩
int math(int a)//�ú������ڽ�һ��������ΪģΪ26ʱ��Ӧ����
{
	if(a<0)
	{
		for(int i=1;;i++)
		{
			a=a+26;
			if(a>=0&&a<26)
				break;
		}
	}
	else
		for(int i=0;;i++)
		{
			if(a>=0&&a<26)
				break;
				a=a-26;
		}

		return a;
}
int main()
{
	int invdet,det,det1,invdet1;//det��invdet�ֱ������ľ��������ʽ��ֵ����ֵ��ģ26�µĵ�����det1��invdet1�Ǽ��ܾ��������ʽ��ֵ����ֵ��ģ26�µĵ���
	int matrix[2][2];//matrix[2][2]Ϊ���ܾ���
	int matrix2[2][2];//matrix2[2,2]Ϊ���ܾ���
	char *m=new char[N];//mָ����֪������
	char *n=new char[N];//nָ���Ӧ�İ���
	int *mm=new int[N];//mָ�����Ķ�Ӧ����������
	int *nn=new int[N];//nָ�����Ķ�Ӧ����������
	cout<<"���û�������֪�����ĺͶ�Ӧ�İ���"<<endl;
	cout<<"����:"<<endl;
	cin>>m;
	cout<<"����:"<<endl;
	cin>>n;
	//�����ĺͰ��Ļ��ɶ�Ӧ���������飬�ֱ�洢��mm��nnָ��Ŀռ�
	for(int i=0; i<N; i++)
	{
		if(m[i] >= 'A' && m[i] <= 'Z')
		{
			m[i] = m[i] + 32;
		}
		if(m[i] >= 'a' && m[i] <'z')
			mm[i]=m[i]-'a'+1;
		else
			mm[i]=0;
	}
	for(i=0; i<N; i++)
	{
		if(n[i] >= 'A' && n[i] <= 'Z')
		{
			n[i] = n[i] + 32;
		}
		if(n[i] >= 'a' && n[i] <'z')
			nn[i]=n[i]-'a'+1;
		else
			nn[i]=0;
	}
	int a=mm[0],b=mm[1],c=mm[2],d=mm[3];
	det=(a*d-b*c);
	for( i=0;det<0||det>=26;i++)
	{
		det=(det+i*26)%26;
	}
	if(det%2==0||det%13==0)
	{
		cout<<"�޷�����";//������������������أ��޷�����
		exit(0);
	}
	i=1;
	while(i++)
	{
		if((det*i)%26==1)
		{
			invdet=i;	
			break;
		}
	}
	//����ܾ���
	int temp=mm[3]*invdet;
	mm[1]=(-1*mm[1])*invdet;
	mm[2]=(-1*mm[2])*invdet;
	mm[3]=mm[0]*invdet;
	mm[0]=temp;
	mm[0]=math(mm[0]);
	mm[1]=math(mm[1]);
	mm[2]=math(mm[2]);
	mm[3]=math(mm[3]);
	matrix[0][0]=nn[0]*mm[0]+nn[2]*mm[1];
	matrix[0][1]=nn[0]*mm[2]+nn[2]*mm[3];
	matrix[1][0]=nn[1]*mm[0]+nn[3]*mm[1];
	matrix[1][1]=nn[1]*mm[2]+nn[3]*mm[3];
	matrix[0][0]=math(matrix[0][0]);
	matrix[0][1]=math(matrix[0][1]);
	matrix[1][0]=math(matrix[1][0]);
	matrix[1][1]=math(matrix[1][1]);
	cout<<'\n'<<"���ܾ���Ϊ��"<<'\n'<<matrix[0][0]<<'\t'<<matrix[0][1]<<'\n'<<matrix[1][0]<<'\t'<<matrix[1][1]<<'\n';
	//����ܾ���
	for(i=0; det1 < 0; i++)
	{
		det1 = ((matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0])+i*26)%26;
	}
	i=1;
	while(i++)
	{
		if((det1*i)%26==1)
		{
			invdet1=i;	
			break;
		}
	}
	int temp1=(matrix[1][1]*invdet1);
	matrix2[0][1]=(-1 * matrix[0][1]) * invdet1;
    matrix2[1][0]=(-1 * matrix[1][0]) * invdet1;
    matrix2[1][1]=(matrix[0][0]*invdet1);
	matrix2[0][0]=temp1;
	matrix2[0][0]=math(matrix2[0][0]);
	matrix2[0][1]=math(matrix2[0][1]);
	matrix2[1][0]=math(matrix2[1][0]);
	matrix2[1][1]=math(matrix2[1][1]);
	 // �õ����ܺ���
	cout<<'\n'<<"���ܾ���:"<<'\n'<<matrix2[0][0]<<'\t'<<matrix2[0][1]<<'\n'<<matrix2[1][0]<<'\t'<<matrix2[1][1]<<'\n';
	cout<<"��������֪�������г��ȼ�����:"<<endl;
	int len;
	cout<<"����:";
	cin>>len;
	char *cip=new char[len];//cipָ������
	cout<<"����:";
	cin>>cip;
	int *s=new int[len];//sָ��������������
	int *mes=new int[len];//mesָ����ܺ�����Ķ�Ӧ����������
	char *ciph2=new char[len];//ciph2ָ����ܺ������
	for(i=0; i<len; i++)
	{
		if(cip[i] >= 'A' && cip[i] <= 'Z')
		{
			cip[i] = cip[i] + 32;
		}
		if(cip[i] >= 'a' && cip[i] <'z')
			s[i]=cip[i]-'a'+1;
		else
			s[i]=0;
	}
	if(len % 2 == 1) 
	 {
		s[len] = 'a';
		len = len+1;
	 }
	for(i=0; i<len; i+=2)
	{
		mes[i] = (s[i] * matrix2[0][0] + s[i + 1] * matrix2[0][1]) % 26;
		mes[i + 1] = (s[i] * matrix2[1][0] + s[i + 1] * matrix2[1][1]) % 26;
	}
	cout<<"����Ϊ:"<<'\n';
	for(i=0; i<len; i++)
	{
		if(mes[i]!=0)
			ciph2[i] =mes[i] + 'a'-1;
		else ciph2[i]='z';
		cout<<(char)ciph2[i]<<'\t';
	}
	return 0;
}




