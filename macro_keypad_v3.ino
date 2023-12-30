//---- Importing Libraries ----//

#include <Keyboard.h>
#include <Adafruit_NeoPixel.h>

//---- Libraries ----//

//---- Adafruit NeoPixel ----//

#define PIN 15

#define NUMPIXELS 5

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//---- Adafruit NeoPixel ----//

//---- Matrix Keymap ----//

const int ROW_1 = 6;
const int ROW_2 = 5;
const int ROW_3 = 4;

const int COLS[4] = {29, 28, 27, 26};

int col_1;
int col_2;
int col_3;
int col_4;

int layer = 0;

//---- Matrix Keymap ----//

//---- Keypad Functions ----//

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

void browser() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write('b');
  delay(100);
  Keyboard.releaseAll();
}

void vs_code() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write('v');
  delay(100);
  Keyboard.releaseAll();
}

void npm_start() {
  Keyboard.print("npm start");
  Keyboard.press(KEY_RETURN);
  delay(10);
  Keyboard.releaseAll();
}

//---- Keypad Functions ----//

//---- RGB-Color functions ----//

bool rgb_fade = true;

bool comb_fade = false;

bool stp = false;

int count = 1;

void combination_rgb_fade() {
  if (layer != 1) {
    return;
  } else {
    for (int i = 0; i < 255; i++) {                 // Yellow Light
      if (layer != 1) return;
      pixels.setPixelColor(0, pixels.Color(i, i, 0));
      pixels.setPixelColor(1, pixels.Color(i, i, 0));
      pixels.setPixelColor(2, pixels.Color(i, i, 0));
      pixels.setPixelColor(3, pixels.Color(i, i, 0));
      pixels.setPixelColor(4, pixels.Color(i, i, 0));
      delay(10);
      pixels.show();
    }

    for (int i = 255; i > 0; i--) {                 // Yellow Light
      if (layer != 1) return;
      pixels.setPixelColor(0, pixels.Color(i, i, 0));
      pixels.setPixelColor(1, pixels.Color(i, i, 0));
      pixels.setPixelColor(2, pixels.Color(i, i, 0));
      pixels.setPixelColor(3, pixels.Color(i, i, 0));
      pixels.setPixelColor(4, pixels.Color(i, i, 0));
      delay(10);
      pixels.show();
    }

    for (int i = 0; i < 255; i++) {                 // Blue-Green Light
      if (layer != 1) return;
      pixels.setPixelColor(0, pixels.Color(0, i, i));
      pixels.setPixelColor(1, pixels.Color(0, i, i));
      pixels.setPixelColor(2, pixels.Color(0, i, i));
      pixels.setPixelColor(3, pixels.Color(0, i, i));
      pixels.setPixelColor(4, pixels.Color(0, i, i));
      delay(10);
      pixels.show();
    }

    for (int i = 255; i > 0; i--) {                 // Blue-Green Light
      if (layer != 1) return;
      pixels.setPixelColor(0, pixels.Color(0, i, i));
      pixels.setPixelColor(1, pixels.Color(0, i, i));
      pixels.setPixelColor(2, pixels.Color(0, i, i));
      pixels.setPixelColor(3, pixels.Color(0, i, i));
      pixels.setPixelColor(4, pixels.Color(0, i, i));
      delay(10);
      pixels.show();
    }

    for (int i = 0; i < 255; i++) {                 // Purple Light
      if (layer != 1) return;
      pixels.setPixelColor(0, pixels.Color(i, 0, i));
      pixels.setPixelColor(1, pixels.Color(i, 0, i));
      pixels.setPixelColor(2, pixels.Color(i, 0, i));
      pixels.setPixelColor(3, pixels.Color(i, 0, i));
      pixels.setPixelColor(4, pixels.Color(i, 0, i));
      delay(10);
      pixels.show();
    }

    for (int i = 255; i > 0; i--) {                 // Purple Light
      if (layer != 1) return;
      pixels.setPixelColor(0, pixels.Color(i, 0, i));
      pixels.setPixelColor(1, pixels.Color(i, 0, i));
      pixels.setPixelColor(2, pixels.Color(i, 0, i));
      pixels.setPixelColor(3, pixels.Color(i, 0, i));
      pixels.setPixelColor(4, pixels.Color(i, 0, i));
      delay(10);
      pixels.show();
    }
  }
}

