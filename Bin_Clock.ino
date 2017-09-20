int second=0,minute=0,hour=0;
int mswi=0,hswi=0,i;
int msep,hsep;
unsigned long pTick=0;
void setup() //Setup Input and Output 
{
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
 
}

void loop() 
{
  unsigned long cTick=millis();
  
  if(cTick-pTick>1000)
  {
    pTick=cTick;
    second++;
  }
  if(second>=60)
  {
    minute++;
    second=0;//reset seconds after overflow
  }
  if(minute==60)
  {
    hour++;
    minute=0;//reset minute after overflow
  }
  if(hour==24)
  {
    hour=0;//reset hour after overflow
    minute=5;//due to the absense of rtc, at the end of the day you will get 5 minutes delay so to compensate this error i manually add 5 minutes. 
  }
  
  msep=minute%10;//seperate lower digit
  hsep=hour%10;//seperate lower digit

  //mintues lower digit
      if(msep == 1 || msep == 3 || msep == 5 || msep == 7 || msep == 9)
      {
       digitalWrite(1,HIGH);} else { digitalWrite(1,LOW);}
      if(msep == 2 || msep == 3 || msep == 6 || msep == 7)
      {
       digitalWrite(2,HIGH);} else { digitalWrite(2,LOW);}
      if(msep == 4 || msep == 5 || msep == 6 || msep == 7)
      {
        digitalWrite(3,HIGH);} else { digitalWrite(3,LOW);}
      if(msep == 8 || msep == 9)
      {
        digitalWrite(4,HIGH);} else { digitalWrite(4,LOW);}
      
      //minutes upper digit
      if((minute >= 10 && minute < 20) || (minute >= 30 && minute < 40) ||  (minute >= 50 && minute <60))
      {digitalWrite(5,HIGH);}else{digitalWrite(5,LOW);}
      if(minute >= 20 && minute < 40) 
      {digitalWrite(6,HIGH);}else{digitalWrite(6,LOW);}
      if(minute >= 40 && minute < 60)
      {digitalWrite(7,HIGH);}else{digitalWrite(7,LOW);}

      //hour lower digit
       if(hsep == 1 || hsep == 3 || hsep == 5 || hsep == 7 || hsep == 9)
      {
       digitalWrite(8,HIGH);} else { digitalWrite(8,LOW);}
      if(hsep == 2 || hsep == 3 || hsep == 6 || hsep == 7)
      {
       digitalWrite(9,HIGH);} else { digitalWrite(9,LOW);}
      if(hsep == 4 || hsep == 5 || hsep == 6 || hsep == 7)
      {
        digitalWrite(10,HIGH);} else { digitalWrite(10,LOW);}
      if(hsep == 8 || hsep == 9)
      {
        digitalWrite(11,HIGH);} else { digitalWrite(11,LOW);}

      //hour
       if(hour >= 10 && hour < 20) 
       {digitalWrite(12, HIGH);} else {digitalWrite(12,LOW);}
       if(hour >= 20 && hour < 24) 
       {digitalWrite(13, HIGH);} else {digitalWrite(13,LOW);}
    
    mswi = analogRead(A0);
    if(mswi>1000){
      minute++;
      second=0;
      delay(500);
    }
    
    hswi = analogRead(A5);
    if(hswi>1000){
      hour++;
      second=0;
      delay(500);
    }
   
 }

