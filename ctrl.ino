void setup() {
  Serial.begin(9600);
  delay(2000);
}

#define THRESHOLD 700

uint8_t key_ctrl[8] = { 0, 0, 0xe0, 0, 0, 0, 0, 0 };
uint8_t key_win[8] = { 0, 0, 0xe3, 0, 0, 0, 0, 0 };
uint8_t key_z[8]    = { 0, 0, 0x1d, 0, 0, 0, 0, 0 };
uint8_t key_none[8] = { 0, 0, 0,    0, 0, 0, 0, 0 };
uint8_t key_slash[8] = { 0, 0, 0x38, 0, 0, 0, 0, 0 }

void loop() {
  static int last_ctrl = 0;
  int input1 = analogRead(5);
  int input2 = analogRead(6);
  
  if(last_ctrl && input1 < THRESHOLD) {
    last_ctrl = 0;
  }
  
  else if(!last_ctrl && input1 > THRESHOLD) {
    last_ctrl = 1;
    if (input2 > THRESHOLD) {
      Serial.write(key_slash, 8);
      Serial.write(key_none, 8);
    }
    else {
      Serial.write(key_win, 8);
      Serial.write(key_z, 8);
      Serial.write(key_none, 8);
    }
  }
}

