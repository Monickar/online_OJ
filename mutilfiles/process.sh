#!/bin/zsh
#创建 temp 文件夹(保证temp一直存在) 并在 文件夹内解压文件,
#修改123
if not [ -f  "temp" ];then
    mkdir temp
fi
cp -r ../static/files/* ./temp/
cd ./temp/
mv *.zip target.zip
unzip  target.zip
rm -rf target.zip
#cd ./temp/
rm -rf __MACOSX 
rm -rf .DS_Store
# 执行 cpl 脚本  进行多文件的编译的准备
cd ../
python3 cpl.py
echo "hahah"
#获取 g++指令
num=1
array_me=(1 2 3 9 10)
gcc_cc="1"
cat gcc_commond.txt | while read line
do
    array_me[$num]=$line
    echo $array_me[$num]
    let num+=1
done
#    if [$num == 0]
#     $gcc_cc = $line
#执行 g++ 指令

echo `pwd`
echo ${array_me[4]}>mid.sh
echo ${array_me[1]}>>mid.sh
chmod +x mid.sh
./mid.sh
echo "before cpl"
echo `pwd`
cd ${array_me[5]}
input1="${array_me[3]}.txt"

if [ -f "a.out" ];then
	cat ../../input/$intput1|./a.out>../out.txt # 编译结果放在 out 文件中
fi

# 和答案进行对比
cd ../../
echo `pwd`
g++ judge.cpp -o b.out
./b.out
# 执行 xlsx 脚本  进行成绩的录入
echo `pwd`
python3 xlsx.py


rm -rf temp b.out gcc_commond.txt
#删除编译的文件
#rm  ./temp/* a.out b.out gcc_commond.txt
#

