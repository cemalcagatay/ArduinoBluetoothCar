
# ArduinoBluetoothCar

Android Cihaz ile Bluetooth Kontrollü Oyuncak Araba

<img src="https://github.com/cemalcagatay/ArduinoBluetoothCar/blob/master/project.jpg"/>


# Android Uygulaması
<img src="https://github.com/cemalcagatay/ArduinoBluetoothCar/blob/master/android_app.PNG"/>

https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller&hl=tr


# bluetoothDegerleriniOku

```java
void bluetoothDegerleriniOku()    //bluetoot verilerini okuyor
{
    if(OKUNAN_DEGER==ON_FARLARI_YAK) {
        digitalWrite(ON_FAR_SAG, HIGH); 
        digitalWrite(ON_FAR_SOL, HIGH); 
        ON_FAR_YANIYOR_MU=true;
    }
    else if(OKUNAN_DEGER==ON_FARLARI_SONDUR){
        digitalWrite(ON_FAR_SAG, LOW); 
        digitalWrite(ON_FAR_SOL, LOW); 
            ON_FAR_YANIYOR_MU=false;
    }
    else if(OKUNAN_DEGER==ARKA_FARLARI_YAK){
          digitalWrite(ARKA_FAR_SAG, HIGH); 
          digitalWrite(ARKA_FAR_SOL, HIGH);
           ARKA_FAR_YANIYOR_MU=true;
    }
    else if(OKUNAN_DEGER==ARKA_FARLARI_SONDUR){    
           digitalWrite(ARKA_FAR_SAG, LOW); 
           digitalWrite(ARKA_FAR_SOL, LOW);
           ARKA_FAR_YANIYOR_MU=false;
    }
    else if(OKUNAN_DEGER==KORNA_CAL) {
         KORNA_CALSIN_MI=true;
    }
    else if(OKUNAN_DEGER==KORNA_KAPA) {
          KORNA_CALSIN_MI=false;
    }
    else if(OKUNAN_DEGER==DORTLU_YAK) {
      DORTLU_YANSIN_MI=true;
    }
    else if(OKUNAN_DEGER==DORTLU_SONDUR){
       DORTLU_YANSIN_MI=false;
    }
    else if(OKUNAN_DEGER==ILERI){
            ileriGit();
    }
    else if(OKUNAN_DEGER==GERI){
            geriGit();
    }
    else if(OKUNAN_DEGER==SAG)
    {
            sagaDondur();
    }
    else if(OKUNAN_DEGER==SOL){
            solaDondur();
    }
    else if(OKUNAN_DEGER==ILERI_SAG) {
            sagaDondur();
    }
    else if(OKUNAN_DEGER==ILERI_SOL){
           ileriSolaGit();
    }
    else if(OKUNAN_DEGER==GERI_SAG){
            geriSagaGit();
    }
    else if(OKUNAN_DEGER==GERI_SOL) {
            geriSolaGit();
    }
    else if(OKUNAN_DEGER==TUM_MOTORLARI_DURDUR) {
            tumMotorlariDurdur();
    }
}

```




```java

void ileriGit(){
  digitalWrite(MOTOR_IG_KIRMIZI,HIGH);
  digitalWrite(MOTOR_IG_BEYAZ,LOW);
}

void geriGit(){
  digitalWrite(MOTOR_IG_KIRMIZI,LOW);
  digitalWrite(MOTOR_IG_BEYAZ,HIGH);
  SIREN_CALSIN_MI=true;
  digitalWrite(ARKA_FAR_SAG, HIGH); 
  digitalWrite(ARKA_FAR_SOL, HIGH); 
  ARKA_FAR_YANIYOR_MU=true;
}


void solaDondur(){
  digitalWrite(MOTOR_SS_KIRMIZI,HIGH);
  digitalWrite(MOTOR_SS_BEYAZ,LOW);
  digitalWrite(MOTOR_SS_BEYAZ,LOW);  
  digitalWrite(ON_FAR_SOL, HIGH); 
  digitalWrite(ARKA_FAR_SOL, HIGH);
  SOL_FARLAR_YANIYOR_MU=true;
}

void sagaDondur(){
  digitalWrite(MOTOR_SS_KIRMIZI,LOW);
  digitalWrite(MOTOR_SS_BEYAZ,HIGH);
  digitalWrite(ON_FAR_SAG, HIGH); 
  digitalWrite(ARKA_FAR_SAG, HIGH);
  SAG_FARLAR_YANIYOR_MU=true;
}


```




```java

void kornaCal(){
  //tone(pin,frekans,süre)
  tone(BUZZER, 3000,250); //250 milisaniye ses çal.
  delay(400); //400 milisaniye dur.
  tone(BUZZER, 3000,800); //800 milisaniye ses çal.
  delay(2000); //2000 milisaniye dur.   
}

void sirenCal(){            //Geri gelirken
  tone(BUZZER, 3000,250); //250 milisaniye ses çal.
  delay(300); //400 milisaniye dur.  
}

void dortluYak(){
  digitalWrite(ON_FAR_SAG, HIGH);
  digitalWrite(ON_FAR_SOL, HIGH);
  digitalWrite(ARKA_FAR_SAG, HIGH);
  digitalWrite(ARKA_FAR_SOL, HIGH);
  delay(400);
  digitalWrite(ON_FAR_SAG, LOW);
  digitalWrite(ON_FAR_SOL, LOW);
  digitalWrite(ARKA_FAR_SAG, LOW);
  digitalWrite(ARKA_FAR_SOL, LOW);
  delay(400);
}

```

License
--------

    Copyright 2018 Cemal ÇAĞATAY.

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
