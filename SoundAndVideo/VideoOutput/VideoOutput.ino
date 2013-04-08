#include <TVout.h>
#include <video_gen.h>

/*
VIDEO OUTPUT
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 While VGA, DVI, and HDMI video are complex digital signals, the
 old-school analog video (sent over RCA connectors) is easy enough
 that your Arduino can generate it (with just a few caveats).
 
 Requires the TVout library - download and usage details:
 http://code.google.com/p/arduino-tvout
 
 Caveats (ie: disclaimers):
 1. Black and white only (no color or grayscale)
 2. Simple shapes, no images
 3. Can be a bit slow to refresh (16MHz is pretty slow for video processing)
 
 For full TVout capabilities, see the example 'DemoNTSC' included with
 the library.
 
 CHALLENGE:
 + Can you control the creation or size of shapes using different
   sensors? This is just a short step from Pong!
 + Look at the 'DemoNTSC' sketch in the TVout examples; in it graphics
   are defined as arrays. Can you write a sketch (using Processing,
   Python, Javascript, etc) that generates those arrays from an existing
   image file and returs an array? 
 */

int rectSize = 10;      // rectangle size
const int width = 128;  // width of screen (best when tuned to your display)
const int height = 96;  // listed as a 'const' since this doesn't change
TVout tv;               // TVout object

void setup() {
  tv.begin(_NTSC, width, height);    // start TV connection
}

void loop() {

  // clear screen and draw shapes
  tv.clear_screen();
  tv.draw_rect(width/2,height/2, rectSize,rectSize);

  // update rectangle size; when too large, reset
  rectSize += 1;
  if (rectSize > width || rectSize > height) {
    rectSize = 10;
  }

  // wait before redrawing - this helps prevent your Arduino from freaking out
  tv.delay(30);
}

