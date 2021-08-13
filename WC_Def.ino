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
  pinMode(PIN_BUTTON_ALARM, INPUT);
  digitalWrite(PIN_BUTTON_ALARM, HIGH); 
  pinMode(PIN_BUTTON_RESET, INPUT);
  digitalWrite(PIN_BUTTON_RESET, HIGH); 
}

void Alarm(){
  digitalWrite(PIN_ALARM, LOW);
  delay(1000);
  digitalWrite(PIN_ALARM, HIGH);
  delay(1000);
}
void loop() {
  if(digitalRead(PIN_BUTTON_ALARM) == 0){
    flag = 1;
  }
  if(digitalRead(PIN_BUTTON_RESET) == 0){
    flag = 0;
  }
  if(flag == 1){
    Alarm();
  }

}
