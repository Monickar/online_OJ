const express = require('express');				//引入 express 框架 - 前后端沟通
const fs = require('fs');						//引入 fs ，对系统进行文件读取
const exec = require('child_process').execSync;	//引入 'child_process' ，为运行脚本
const exec2 = require('child_process').execSync;
var app = express();
//app.use(express.json());
app.use(express.urlencoded({ extended:true }));
var bodyParser = require('body-parser') // 引入中间件

app.get('/server',(request, response)=>{		//get请求（暂时不看）
	response.setHeader('Access-Control-Allow-Origin','*');
	response.send('hello , wait for you long time!');
});
// app.get('/1.html',function(req,res) {
// 	res.render('1.html');
// });
app.post('/server',(request,response)=> {		//post 请求 ，request 为前端发来的内容
	response.setHeader('Access-Control-Allow-Origin','*');// 设置请求头


	//response.send(' true ');

	var content_data;	//定义变量

	content_data = String(request.body.ans);//将前端的内容进行 格式串 化
	content_data.toString();

	//创建一个 ’content.cpp’的文件，并把内容写进这个文件
	fs.writeFile('content.cpp', content_data, err => {
		if(err) {
			console.error(err)//如果错误就报错
			return
		}
	})

    setTimeout(() => {//设置一个 定时器，0.5s后执行，防止没来得及编译的情况发生
    exec('zsh start.sh'); //执行当前目录下 名叫’pre.sh'的脚本
}, 500)

	var data2;			//定义一个 data2 来放 编译结果
	setTimeout(() =>{
	 data2 = fs.readFileSync('cmpans.txt'); // 将 ’cmpans.txt’文件中的内容拿出给到data2

	},800)
	setTimeout(() => {
		data2.toString();
		response.send(data2); //把编译结果返回给前端
		exec2('zsh 2.sh');//执行 ’2.sh’的脚本
	},1000)
});

app.listen(8000,()=>{		//打开 8000 端口
	console.log("服务启动，8000端口监听中。。。");
});