void rgb_fade_in_out() {
  if (layer != 0) {
    return;
  } else {
    for (int i = 0; i < 255; i++) {                 // Blue light
      if (layer != 0) return;
      pixels.setPixelColor(0, pixels.Color(0, 0, i));
      pixels.setPixelColor(1, pixels.Color(0, 0, i));
      pixels.setPixelColor(2, pixels.Color(0, 0, i));
      pixels.setPixelColor(3, pixels.Color(0, 0, i));
      pixels.setPixelColor(4, pixels.Color(0, 0, i));
      delay(10);
      pixels.show();
    }

    for (int i = 255; i > 0; i--) {                 // Blue light
      if (layer != 0) return;
      pixels.setPixelColor(0, pixels.Color(0, 0, i));
      pixels.setPixelColor(1, pixels.Color(0, 0, i));
      pixels.setPixelColor(2, pixels.Color(0, 0, i));
      pixels.setPixelColor(3, pixels.Color(0, 0, i));
      pixels.setPixelColor(4, pixels.Color(0, 0, i));
      delay(10);
      pixels.show();

    }

    for (int i = 0; i < 255; i++) {                 // Green light
      if (layer != 0) return;
      pixels.setPixelColor(0, pixels.Color(0, i, 0));
      pixels.setPixelColor(1, pixels.Color(0, i, 0));
      pixels.setPixelColor(2, pixels.Color(0, i, 0));
      pixels.setPixelColor(3, pixels.Color(0, i, 0));
      pixels.setPixelColor(4, pixels.Color(0, i, 0));
      delay(10);
      pixels.show();
    }

    for (int i = 255; i > 0; i--) {                 // Green light
      if (layer != 0) return;
      pixels.setPixelColor(0, pixels.Color(0, i, 0));
      pixels.setPixelColor(1, pixels.Color(0, i, 0));
      pixels.setPixelColor(2, pixels.Color(0, i, 0));
      pixels.setPixelColor(3, pixels.Color(0, i, 0));
      pixels.setPixelColor(4, pixels.Color(0, i, 0));
      delay(10);
      pixels.show();
    }

    for (int i = 0; i < 255; i++) {                 // Red light
      if (layer != 0) return;
      pixels.setPixelColor(0, pixels.Color(i, 0, 0));
      pixels.setPixelColor(1, pixels.Color(i, 0, 0));
      pixels.setPixelColor(2, pixels.Color(i, 0, 0));
      pixels.setPixelColor(3, pixels.Color(i, 0, 0));
      pixels.setPixelColor(4, pixels.Color(i, 0, 0));
      delay(10);
      pixels.show();
    }

    for (int i = 255; i > 0; i--) {                 // Red light
      if (layer != 0) return;
      pixels.setPixelColor(0, pixels.Color(i, 0, 0));
      pixels.setPixelColor(1, pixels.Color(i, 0, 0));
      pixels.setPixelColor(2, pixels.Color(i, 0, 0));
      pixels.setPixelColor(3, pixels.Color(i, 0, 0));
      pixels.setPixelColor(4, pixels.Color(i, 0, 0));
      delay(10);
      pixels.show();
    }
  }
}

int b = 0;
int led = 0;

bool red = false;
bool green = false;
bool blue = true;

void change_color() {
  if (red) {
    red = false;
    green = true;
    blue = false;
  } else if (green) {
    red = false;
    green = false;
    blue = true;
  } else if (blue) {
    red = true;
    green = false;
    blue = false;
  }
}

void rgb_snake() {
  for (led = 0; led < NUMPIXELS; led++) {
    for (b = 0; b < 255; b++) {
      red ? pixels.setPixelColor(led, pixels.Color(b, 0, 0)) : green ? pixels.setPixelColor(led, pixels.Color(0, b, 0)) : blue ? pixels.setPixelColor(led, pixels.Color(0, 0, b)) : pixels.setPixelColor(led, pixels.Color(0, 0, b));
      delay(1);
      pixels.show();
    }
  }

  delay(1000);
  /*
    for (led = NUMPIXELS; led >= 0; led--) {
    for (b = 255; b >= 0; b--) {
      red ? pixels.setPixelColor(led, pixels.Color(b, 0, 0)) : green ? pixels.setPixelColor(led, pixels.Color(0, b, 0)) : blue ? pixels.setPixelColor(led, pixels.Color(0, 0, b)) : pixels.setPixelColor(led, pixels.Color(0, 0, b));
      delay(1);
      pixels.show();
    }
    } */

  for (led = 0; led < NUMPIXELS; led++) {
    for (b = 255; b >= 0; b--) {
      red ? pixels.setPixelColor(led, pixels.Color(b, 0, 0)) : green ? pixels.setPixelColor(led, pixels.Color(0, b, 0)) : blue ? pixels.setPixelColor(led, pixels.Color(0, 0, b)) : pixels.setPixelColor(led, pixels.Color(0, 0, b));
      delay(1);
      pixels.show();
    }
  }
  delay(1000);
}





//---- RGB-Color functions ----//


//---- Second Core ----//
//---- Handling NeoPixel RGB's ----//

