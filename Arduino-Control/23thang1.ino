#include <Servo.h>

// Cấu trúc lưu thông tin về servo
struct ServoPins {
  Servo servo;
  int servoPin;
  String servoName;
  int initialPosition;
};

ServoPins servoPins[] = {
  { Servo(), 9, "Base", 90 },
  { Servo(), 10, "Shoulder", 90 },
  { Servo(), 11, "Elbow", 130 },
  { Servo(), 12, "Gripper", 180 },
};

// Chiều dài các đoạn của cánh tay
const float L1 = 8.0; 
const float L2 = 8.0; 

// Chân kết nối HC-SR04
#define TRIGGER_PIN 3
#define ECHO_PIN 2

// Dữ liệu vị trí được lưu
const int MAX_POSITIONS = 20;
struct SavedPosition {
  int positions[4];
};
SavedPosition savedPositions[MAX_POSITIONS];
int positionCount = 0;

// Biến trạng thái
bool isReplaying = false;

// Khai báo các hàm
void detectObjectAndMoveToTarget();
void handleCommand(String command);
void moveToPosition(float x, float y, float z);
void moveServo(int servoIndex, int deltaAngle);
void saveCurrentPosition();
void replayPositions();
void clearSavedPositions();
void stopReplay();
float getDistance();

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    servoPins[i].servo.attach(servoPins[i].servoPin);
    servoPins[i].servo.write(servoPins[i].initialPosition);
  }

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.println("Robot Arm Initialized. Ready to receive commands.");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    handleCommand(command);
  }
}

void handleCommand(String command) {
  command.trim();

  if (command.startsWith("detect")) {
    detectObjectAndMoveToTarget();
  } else if (command.startsWith("SHOULDER_UP")) {
    moveServo(1, -10);
  } else if (command.startsWith("SHOULDER_DOWN")) {
    moveServo(1, 10);
  } else if (command.startsWith("BASE_LEFT")) {
    moveServo(0, -10);
  } else if (command.startsWith("BASE_RIGHT")) {
    moveServo(0, 10);
  } else if (command.startsWith("ELBOW_UP")) {
    moveServo(2, 10);
  } else if (command.startsWith("ELBOW_DOWN")) {
    moveServo(2, -10);
  } else if (command.startsWith("WRIST_UP")) {
    servoPins[3].servo.write(180);
  } else if (command.startsWith("WRIST_DOWN")) {
    servoPins[3].servo.write(165);
  } else if (command.startsWith("SAVE_POSITIONS")) {
    saveCurrentPosition();
  } else if (command.startsWith("REPLAY_POSITIONS")) {
    isReplaying = true;
    replayPositions();
  } else if (command.startsWith("STOP_REPLAY")) {
    stopReplay();
  } else if (command.startsWith("CLEAR_POSITIONS")) {
    clearSavedPositions();
  } else if (command.startsWith("SET_SERVO")) {
    setServoPosition(command);
  } else {
    Serial.println("Invalid command.");
  }
}


void setServoPosition(String command) {
  int servoIndex, angle;
  if (sscanf(command.c_str(), "SET_SERVO %d %d", &servoIndex, &angle) == 2) {
    if (servoIndex >= 0 && servoIndex < 4 && angle >= 0 && angle <= 180) {
      servoPins[servoIndex].servo.write(angle);

    } else {
      Serial.println("Invalid servo index or angle out of range (0-180).");
    }
  } 
}


void detectObjectAndMoveToTarget() {
  float distance = getDistance();

  if (distance > 2 && distance <= 10) {
    float x = 15.0;
    float z = 2.0;
    float y = distance;

    servoPins[3].servo.write(165);
    delay(2000);

    moveToPosition(x, y, z);
    servoPins[3].servo.write(180);
    delay(2000);

    servoPins[2].servo.write(165);
    delay(2000);

    moveToPosition(0, 13,2);
    servoPins[3].servo.write(165);
    delay(2000);
    servoPins[3].servo.write(180);
    // servoPins[3].servo.write(180);
    // moveToPosition(13, 0, 0);

  } else if (distance > 10) {
    Serial.println("Object detected but out of range (>10 cm).");
  } else {
    Serial.println("No object detected or out of valid range.");
  }
}

