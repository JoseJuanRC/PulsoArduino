const int min_frequency = 300;
const int max_frequency = 1500;
const int wave_period_time = 50000;
volatile float timer;
volatile int current_frequency;
volatile byte state = LOW;

void setup( ){
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop( ){
  timer = sin(PI*(millis())/wave_period_time);
  current_frequency = override_map(timer, -1, 1, min_frequency, max_frequency);
  digitalWrite(LED_BUILTIN, state); 
  delay (current_frequency); 
  state = !state;
}

int override_map(float x, float in_min, float in_max, int out_min, int out_max) {
  return (int)((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}
