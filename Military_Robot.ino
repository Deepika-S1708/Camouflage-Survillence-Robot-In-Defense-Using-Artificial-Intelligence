int in1=16;
int in2=17;
int in3=19;
int in4=18;

int in5_las=6;
int in6_las=7;

int in7_Metal=14;
int in8_Metal=15;

int relay1=2;
int relay2=3;
int relay3=4;
int relay4=5;

int ir=8;
int metal=9;
int laser=11;
char ch;
void setup() {
Serial.begin(9600);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

//pinMode(in5_las,OUTPUT);
//pinMode(in6_las,OUTPUT);

pinMode(in7_Metal,OUTPUT);
pinMode(in8_Metal,OUTPUT);

pinMode(relay1,OUTPUT);
pinMode(relay2,OUTPUT);
pinMode(relay3,OUTPUT);
pinMode(relay4,OUTPUT);

pinMode(laser,OUTPUT);

pinMode(ir,INPUT);
pinMode(metal,INPUT);

Serial.print("Military Robot");
delay(1000);
}

void loop() 
{
IR_Read();
}
void IR_Read()
{
  if(digitalRead(ir)==LOW)
  {
    STOP();
    Serial.print('A');
    while(1)
    {
      if(Serial.available()>0)
      {
        ch = Serial.read();
        if(ch == 'R')
           {  
            digitalWrite(relay4,HIGH);         
            digitalWrite(relay3,LOW);         
            digitalWrite(relay2,LOW);             
           }
          if(ch == 'G')
           {  
            digitalWrite(relay3,HIGH);        
            digitalWrite(relay4,LOW);         
            digitalWrite(relay2,LOW);               
           }
          if(ch == 'B')
           {
             // Serial.print("Slave 2 Work is Finished"); 
            digitalWrite(relay2,HIGH);
            digitalWrite(relay3,LOW);         
            digitalWrite(relay4,LOW);                       
           } 
           if(ch=='L')
           {
            digitalWrite(laser,HIGH);
            digitalWrite(relay1,HIGH);        
            digitalWrite(relay2,LOW);
            digitalWrite(relay3,LOW);         
            digitalWrite(relay4,LOW);  
            delay(2000);
            digitalWrite(relay1,LOW);        
            digitalWrite(laser,LOW);
            delay(2000);                
           } 
            if(ch == 'F')
           { 
            digitalWrite(relay1,LOW);        
            digitalWrite(relay2,LOW);
            digitalWrite(relay3,LOW);         
            digitalWrite(relay4,LOW);     
              FORWARD();
              while(1)
              { 
              loop();
              }                
           }            
            if(ch=='U')
           {
            digitalWrite(laser,HIGH);
            digitalWrite(in5_las,HIGH);
            digitalWrite(in6_las,LOW);
            delay(1000);
             digitalWrite(in5_las,HIGH);
            digitalWrite(in6_las,HIGH);
            delay(500);
            digitalWrite(relay1,HIGH);        
            digitalWrite(relay2,LOW);
            digitalWrite(relay3,LOW);         
            digitalWrite(relay4,LOW);  
            delay(2000);
            digitalWrite(relay1,LOW);        
            digitalWrite(laser,LOW);
            
            delay(2000);    
            digitalWrite(in5_las,LOW);
            digitalWrite(in6_las,HIGH);
            delay(1000);   
            digitalWrite(in5_las,LOW);
            digitalWrite(in6_las,LOW);
            delay(500);              
           } 
           if(ch=='S')
           {
            FORWARD();
            delay(3000);
            STOP();
            delay(1000);
            LEFT();
            delay(1000);
            STOP();
           } 
           if(ch=='H')
           {
            FORWARD();
            delay(3000);
            STOP();
            delay(1000);
            RIGHT();
            delay(1000);
            STOP(); 
            delay(1000);      
           } 
      }
    }
  }
  else
  {
//    Person();  
    Proximity();
        FORWARD();

  }
}
void Proximity()
{
  if(digitalRead(metal)==HIGH)
  {
    STOP();
  digitalWrite(in7_Metal,HIGH);
  digitalWrite(in8_Metal,LOW);
  delay(500);
  digitalWrite(in7_Metal,LOW);
  digitalWrite(in8_Metal,LOW);
  delay(1000);
  digitalWrite(in7_Metal,LOW);
  digitalWrite(in8_Metal,HIGH);
  delay(500);   
  digitalWrite(in7_Metal,LOW);
  digitalWrite(in8_Metal,LOW);
  delay(1000);   
  }
  else
  {
    FORWARD();
  }
}
void FORWARD()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  
} 
void REVERSE()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  
} 
void LEFT()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  
} 
void RIGHT()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  
} 
void STOP()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
} 
//void Person()
//{
//  digitalWrite(in5_las,HIGH);
//  digitalWrite(in6_las,LOW);
//  delay(1000);
//  digitalWrite(in5_las,LOW);
//  digitalWrite(in6_las,LOW);
//  delay(1000);
//  digitalWrite(in5_las,LOW);
//  digitalWrite(in6_las,HIGH);
//  delay(1000);
//}
