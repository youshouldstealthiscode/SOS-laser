// Constants for laser pin, short and long flash durations, and delays
const int laserPin = 7;
const int shortFlashDuration = 500; // 0.5 seconds in milliseconds
const int longFlashDuration = 1500; // 1.5 seconds in milliseconds
const int gapBetweenFlashes = 500;
const int delayBetweenRuns = 3000;

void setup() {
  pinMode(laserPin, OUTPUT); // Set laserPin as OUTPUT
}

void loop() {
  // Send "SOS" in Morse code
  // "S" in Morse code: 3 short flashes
  for (int i = 0; i < 3; i++) {
    flash(shortFlashDuration);
  }
  // Gap between letters
  delay(gapBetweenFlashes);

  // "O" in Morse code: 3 long flashes
  for (int i = 0; i < 3; i++) {
    flash(longFlashDuration);
  }
  // Gap between letters
  delay(gapBetweenFlashes);

  // "S" in Morse code: 3 short flashes
  for (int i = 0; i < 3; i++) {
    flash(shortFlashDuration);
  }

  // Wait for 3 seconds before repeating the loop
  delay(delayBetweenRuns);
}

void flash(int duration) {
  digitalWrite(laserPin, HIGH); // Turn on the laser
  delay(duration); // Wait for the duration of the flash
  digitalWrite(laserPin, LOW); // Turn off the laser
  delay(gapBetweenFlashes); // Wait for the gap between flashes
}