void moveServo(int servoIndex, int deltaAngle) {
  if (servoIndex >= 0 && servoIndex < 4) {
    int currentAngle = servoPins[servoIndex].servo.read();
    int newAngle = constrain(currentAngle + deltaAngle, 0, 180);
    servoPins[servoIndex].servo.write(newAngle);
  }
}

void saveCurrentPosition() {
  if (positionCount < MAX_POSITIONS) {
    for (int i = 0; i < 4; i++) {
      savedPositions[positionCount].positions[i] = servoPins[i].servo.read();
    }
    positionCount++;
    Serial.println("Position saved.");
  } else {
    Serial.println("Maximum number of positions reached.");
  }
}

void replayPositions() {
  if (positionCount == 0) {
    Serial.println("No positions saved.");
    return;
  }

  Serial.println("Replaying positions...");
  unsigned long lastUpdateTime = 0; // Thời điểm cuối cùng servo được cập nhật
  const unsigned long updateInterval = 3000; // Thời gian giữa các lần phát lại (ms)
  int currentPositionIndex = 0;

  while (isReplaying) {
    // Kiểm tra dữ liệu từ Serial để dừng replay
    if (Serial.available() > 0) {
      String command = Serial.readStringUntil('\n');
      command.trim();
      if (command.equals("STOP_REPLAY")) {
        stopReplay();
        break;
      }
    }

    // Cập nhật vị trí servo nếu đã đủ thời gian
    if (millis() - lastUpdateTime >= updateInterval) {
      lastUpdateTime = millis();

      // Di chuyển servo tới vị trí hiện tại
      for (int j = 0; j < 4; j++) {
        servoPins[j].servo.write(savedPositions[currentPositionIndex].positions[j]);
      }

      currentPositionIndex++; // Tới vị trí tiếp theo
      if (currentPositionIndex >= positionCount) {
        currentPositionIndex = 0; // Lặp lại từ đầu
      }
    }
  }
}


void stopReplay() {
  isReplaying = false;
  Serial.println("Replay stopped.");
}

void clearSavedPositions() {
  positionCount = 0;
  Serial.println("All saved positions cleared.");
}

float getDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = (duration * 0.0343) / 2;
  return distance;
}

void moveToPosition(float x, float y, float z) {
  float phi1 = atan2(y, x);
  float a = x - 5 * cos(phi1);
  float b = y - 5 * sin(phi1);
  float r = sqrt(a * a + b * b);
  float d = sqrt(r * r + z * z);

  if (d > (L1 + L2) || d < abs(L1 - L2)) {
    Serial.println("Position out of reach.");
    return;
  }

  float phi = atan2(z, r);
  float cosAngleShoulder = (L1 * L1 + d * d - L2 * L2) / (2 * L1 * d);
  float angleShoulderRad = acos(cosAngleShoulder) + phi;

  float cosAngleElbow = (L1 * L1 + L2 * L2 - d * d) / (2 * L1 * L2);
  float angleElbowRad = acos(cosAngleElbow);

  float angleBase = degrees(phi1);
  float angleShoulder = 180 - degrees(angleShoulderRad);
  float angleElbow = 35 + 180 - degrees(angleElbowRad);

  if (angleBase < 0 || angleBase > 180 || angleShoulder < 0 || angleShoulder > 180 || angleElbow < 0 || angleElbow > 180) {
    Serial.println("Calculated angles are out of range.");
    return;
  }

  servoPins[0].servo.write(angleBase);
  delay(2000);
  servoPins[1].servo.write(angleShoulder);
  delay(2000);
  servoPins[2].servo.write(angleElbow);
  delay(2000);
}
