#define DIODA_CZERWONA 8
#define DIODA_ZIELONA 9
#define CZUJNIK_OKNA 10

void setup() 
{
  Serial.begin(9600);

  pinMode(DIODA_CZERWONA, OUTPUT);
  pinMode(DIODA_ZIELONA, OUTPUT);
  pinMode(CZUJNIK_OKNA, INPUT_PULLUP);

  digitalWrite(DIODA_CZERWONA, LOW);
  digitalWrite(DIODA_ZIELONA, LOW);
}

void loop() 
{
  if(digitalRead(CZUJNIK_OKNA) == LOW){
    digitalWrite(DIODA_ZIELONA, HIGH);
    digitalWrite(DIODA_CZERWONA, LOW);
  }
  else{
    digitalWrite(DIODA_ZIELONA, LOW);
    digitalWrite(DIODA_CZERWONA, HIGH);
    Serial.println("Uwaga!! Alarm!! It's a trap");

    while (digitalRead(CZUJNIK_OKNA) == HIGH){
      delay(25);
    }
  }
}
