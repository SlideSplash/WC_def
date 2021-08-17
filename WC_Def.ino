/***************
  Projeto: Botão de pânico WC Deficientes
  Autor: Victor Correia
  Versao 1.0
  Git: https://github.com/SlideSplash/WC_def.git
  Data: 13/08/2021

***************/

#define PIN_ALARM 10
#define PIN_BUTTON_ALARM 4
#define PIN_BUTTON_RESET 5
#define LED_VERDE 6
#define LED_VERMELHO 7

bool flag = 0;

void setup() { 
  Serial.begin(9600);
  Serial.println("Projeto: Botão de pânico WC Deficientes");
  Serial.println("Autor: Victor Correia");
  Serial.println("Versao 1.0");
  Serial.println("Git: https://github.com/SlideSplash/WC_def.git");
  Serial.println("Data: 13/08/2021");
  
  pinMode(PIN_ALARM, OUTPUT);  
  digitalWrite(PIN_ALARM, HIGH);
  pinMode(LED_VERDE, OUTPUT);  
  digitalWrite(LED_VERDE, LOW);
  pinMode(LED_VERMELHO, OUTPUT);  
  digitalWrite(LED_VERMELHO, LOW); 
  pinMode(PIN_BUTTON_ALARM, INPUT);
  digitalWrite(PIN_BUTTON_ALARM, HIGH); 
  pinMode(PIN_BUTTON_RESET, INPUT);
  digitalWrite(PIN_BUTTON_RESET, HIGH);
  test_leds();
  digitalWrite(LED_VERDE, HIGH); 
}

void test_leds(){
  digitalWrite(LED_VERDE, HIGH);
  delay(500);
  digitalWrite(LED_VERDE, LOW);
  delay(500);
  digitalWrite(LED_VERDE, HIGH);
  delay(500);
  digitalWrite(LED_VERDE, LOW);
  delay(500);  
  digitalWrite(LED_VERMELHO, HIGH);
  delay(500);
  digitalWrite(LED_VERMELHO, LOW);
  delay(500);
  digitalWrite(LED_VERMELHO, HIGH);
  delay(500);
  digitalWrite(LED_VERMELHO, LOW);
  delay(500);;
}

void Alarm(){
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(PIN_ALARM, LOW);
  digitalWrite(LED_VERMELHO, HIGH);
  delay(1000);
  digitalWrite(PIN_ALARM, HIGH);
  digitalWrite(LED_VERMELHO, LOW);
  delay(1000);
}
void loop() {
  if(digitalRead(PIN_BUTTON_ALARM) == 0){
    flag = 1;
  }
  if(digitalRead(PIN_BUTTON_RESET) == 0){
    flag = 0;
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_VERDE, HIGH);
  }
  if(flag == 1){
    Alarm();
  }

}
