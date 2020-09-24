// PCM5102 I2S DAC board demo with Teensy 3.6
// http://www.icstation.com/pcm5102-decoder-voice-playback-module-raspberry-p-14738.html
//
// This sketch plays audio samples from memory on the DAC board via I2S
//
// Tested with Arduino IDE 1.8.10,  with installed Teensy Loader 1.48
//
// Connections between Teensy and Audio Board:
//
// PCM5102 board   Teensy Pins
// VCC                  5V
// GND                  GND
// LRCK                 23
// DATA                 22
// BCK                  9
//
// Gadget Reboot

#include <Audio.h>

// WAV files converted to code by wav2sketch
#include "AudioSampleSnare.h"        // http://www.freesound.org/people/KEVOY/sounds/82583/
#include "AudioSampleTomtom.h"       // http://www.freesound.org/people/zgump/sounds/86334/
#include "AudioSampleHihat.h"        // http://www.freesound.org/people/mhc/sounds/102790/
#include "AudioSampleKick.h"         // http://www.freesound.org/people/DWSD/sounds/171104/

// Audio samples stored in memory for playback
AudioPlayMemory    sound0;
AudioPlayMemory    sound1;
AudioPlayMemory    sound2;
AudioPlayMemory    sound3;

// 4-channel mixer for audio samples
AudioMixer4        mix1;

// I2S interface DAC board
AudioOutputI2S     i2s1;

// test audio synthesized waveforms
AudioSynthWaveformSine   sine1;

// audio path patch cords
AudioConnection patchCord1(sound0, 0, mix1, 0);  // sound samples to mixer input channels
AudioConnection patchCord2(sound1, 0, mix1, 1);
AudioConnection patchCord3(sound2, 0, mix1, 2);
AudioConnection patchCord4(sine1,  0, mix1, 3);

AudioConnection patchCord5(mix1, 0, i2s1, 0);    // output of mixer into I2S DAC board left+right
AudioConnection patchCord6(mix1, 0, i2s1, 1);


void setup()
{
  AudioMemory(10);

  // sine wave settings
  sine1.amplitude(0);
  sine1.frequency(1000);

  // set mixer input gains from 0-1
  mix1.gain(0, 0.3);
  mix1.gain(1, 0.3);
  mix1.gain(2, 0.1);
  mix1.gain(3, 0.5);
}

void loop()
{

  sine1.amplitude(0.5);
  sine1.frequency(1000);
  delay(500);
  sine1.frequency(500);
  delay(500);
  sine1.frequency(200);
  delay(500);
  sine1.frequency(100);
  delay(500);

  sine1.amplitude(0);
  delay(50);
  sine1.amplitude(0.5);
  delay(50);
  sine1.amplitude(0);
  delay(50);
  sine1.amplitude(0.5);
  delay(50);
  sine1.amplitude(0);
  delay(50);
  sine1.amplitude(0.5);
  delay(200);

  sine1.amplitude(0);
  delay(50);
  sine1.amplitude(0.5);
  delay(50);
  sine1.amplitude(0);
  delay(50);
  sine1.amplitude(0.5);
  delay(50);
  sine1.amplitude(0);
  delay(50);
  sine1.amplitude(0.5);
  delay(200);

  sine1.frequency(150);

  sine1.amplitude(0);
  delay(50);
  sine1.amplitude(0.5);
  delay(50);
  sine1.amplitude(0);
  delay(50);
  sine1.amplitude(0.5);
  delay(50);
  sine1.amplitude(0);
  delay(50);
  sine1.amplitude(0.5);
  delay(200);

  sine1.amplitude(0);
  delay(50);
  sine1.amplitude(0.5);
  delay(50);
  sine1.amplitude(0);
  delay(50);
  sine1.amplitude(0.5);
  delay(50);
  sine1.amplitude(0);
  delay(50);
  sine1.amplitude(0.5);
  delay(200);

  sine1.amplitude(0);

  sound1.play(AudioSampleKick);
  sound2.play(AudioSampleHihat);
  delay(200);
  sound2.play(AudioSampleHihat);
  delay(200);
  sound0.play(AudioSampleSnare);
  sound2.play(AudioSampleHihat);
  delay(200);
  sound2.play(AudioSampleHihat);
  delay(200);

  sound1.play(AudioSampleKick);
  sound2.play(AudioSampleHihat);
  delay(200);
  sound1.play(AudioSampleKick);
  sound2.play(AudioSampleHihat);
  delay(200);
  sound0.play(AudioSampleSnare);
  sound2.play(AudioSampleHihat);
  delay(200);
  sound2.play(AudioSampleHihat);
  delay(200);

  sound0.play(AudioSampleSnare);
  delay(200);
  sound1.play(AudioSampleKick);
  delay(200);
  sound1.play(AudioSampleKick);
  delay(200);
  sound1.play(AudioSampleKick);
  delay(200);

  sound2.play(AudioSampleHihat);
  sound0.play(AudioSampleSnare);
  delay(200);
  sound1.play(AudioSampleKick);
  delay(200);
  sound0.play(AudioSampleSnare);
  sound1.play(AudioSampleKick);
  delay(100);
  sound1.play(AudioSampleKick);
  delay(100);
  sound1.play(AudioSampleKick);
  delay(100);
  sound1.play(AudioSampleKick);
  delay(100);


}
