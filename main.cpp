#include <iostream>
#include "Utility/metro.h"

int main() {
    daisysp::Metro metro;
    metro.Init(1000, 48000);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
