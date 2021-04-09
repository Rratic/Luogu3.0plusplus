## 语言说明
[见此](versions.md)
## 解释器说明
使用方式：命令行
格式`luogu++ [参数] 文件位置`
解释器会自动找到`.lgpp`源代码和`.in`栈初始化（可以没有），生成输出至`.out`

`.in`格式：
```in
A data0 data1 ... datan
B data0 data1 ... datan
C data0 data1 ... datan
```
其中data0 ... datan默认按从**栈底**到**栈顶**的顺序

`.out`中的data0 ... datan默认按从**栈顶**到**栈底**顺序
例子：
```shell
D:/code/cat.in
|A 3 4 5

D:/code/cat.lgpp
|1 1
|TER

shell>luogu++ D:/code/cat

...a few seconds later...

D:/code/cat.out
|A 5 4 3
```
[参数说明见此](args.md)
