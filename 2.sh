#!bin/zsh
rm content.cpp  ex.txt #删除 编译的文件
if [ -f "a.out" ]; then
    rm a.out
elif [ -f "work.out" ]; then
    rm work.out
fi
