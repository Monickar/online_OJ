import xlwings as xw
import os
#app1 = xw.App(visible=True,add_book=False)
#app = xw.App()

filepath='./data.xlsx'
wb=xw.App(visible=True,add_book=False).books.open(filepath)
#wb=app1.books.open(filepath)

gcc_commond = open('gcc_commond.txt','r')
list1 = []
for line in gcc_commond.readlines():
	line = line.strip()
	list1.append(line)

#获取成绩
score=0
gcc_commond = open('grade1.txt','r')
for line in gcc_commond.readlines():
	line = line.strip()
	score = int(line)


#count_record 和 name_record 分别代表 次数 和 姓名
name_record = list1[1]
count_record = int(list1[2]) 
print(name_record)
sht = wb.sheets['sheet1']

num_count = 0
for x in range(2,31):
	cell = 'A' + str(x)
#	print(sht.range(cell).value)
	if (str(sht.range(cell).value) == str(name_record)):
		num_count = x
		print("find it!!!")
		print(num_count)
		break

count_record += 65 #转换成 ascill
tar = chr(count_record)
tar = tar + str(num_count)
print(tar)
sht.range(tar).value = str(score)


wb.save()
wb.close()
app.quit()
