/**
 * App for testing real-time audio and midi stuff.
 */
#include <rtaudio/RtAudio.h>
#include <iostream>
#include <cstdlib>
#include "primitive/saw.hpp" // XXX: This should be obviously named as a test thingy

int main() {
    RtAudio dac;
    if (dac.getDeviceCount() < 1) {
        std::cout << "\nNo audio devices found!\n";
        exit(0);
    }

    RtAudio::StreamParameters parameters;
    parameters.deviceId = dac.getDefaultOutputDevice();
    parameters.nChannels = 2;
    parameters.firstChannel = 0;
    unsigned int sampleRate = 44100;
    unsigned int bufferFrames = 256; // 256 sample frames
    double data[2] = {0, 0};
    dac.openStream(&parameters, NULL, RTAUDIO_FLOAT64,
                   sampleRate, &bufferFrames, &saw, (void *) &data);
    dac.startStream();

    char input;
    std::cout << "\nPlaying ... press <enter> to quit.\n";
    std::cin.get(input);

    if (dac.isStreamOpen()) dac.closeStream();

    return 0;
}