## 语言说明
**Luogu 3.0++**（确定性三栈洛谷自动机，Deterministic Luogu Automaton with Three Stacks）是上海洛谷网络科技有限公司于 2021 年推出的计算机语言。

[Luogu 3.0++ 语言用户手册（上）——语法基础](docs/1.md)by [小粉兔](https://www.luogu.com.cn/user/10703)

[Luogu 3.0+++ 语言用户手册（下）——扩展状态类型集](docs/2.md)by [小粉兔](https://www.luogu.com.cn/user/10703)

## 解释器说明
使用方式：命令行
格式`luogu++ fileplace`
解释器会自动找到`.lgpp`源代码和`.in`栈初始化（可以没有），生成输出至`.out`

`.in`格式：
```in
A data0 data1 ... datan
C data0 data1 ... datam
```
其中data0\~datan按从**栈底**到**栈顶**的顺序

`.out`中的data0\~datan按从**栈顶**到**栈底**顺序
例子：
```
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
