/**
 * App for testing real-time audio and midi stuff.
 */
#include <rtaudio/RtAudio.h>
#include <iostream>
#include <gtest/gtest.h>
#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include "primitive/saw.hpp" // XXX: This should be obviously named as a test thingy

namespace oSoundRealtime {
    class RealtimeTest : public ::testing::Test {

    protected:
        RtAudio *dac = new RtAudio();
        RtAudio::StreamParameters *parameters = new RtAudio::StreamParameters();
        unsigned int sampleRate = 44100;
        unsigned int bufferFrames = 256; // 256 sample frames

    public:
        ~RealtimeTest() override {
            delete dac;
            delete parameters;
        }


        void SetUp() override {
            PLOGI.printf("I'm setting up!");
            EXPECT_EQ(dac->getDeviceCount(), 2);
            parameters->deviceId = dac->getDefaultOutputDevice();
            parameters->nChannels = 2;
            parameters->firstChannel = 0;

        }

        void TearDown() override {
            PLOGI.printf("I'm tearing down!");
            if (dac->isStreamOpen()) dac->closeStream();
        }
    };

    TEST_F(RealtimeTest, CanPlayAudio) {
        PLOGI.printf("I GOT RUN!");
        double data[2] = {0, 0};
        dac->openStream(parameters, nullptr, RTAUDIO_FLOAT64,
                        sampleRate, &bufferFrames, &saw, (void *) &data);
        dac->startStream();

        // sleep for a while to listen; it's pretty unpleasant sounding, so not too long
        sleep(2);
    }
}

int main(int argc, char *argv[]) {
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::debug, &consoleAppender);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/**
#include "RtAudio.h"
#include <iostream>
#include <cstdlib>

// Two-channel sawtooth wave generator.
int saw( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *userData )
{
  unsigned int i, j;
  double *buffer = (double *) outputBuffer;
  double *lastValues = (double *) userData;

  if ( status )
    std::cout << "Stream underflow detected!" << std::endl;

  // Write interleaved audio data.
  for ( i=0; i<nBufferFrames; i++ ) {
    for ( j=0; j<2; j++ ) {
      *buffer++ = lastValues[j];

      lastValues[j] += 0.005 * (j+1+(j*0.1));
      if ( lastValues[j] >= 1.0 ) lastValues[j] -= 2.0;
    }
  }

  return 0;
}

int main()
{
  RtAudio dac;
  if ( dac.getDeviceCount() < 1 ) {
    std::cout << "\nNo audio devices found!\n";
    exit( 0 );
  }

  RtAudio::StreamParameters parameters;
  parameters.deviceId = dac.getDefaultOutputDevice();
  parameters.nChannels = 2;
  parameters.firstChannel = 0;
  unsigned int sampleRate = 44100;
  unsigned int bufferFrames = 256; // 256 sample frames
  double data[2] = {0, 0};

  try {
    dac.openStream( &parameters, NULL, RTAUDIO_FLOAT64,
                    sampleRate, &bufferFrames, &saw, (void *)&data );
    dac.startStream();
  }
  catch ( RtAudioError& e ) {
    e.printMessage();
    exit( 0 );
  }

  char input;
  std::cout << "\nPlaying ... press <enter> to quit.\n";
  std::cin.get( input );

  try {
    // Stop the stream
    dac.stopStream();
  }
  catch (RtAudioError& e) {
    e.printMessage();
  }

  if ( dac.isStreamOpen() ) dac.closeStream();

  return 0;
}
*/