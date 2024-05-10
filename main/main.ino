#include <PS2X_lib.h>
#include <SoftwareSerial.h>

PS2X ps2x;
int error;

// 定義連接藍牙模組的序列埠
SoftwareSerial BT(5, 6);  // 接收腳, 傳送腳
char val;                 // 儲存接收資料的變數

void setup() {
  Serial.begin(9600);
  Serial.println("BT is ready!");

  // 設定藍牙模組的連線速率
  // 如果是HC-06，請改成9600
  BT.begin(9600);

  //配對接收器
  do {
    //GamePad(clock, command, attention, data, Pressures?, Rumble?)
    error = ps2x.config_gamepad(13, 11, 10, 12, true, true);  //這行要和接線對應正確
    if (error == 0) {
      Serial.print("Gamepad found!");
      break;
    } else {
      delay(100);
    }
  } while (1);
}

void loop() {
  ps2x.read_gamepad(false, 0);  //讀取手把狀態

  //測試每一個按鈕和搖桿
  if (ps2x.Button(PSB_START)) {  //Start鍵
    Serial.println("Start is being held");
    BT.print("Start is being held");
  }
  if (ps2x.Button(PSB_SELECT)) {  //Select鍵
    Serial.println("Select is being held");
    BT.print(val);
  }
  if (ps2x.Button(PSB_PAD_UP)) {  //十字方向，上
    Serial.print("Up held this hard: ");
    Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
  }
  if (ps2x.Button(PSB_PAD_RIGHT)) {  //十字方向，右
    Serial.print("Right held this hard: ");
    Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
  }
  if (ps2x.Button(PSB_PAD_LEFT)) {  //十字方向，左
    Serial.print("LEFT held this hard: ");
    Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
  }
  if (ps2x.Button(PSB_PAD_DOWN)) {  //十字方向，下
    Serial.print("DOWN held this hard: ");
    Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
  }
  if (ps2x.NewButtonState(PSB_L3))  //L3鍵，NewButtonState按下不管多久只會觸發兩次(按下和放開)
    Serial.println("L3 pressed");
  if (ps2x.NewButtonState(PSB_R3))  //R3鍵
    Serial.println("R3 pressed");
  if (ps2x.NewButtonState(PSB_L2))  //L2鍵
    Serial.println("L2 pressed");
  if (ps2x.NewButtonState(PSB_R2))  //R2鍵
    Serial.println("R2 pressed");
  if (ps2x.NewButtonState(PSB_TRIANGLE))  //三角按鍵
    Serial.println("Triangle pressed");
  if (ps2x.NewButtonState(PSB_CIRCLE))  //圓型按鍵
    Serial.println("Circle pressed");
  if (ps2x.NewButtonState(PSB_CROSS))  //X按鍵
    Serial.println("X pressed");
  if (ps2x.NewButtonState(PSB_SQUARE))  //方型按鍵
    Serial.println("Square pressed");

  if (ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) {  //按下L1或L2鍵，顯示兩個香菇頭的數值
    Serial.print("Stick Values:");
    Serial.print(ps2x.Analog(PSS_LY), DEC);  //左，上下
    Serial.print(",");
    Serial.print(ps2x.Analog(PSS_LX), DEC);  //左，左右
    Serial.print(",");
    Serial.print(ps2x.Analog(PSS_RY), DEC);  //右，上下
    Serial.print(",");
    Serial.println(ps2x.Analog(PSS_RX), DEC);  //右，左右
  }
  delay(10);
}