int diodePin = A0;
int sensorValue = 0;
int sensorVoltage = 0;
int avg[10] = {0,0,0,0,0,0,0,0,0,0};
int avgTotal = 0;
int div10 = 0;
int middle[50];
int midAvg = 0;
int i = 0;
int j = 0;
int k = 0;
int kLast = 0;
int sensorMult = 0;
int comp = 0;
int BP5 = 0;
int BP4 = 0;
int BP3 = 0;
int BP2 = 0;
int BP1 = 0;
int BP0 = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  for(j = 0; j < 20; j++){
    middle[j] = 0;
  }
  j = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(diodePin);
  sensorVoltage = sensorValue*(5000/1024);
  avgTotal += sensorVoltage;
  avgTotal -= avg[i];
  div10 = avgTotal/10;
  avg[i] = sensorVoltage;
  i++;
  if(i==10){
    i = 0;
  }


  /* ALL THIS STUFF WAS MADE FOR CRUDE HEARTRATE*/
  /*
  //every 1 seconds, take a comp value to determine frequency from
  j++;
  if(j == 100){
    j = 0;
    comp = sensorVoltage;
  }
  //for 4, 4 second moving windows, check whats up.
  k++;

  if(k != 1200){
    if(div10 == comp && div10 != kLast){
      //count it as a hit;
      BP5++;
      BP4++;
      BP3++;
      BP2++;
      BP1++;
      BP0++;
    }
  }
  if(k==100 || k==700){
    //Serial.println(BP0/2*10);
    BP0 = 0;
  }
  else if(k==200 || k==800){
    //Serial.println(BP1/2*10);
    BP1 = 0;
  }
  else if(k==300 || k==900){
    //Serial.println(BP2/2*10);
    BP2 = 0;
  }
  else if(k==400 || k==1000){
    //Serial.println(BP3/2*10);
    BP3 = 0;
  }
  else if(k==500 || k==1100){
    //Serial.println(BP4/2*10);
    BP4 = 0;
  }
  else if(k==600|| k == 1200){
    //Serial.println(BP5/2*10);
    BP5 = 0;
    if(k=1200)k = 0;
  }
*/

  //records this reading for next loop
 // kLast = div10;
  Serial.println(avgTotal/10);
  //Serial.println(sensorVoltage);
  //Serial.print(" ");
  //Serial.println(BP4*15);
  delay(10);
}
