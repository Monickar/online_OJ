#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string t,ans,ans2;
	ofstream ofs;//用以记录成绩
	int g=100;//每组成绩参数
	int i;
	//freopen("out.txt","r",stdin);//打开out1文件
	freopen("./temp/out.txt","r",stdin);//打开out1文件
	char c;
	while(scanf("%c",&c)!=EOF) 
	if(c!='\n')
		ans+=c;//记录文件中除了回车之外的字符
	fclose(stdin);
	freopen("./ans/ans.txt","r",stdin);
	while(scanf("%c",&c)!=EOF) 
	if(c!='\n')
			ans2+=c;//记录答案文件中除了回车之外的字符
	fclose(stdin);
	
	ofs.open("./grade1.txt",ios::out | ios::trunc);
	if(ans.size()!=ans2.size())
		{
			ofs<<"0"<<endl;
			return 0;
		}//答案大小不同，直接判错
	for(i=0;i<ans.size();i++)
	{	
		if(ans[i]!=ans2[i])
			{
				ofs<<"0"<<endl;
				return 0;
			}//判断内容是否一致
	}
	ofs<<g<<endl;
	return 0;
}
