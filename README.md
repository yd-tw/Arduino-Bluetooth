# Arduino-Bluetooth

- [專案介紹](#專案介紹) 
- [技術細節](#技術細節) 
- [製作歷程](#製作歷程) 
- [使用方法](#使用方法) 
- [注意事項](#注意事項) 

## 專案介紹
透過Arduino與HC-05藍芽模組實現將PS2搖桿與手機連線

## 技術細節
- Arduino
- HC-05藍牙模組
- PS2搖桿

## 製作歷程
- beta-1.0 完成藍牙模組傳送測試數據給手機終端機

## 使用方法
1. clone這個儲存庫
2. 安裝依賴庫：
    https://github.com/PaulStoffregen/SoftwareSerial
    https://github.com/madsci1016/Arduino-PS2X
3. 使用Arduino開啟並編譯上傳至開發版
4. 依照配線圖(未提供)連接電路
5. 至app/目錄安裝APK檔案至手機
6. 配對藍牙裝置，並開啟應用程式即可使用

## 注意事項
文件尚未編輯完畢，仍有部分資訊尚未添加完善。歡迎回報問題。