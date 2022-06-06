#!bin/zsh
g++ content.cpp -o a.out
# 编译 .cpp文件 并生成可执行文件
if [ -f "a.out" ];then  #如果 可执行文件存在
    ./a.out > ex.txt    #把结果放到 ex.txt文件中

fi
#./a.out > ex.txt
