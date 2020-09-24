// PCM5102 I2S DAC board demo with Teensy 3.6
// http://www.icstation.com/pcm5102-decoder-voice-playback-module-raspberry-p-14738.html
//
// This sketch allows the DAC board to appear as a USB sound output card on a computer (Tested with MAC)
//
// Tested with Arduino IDE 1.8.10,  with installed Teensy Loader 1.48
// In the IDE, set Tools > USB Type to Audio 
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
// Based on example found here:  https://forum.pjrc.com/threads/55669-Audio-library-USB-audio-interface-volume-setting
//
// Gadget Reboot



#include <Audio.h>

AudioInputUSB            usb1;                         // USB audio source to send to DAC board
AudioOutputI2S           i2s1;                         // I2S interface DAC board
AudioAmplifier           amp1;                         // amplifier to control audio level in software before sending to DAC
AudioAmplifier           amp2;
AudioConnection          patchCord1(usb1, 0, amp1, 0); // connect USB audio paths to amplifiers
AudioConnection          patchCord2(usb1, 1, amp2, 0);
AudioConnection          patchCord3(amp2, 0, i2s1, 1); // connect amplifiers to I2S DAC board
AudioConnection          patchCord4(amp1, 0, i2s1, 0);

void setup()
{
  AudioMemory(12);
}

void loop()
{
  float vol = usb1.volume();  // read PC volume setting
  amp1.gain(vol);             // set gain according to PC volume
  amp2.gain(vol);
  delay(100);
}
