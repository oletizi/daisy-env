#ifndef DAISY_ENV_SAW_HPP
#define DAISY_ENV_SAW_HPP

// Two-channel sawtooth wave generator.
int saw(void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
        double streamTime, RtAudioStreamStatus status, void *userData);

#endif //DAISY_ENV_SAW_HPP
