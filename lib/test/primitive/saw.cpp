//
// Created by Orion Letizi on 11/27/21.
//

#include <unistd.h>
#include <csignal>
#include "rtaudio/RtAudio.h"
#include <cstdlib>
#include <iostream>
#include <rtaudio/RtAudio.h>
#include "saw.hpp"


int saw(void *outputBuffer,
        void *inputBuffer,
        unsigned int nBufferFrames,
        double streamTime,
        RtAudioStreamStatus status,
        void *userData) {
    unsigned int i, j;
    auto *buffer = (double *) outputBuffer;
    auto *lastValues = (double *) userData;

    if (status)
        std::cout << "Stream underflow detected!" << std::endl;

    // Write interleaved audio data.
    for (i = 0; i < nBufferFrames; i++) {
        for (j = 0; j < 2; j++) {
            *buffer++ = lastValues[j];

            lastValues[j] += 0.005 * (j + 1 + (j * 0.1));
            if (lastValues[j] >= 1.0) lastValues[j] -= 2.0;
        }
    }
    return 0;
}
