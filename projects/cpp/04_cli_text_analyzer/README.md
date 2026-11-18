# 04 CLI 文本分析器：C++ 核心差异项目

这个项目不是字符串基础练习。骨架已经提供可运行的 ASCII 分词器、CMake 配置和基线测试；学习任务从容器语义与参数传递开始。

## 当前结构

```text
04_cli_text_analyzer/
├── CMakeLists.txt
├── include/
│   └── text_input.hpp       已完成的分词接口
├── src/
│   ├── main.cpp             可运行演示
│   └── text_input.cpp       已完成的机械性分词实现
├── tests/
│   └── test_text_input.cpp  已完成的基线测试
└── samples/
    └── basic.txt
```

## 第一章由你新增

自行创建 `text_analysis.hpp/.cpp`，完成以下职责，不要改写分词器：

- `map` 词频统计：输入只读词序列，返回新的统计表；
- `set` 停用词过滤：明确选择返回副本或原地修改，并解释取舍；
- `vector` 排序报告：次数降序，同频字典序；
- 最小次数或 TopK 变形；
- 对应测试，至少包含空输入、同频、重复停用词和筛选后为空。

接口名字可以自定，但每个参数都要能解释为何使用值、引用或 `const` 引用。

## 构建与运行

```powershell
cmake -S . -B build_current -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=D:/mingw64/bin/g++.exe
cmake --build build_current
ctest --test-dir build_current --output-on-failure
```

上面的生成器和编译器路径对应当前机器；若以后已配置默认 C++ 工具链，可省略 `-G` 和 `-DCMAKE_CXX_COMPILER`。

若暂时不用 CMake，可运行：

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/main.cpp src/text_input.cpp src/word_counts.cpp src/file_reader.cpp -o text_analyzer.exe
.\text_analyzer.exe 3 samples\basic.txt
```

## 命令行分析

运行 `.\build_current\text_analyzer.exe 3 文件1 文件2` 可合并统计多个文件，数字是最多输出的词条数。可在 K 后加入 `--stop-words 停用词文件`，例如 `.\build_current\text_analyzer.exe 3 --stop-words tests\cli_stop_words.txt tests\cli_first.txt`。停用词按同样的 ASCII 分词和小写规则处理。无法读取的输入文件会单独报告；只要至少一个输入文件读取成功，程序继续输出结果。全部失败或停用词文件无法读取时返回非零状态；空文件视为读取成功。

本目录保留文本分析器源码与已有测试。第三、四章练习已移到同级的 [05_lifetime_and_templates](../05_lifetime_and_templates/README.md)，直接使用其 main.cpp；本目录不再嵌套 exercises。既有实现不因目录调整自动记为独立掌握。
