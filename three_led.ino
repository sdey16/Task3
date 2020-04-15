int l1=5;
int l2=8;
int l3=11;
int num[3]={0,0,0};
int mul=1;
int i;
int t=0;

String in;

void setup()
{
  pinMode(l1,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
  digitalWrite(l1,HIGH);
  digitalWrite(l2,HIGH);
  digitalWrite(l3,HIGH);
}

void loop()
{
  //t=0;
  //int num[3]={0,0,0};

  in=Serial.readString();
  /*if(!(in[0]>='A'&&in[0]<='Z'))
  {
    Serial.println("Incorrect string");
    exit(1);
  }*/
  
  
    for(i=0;in[i]!='\0';i++)
    {
      if(in[i]=='A')
      {
        mul=1;
        while(in[i+1]!='B')
        {
          num[0]+=(in[i+1]-48)*mul;
          mul*=10;
          i++;
        }
      }
      if(in[i]=='B')
      {
        mul=1;
        while(in[i+1]!='C')
        {
          num[1]+=(in[i+1]-48)*mul;
          mul*=10;
          i++;
        }
      }
      if(in[i]=='C')
      {
        mul=1;
        while(in[i+1]!='\0')
        {
          num[2]+=(in[i+1]-48)*mul;
          mul*=10;
          i++;
        }
      }
    }
  
  Serial.println(num[0]);
  Serial.println(num[1]);
  Serial.println(num[2]);
  t = millis();
  Serial.println(t);
  while(millis() < t + num[0])
  {
    digitalWrite(l1,LOW);
  }
  while(millis() < t + num[1])
  {
    digitalWrite(l2,LOW);
  }
  while(millis() < t + num[2])
  {
    digitalWrite(l3,LOW);
  }
}
