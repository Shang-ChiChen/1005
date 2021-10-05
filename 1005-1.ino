void setup() {
  Serial.begin(115200);
  pinMode(13, INPUT);

  ledcSetup(0, 5000, 8);
  ledcAttachPin(14, 0);
}

void loop() {
  int input = analogRead(13);
  input = min(input, 300);    
  int input_map = 255-map(input, 0, 300, 0, 255);
  Serial.println(input_map);         

  ledcWrite(0, input_map);
}
