# TuringSurakarta 第一阶段测试

## 介绍

你需要填空 `src/surakarta/surakarta_rule_manager.cpp` 中的函数以正确完成一系列和规则判断有关的函数。游戏的执行逻辑已经在 `src/surakarta/surakarta_game.cpp` 中实现，他们会调用你实现的函数，了解执行逻辑可能会有助于你完成 `surakarta_rule_manager.cpp` 中的函数。具体来说，请全局搜索 `TODO` 并阅读相关注释。

因为用到了少量未来课程的知识，你还可以通过完成 `src/hello_cpp` 中的 TODO 来学习。

## 运行方法

### 安装 Google Test

```bash
git clone git@github.com:google/googletest.git
cd googletest
mkdir build
cd build
cmake ..
make
sudo make install
```

### 运行本项目

```bash
mkdir build
cd build
cmake ..
make
./bin/main # 对应 src/surakarta/main.cpp，你可以用来调试 surakarta
./bin/hello_cpp_test # 验证 src/hello_cpp/hello_cpp.h 的正确性
./bin/surakarta_rule_manager_test # 验证 src/surakarta/surakarta_rule_manager.h 的正确性
```

## 开发环境

该项目推荐使用 VSCode + 插件 C/C++, CMake, CMake Tools 在 Linux 下开发。

为了 `IntelliSense` 能正常工作，我推荐你在本 Workspace 下这样设置 `settings.json`：

```json
{
    // "C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools",
    "C_Cpp.default.configurationProvider": "ms-vscode.cpp-tools",
    "C_Cpp.default.includePath": [
        "${workspaceFolder}/src"
    ],
}
```

`"C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools"` 会有点问题

## 算法实现

### 提示

一种比较简单的实现吃子判断的思路是：在吃子路线上绕一圈，维护一个棋子链，检查每个圆弧的两边是不是异色棋子，如果是，这对棋子就是可以互吃的。

这是一个粗糙的思路，还有细节的问题请自行思考。

### 提醒

我们会测试棋盘不变的情况下，多次（100次）查询不同的 `JudgeMove` 和 `JudgeEnd`，而不总是棋盘每次改变只查询一次，你可以针对性地优化性能。

## Test

我们给 `JudgeEnd` 和 `JudgeMove` 单独写了测试，你不必一上来就跑最后的那个随机测试。

随机测试默认会跑 10000 局，每局约 100 步，每步会插入 100 条随机测试。测试耗时在 10-100 秒之间是比较合理的。你可以这样修改具体的参数，比如跑更多的局数。

```
export NUM_GAME=100000
export OFFLINE_TEST_ROUND=100
./bin/surakarta_rule_manager_test
```

## Q&A

### Q：怎么创建自己的辅助函数？

我写了两个例子，比较正式的方法是 `SurakartaRuleManager::HelloWorld`，比较省事的是 `SurakartaRuleManager::InlineHelloWorld`。

### Q：std::shared_ptr 和 std::unique_ptr 是什么东西？

智能指针，避免手动管理内存以预防内存泄露，我建议一开始就学习使用智能指针，不要使用裸指针。（虽然这个是后面课程的内容）

考虑下面这段代码，其中 `new` 会在堆上分配内存，`delete` 会释放内存，但是如果你忘记 `delete`，那么这块内存就会一直被占用，直到重启电脑。这就是内存泄露，而智能指针可以帮助我们避免这种情况。

```cpp
// raw pointer example
#include <iostream>

int main(){
    int* p = new int(1);
    std::cout << *p << std::endl;
    // delete p;
}
```

`std::shared_ptr` 和 `std::unique_ptr` 都是智能指针，它们的区别在于，`std::shared_ptr` 可以被多个指针指向同一个对象，而 `std::unique_ptr` 只能被一个指针指向。

其原理是 p 是分配在栈上的，其会被自动释放，其自动释放时会把指向对象的引用计数减一，当引用计数为 0 时，其就会自动释放堆上的内存。

unique_ptr 的稍微特别一点，其不允许被复制，但是可以被移动，即本来是 r 指向的对象，现在变成了 s 指向的对象，但这样 r 就不再指向任何对象了，或者说变成了空指针，你再使用 r 就会出错。

```cpp
// smart pointer example
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> p = std::make_shared<int>(1);
    std::shared_ptr<int> q = p;
    std::cout << *p << std::endl;
    std::cout << *q << std::endl;

    std::unique_ptr<int> r = std::make_unique<int>(1);
    // std::unique_ptr<int> s = r;  // Compile error
    std::cout << *r << std::endl;

    std::unique_ptr<int> s = std::move(r);  // ok
    std::cout << *s << std::endl;
    // std::cout << *r << std::endl;  // Segmentation fault
}
```

> 智能指针，你可以理解为，写起来复杂，但只要写出来了就一般不会错。普通指针就是好写，但是容易出错。

### Q：为什么 board_ 的类型不是直接二维数组，然后 0 1 2 表示空白，黑色，白色？

可以，但是我们仍然不可避免地会遇到“棋子类”，比如你在 Qt 中想要用某个控件表示棋子，这个控件必然是一个类。
此时这个 board_ 更像一个映射，由坐标到类的映射，方便在比如你吃掉一个棋子的时候，找到对应的控件并删除它。
但是还有一种比较暴力的方法是，每次都根据 board_ 遍历棋盘，重绘所有棋子，当画画来处理，那可能就不需要这种形式的实现了。但我更推荐前者的实现逻辑。

### Q：一定要采用这个框架嘛？

这个阶段必须用这个框架，之后你可以自己写一个框架，但是要求能通过这个测试，即你把你的框架内的规则相关的类取出来，然后在 `JudgeMove` 和 `JudgeEat` 中调用你的函数，你可能需要做一个转化，比如你是用二维int数组表示棋盘的，你就在函数里预处理一下啥的。

这个实验的目的是强制面向对象，或者说展示面向对象的优势：方便扩展。

## 开发手册

> 该部分和学生任务无关

```bash
cmake .. -DENV=TEST # 测试环境
cmake .. -DENV=DEV # 开发环境
```

开发环境下 `make install` 会生成助教实现的 `src/surakarta_ta/surakarta_rule_manager_imp.cpp` 的动态链接库到 `surakarta_ta`

测试环境下会到 `surakarta_ta` 下寻找动态链接库用于测试。