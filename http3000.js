const koa = require("koa");
const static = require("koa-static");
const Router = require("koa-router");
const express = require('express');
const koabody = require("koa-body");
const fs = require("fs");
const cors = require("koa-cors");
const exec = require('child_process').execSync;
let app = new koa();
let router = new Router();
var score_re = new express();
app.use(static(__dirname+"/static"));
app.use(koabody({
    multipart:true
}));
var score1;
router.post("/upload",(ctx,next)=>{
    // console.log(ctx.request.body);
    console.log(ctx.request.files.obj.originalFilename);


     let filedata = fs.readFileSync(ctx.request.files.obj.filepath);
    fs.writeFileSync("static/files/"+ctx.request.files.obj.originalFilename,filedata);
//    fs.writeFileSync("static/files/target.zip",filedata);

    setTimeout(() => {//设置一个 定时器，0.5s后执行，防止没来得及编译的情况发生
    console.log("waiting...")

    }, 1500)


    setTimeout(() => {//设置一个 定时器，0.5s后执行，防止没来得及编译的情况发生
    exec('cd ./mutilfiles;zsh process.sh'); //执行当前目录下
    }, 1500)
    console.log("step1");
    var data2;			//定义一个 data2 来放 编译结果
	setTimeout(() =>{
//    exec('cp ./mutilfiles/grade1.txt ../grade1.txt');
    data2 = fs.readFileSync('./mutilfiles/grade1.txt'); // 将 ’ex.txt’文件中的内容拿出给到
    score=data2.toString();
    score1=score;

	},2800)
    setTimeout(() => {
//		data2.toString();
        console.log(score);
//		next.send(data2); //把编译结果返回给前端
        exec('cd ./mutilfiles;zsh 2.sh');
	},3800)

    ctx.body = "请求成功";
})
score_re.use(express.urlencoded({ extended:true }));

score_re.get('/upload',(request, response)=>{		//get请求（暂时不看）
	response.setHeader('Access-Control-Allow-Origin','*');

    response.send(score1);
});


app.use(router.routes());
app.use(router.allowedMethods());
score_re.listen(3001)
app.listen(3000);
