#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
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
    float sample_rate = 48000;
    metro.Init(frequency, sample_rate);

    int ticks = 0;
    for (int i=0; i<sample_rate; i++) {
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
#pragma clang diagnostic pop