int l=0,x,y,z,val=0,index=0,p[300],r=0,i=0;
String num;
int l1=5;
int l2=8;
int l3=11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(l1,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  num = Serial.readString();
  x=num[0];
  y=num[1];
  for(l=2,i=0;l<num.length();l++,i++)
  {
    z=num[l];
    val=(x-48)*100+10*(y-48)+(z-48);
    for(r=0;r<=i;r++)
    {
      if(val==p[r])
      {
        index=1;
        break;
      }
      else index=0;
    }
    if(index==0)
    {
      p[i]=val;
      digitalWrite(l1,x);
      digitalWrite(l2,y);
      digitalWrite(l3,z);
    }
  }
}
