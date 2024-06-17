# CMake 模板

> a cmake project template for Qt in vscode

```
.
├── CMakeLists.txt                  # 主干
├── cmake                           # 工具函数文件夹
├   ├── AutoSearch.cmake            # 提供根据路径搜索头文件或源文件
├   ├── ColorLog.cmake              # 彩色日志打印
├   └── sub_template.cmake.in       # 子文件夹内CMakeLists.txt模板
└── toolkit                         # Qt 编译套件文件夹
    └── mingw81_64.cmake            # 指定相关宏
```
