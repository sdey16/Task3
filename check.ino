String str,sub;
int i,j,k,l,poso[10],posw[10],m=0,n=0,flag=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>1){
  str = Serial.readString();
  sub = Serial.readString();
  for(i=0;i<str.length();i++)
  {
    if(sub[0]==str[i])
    {
      k=i;
      for(j=0,l=k;j<sub.length();j++,l++)
      {
        if(str[l]==sub[j])
        {
          flag=1;
          i=l;
        }
        else{
          flag=0;
          i=k+1;
          break;
        }
      }
      if(flag==1)
      {
        poso[m]=i;
        m++;
      }
    }
  }
  for(i=0;i<str.length();i++)
  {
    if(sub[0]==str[i])
    {
      k=i;
      for(j=0,l=k;j<sub.length();j++,l++)
      {
        if(str[l]==sub[j])
        {
          flag=1;
          i=k+1;
        }
        else{
          flag=0;
          i=k+1;
          break;
        }
      }
      if(flag==1)
      {
        posw[n]=i;
        n++;
      }
    }
  }
  Serial.println("Without overlap:");
  for(i=0;i<sizeof(posw)/sizeof(int);i++)
  {
    Serial.print(posw[i]);
  }
    Serial.println("With overlap:");
  for(i=0;i<sizeof(poso)/sizeof(int);i++)
  {
    Serial.print(poso[i]);
  }
}}
