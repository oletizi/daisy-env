#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>

int main() {
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::debug, &consoleAppender);

    PLOGI.printf("I'm testing!!!");
}