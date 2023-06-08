#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
    while(b != 0)
    {
        int r = b;
        b = a%b;
        a = r;
    }
    return a;
} 
int math(int a)
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
	int matrix[2][2];//matrix[2][2]Ϊ���ܾ���
	int dt,p,len;//dtΪ����ʽ��ֵ��flag�������ģ����ȵ���ż��־��0Ϊż����1Ϊ����
	cout<<"���������ĳ���:";
	cin>>len;
	cout<<'\n'<<"����������:";
	char *pla=new char[len];//plazָ���û���������ģ�26����ĸ���)
	int *tran1=new int[len];//tran1ָ�����Ķ�Ӧ��������ɵ�����
	char *ciph=new char[len];//ciphָ������
	int *s=new int[len];//sָ��������������
	for(int i=0;i<len;i++)
		cin>>pla[i];
	//�������һ����ģΪ26����Ķ��׾���
	do
	{
		matrix[0][0]=rand()%26;
		matrix[0][1]=rand()%26;
		matrix[1][0]=rand()%26;
		matrix[1][1]=rand()%26;
		dt = -1;
		for(p=1; dt < 0; p++)
		{
			dt = ((matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) + 26 * p)%26; //����ʽ��ֵ 
		}
	}while(dt%2==0||dt%13==0);
	cout<<'\n'<<"���ܾ���Ϊ��"<<'\n'<<matrix[0][0]<<'\t'<<matrix[0][1]<<'\n'<<matrix[1][0]<<'\t'<<matrix[1][1]<<'\n';
	//�ж��������ĵĳ����Ƿ�Ϊż��
	if(len % 2 == 1) 
	 {
		pla[len] = 'a';
		len = len+1;
	 }
	//�����������ĸת��Ϊ��Ӧ�����֣�Ҫ���ִ�Сд,��д��ĸҪ��ת��ΪСд��ĸ)
	for(i=0; i<len; i++)
	{
		if(pla[i] >= 'A' && pla[i] <= 'Z')
		{
			pla[i] = pla[i] + 32;
		}
		if(pla[i] >= 'a' && pla[i] <'z')
			tran1[i]=pla[i]-'a'+1;
		else
			tran1[i]=0;
	}
	//������Ϊһ�飬һ�μ���
	for(i=0; i<len; i=i+2)
	{
		s[i]=(tran1[i]*matrix[0][0]+tran1[i + 1]*matrix[0][1])%26;
		s[i + 1] = (tran1[i] *matrix[1][0] + tran1[i + 1] * matrix[1][1]) % 26;
    }
	//�Ѽ��ܺ����������ת��Ϊ��ĸ�������ִ�Сд��
	cout<<"����:"<<'\n';
	for(i=0; i<len; i++)
	{
		if(s[i]!=0)
			ciph[i] = s[i] + 'a'-1;
		else ciph[i]='z';
		cout<<(char)ciph[i]<<'\t';
	}

	//��������
	int det = -1,invdet;//invdetΪ���ܾ���ģ�ĵ���
	int matrix2[2][2];//matrix2[2,2]Ϊ���ܾ���
	int *mes=new int[len];//mesָ����ܺ�����Ķ�Ӧ����������
	char *ciph2=new char[len];//ciph2ָ����ܺ������
    /*for(i=0; det < 0; i++)
	{
		det = ((matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0])+i*26)%26;
	}
	i=1;*/
	while(i++)
	{
		if((dt*i)%26==1)
		{
			invdet=i;	
			break;
		}
	}
    /*i = 1;
    while(1)
	{
		if((det * i) % 26 == 1)
		{
			invdet=i;
			break;
        }
		else
			i++;
	}*/
	//�����
    int temp=(matrix[1][1]*invdet);
	matrix2[0][1]=(-1 * matrix[0][1]) * invdet;
    matrix2[1][0]=(-1 * matrix[1][0]) * invdet;
    matrix2[1][1]=(matrix[0][0]*invdet);
	matrix2[0][0]=temp;
	matrix2[0][0]=math(matrix2[0][0]);
	matrix2[0][1]=math(matrix2[0][1]);
	matrix2[1][0]=math(matrix2[1][0]);
	matrix2[1][1]=math(matrix2[1][1]);
    // �õ����ܺ���
	cout<<'\n'<<"���ܾ���:"<<'\n'<<matrix2[0][0]<<'\t'<<matrix2[0][1]<<'\n'<<matrix2[1][0]<<'\t'<<matrix2[1][1]<<'\n';
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
