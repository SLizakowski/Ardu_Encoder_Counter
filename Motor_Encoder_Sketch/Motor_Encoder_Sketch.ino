//variables
int Apin = A0;  //A click
int Bpin = A5;  //B click
int NewA = 0;
int NewB = 0;
int OldA = 0;
int OldB = 0;
int pulsePin = 0;  //Pin5 is where the pulse sensor purple wire connects
int failCount = 0;    //Failure Movement Count
int count = 0;    // Movement Count
int sensorValue = 0;        // value read from the pot
int sensorValue2 = 0;        // value read from the pot
int i=0;

void setup() {
  // declare the pins as an OUTPUT:
  pinMode(Apin, INPUT);
  pinMode(Bpin, INPUT);
  Serial.begin(9600); 

}

void loop() {  
  sensorValue = analogRead (Apin);
  sensorValue2 = analogRead (Bpin);

  // map it to the range of the analog out:
  if (sensorValue < 512) {
    NewA = 0; 
  }
  else {
    NewA = 1; 
  }

  if (sensorValue2 < 512) {
    NewB = 0; 
  }
  else {
    NewB = 1; 
  }
  //  Serial.print("Sensors 1 and 2  ");
  //  Serial.print(sensorValue);
  //  Serial.print("  .  ");
  //  Serial.print(sensorValue2);
  //
  //
  //  Serial.print("        New A and B  ");
  //  Serial.print (NewA);
  //  Serial.print(" , ");
  //  Serial.print (NewB);
  //  Serial.print("       Old A and B  ");
  //  Serial.print (OldA);
  //  Serial.print(" , ");
  //  Serial.print (OldB);

  updateIt();

  //  Serial.print("        count equal  ");
  if (i++ % 10 == 0) {   // every 10th time, let's print it out, so we run faster.   % means modulo
    Serial.print(count); 
    Serial.print(", "); 
    Serial.println(failCount);
  }
  OldA = NewA;
  OldB = NewB;
}


void updateIt()
{

  if (OldA==0 && OldB==0) 
  {
    if (NewA==0 && NewB==0) {
      //nothing happens 
    }
    else if (NewA==0 && NewB==1){
      count++;
    }
    else if (NewA==1 && NewB==1){
      failCount++;
    }
    else if (NewA==1 && NewB==0){
      count--;
    }
  }
  else if (OldA==0 && OldB==1)
  {
    if (NewA==0 && NewB==0) {
      count--; 
    }
    else if (NewA==0 && NewB==1){
      //nothing happens
    }
    else if (NewA==1 && NewB==1){
      count++;
    }
    else if (NewA==1 && NewB==0){
      failCount++;
    }
  }  
  else if (OldA==1 && OldB==0)
  {
    if (NewA==0 && NewB==0) {
      count++;
    }
    else if (NewA==0 && NewB==1){
      failCount++;
    }
    else if (NewA==1 && NewB==1){
      count--;
    }
    else if (NewA==1 && NewB==0){
      //nothing happens
    }
  }    
  else if (OldA==1 && OldB==1)
  {
    if (NewA==0 && NewB==0) {
      failCount;
    }
    else if (NewA==0 && NewB==1){
      count--;
    }
    else if (NewA==1 && NewB==1){
      //nothing happens
    }
    else if (NewA==1 && NewB==0){
      count++;
    }
  }


}



