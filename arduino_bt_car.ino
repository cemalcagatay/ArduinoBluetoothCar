
/*##################################
###    CEMAL  ÇAĞATAY            ###
###    2018                      ###
###    cemalcagatay@yandex.com   ###
##################################*/



/*##########################
###     SABİTLER         ###    //Bu kısımda bluetoot tan gelen verileri tanımladık. 
##########################*/

char OKUNAN_DEGER = 0; 
char ON_FARLARI_YAK ='W';
char ON_FARLARI_SONDUR ='w';

char ARKA_FARLARI_YAK ='U';
char ARKA_FARLARI_SONDUR ='u';

char KORNA_CAL ='V';
char KORNA_KAPA ='v';

char DORTLU_YAK ='X';
char DORTLU_SONDUR ='x';

char ILERI = 'F';
char GERI = 'B';
char SAG = 'R';
char SOL = 'L';

char ILERI_SAG = 'I';
char ILERI_SOL = 'G';
char GERI_SAG = 'J';
char GERI_SOL = 'H';

char TUM_MOTORLARI_DURDUR = 'S';
char TUMUNU_DURDUR = 'D';

bool DORTLU_YANSIN_MI=false;   //bu kısımda her motor hereketine bağlı led yanma söz konusu olduğu için led kontrolü yaptırmak için bool olarak tanımladık.
bool SIREN_CALSIN_MI=false;
bool KORNA_CALSIN_MI=false;

bool ON_FAR_YANIYOR_MU=false;
bool ARKA_FAR_YANIYOR_MU=false;

bool SAG_FARLAR_YANIYOR_MU=false;
bool SOL_FARLAR_YANIYOR_MU=false;

/*##########################
###     PİNLER           ###    //bu kısımda arduinoya bağlı pin girişlerini tanımladık.
##########################*/

int MOTOR_IG_KIRMIZI=9;
int MOTOR_IG_BEYAZ=10;

int MOTOR_SS_KIRMIZI=11;
int MOTOR_SS_BEYAZ=12;

int ARKA_FAR_SAG=6;
int ARKA_FAR_SOL=8;
int ON_FAR_SAG=5;
int ON_FAR_SOL=7;


int BUZZER=4;



