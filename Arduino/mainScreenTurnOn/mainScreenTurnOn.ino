/* Simple Serial ECHO script : Written by ScottC 03/07/2012 */

/* Use a variable called byteRead to temporarily store
   the data coming from the computer */
byte byteRead;

int led = 4;

String readString = String("");

void setup() {                
// Turn the Serial Protocol ON
  Serial.begin(9600);
  
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
  
}

void loop() {
   /*  check if data has been sent from the computer: */
  if (Serial.available()) {
    /* read the most recent byte */
    byteRead = Serial.read();
    /*ECHO the value that was read, back to the serial port. */
    Serial.write(byteRead);

    char readChar = char(byteRead);
    readString.concat(readChar);
           
    if (readString.length() > 10)
    {
        readString = "";
    }
  
    if (readChar == '\n')
    {
      /*if (readString.equals("ON\n"))
      {
          digitalWrite(led, HIGH);
      }
      
      if (readString.equals("OFF\n"))
      {
          digitalWrite(led, LOW);
      }
*/      
      if (readString.equals("TOGGLE\n"))
      {
          digitalWrite(led, HIGH);
          delay(1500);
          digitalWrite(led, LOW);
      }
      readString="";
    }
    
  }
}
