#include <iostream>
#include <cstdio>
#include "Utility/metro.h"
#include <plog/Log.h> // Step1: include the headers
#include <plog/Appenders/ColorConsoleAppender.h>

int main() {
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::debug, &consoleAppender);
    daisysp::Metro metro;
    metro.Init(1000, 48000);
    uint8_t processed = metro.Process();

    PLOGI.printf("Processed: %d", processed);
    PLOGI.printf("Hello, log");

    return 0;
}
