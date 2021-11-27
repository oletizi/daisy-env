#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <gtest/gtest.h>

TEST(Basics, TestBasics) {
    PLOGI.printf("This should work.");
}

int main(int argc, char *argv[]) {
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::debug, &consoleAppender);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
