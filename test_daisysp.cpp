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

