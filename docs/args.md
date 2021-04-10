# 参数说明
* -disable-in 不寻找初始化文件
* -disable-out 不生成输出文件
* --mod=n 设置元素求余时所模的数，默认为998244353
* -revin 设置初始化文件栈顶->栈底
* -revout 设置输出文件栈底->栈顶
* --stack=n 设置栈最大容量n，默认100w
* --state=n 设置最大状态数为n，默认10w
* --std=n 设置遵循的标准为n，默认为1
* --t13-base=n 设置`T13`指令的基数为n，默认114514（此值为GitPinkRabbit制订）
* --time-limit=n 设置时间限制n，默认100w
* --txx-cost=n 设置形如`Txx`的指令消耗时间为，默认1w
* --txx-oper=n 设置形如`Txx`的指令所允许的最大操作数为n，默认1w

以上所有参数应在`1~2^31-1`中，尽量不要取极端值

建议参数：
* 纯研究：`--txx-cost=1`
* OnlineJudge：`-disable-in -disable-out --std=2`
