#include "SevSeg.h"


#include <OneWire.h>
#include <DallasTemperature.h>

/*
Name:    Display.ino
Created:  10/19/2015 7:16:32 PM
Author: canikrause
*/


/* Termometro Ds18b20 */
int PINO_TERMOMETRO = 3;

byte numDigits = 3;
byte digitPins[] ={12,10,11};
byte segmentPins[] = {5,6,7,9,8,4,3};

SevSeg displaySeg;

int digito1 = 12;
int digito2 = 10;
int digito3 = 11;

int a = 5;
int b = 6;
int c = 7;
int d = 9;
int e = 8;
int f = 4;
int g = 2;

long intervalo = 6000;
long ultimaExecucao= 0;
float temperatura = 0;
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

	//displaySeg.begin(COMMON_CATHODE,numDigits,digitPins,segmentPins);
	LocalizarSensor();
	ObterTemperatura();
}

// the loop function runs over and over again until power down or reset
void loop() {

	unsigned long execucao = millis();
	/*Serial.print("MILLIS: ");
	Serial.print(execucao);
	Serial.println(" ");
	Serial.print("Ult: ");
	Serial.print(ultimaExecucao);
	Serial.println(" ");*/
	if(execucao - ultimaExecucao > intervalo)
	{
		ObterTemperatura();
		ultimaExecucao = millis();
	}


	ApresentaTemperatura();


}

float ObterTemperatura()
{
	byte data[12];
	byte addr[8];
	if ( !oneWire.search(addr)) {
		//no more sensors on chain, reset search
		oneWire.reset_search();
		return -1000;
	}
	if ( OneWire::crc8( addr, 7) != addr[7]) {
		Serial.println("CRC is not valid!");
		return -1000;
	}
	if ( addr[0] != 0x10 && addr[0] != 0x28) {
		Serial.print("Device is not recognized");
		return -1000;
	}
	oneWire.reset();
	oneWire.select(addr);
	oneWire.write(0x44,1); 
	byte present = oneWire.reset();
	oneWire.select(addr); 
	oneWire.write(0xBE); 

	for (int i = 0; i < 9; i++) { 
		data[i] = oneWire.read();
	}

	oneWire.reset_search();

	byte MSB = data[1];
	byte LSB = data[0];
	float TRead = ((MSB, 8) | LSB); 
	temperatura = TRead / 16;

}

void ApresentaTemperatura()
{
	int v = (int)temperatura;
	int n;
	n = v / 10;  
	v = v - (n*10);
	DisplayNumber(digito1,n);

	// Print decimal part - second digit  
	n = v / 10;
	v = v - (n*10);
	DisplayNumber(digito2,v);
}

void TesteTemperatura()
{
	//int antes = millis();
	int valorAnalogico = digitalRead(PINO_TERMOMETRO);
	temperatura= ( 5 * valorAnalogico * 100) / 1024;
	//sensors.requestTemperaturesByIndex(0);
	//temperatura = sensors.getTempC(sensor1);
	//int depois = millis();
	//Serial.println(depois-antes);
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

void check_pin(int pin, int b) {
	int pausa = 500;
	if (b == 0) {
		digitalWrite(pin, LOW); 
		delayMicroseconds(pausa);
		digitalWrite(pin, HIGH);  
	} else 
		digitalWrite(pin, HIGH);
}

void DisplayNumber(int digito,int numero)
{
	int pausa = 50;
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
		check_pin(a,number1[0]);
		check_pin(b,number1[1]);
		check_pin(c,number1[2]);
		check_pin(d,number1[3]);
		check_pin(e,number1[4]);
		check_pin(f,number1[5]);
		check_pin(g,number1[6]);
		break;
	case 2:
		check_pin(a,number2[0]);
		check_pin(b,number2[1]);
		check_pin(c,number2[2]);
		check_pin(d,number2[3]);
		check_pin(e,number2[4]);
		check_pin(f,number2[5]);
		check_pin(g,number2[6]);
		break;
	case 3:
		check_pin(a,number3[0]);
		check_pin(b,number3[1]);
		check_pin(c,number3[2]);
		check_pin(d,number3[3]);
		check_pin(e,number3[4]);
		check_pin(f,number3[5]);
		check_pin(g,number3[6]);
		break;
	case 4:
		check_pin(a,number4[0]);
		check_pin(b,number4[1]);
		check_pin(c,number4[2]);
		check_pin(d,number4[3]);
		check_pin(e,number4[4]);
		check_pin(f,number4[5]);
		check_pin(g,number4[6]);
		break;
	case 5:
		check_pin(a,number5[0]);
		check_pin(b,number5[1]);
		check_pin(c,number5[2]);
		check_pin(d,number5[3]);
		check_pin(e,number5[4]);
		check_pin(f,number5[5]);
		check_pin(g,number5[6]);
		break;
	case 6:
		check_pin(a,number6[0]);
		check_pin(b,number6[1]);
		check_pin(c,number6[2]);
		check_pin(d,number6[3]);
		check_pin(e,number6[4]);
		check_pin(f,number6[5]);
		check_pin(g,number6[6]);
		break;
	case 7:
		check_pin(a,number7[0]);
		check_pin(b,number7[1]);
		check_pin(c,number7[2]);
		check_pin(d,number7[3]);
		check_pin(e,number7[4]);
		check_pin(f,number7[5]);
		check_pin(g,number7[6]);
		break;
	case 8:
		check_pin(a,number8[0]);
		check_pin(b,number8[1]);
		check_pin(c,number8[2]);
		check_pin(d,number8[3]);
		check_pin(e,number8[4]);
		check_pin(f,number8[5]);
		check_pin(g,number8[6]);
		break;
	case 9:
		check_pin(a,number9[0]);
		check_pin(b,number9[1]);
		check_pin(c,number9[2]);
		check_pin(d,number9[3]);
		check_pin(e,number9[4]);
		check_pin(f,number9[5]);
		check_pin(g,number9[6]);
		break;
	case 0:
		check_pin(a,number0[0]);
		check_pin(b,number0[1]);
		check_pin(c,number0[2]);
		check_pin(d,number0[3]);
		check_pin(e,number0[4]);
		check_pin(f,number0[5]);
		check_pin(g,number0[6]);
		break;
	default:
		break;
	}

	digitalWrite(digito,LOW);

}
