#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <gtest/gtest.h>
#include <Utility/metro.h>

/**
 * Test that the metronome ticks as the configured frequency.
 */
TEST(Metro, MetroFrequency) {
    daisysp::Metro metro;
    float frequency = 1000;
    float sampleRate = 48000;
    metro.Init(frequency, sampleRate);

    int ticks = 0;
    for (int i = 0; i < (int) sampleRate; i++) {
        ticks += metro.Process();
    }
    EXPECT_EQ(ticks, frequency);
}

int main(int argc, char *argv[]) {
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::debug, &consoleAppender);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}