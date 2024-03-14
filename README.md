# Surakarta 第一阶段测试

> 如果你正在寻找主仓库，请访问 [Surakarta](https://github.com/panjd123/Surakarta)

## 介绍

### 主任务

第一阶段你有两项任务：

- 完成游戏规则的实现
- 实现一个简单的 AI

所有我认为你需要阅读/填空/修改的代码，我都加了 `TODO` 注释，你可以全局搜索。

### 附加任务

保证整个项目的编译过程没有任何警告（打开 `-Wall -Wextra`），这个任务包括完成 `src/hello_cpp` 中的 cpp 学习部分，且编译也没有警告。

### 游戏规则实现

你需要填空 `src/surakarta/surakarta_rule_manager.cpp` 中的函数以正确完成一系列和规则判断有关的函数。

游戏的执行逻辑已经在 `src/surakarta/surakarta_game.cpp` 中实现，他们会调用你实现的函数，了解执行逻辑可能会有助于你完成 `surakarta_rule_manager.cpp` 中的函数。

因为用到了少量未来课程的知识，你还可以通过完成 `src/hello_cpp` 中的 TODO 来学习。

### AI 实现

在 `src/surakarta/surakarta_agent` 下有两个具体的 AI 实现，其中 `surakarta_agnet_random` 是已经实现好的随机 AI，只要你把 `rule_manager` 的 `JudgeMove` 实现好，就可以正确运行。

`surakarta_agnet_mine` 是你需要实现的 AI，你可以在其中实现你的 AI 算法，并最终在 `src/surakarta/main.cpp` 中调用你的 AI 和随机 AI 进行对战。

实现好后，你可以运行 `build/bin/main` 来观察，这一部分没有 google test。

## 开发环境

- 该项目要求在 x86 架构的 Linux 下开发，其他系统和架构都不能运行。
- 该项目推荐使用的 IDE 配置：VSCode，插件： C/C++, CMake, CMake Tools。

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


## 怎么 clone 这个仓库（或者说怎么从这个共有仓库里 fork 出你的私有仓库）

我们**要求**用以下这种方式，以保证你可以借助 git 工具来将这个仓库的更新 pull 到你的仓库里，不使用 git 会让你同步更新时非常痛苦。

> 参考自 https://github.com/cmu-db/bustub

The following instructions are adapted from the Github documentation on [duplicating a repository](https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/creating-a-repository-on-github/duplicating-a-repository). The procedure below walks you through creating a private Surakarta-RuleAiTest repository that you can use for development.

1. Go [here](https://github.com/new) to create a new repository under your account. Pick a name (e.g. `Surakarta-RuleAiTest-private`) and select **Private** for the repository visibility level.

2. On your development machine, create a bare clone of the public Surakarta-RuleAiTest repository:

   ```
   $ git clone --bare https://github.com/panjd123/Surakarta-RuleAiTest.git Surakarta-RuleAiTest-public
   ```

3. Next, [mirror](https://git-scm.com/docs/git-push#Documentation/git-push.txt---mirror) the public Surakarta-RuleAiTest repository to your own private Surakarta-RuleAiTest repository. Suppose your GitHub name is `student` and your repository name is `Surakarta-RuleAiTest-private`. The procedure for mirroring the repository is then:

   ```
   $ cd Surakarta-RuleAiTest-public
   
   # If you pull / push over HTTPS
   $ git push https://github.com/student/Surakarta-RuleAiTest-private.git master
   
   # If you pull / push over SSH
   $ git push git@github.com:student/Surakarta-RuleAiTest-private.git master
   ```

   This copies everything in the public Surakarta-RuleAiTest repository to your own private repository. You can now delete your local clone of the public repository:

   ```
   $ cd ..
   $ rm -rf Surakarta-RuleAiTest-public
   ```

4. Clone your private repository to your development machine:

   ```
   # If you pull / push over HTTPS
   $ git clone https://github.com/student/Surakarta-RuleAiTest-private.git
   
   # If you pull / push over SSH
   $ git clone git@github.com:student/Surakarta-RuleAiTest-private.git
   ```

5. Add the public Surakarta-RuleAiTest repository as a second remote. This allows you to retrieve changes from the panjd123 repository and merge them with your solution throughout the semester:

   ```
   $ git remote add public https://github.com/panjd123/Surakarta-RuleAiTest.git
   ```

   You can verify that the remote was added with the following command:

   ```
   $ git remote -v
   origin	https://github.com/student/Surakarta-RuleAiTest-private.git (fetch)
   origin	https://github.com/student/Surakarta-RuleAiTest-private.git (push)
   public	https://github.com/panjd123/Surakarta-RuleAiTest.git (fetch)
   public	https://github.com/panjd123/Surakarta-RuleAiTest.git (push)
   ```

6. You can now pull in changes from the public Surakarta-RuleAiTest repository as needed with:

   ```
   $ git pull public master
   ```

We suggest working on your projects in separate branches. If you do not understand how Git branches work, [learn how](https://git-scm.com/book/en/v2/Git-Branching-Basic-Branching-and-Merging). If you fail to do this, you might lose all your work at some point in the semester, and nobody will be able to help you.

## 运行方法

### 安装 Google Test

```bash
git submodule update --init --recursive
# to clone faster, you can use the following command
# git submodule update --init --recursive --depth 1
cd third-party/googletest
cmake -B build .
cd build
make -j
sudo make install
```

### 运行本项目

```bash
mkdir build
cd build
cmake ..
make -j
./bin/main # 对应 src/surakarta/main.cpp，你可以用来调试 surakarta
./bin/main_ta # 对应 src/surakarta_ta/main.cpp，相当于助教的实现，你们完成项目后应该达成的效果
./bin/hello_cpp_test # 验证 src/hello_cpp/hello_cpp.h 的正确性
./bin/surakarta_rule_manager_test # 验证 src/surakarta/surakarta_rule_manager.cpp 的正确性
```

## 算法实现

### 提示

一种比较简单的实现吃子判断的思路是：在吃子路线上绕一圈，维护一个棋子链，检查每个圆弧的两边是不是异色棋子，如果是，这对棋子就是可以互吃的。

这是一个粗糙的思路，还有细节的问题请自行思考。

-----------

在本作业中旬，我们上传了一份更详细的思路介绍，见 [主仓库 guidance/lectures](https://github.com/panjd123/Surakarta/blob/main/guidance/lectures/stage1.md)。


### 测试

`./bin/surakarta_rule_manager_test` 中有 3 个测试单元：

- `EndReasonTest`：手工构造的测试用例，仅测试 `JudgeEnd` 函数，BOARD_SIZE != 6 时跳过。
- `MoveReasonTest`：手工构造的测试用例，仅测试 `JudgeMove` 函数，BOARD_SIZE != 6 时跳过。
- `RandomTest`：随机生成的测试用例，同时测试 `JudgeEnd` 和 `JudgeMove`，支持 BOARD_SIZE != 6 的情况。

其中随机测试默认会跑 10000 局，每局约 100 步，每步会插入 100 条随机测试。测试耗时在 10-100 秒之间是比较合理的。

也就是我们会测试棋盘不变的情况下，多次（100次）查询不同的 `JudgeMove` 和 `JudgeEnd`，而不总是棋盘每次改变只查询一次，你可以针对地优化性能。

## 测试的进阶用法

前面我们提到，随机测试默认会跑 10000 局，每步会插入 100 条随机测试，你还可以这样修改这两个参数，比如跑更多的局数。

以及我们现在还支持手动指定随机数种子，这可能方便你复现某个测试。

```
export NUM_GAME=100000
export OFFLINE_TEST_ROUND=100
export CUSTOM_SEED=123
./bin/surakarta_rule_manager_test
```

## 项目的已知 BUG

项目有些地方的 `ILLEGAL` 被写成了 `ILLIGAL`，因为这个 BUG 发现在作业中期，所以我们不修复这个问题，我建议：

- 如果你是本学期的学生，你可以在下一阶段的大项目里全局替换一下，且**千万不要**在第一阶段的项目里修复这个 BUG，因为我们的自动化测试会用助教的仓库覆盖部分代码，助教的仓库里就是 `ILLIGAL`。
- 如果你是下学期的助教，请在下次布置作业时全局替换一下。

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

设计这个测试的一大目的是强制面向对象。

## 开发手册

> 该部分和学生任务无关

```bash
cmake .. -DENV=TEST # 测试环境
cmake .. -DENV=DEV # 开发环境
```

开发环境下 `make install` 会生成助教实现的 `src/surakarta_ta/surakarta_rule_manager_imp.cpp` 的动态链接库到 `surakarta_ta`

测试环境下会到 `surakarta_ta` 下寻找动态链接库用于测试。
