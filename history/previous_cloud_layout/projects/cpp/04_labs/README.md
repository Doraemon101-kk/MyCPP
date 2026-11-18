# 专项实验 跟随课程再打开

这些文件各有自己的main，分别编译，每次只运行一个。不要将整个文件夹里的.cpp一起链接。

| 日期 | 文件 | 完整任务与验收 |
|---|---|---|
| 9/28 | lifetime.cpp | 定义打印名字的构造/析构，预测嵌套作用域中的销毁顺序；对照传值/引用；回到Robot/Grid解释依赖的存活范围 |
| 9/29 | vector_changes.cpp | 删除所有2后为1,3,4；全删/全留/空输入；观察扩容，说明有效索引与失效引用；再迁移到轨迹记录 |
| 10/12 | top_k.cpp | 自写排序与堆两个版本；Top2均为blue:2,red:2；K=0/超量/空/同频；说明复杂度和比较器 |
| 10/14 | template_filter.cpp + filter_template.hpp | 两个具体类型先各自筛选，再抽一个模板；两个输入都通过，原序和原数据不改变；用于文本工具 |

例如编译生命周期实验：

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic -g lifetime.cpp -o lifetime.exe
.\lifetime.exe
```

其余替换对应.cpp文件名。模板的定义补在.hpp中，只编译template_filter.cpp即可。提供的是声明/样例，不含核心实现；初始程序输出提示属于骨架检查，不是实验完成。
