//---- Importing Libraries ----//

#include <Keyboard.h>
#include <String.h>

#include <Adafruit_NeoPixel.h>

//---- Libraries ----//

//---- Adafruit NeoPixel ----//

#define PIN 15

#define NUMPIXELS 5

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const int ENTER_TIME = 5500;

//---- Adafruit NeoPixel ----//


//---- Libraries ----//

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

const int SHORT_PRESS = 500;
const int LONG_PRESS = 1000;

int lastState = HIGH;
int currentState;

unsigned long pressedTime = 0;
unsigned long releasedTime = 0;

//---- Keypad Functions ----//

//---- Keypad Functions ----//

//---- First Core ----//

bool pressed = false;

//---- RGB-Color functions ----//

void red_layer() {
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

void green_layer() {
  for (int i = 0; i < 255; i++) {                 // Green light
    if (layer != 1) return;
    pixels.setPixelColor(0, pixels.Color(0, i, 0));
    pixels.setPixelColor(1, pixels.Color(0, i, 0));
    pixels.setPixelColor(2, pixels.Color(0, i, 0));
    pixels.setPixelColor(3, pixels.Color(0, i, 0));
    pixels.setPixelColor(4, pixels.Color(0, i, 0));
    delay(10);
    pixels.show();
  }

  for (int i = 255; i > 0; i--) {                 // Green light
    if (layer != 1) return;
    pixels.setPixelColor(0, pixels.Color(0, i, 0));
    pixels.setPixelColor(1, pixels.Color(0, i, 0));
    pixels.setPixelColor(2, pixels.Color(0, i, 0));
    pixels.setPixelColor(3, pixels.Color(0, i, 0));
    pixels.setPixelColor(4, pixels.Color(0, i, 0));
    delay(10);
    pixels.show();
  }
}

void blue_layer() {
  for (int i = 0; i < 255; i++) {                 // Blue light
    if (layer != 2) return;
    pixels.setPixelColor(0, pixels.Color(0, 0, i));
    pixels.setPixelColor(1, pixels.Color(0, 0, i));
    pixels.setPixelColor(2, pixels.Color(0, 0, i));
    pixels.setPixelColor(3, pixels.Color(0, 0, i));
    pixels.setPixelColor(4, pixels.Color(0, 0, i));
    delay(10);
    pixels.show();
  }

  for (int i = 255; i > 0; i--) {                 // Blue light
    if (layer != 2) return;
    pixels.setPixelColor(0, pixels.Color(0, 0, i));
    pixels.setPixelColor(1, pixels.Color(0, 0, i));
    pixels.setPixelColor(2, pixels.Color(0, 0, i));
    pixels.setPixelColor(3, pixels.Color(0, 0, i));
    pixels.setPixelColor(4, pixels.Color(0, 0, i));
    delay(10);
    pixels.show();

  }
}

//---- RGB-Color functions ----//

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

  if (col_1 == LOW && pressed == false) { // COLUMN 1 == LOW
    pressed = true;

    digitalWrite(ROW_1, HIGH); // SET ROW 1 = HIGH

    col_1 = digitalRead(COLS[0]);

    if (col_1 == LOW) {
      digitalWrite(ROW_2, HIGH);
      col_1 = digitalRead(COLS[0]);

      if (col_1 == LOW) {
        //Serial.println("COL 1 | ROW 3"); // COL 1 ROW 3
        key9();
      } else {
        //Serial.println("COL 1 | ROW 2");
        digitalWrite(ROW_2, LOW);
        key5(); // COL 1 ROW 2
      }
    } else {
      key1(); // COL 1 ROW 1
      digitalWrite(ROW_1, LOW); // SET ROW 1 = LOW
    }
  } else if (col_2 == LOW && pressed == false) {

    pressed = true;

    digitalWrite(ROW_1, HIGH); // SET ROW 1 = HIGH

    col_2 = digitalRead(COLS[1]);

    if (col_2 == LOW) {
      digitalWrite(ROW_2, HIGH);
      col_2 = digitalRead(COLS[1]);

      if (col_2 == LOW) {
        //Serial.println("COL 2 | ROW 3"); // COL 2 ROW 3
        key10();
      } else {
        key6(); // COL 2 ROW 2
        digitalWrite(ROW_2, LOW);
      }
    } else {
      key2(); // COL 2 ROW 1
      digitalWrite(ROW_1, LOW); // SET ROW 1 = LOW
    }
  } else if (col_3 == LOW && pressed == false) {

    pressed = true;

    digitalWrite(ROW_1, HIGH); // SET ROW 1 = HIGH

    col_3 = digitalRead(COLS[2]);

    if (col_3 == LOW) {
      digitalWrite(ROW_2, HIGH);
      col_3 = digitalRead(COLS[2]);

      if (col_3 == LOW) {
        //Serial.println("COL 3 | ROW 3"); // COL 3 ROW 3
        key11();
      } else {
        key7(); // COL 3 ROW 2
        digitalWrite(ROW_2, LOW);
      }
    } else {
      key3(); // COL 3 ROW 1
      digitalWrite(ROW_1, LOW); // SET ROW 1 = LOW
    }
  } else if (col_4 == LOW && pressed == false) {

    pressed = true;

    digitalWrite(ROW_1, HIGH); // SET ROW 1 = HIGH

    col_4 = digitalRead(COLS[3]);

    if (col_4 == LOW) {
      digitalWrite(ROW_2, HIGH);
      col_4 = digitalRead(COLS[3]);

      if (col_4 == LOW) {
        //Serial.println("COL 4 | ROW 3"); // COL 4 ROW 3
        key12();
      } else {
        key8(); // COL 4 ROW 2
        digitalWrite(ROW_2, LOW);
      }
    } else {
      key4(); // COL 4 ROW 1
      digitalWrite(ROW_1, LOW); // SET ROW 1 = LOW
    }
  } else if (col_1 == HIGH && col_2 == HIGH && col_3 == HIGH && col_4 == HIGH) {
    digitalWrite(ROW_1, LOW);
    digitalWrite(ROW_2, LOW);
    digitalWrite(ROW_3, LOW);
    pressed = false;
  }
  delay(100);
}

