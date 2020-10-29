#define DELAY 500 // default delay (in ms)

// morse code reference table
char morse_code[][5] = {
  ".-",   //A
  "-...", //B
  "-.-.", //C
  "-..",  //D
  ".",    //E
  "..-.", //F
  "--.",  //G
  "....", //H
  "..",   //I
  ".---", //J
  "-.-",  //K
  ".-..", //L
  "--",   //M
  "-.",   //N
  "---",  //O
  ".--.", //P
  "--.-", //Q
  ".-.",  //R
  "...",  //S
  "-",    //T
  "..-",  //U
  "...-", //V
  ".--",  //W
  "-..-", //X
  "-.--", //Y
  "--..", //Z
};

// enter the message here (in CAPS)
char message[] = "THANK YOU";

// to get length of a string
short get_str_len(char str[]) {
  short str_len = 0;
  while(str[str_len] != '\0')
    str_len++;
  return(str_len);
}

void setup() {

  short letter_code_len = 0, message_len = 0;;
  
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

  // set the message length
  message_len = get_str_len(message);

  for(short letter = 0; letter < message_len; letter++) {

    if(message[letter] < 'A' || message[letter] > 'Z') {
      if(message[letter] == ' ') {
        delay(DELAY*7); // delay between words is 7 units
        continue;
      } else {
        // it's either not an alphabet/space or isn't in CAPS
        // fix your message
        return -1;
      }
    }

    // get letter's morse code's length
    letter_code_len = get_str_len(morse_code[((message[letter]) - 'A')]);

    // loop to indicate the code
    for(short len = 0; len < letter_code_len; len++) {
      
      // light up the LED
      digitalWrite(LED_BUILTIN, HIGH);
      
      if(morse_code[((message[letter]) - 'A')][len] == '.')
        delay(DELAY); // '.' must be equal to 1 unit
      else if(morse_code[((message[letter]) - 'A')][len] == '-')
        delay(DELAY*3); // '-' must be equal to 3 units

      // turn of the LED
      digitalWrite(LED_BUILTIN, LOW);

      // keep the LED turned off for DELAY ms
      delay(DELAY); // delay between letter's codes must be 1 unit
    }
    delay(DELAY*2); // delay between letters must be equal to 3 units
  }
}

void loop() {
  // didn't put anything here because I didn't want to repeat things
}
