#include <Keyboard.h>
#include <Adafruit_NeoPixel.h>

#define PIN 15

#define NUMPIXELS 5

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const int ROW_1 = 6;
const int ROW_2 = 5;
const int ROW_3 = 4;

const int COLS[4] = {29, 28, 27, 26};

int col_1;
int col_2;
int col_3;
int col_4;

void alt_tab() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
}

void win_log() {
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.print("230106");
}

void kill_task() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.releaseAll();
}

void setup() {
  Serial.begin(9600);

  pinMode(ROW_1, OUTPUT);
  pinMode(ROW_2, OUTPUT);
  pinMode(ROW_3, OUTPUT);

  digitalWrite(ROW_1, LOW);
  digitalWrite(ROW_2, LOW);
  digitalWrite(ROW_3, LOW);

  for (int i = 0; i < 4; i++) pinMode(COLS[i], INPUT_PULLUP);

  Keyboard.begin();
  pixels.begin();
  pixels.clear();
}

void loop() {
  col_1 = digitalRead(COLS[0]);
  col_2 = digitalRead(COLS[1]);
  col_3 = digitalRead(COLS[2]);
  col_4 = digitalRead(COLS[3]);

  for (int i = 0; i < 5; i++) pixels.setPixelColor(i, pixels.Color(0, 255, 0));

  pixels.show();   // Send the updated pixel colors to the hardware.

  if (col_1 == LOW) { // COLUMN 1 == LOW
    digitalWrite(ROW_1, HIGH); // SET ROW 1 = HIGH
    col_1 = digitalRead(COLS[0]);
    if (col_1 == LOW) {
      digitalWrite(ROW_2, HIGH);
      col_1 = digitalRead(COLS[0]);
      if (col_1 == LOW) {
        Serial.println("COL 1 | ROW 3"); // COL 1 ROW 3
        Keyboard.print("9");
      } else kill_task(); // COL 1 ROW 2
    } else Keyboard.print("230106"); // COL 1 ROW 1
  } else if (col_2 == LOW) {
    digitalWrite(ROW_1, HIGH); // SET ROW 1 = HIGH
    col_2 = digitalRead(COLS[1]);
    if (col_2 == LOW) {
      digitalWrite(ROW_2, HIGH);
      col_2 = digitalRead(COLS[1]);
      if (col_2 == LOW) {
        Serial.println("COL 2 | ROW 3"); // COL 2 ROW 3
        Keyboard.print("10");
      } else Keyboard.print("6"); // COL 2 ROW 2
    } else Keyboard.print("2"); // COL 2 ROW 1
  } else if (col_3 == LOW) {
    digitalWrite(ROW_1, HIGH); // SET ROW 1 = HIGH
    col_3 = digitalRead(COLS[2]);
    if (col_3 == LOW) {
      digitalWrite(ROW_2, HIGH);
      col_3 = digitalRead(COLS[2]);
      if (col_3 == LOW) {
        Serial.println("COL 3 | ROW 3"); // COL 3 ROW 3
        Keyboard.print("11");
      } else Keyboard.print("7"); // COL 3 ROW 2
    } else Keyboard.print("3"); // COL 3 ROW 1
  } else if (col_4 == LOW) {
    digitalWrite(ROW_1, HIGH); // SET ROW 1 = HIGH
    col_4 = digitalRead(COLS[3]);
    if (col_4 == LOW) {
      digitalWrite(ROW_2, HIGH);
      col_4 = digitalRead(COLS[3]);
      if (col_4 == LOW) {
        Serial.println("COL 4 | ROW 3"); // COL 4 ROW 3
        Keyboard.print("12");
      } else Keyboard.print("8"); // COL 4 ROW 2
    } else alt_tab(); // COL 4 ROW 1
  } else {
    digitalWrite(ROW_1, LOW);
    digitalWrite(ROW_2, LOW);
    digitalWrite(ROW_3, LOW);
  }
  delay(100);
}
