#include <OneWire.h>
#include <DallasTemperature.h>

/*
Name:    Display.ino
Created:  10/19/2015 7:16:32 PM
Author: canikrause
*/



int PINO_TERMOMETRO = 2;

int digito1 = 12;
int digito2 = 10;
int digito3 = 11;

int a = 5;
int b = 6;
int c = 7;
int d = 9;
int e = 8;
int f = 4;
int g = 3;

int contador;
int arraySize;

char bufferTemperatura[1];

OneWire oneWire(PINO_TERMOMETRO);
DallasTemperature sensors(&oneWire);

DeviceAddress sensor1;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(digito1,OUTPUT);
  pinMode(digito2,OUTPUT);
  pinMode(digito3,OUTPUT);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  LocalizarSensor();
  
}

// the loop function runs over and over again until power down or reset
void loop() {
  
  //digitalWrite(digito1,HIGH);
  DisplayNumber(digito1,8);
  //delay(1000);
  //digitalWrite(digito1,LOW);
  ///digitalWrite(digito2,HIGH);
  //DisplayNumber(digito2,2);
  //delay(1000);
  //digitalWrite(digito2,LOW);
  //DisplayNumber(digito3,6);

  sensors.requestTemperatures();
  int temperatura = sensors.getTempC(sensor1);
  Serial.println((int)temperatura);
  
  dtostrf(temperatura,1,0,bufferTemperatura);
  Serial.println(bufferTemperatura[0]);
  Serial.println(bufferTemperatura[1]);

  contador = 0;
  arraySize =  sizeof(bufferTemperatura);

  Serial.println("Contador: " + contador);
  Serial.println("Tamanho do Array da Temperatura" + arraySize);
  
  for (contador = 0; contador < arraySize - 1; contador++)
  {
    if(contador = 0)
    {
      Serial.println("Escreve valor");
      DisplayNumber(digito1,(int)bufferTemperatura[contador]);
    }
    else
    {
      //DisplayNumber(digito2,(int)buffer[i]);
    }
    
  }

  contador = 0;
  delay(1000);
 
}

void LocalizarSensor()
{
  sensors.begin();
  // Localiza e mostra enderecos dos sensores
  Serial.println("Localizando sensores DS18B20...");
  Serial.print("Foram encontrados ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" sensores.");
  if (!sensors.getAddress(sensor1, 0)) 
    Serial.println("Sensores nao encontrados !"); 
}

void DisplayNumber(int digito,int numero)
{
  digitalWrite(digito,HIGH);

  byte number1[] = {1,0,0,1,1,1,1};
  byte number2[] = {0,0,1,0,0,1,0};
  byte number3[] = {0,0,0,0,1,1,0};
  byte number4[] = {1,0,0,1,1,0,0};
  byte number5[] = {0,1,0,0,1,0,0};
  byte number6[] = {0,1,0,0,0,0,0};
  byte number7[] = {0,0,0,1,1,1,1};
  byte number8[] = {0,0,0,0,0,0,0};
  byte number9[] = {0,0,0,0,1,0,0};
  byte number0[] = {0,0,0,0,0,0,1};

  switch (numero)
  {
  case 1:
    digitalWrite(a,number1[0]);
    digitalWrite(b,number1[1]);
    digitalWrite(c,number1[2]);
    digitalWrite(d,number1[3]);
    digitalWrite(e,number1[4]);
    digitalWrite(f,number1[5]);
    digitalWrite(g,number1[6]);
    break;
  case 2:
    digitalWrite(a,number2[0]);
    digitalWrite(b,number2[1]);
    digitalWrite(c,number2[2]);
    digitalWrite(d,number2[3]);
    digitalWrite(e,number2[4]);
    digitalWrite(f,number2[5]);
    digitalWrite(g,number2[6]);
    break;
  case 3:
    digitalWrite(a,number3[0]);
    digitalWrite(b,number3[1]);
    digitalWrite(c,number3[2]);
    digitalWrite(d,number3[3]);
    digitalWrite(e,number3[4]);
    digitalWrite(f,number3[5]);
    digitalWrite(g,number3[6]);
    break;
  case 4:
    digitalWrite(a,number4[0]);
    digitalWrite(b,number4[1]);
    digitalWrite(c,number4[2]);
    digitalWrite(d,number4[3]);
    digitalWrite(e,number4[4]);
    digitalWrite(f,number4[5]);
    digitalWrite(g,number4[6]);
    break;
  case 5:
    digitalWrite(a,number5[0]);
    digitalWrite(b,number5[1]);
    digitalWrite(c,number5[2]);
    digitalWrite(d,number5[3]);
    digitalWrite(e,number5[4]);
    digitalWrite(f,number5[5]);
    digitalWrite(g,number5[6]);
    break;
  case 6:
    digitalWrite(a,number6[0]);
    digitalWrite(b,number6[1]);
    digitalWrite(c,number6[2]);
    digitalWrite(d,number6[3]);
    digitalWrite(e,number6[4]);
    digitalWrite(f,number6[5]);
    digitalWrite(g,number6[6]);
    break;
  case 7:
    digitalWrite(a,number7[0]);
    digitalWrite(b,number7[1]);
    digitalWrite(c,number7[2]);
    digitalWrite(d,number7[3]);
    digitalWrite(e,number7[4]);
    digitalWrite(f,number7[5]);
    digitalWrite(g,number7[6]);
    break;
  case 8:
    digitalWrite(a,number8[0]);
    digitalWrite(b,number8[1]);
    digitalWrite(c,number8[2]);
    digitalWrite(d,number8[3]);
    digitalWrite(e,number8[4]);
    digitalWrite(f,number8[5]);
    digitalWrite(g,number8[6]);
    break;
  case 9:
    digitalWrite(a,number9[0]);
    digitalWrite(b,number9[1]);
    digitalWrite(c,number9[2]);
    digitalWrite(d,number9[3]);
    digitalWrite(e,number9[4]);
    digitalWrite(f,number9[5]);
    digitalWrite(g,number9[6]);
    break;
  case 0:
    digitalWrite(a,number0[0]);
    digitalWrite(b,number0[1]);
    digitalWrite(c,number0[2]);
    digitalWrite(d,number0[3]);
    digitalWrite(e,number0[4]);
    digitalWrite(f,number0[5]);
    digitalWrite(g,number0[6]);
    break;
  default:
    break;
  }
  digitalWrite(digito,LOW);

}
