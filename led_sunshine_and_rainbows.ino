/*
 * Sunshine and rainbows LED strips controller
 * Created for MK P.
 * 2022-04-28
 */

#include <Adafruit_NeoPixel.h>

#define LED_PIN_RAINBOW    26
#define LED_PIN_SUN    27
#define LED_COUNT_RAINBOW 30
#define LED_COUNT_SUN 7
#define LED_BRIGHTNESS 50 // about 1/5 (max = 255)

//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
Adafruit_NeoPixel stripRainbow(LED_COUNT_RAINBOW, LED_PIN_RAINBOW, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripSun(LED_COUNT_SUN, LED_PIN_SUN, NEO_GRB + NEO_KHZ800);


void setup() {
  stripRainbow.begin();
  stripRainbow.show();
  stripRainbow.setBrightness(LED_BRIGHTNESS);
  stripSun.begin();
  stripSun.show();
  stripSun.setBrightness(LED_BRIGHTNESS);
}

void loop() {

  // Set the LEDs on the Sun
  sunColor(stripSun);

  // Set and animate the rainbow
  rainbow(stripRainbow, 10);
}


void sunColor(Adafruit_NeoPixel &strip) {
  
  for(int i = 0; i < strip.numPixels(); i++) {
    long hue = random(6000,11000); // orange to yellow
    strip.setPixelColor(i, Adafruit_NeoPixel::ColorHSV(hue));
    strip.show();
  }
}

// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(Adafruit_NeoPixel &strip, int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    // strip.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).
    strip.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}
