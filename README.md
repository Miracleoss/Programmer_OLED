# Programmer_OLED
## 此readme只作为指引，详细内容在另一分支-master 中
## 芯片
### stm32f103cbt6/HK32f103cbt6
- 这里注意 这两个芯片的flash是128k的。
- 代码的量是大于64k的，不能用小于128k的芯片
## 开发环境
### keil5 + STM32CubeMX
## 语言
### C语言-HAL库
## 项目简介
### 本项目使用软件IIC来驱动OLED，显示一些有趣的小动画
- OLED的芯片是 SSD1306
- OLED尺寸是0.96英寸
- 小动画包括：进度条、汉字显示、代码逐行显示