void setup1() {
  Serial.begin(9600);
  pixels.begin();
  pixels.clear();
}

void loop1() {
  /*
    if (Serial.available()) {
    command = Serial.readStringUntil('\n');

    if (command == "rgb fade") {
      rgb_fade = true;
      comb_fade = false;
      stp = 1;
      delay(100);
      stp = 0;
      rgb_fade_in_out();
      Serial.println("rgb fade set");
    }
    else if (command == "comb fade") {
      rgb_fade = false;
      comb_fade = true;
      stp = 1;
      delay(100);
      stp = 0;
      combination_rgb_fade();
      Serial.println("combination fade set");
    }
    }

    if (rgb_fade) rgb_fade_in_out();
    else if (comb_fade) combination_rgb_fade();
  */
  switch (layer) {
    case 0:
      rgb_fade_in_out();
      break;
    case 1:
      combination_rgb_fade();
      break;
    default:
      rgb_snake();
  }

}

//---- Second Core ----//

//---- First Core ----//

void key_n() {
  Keyboard.print("d");
}

void key_map(
  void key1(), void key2(), void key3(), void key4(),
  void key5(), void key6(), void key7(), void key8(),
  void key9(), void key10(), void key11(), void key12()
)
{
  col_1 = digitalRead(COLS[0]);
  col_2 = digitalRead(COLS[1]);
  col_3 = digitalRead(COLS[2]);
  col_4 = digitalRead(COLS[3]);

  if (col_1 == LOW) { // COLUMN 1 == LOW
    digitalWrite(ROW_1, HIGH); // SET ROW 1 = HIGH
    col_1 = digitalRead(COLS[0]);
    if (col_1 == LOW) {
      digitalWrite(ROW_2, HIGH);
      col_1 = digitalRead(COLS[0]);
      if (col_1 == LOW) {
        Serial.println("COL 1 | ROW 3"); // COL 1 ROW 3
        key9();
      } else key5(); // COL 1 ROW 2
    } else key1(); // COL 1 ROW 1
  } else if (col_2 == LOW) {
    digitalWrite(ROW_1, HIGH); // SET ROW 1 = HIGH
    col_2 = digitalRead(COLS[1]);
    if (col_2 == LOW) {
      digitalWrite(ROW_2, HIGH);
      col_2 = digitalRead(COLS[1]);
      if (col_2 == LOW) {
        Serial.println("COL 2 | ROW 3"); // COL 2 ROW 3
        key10();
      } else key6(); // COL 2 ROW 2
    } else key2(); // COL 2 ROW 1
  } else if (col_3 == LOW) {
    digitalWrite(ROW_1, HIGH); // SET ROW 1 = HIGH
    col_3 = digitalRead(COLS[2]);
    if (col_3 == LOW) {
      digitalWrite(ROW_2, HIGH);
      col_3 = digitalRead(COLS[2]);
      if (col_3 == LOW) {
        Serial.println("COL 3 | ROW 3"); // COL 3 ROW 3
        key11();
      } else key7(); // COL 3 ROW 2
    } else key3(); // COL 3 ROW 1
  } else if (col_4 == LOW) {
    digitalWrite(ROW_1, HIGH); // SET ROW 1 = HIGH
    col_4 = digitalRead(COLS[3]);
    if (col_4 == LOW) {
      digitalWrite(ROW_2, HIGH);
      col_4 = digitalRead(COLS[3]);
      if (col_4 == LOW) {
        Serial.println("COL 4 | ROW 3"); // COL 4 ROW 3
        key12();
      } else key8(); // COL 4 ROW 2
    } else key4(); // COL 4 ROW 1
  } else {
    digitalWrite(ROW_1, LOW);
    digitalWrite(ROW_2, LOW);
    digitalWrite(ROW_3, LOW);
  }
  delay(100);
}

void change_layer() {
  if (layer < 1) {
    layer += 1;
  } else layer = 0;
}

String command[3];

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
}

int c = 0;

void loop() {
  if (Serial.available() > 0) {
    Serial.println("Hello from RP2040!");
    if (c <= 2) {
      command[c] = Serial.readStringUntil('\n');
      Serial.println(c);
      c += 1;
    } 
    if (c > 2) {
      Serial.println(command[0]);
      Serial.println(command[1]);
      Serial.println(command[2]);
      c = 0;
    }
  }
  if (layer == 0) {
    key_map(
      win_log, vs_code, browser, alt_tab,
      kill_task, npm_start, key_n, key_n,
      change_layer, key_n, key_n, change_color
    );
  } else if (layer == 1) {
    key_map(
      key_n, key_n, key_n, alt_tab,
      kill_task, key_n, key_n, npm_start,
      change_layer, key_n, key_n, change_color
    );
  }
}

//---- First Core ----//
