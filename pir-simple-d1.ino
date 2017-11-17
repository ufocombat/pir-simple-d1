int ledPin = 13;  // инициализируем пин для светодиода
int inputPin = D8;  // инициализируем пин для получения сигнала от пироэлектрического датчика движения
int pirState = LOW;  // начинаем работу программы, предполагая, что движения нет
int val = 0;  // переменная для чтения состояния пина

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  pinMode(ledPin, OUTPUT);  // объявляем светодиод в качестве  OUTPUT
  pinMode(inputPin, INPUT);  // объявляем датчик в качестве INPUT
  Serial.begin(9600);
  delay(1000);
}

void loop(){
  val = digitalRead(inputPin);  // считываем значение с датчика
  if (val == HIGH) {  // проверяем, соответствует ли считанное значение HIGH
    digitalWrite(ledPin, HIGH);  // включаем светодиод
    if (pirState == LOW) {
    // мы только что включили
    Serial.println("Motion detected!");
    // мы выводим на серийный монитор изменение, а не состояние
    pirState = HIGH;
    digitalWrite(LED_BUILTIN, LOW);
    }
  } else {
    digitalWrite(ledPin, LOW); // выключаем светодиод
    if (pirState == HIGH){
      // мы только что его выключили
      Serial.println("Motion ended!");
      // мы выводим на серийный монитор изменение, а не состояние
      pirState = LOW;
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }
}
