#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string t,ans,ans2,ans3;
	ofstream ofs;//���Լ�¼�ɼ�
	int g=50;//ÿ��ɼ�����
	int out=0,j=0;//��¼�ɼ�
	int i;
	char c;
	freopen("out1.txt","r",stdin);//��out1�ļ�
	while(scanf("%c",&c)!=EOF) 
	if(c!='\n')
		ans+=c;//��¼�ļ��г��˻س�֮����ַ�
	fclose(stdin);
	freopen("ans1.txt","r",stdin);
	while(scanf("%c",&c)!=EOF) 
	if(c!='\n')
		ans2+=c;//��¼���ļ��г��˻س�֮����ַ�
	fclose(stdin);
	freopen("ans2.txt","r",stdin);
	while(scanf("%c",&c)!=EOF) 
	if(c!='\n')
		ans3+=c;
	ofs.open("grade2.txt",ios::out | ios::trunc);
	if(ans.size()!=ans2.size()+ans3.size())
		{
			ofs<<"�ļ������ʽ����ȷ"<<endl;
			return 0;
		}//�𰸴�С��ͬ��ֱ���д�
	for(i=0;i<ans2.size();i++)
	{	
		if(ans[i]!=ans2[i])
			{
				j=-1;
				break;
			}//�𰸲�ͬ��ֱ���д�
	}
	if(j!=-1)
		out+=g;//��¼��һ�����
		j=0;
	for(i=ans2.size();i<ans3.size()+ans2.size();i++)
		{	
			if(ans[i]!=ans3[i-ans2.size()])
				{
					j=-1;
					break;
				}//�жϵڶ��������Ƿ�һ��
		}
		
	if(j!=-1)
		out+=g;
	ofs<<"�ɼ�Ϊ"<<out<<endl;
	return 0;
}
