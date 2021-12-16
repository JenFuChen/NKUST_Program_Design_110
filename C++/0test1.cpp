int read = 0;
int check = 0;
int Q = 0;
int Qba = 0;
void setup() {
    pinMode(2, OUTPUT);   // CLK
    pinMode(3, OUTPUT);   // PR
    pinMode(4, OUTPUT);   // CLR
    pinMode(5, OUTPUT);   // J
    pinMode(6, OUTPUT);   // K
    pinMode(7, INPUT);    // Q
    pinMode(8, INPUT);    // Q'
    pinMode(9, OUTPUT);   // LED
    pinMode(10, OUTPUT);  // LED_Wrong
    Serial.begin(9600);
    // Preset
    digitalWrite(3, 0);
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    Q = digitalRead(7);
    Qba = digitalRead(8);
    digitalWrite(2, 0);
    delay(500);
    digitalWrite(2, 1);
    delay(500);
    if (Q == 1 && Qba == 0) {
        check += 1;
    }
    // Clear
    digitalWrite(3, 1);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    Q = digitalRead(7);
    Qba = digitalRead(8);
    digitalWrite(2, 0);
    delay(500);
    digitalWrite(2, 1);
    delay(500);
    if (Q == 0 && Qba == 1) {
        check += 1;
    }
    // JK
    for (int i = 0; i < 4; i++) {
        digitalWrite(5, i & 0x01);  // J
        digitalWrite(6, i & 0x02);  // K
        if (i == 0 && Q == 0 && Qba == 1) {
            check += 1;
        }
        if (i == 1 && Q == 0 && Qba == 1) {
            check += 1;
        }
        if (i == 2 && Q == 1 && Qba == 0) {
            check += 1;
        }
        if (i == 3 && Q == 0 && Qba == 1) {
            check += 1;
        }
        digitalWrite(3, 1);  // PR
        digitalWrite(4, 1);  // CLR
        digitalWrite(2, 1);  // CLK
        delay(500);
        digitalWrite(2, 0);  // CLK
        
        Q = digitalRead(7);
        Qba = digitalRead(8);
    }
    //////
}
void loop() {
    Serial.print(check);
    delay(1000);
}