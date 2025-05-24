#ifndef __ANIMATION_H
#define __ANIMATION_H

#include "headfile.h"
// 定义画面ID
typedef enum
{
    SCREEN_PROGRESSBAR = 0, // 进度条 动画
    SCREEN_CHINESE = 1,     // 中文：“你好，程序员” 动画
    SCREEN_CODE = 2,   // 代码：“Hello, World!” 动画
    SCREEN_FLOWER = 3, //  花绽放的过渡 动画
	SCREEN_STOP = 4
} ScreenID;

// 声明 当前页面ID
extern volatile ScreenID currentScreen;

void AnimationManager_Handle(void);

void ShowProgressBar(void);
void ShowResult(void);
void ShowChinese(void);
void ShowCode(void);

void OLED_Typewriter(int x, int y,  char *str, const Font *font, int delay_ms);

void OLED_TypewriterLine(int x, int y, char *str, const Font *font, int delay_ms);
void OLED_TypewriterCodePaged(int x, int y, const Font *font, int delay_ms);
#endif
