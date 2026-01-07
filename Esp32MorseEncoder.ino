const int ledPin = 5;
const int dotDelay = 200;

const char* letters[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "-.", // A-G
                     "....", "..", ".---", "-.-", ".-..", "--", "-.", // H-N
                    "---", ".--.", "--.-", ".-.", "...", "-", "..-", // O-U
                    "...-", ".--", "-..-", "-.--", "--.." // V-Z
                    };

const char* numbers[10] = {"-----", ".----", "..---", "...--", "....-",
                    ".....", "-....", "--...", "---..", "----."};

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  char ch;
  if (Serial.available() > 0) {
    ch = Serial.read();
    ch = toupper(ch);

    if (ch >= 'A' && ch <= 'Z') {
      morseCode(letters[ch - 'A']);
    }

    else if (ch >= '0' && ch <= '9') {
      morseCode(numbers[ch - '0']);
    }

    else if (ch == ' ') {
      delay(dotDelay * 4);
    }
  }
}

void morseCode(const char* pattern) {
  for (int i = 0; pattern[i] != '\0'; i++) {
    if (pattern[i] == '.') {
      dot();
    }
    else if (pattern[i] == '-') {
      dash();
    }
  }
  delay(dotDelay * 3);
}

void dot() {
  digitalWrite(ledPin, HIGH);
  delay(dotDelay);
  digitalWrite(ledPin, LOW);
  delay(dotDelay);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(dotDelay * 3);
  digitalWrite(ledPin, LOW);
  delay(dotDelay);
}