void setup() {

  Serial.begin(9600);             //bluetoot haberleşmesi için serial bağlantısını sağladık.
  
  pinMode(MOTOR_IG_KIRMIZI,OUTPUT);  // burada pinleri çıkış pin i olarak tanımladık.   //Kırmızı + olan
  pinMode(MOTOR_IG_BEYAZ,OUTPUT);    //Beyaz - olan
  pinMode(MOTOR_SS_KIRMIZI,OUTPUT);
  pinMode(MOTOR_SS_BEYAZ,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  pinMode(ON_FAR_SAG,OUTPUT);
  pinMode(ON_FAR_SOL,OUTPUT);
  pinMode(ARKA_FAR_SOL,OUTPUT);
  pinMode(ARKA_FAR_SAG,OUTPUT);
}

void loop() {
  
    if(Serial.available() > 0) //eğer seri bağlantı aktif ise
    {
       OKUNAN_DEGER = Serial.read();//bluetoothtan gelen değeri yakaladık.
       Serial.print(OKUNAN_DEGER);  //gelen değeri görmek için ekrana bastık.
       bluetoothDegerleriniOku();
    }  


  if(DORTLU_YANSIN_MI)    //Burada Led,korna,siren vb kontrolleri yaptırdık.
  {
    dortluYak();
  }
  else
  {
      dortluSondur();
  }

  if(KORNA_CALSIN_MI)
  {
    kornaCal();
  }
  else
  {
     noTone(BUZZER);
  }

  if(SIREN_CALSIN_MI)  
  {
        sirenCal();
  }
  else
  {
     noTone(BUZZER);
  }
}

/*##########################
###     FONKSİYONLAR     ###
##########################*/


void bluetoothDegerleriniOku()    //bu kısımda bluetoot verilerini okuttuk.
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


void ileriGit(){                             //Burada aracın ileri gitmesini sağlayan metodu yazdık.
  digitalWrite(MOTOR_IG_KIRMIZI,HIGH);
  digitalWrite(MOTOR_IG_BEYAZ,LOW);
}

void geriGit(){                              //Burada aracın geri gitmesini ve geri gelirken hem arka lamba hemde siren çalmasını sağlayan metodu yazdık.
  digitalWrite(MOTOR_IG_KIRMIZI,LOW);
  digitalWrite(MOTOR_IG_BEYAZ,HIGH);
  SIREN_CALSIN_MI=true;
  digitalWrite(ARKA_FAR_SAG, HIGH); 
  digitalWrite(ARKA_FAR_SOL, HIGH); 
  ARKA_FAR_YANIYOR_MU=true;
}


void solaDondur(){                            //Burada aracın sola dönmesini ve sol sinyallerinin yanmasını sağlayan metodu yazdık.
  digitalWrite(MOTOR_SS_KIRMIZI,HIGH);
  digitalWrite(MOTOR_SS_BEYAZ,LOW);
  digitalWrite(MOTOR_SS_BEYAZ,LOW);  
  digitalWrite(ON_FAR_SOL, HIGH); 
  digitalWrite(ARKA_FAR_SOL, HIGH);
  SOL_FARLAR_YANIYOR_MU=true;
}

void sagaDondur(){                            //Burada aracın sağa dönmesini ve sağ sinyallerinin yanmasını sağlayan metodu yazdık.
  digitalWrite(MOTOR_SS_KIRMIZI,LOW);
  digitalWrite(MOTOR_SS_BEYAZ,HIGH);
  digitalWrite(ON_FAR_SAG, HIGH); 
  digitalWrite(ARKA_FAR_SAG, HIGH);
  SAG_FARLAR_YANIYOR_MU=true;
}

void ileriSagaGit(){                        //Burada aracın ileri ve sağa gitmesini sağlayan metodu yazdık.  
  ileriGit();
  sagaDondur();
}

void ileriSolaGit(){                        //Burada aracın ileri ve sola gitmesini sağlayan metodu yazdık.   
  ileriGit();
  solaDondur();
}

void geriSagaGit(){                         //Burada aracın geri ve sağa gitmesini sağlayan metodu yazdık.
  geriGit();
  sagaDondur();
}

void geriSolaGit(){                         //Burada aracın geri ve sola gitmesini sağlayan metodu yazdık.
  geriGit();
  solaDondur();
}

void tumMotorlariDurdur(){                  //Bu kısımda bluetoot tan hiçbir veri gelmemesi halinde aaracın hiçbirşey yapmaması için tüm motor led vb. kontrolleri durdurduk
  digitalWrite(MOTOR_SS_KIRMIZI,LOW);
  digitalWrite(MOTOR_SS_BEYAZ,LOW);
  digitalWrite(MOTOR_IG_KIRMIZI,LOW);
  digitalWrite(MOTOR_IG_BEYAZ,LOW);
  SIREN_CALSIN_MI=false;
  digitalWrite(ARKA_FAR_SAG, LOW);
  digitalWrite(ARKA_FAR_SOL, LOW);
  digitalWrite(ON_FAR_SAG, LOW);
  digitalWrite(ON_FAR_SOL, LOW);
  ARKA_FAR_YANIYOR_MU=false;
  SAG_FARLAR_YANIYOR_MU=false;
  SOL_FARLAR_YANIYOR_MU=false;
}

void kornaCal(){                          //Bu kısımda araçta çalacak olan kornanın tonlarını içeren metodu yazdık.
  //tone(pin,frekans,süre)
  tone(BUZZER, 3000,250); //250 milisaniye ses çal.
  delay(400); //400 milisaniye dur.
  tone(BUZZER, 3000,800); //800 milisaniye ses çal.
  delay(2000); //2000 milisaniye dur.   
}

void sirenCal(){                          //Bu kısımada aracın geri gelirken çalması gereken siren metodunu yazdık. 
  tone(BUZZER, 3000,250); //250 milisaniye ses çal.
  delay(300); //400 milisaniye dur.  
}

void dortluYak(){                         //Bu kısımda aracın tüm farlarının(dörtlü) yanıp sönmesini sağlayan metodu yazdık.
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

void dortluSondur(){                      //Bu kısımda dörtlülerin sönmesini sağlayan kontrolleri yaptırdık.
  
  if(ARKA_FAR_YANIYOR_MU!=true) 
  {

    if(SOL_FARLAR_YANIYOR_MU!=true)
    {
        digitalWrite(ARKA_FAR_SOL, LOW);
    }
   
    if(SAG_FARLAR_YANIYOR_MU!=true)
    {
         digitalWrite(ARKA_FAR_SAG, LOW);
    }
     ARKA_FAR_YANIYOR_MU=false;
  }

  if(ON_FAR_YANIYOR_MU!=true) 
  {

     if(SOL_FARLAR_YANIYOR_MU!=true)
    {
        digitalWrite(ON_FAR_SOL, LOW);
    }
   
    if(SAG_FARLAR_YANIYOR_MU!=true)
    {
         digitalWrite(ON_FAR_SAG, LOW);
    }
    
    ON_FAR_YANIYOR_MU=false;
  }
}
