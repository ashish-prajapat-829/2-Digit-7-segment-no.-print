#define a 12
#define b 11
#define c 10
#define d 9
#define e 8
#define f 7
#define g 6

#define d1 5
#define d2 4
int d11;
int d12;
int seg[7] = { a, b, c, d, e, f, g };

int digit[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },  // 0
  { 0, 1, 1, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1 },  // 2
  { 1, 1, 1, 1, 0, 0, 1 },  // 3
  { 0, 1, 1, 0, 0, 1, 1 },  // 4
  { 1, 0, 1, 1, 0, 1, 1 },  // 5
  { 1, 0, 1, 1, 1, 1, 1 },  // 6
  { 1, 1, 1, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1 },  // 8
  { 1, 1, 1, 1, 0, 1, 1 }   // 9
};

void setup() {

  for (int i = 0; i < 7; i++) {
    pinMode(seg[i], OUTPUT);
  }

  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 99; i++) {

    int d11 = i / 10;   // tens digit
    int d22 = i % 10;   // ones digit

      digitalWrite(d1, LOW);
      digitalWrite(d2, HIGH);

      for (int j = 0; j < 7; j++) {
        digitalWrite(seg[j], digit[d11][j]);
      }
      delay(100);

      
      digitalWrite(d1, HIGH);
      digitalWrite(d2, LOW);

      for (int j = 0; j < 7; j++) {
        digitalWrite(seg[j], digit[d22][j]);
      }
      delay(100);
  }
}