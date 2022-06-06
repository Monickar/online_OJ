import os
import shutil


#记录 解压后文件的目录
path = './temp/'
file = os.listdir(path)

#需要记录的参数 name_record 为姓名 count_record 为第几次
name_record =""
count_record = 0
tar_file = ""

# 获取解压文件的准确目录 （解压可能产生副目录 05-05-xxx ['05','05','xxx']
for f in file:
	
	if (name_record != "__MACOSX" and name_record != ".DS_Store"):
		name_record = f.split('-')[-1]	#xxx
		count_record = f.split('-')[1]  #第几次
		tar_file = f
#		print(tar_file)

# 进入准确目录
path = "./temp/" + tar_file 
files = os.listdir(path)
list0 = []	#记录 cpp 文件名
list1 = []  #记录 .h 文件名

for f in files:
	#获取 拓展名

	file_name = f.split('.')[-1]
	
	if file_name == 'h':
		list1.append(f)
	elif file_name == "cpp":
		list0.append(f)
#	print(f)
#完善 g++ 指令
str1 = "g++ "
for x in list0:
	str1 = str1 + x + " "
str1 = str1 + "-include "
for x in list1:
	str1 = str1 + x + " "
str1 = str1 + "-o a.out"
#print(str)
#保存相关 指令和数据 到 txt 文件中
#print(count_record)
gcc_commond = open('gcc_commond.txt','w+')
step1 = gcc_commond.write(str1 + '\n')
step2 = gcc_commond.write(name_record + '\n')

str2 = str(count_record)
step3 = gcc_commond.write(str2 + '\n')
path =  path + "/"
step4 = gcc_commond.write("cd " + path + '\n')
step5 = gcc_commond.write(path + '\n')
