
class AD8232_ECG {
  private:
    int plusL;
    int minusL;
    int frequency;
  public:
      AD8232_ECG(int plusL, int minusL, int frequency) {
      this->plusL  = plusL ;
      this->minusL = minusL;
      this->frequency = frequency;     
    }
    bool create(){
      pinMode(plusL, INPUT); // Setup for leads off detection LO +
      pinMode(minusL, INPUT); // Setup for leads off detection LO -
      return true;
    }
    int getValue(){
        if((digitalRead(plusL) == 1)||(digitalRead(minusL) == 1)){
           return -1;
        }
        else
        {    
           return analogRead(A0);
        }
        delay(frequency);
    }
};

AD8232_ECG ecg = AD8232_ECG(6, 7, 1);
void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  ecg.create();
}



void loop() 
{
  Serial.print(ecg.getValue());
}
