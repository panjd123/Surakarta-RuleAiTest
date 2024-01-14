#include "hello_cpp/hello_cpp.h"
#include <memory>
#include "gtest/gtest.h"

TEST(HelloCppTest, Add) {
    ASSERT_EQ(hello_cpp::Add(1, 2), 3);
    ASSERT_EQ(hello_cpp::Add(1, -2), -1);
}

TEST(HelloCppTest, GenerateAllPositions) {
    std::unique_ptr<std::vector<SurakartaPosition>> positions = hello_cpp::GenerateAllPositions();
    ASSERT_NE(positions, nullptr);
    ASSERT_EQ(positions->size(), 36u);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; ++j) {
            SurakartaPosition pos(i, j);
            ASSERT_EQ((*positions)[i * 6 + j], pos);
        }
    }
}

TEST(HelloCppTest, SmartPointerContainer) {
    hello_cpp::SmartPointerContainer container(1, 2.0, 3, 4.0, 5, 6.0);
    ASSERT_EQ(container.DoSomething(), 9);
}

TEST(HelloCppTest, LearningUniquePtr) {
    std::unique_ptr<int> ptr = hello_cpp::LearningUniquePtr();
    ASSERT_NE(ptr, nullptr);
    ASSERT_EQ(abs(*ptr - 1), 1);
}