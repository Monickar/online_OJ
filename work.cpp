#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(void) {
	FILE* fp;
	char buffer[1024];

	sprintf(buffer,"./pre.sh");
	fp = popen(buffer,"r");//执行当前目录下 pre.sh 的脚本
	pclose(fp);

	ifstream myfile("./ex.txt"); //客户编译的结果
	ifstream input("./ans.txt"); //正确答案
	ofstream outfile("./cmpans.txt") //对比的结果
	string tmp1, tmp2;				

	if(!=myfile.is_open())
	{
		printf("open falut");	//如果 ex.txt不存在
		outfile<<"WA";			//直接报错
		return 0;
	}
	bool judge = true;
	while(getline(myfile,tmp1) && getline(input,tmp2))
	{
		int jud = tmp1.compare(tmp2);	//和正确答案进行对比
		if(!jud) judge = false;
	}
	if (judge) outfile<<"AC";		//如果全对，就在 cmp.txt 里输入结果
	else outfile<<"WA";
		

	return 0;
}