void change_layer() {
  if (layer < 2) {
    layer += 1;
  } else layer = 0;
  Serial.println("l" + String(layer));
}

String *command;

String str_111;
String str_112;
String str_113;
String str_114;
String url_1;

String str_211;
String str_212;
String str_213;
String str_214;
String url_5;

String str_311;
String str_312;
String str_313;
String str_314;
String url_9;

String str_121;
String str_122;
String str_123;
String str_124;
String url_2;

String str_221;
String str_222;
String str_223;
String str_224;
String url_6;

String str_321;
String str_322;
String str_323;
String str_324;
String url_10;

String str_131;
String str_132;
String str_133;
String str_134;
String url_3;

String str_231;
String str_232;
String str_233;
String str_234;
String url_7;

String str_331;
String str_332;
String str_333;
String str_334;
String url_11;

String str_141;
String str_142;
String str_143;
String str_144;
String url_4;

String str_241;
String str_242;
String str_243;
String str_244;
String url_8;

String str_341;
String str_342;
String str_343;
String str_344;
String url_12;

String stroke_1;
String stroke_2;
String stroke_3;
String stroke_4;

String url;

int btn_row;
int btn_col;

int m = 19;

String keymap[12];

void check_key(String comm) {
  stroke_1 = comm.substring(1, 4);
  stroke_2 = comm.substring(5, 8);
  stroke_3 = comm.substring(9, 12);
  stroke_4 = comm.substring(13, 16);
  while (comm[m] != '~') {
    url += comm[m];
    m++;
  }
  btn_row = comm.substring(m + 5, m + 6).toInt();
  btn_col = comm.substring(m + 7).toInt();

  if (btn_row == 1 && btn_col == 1) {
    str_111 = stroke_1;
    str_112 = stroke_2;
    str_113 = stroke_3;
    str_114 = stroke_4;
    url_1 = url;
  } else if (btn_row == 1 && btn_col == 2) {
    str_121 = stroke_1;
    str_122 = stroke_2;
    str_123 = stroke_3;
    str_124 = stroke_4;
    url_2 = url;
  } else if (btn_row == 1 && btn_col == 3) {
    str_131 = stroke_1;
    str_132 = stroke_2;
    str_133 = stroke_3;
    str_134 = stroke_4;
    url_3 = url;
  } else if (btn_row == 1 && btn_col == 4) {
    str_141 = stroke_1;
    str_142 = stroke_2;
    str_143 = stroke_3;
    str_144 = stroke_4;
    url_4 = url;
  } else if (btn_row == 2 && btn_col == 1) {
    str_211 = stroke_1;
    str_212 = stroke_2;
    str_213 = stroke_3;
    str_214 = stroke_4;
    url_5 = url;
  } else if (btn_row == 2 && btn_col == 2) {
    str_221 = stroke_1;
    str_222 = stroke_2;
    str_223 = stroke_3;
    str_224 = stroke_4;
    url_6 = url;
  } else if (btn_row == 2 && btn_col == 3) {
    str_231 = stroke_1;
    str_232 = stroke_2;
    str_233 = stroke_3;
    str_234 = stroke_4;
    url_7 = url;
  } else if (btn_row == 2 && btn_col == 4) {
    str_241 = stroke_1;
    str_242 = stroke_2;
    str_243 = stroke_3;
    str_244 = stroke_4;
    url_8 = url;
  } else if (btn_row == 3 && btn_col == 1) {
    str_311 = stroke_1;
    str_312 = stroke_2;
    str_313 = stroke_3;
    str_314 = stroke_4;
    url_9 = url;
  } else if (btn_row == 3 && btn_col == 2) {
    str_321 = stroke_1;
    str_322 = stroke_2;
    str_323 = stroke_3;
    str_324 = stroke_4;
    url_10 = url;
  } else if (btn_row == 3 && btn_col == 3) {
    str_331 = stroke_1;
    str_332 = stroke_2;
    str_333 = stroke_3;
    str_334 = stroke_4;
    url_11 = url;
  } else if (btn_row == 3 && btn_col == 4) {
    str_341 = stroke_1;
    str_342 = stroke_2;
    str_343 = stroke_3;
    str_344 = stroke_4;
    url_12 = url;
  }

  delay(100);

  stroke_1 = "";
  stroke_2 = "";
  stroke_3 = "";
  stroke_4 = "";
  url = "";
  comm = "";

}


