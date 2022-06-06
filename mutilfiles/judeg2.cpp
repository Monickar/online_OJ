#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string t,ans,ans2,ans3;
	ofstream ofs;//用以记录成绩
	int g=50;//每组成绩参数
	int out=0,j=0;//记录成绩
	int i;
	char c;
	freopen("out1.txt","r",stdin);//打开out1文件
	while(scanf("%c",&c)!=EOF) 
	if(c!='\n')
		ans+=c;//记录文件中除了回车之外的字符
	fclose(stdin);
	freopen("ans1.txt","r",stdin);
	while(scanf("%c",&c)!=EOF) 
	if(c!='\n')
		ans2+=c;//记录答案文件中除了回车之外的字符
	fclose(stdin);
	freopen("ans2.txt","r",stdin);
	while(scanf("%c",&c)!=EOF) 
	if(c!='\n')
		ans3+=c;
	ofs.open("grade2.txt",ios::out | ios::trunc);
	if(ans.size()!=ans2.size()+ans3.size())
		{
			ofs<<"文件输出格式不正确"<<endl;
			return 0;
		}//答案大小不同，直接判错
	for(i=0;i<ans2.size();i++)
	{	
		if(ans[i]!=ans2[i])
			{
				j=-1;
				break;
			}//答案不同，直接判错
	}
	if(j!=-1)
		out+=g;//记录第一组分数
		j=0;
	for(i=ans2.size();i<ans3.size()+ans2.size();i++)
		{	
			if(ans[i]!=ans3[i-ans2.size()])
				{
					j=-1;
					break;
				}//判断第二组内容是否一致
		}
		
	if(j!=-1)
		out+=g;
	ofs<<"成绩为"<<out<<endl;
	return 0;
}