void alt_tab() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
}

void win_log() {
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.print("02082010");
}

void kill_task() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.releaseAll();
}

void browser() {
  Keyboard.press(128);
  Keyboard.press(129);
  Keyboard.press(130);
  Keyboard.write(98);
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

void prompt() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('r');
  delay(100);
  Keyboard.releaseAll();
  Keyboard.print("cmd");
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.releaseAll();
  Keyboard.print("prompt WIN_32: ");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  Keyboard.print("cls");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}
void ser_1() {
  Keyboard.press(int(str_111.toInt()));
  delay(5);
  Keyboard.press(int(str_112.toInt()));
  delay(5);
  Keyboard.press(int(str_113.toInt()));
  delay(5);
  Keyboard.press(int(str_114.toInt()));
  delay(5);
  Keyboard.releaseAll();
  if (url_1 != "000") {
    delay(ENTER_TIME);
    Keyboard.print(url_1);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
}

void ser_2() {
  Keyboard.press(int(str_121.toInt()));
  delay(5);
  Keyboard.press(int(str_122.toInt()));
  delay(5);
  Keyboard.press(int(str_123.toInt()));
  delay(5);
  Keyboard.press(int(str_124.toInt()));
  delay(5);
  Keyboard.releaseAll();
  if (url_2 != "000") {
    delay(ENTER_TIME);
    Keyboard.print(url_2);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
}

void ser_3() {
  Keyboard.press(int(str_131.toInt()));
  delay(5);
  Keyboard.press(int(str_132.toInt()));
  delay(5);
  Keyboard.press(int(str_133.toInt()));
  delay(5);
  Keyboard.press(int(str_134.toInt()));
  delay(5);
  Keyboard.releaseAll();
  if (url_3 != "000") {
    delay(ENTER_TIME);
    Keyboard.print(url_3);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
}

void ser_4() {
  Keyboard.press(int(str_141.toInt()));
  delay(5);
  Keyboard.press(int(str_142.toInt()));
  delay(5);
  Keyboard.press(int(str_143.toInt()));
  delay(5);
  Keyboard.press(int(str_144.toInt()));
  delay(5);
  Keyboard.releaseAll();
  if (url_4 != "000") {
    delay(ENTER_TIME);
    Keyboard.print(url_4);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
}



void ser_5() {
  Keyboard.press(int(str_211.toInt()));
  delay(5);
  Keyboard.press(int(str_212.toInt()));
  delay(5);
  Keyboard.press(int(str_213.toInt()));
  delay(5);
  Keyboard.press(int(str_214.toInt()));
  delay(5);
  Keyboard.releaseAll();
  if (url_1 != "000") {
    delay(ENTER_TIME);
    Keyboard.print(url_1);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
}

void ser_6() {
  Keyboard.press(int(str_221.toInt()));
  delay(5);
  Keyboard.press(int(str_222.toInt()));
  delay(5);
  Keyboard.press(int(str_223.toInt()));
  delay(5);
  Keyboard.press(int(str_224.toInt()));
  delay(5);
  Keyboard.releaseAll();
  if (url_6 != "000") {
    delay(ENTER_TIME);
    Keyboard.print(url_6);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
}

void ser_7() {
  Keyboard.press(int(str_231.toInt()));
  delay(5);
  Keyboard.press(int(str_232.toInt()));
  delay(5);
  Keyboard.press(int(str_233.toInt()));
  delay(5);
  Keyboard.press(int(str_234.toInt()));
  delay(5);
  Keyboard.releaseAll();
  if (url_7 != "000") {
    delay(ENTER_TIME);
    Keyboard.print(url_7);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
}

void ser_8() {
  Keyboard.press(int(str_241.toInt()));
  delay(5);
  Keyboard.press(int(str_242.toInt()));
  delay(5);
  Keyboard.press(int(str_243.toInt()));
  delay(5);
  Keyboard.press(int(str_244.toInt()));
  delay(5);
  Keyboard.releaseAll();
  if (url_8 != "000") {
    delay(ENTER_TIME);
    Keyboard.print(url_8);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
}



void ser_9() {
  Keyboard.press(int(str_311.toInt()));
  delay(5);
  Keyboard.press(int(str_312.toInt()));
  delay(5);
  Keyboard.press(int(str_313.toInt()));
  delay(5);
  Keyboard.press(int(str_314.toInt()));
  delay(5);
  Keyboard.releaseAll();
  if (url_9 != "000") {
    delay(ENTER_TIME);
    Keyboard.print(url_9);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
}

void ser_10() {
  Keyboard.press(int(str_321.toInt()));
  delay(5);
  Keyboard.press(int(str_322.toInt()));
  delay(5);
  Keyboard.press(int(str_323.toInt()));
  delay(5);
  Keyboard.press(int(str_324.toInt()));
  delay(5);
  Keyboard.releaseAll();
  if (url_10 != "000") {
    delay(ENTER_TIME);
    Keyboard.print(url_10);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
}

void ser_11() {
  Keyboard.press(int(str_331.toInt()));
  delay(5);
  Keyboard.press(int(str_332.toInt()));
  delay(5);
  Keyboard.press(int(str_333.toInt()));
  delay(5);
  Keyboard.press(int(str_334.toInt()));
  delay(5);
  Keyboard.releaseAll();
  if (url_11 != "000") {
    delay(ENTER_TIME);
    Keyboard.print(url_11);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
}

void ser_12() {
  Keyboard.press(int(str_341.toInt()));
  delay(5);
  Keyboard.press(int(str_342.toInt()));
  delay(5);
  Keyboard.press(int(str_343.toInt()));
  delay(5);
  Keyboard.press(int(str_344.toInt()));
  delay(5);
  Keyboard.releaseAll();
  if (url_12 != "000") {
    delay(ENTER_TIME);
    Keyboard.print(url_12);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }
}

void key_n() {
  Keyboard.print("n");
}


void setup1() {
  Serial.begin(9600);
  pixels.begin();
  pixels.clear();
}

void loop1() {
  switch (layer) {
    case 0:
      red_layer();
      break;
    case 1:
      green_layer();
      break;
    case 2:
      blue_layer();
      break;
  }
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
}

int c = 0;
int k = 0;

int key_map_array[3][4];

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    check_key(command);
    m = 19;
    delay(100);
  }
  if (layer == 0) {
    
  }
  if (layer == 0) {
    key_map(
      win_log, vs_code, browser, alt_tab,
      kill_task, npm_start, key_n, key_n,
      change_layer, key_n, key_n, key_n
    );
  } else if (layer == 1) {
    key_map(
      browser, prompt, key_n, alt_tab,
      kill_task, key_n, key_n, npm_start,
      change_layer, key_n, key_n, key_n
    );
  } else if (layer == 2) {
    key_map(
      ser_1, ser_2, ser_3, ser_4,
      ser_5, ser_6, ser_7, ser_8,
      change_layer, ser_10, ser_11, ser_12
    );
  }
}

//---- First Core ----//
