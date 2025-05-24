#include "animation.h"
#include "headfile.h"

// 当前页面ID
volatile ScreenID currentScreen = SCREEN_PROGRESSBAR; // 定义并初始化变量

// 总处理函数
void AnimationManager_Handle()
{
    switch (currentScreen)
    {
    case SCREEN_PROGRESSBAR:
        ShowProgressBar();
        break;
    case SCREEN_CHINESE:
        ShowChinese();
        break;
    case SCREEN_CODE:
        ShowCode();
        break;
    case SCREEN_FLOWER:
        // ShowFlower();
        for (int i = 0; i < 10; i++)
        {
            OLED_NewFrame();
            OLED_PrintString(0, 20, ".", &font16x16, OLED_COLOR_NORMAL);
            OLED_ShowFrame();

            OLED_NewFrame();
            OLED_PrintString(0, 20, "..", &font16x16, OLED_COLOR_NORMAL);
            OLED_ShowFrame();

            OLED_NewFrame();
            OLED_PrintString(0, 20, "...", &font16x16, OLED_COLOR_NORMAL);
            OLED_ShowFrame();
        }

        OLED_NewFrame();
        OLED_PrintString(0, 20, "Hello World!", &font16x16, OLED_COLOR_NORMAL);
		OLED_PrintString(0,40,"--------------------",&font16x16, OLED_COLOR_NORMAL);
        OLED_ShowFrame();
		HAL_Delay(2000);
		currentScreen = SCREEN_STOP;
        break;
    default:
        break;
    }
}

// 写其他三个函数的时候 记得把当前帧索引 加以区分。
// 指针数组 也要有命名区分
// 动画 的帧 的名字 也要区分

// 然后 要想一下 什么时候 停止一个 动画 开始另一个动画
void ShowProgressBar()
{
    static int currentFrame = 0;                         // 当前帧索引
    const Image *frame = animation_frames[currentFrame]; // 包含所有动画帧的指针数组

    OLED_NewFrame();
    OLED_DrawImage(5, 0, frame, OLED_COLOR_NORMAL);
    OLED_ShowFrame();

    //  更新帧索引
    currentFrame = (currentFrame + 1) % 66;
    // 66是动画帧的数量

    if (currentFrame == 0)
    {
        currentScreen = SCREEN_CHINESE; // 切换到下一个动画
    }
}

// void ShowResult()
//{
//	OLED_Printstring(0, 20, "你好", &font16x16, OLED_COLOR_NORMAL);
//     for(int i = 0; i < 50; i++)
//     {
//
//       //  OLED_Printstring(0, 20, "q", &font16x16, OLED_COLOR_NORMAL);
//

//
//        OLED_Printstring(0, 20, "qrw", &font16x16, OLED_COLOR_NORMAL);
//        OLED_ShowFrame();

//        OLED_NewFrame();
//        OLED_Printstring(0, 20, "...", &font16x16, OLED_COLOR_NORMAL);
//        OLED_ShowFrame();
//    }
//}

void ShowChinese()
{
    // OLED_PrintString(0, 20, "...", &font16x16, OLED_COLOR_NORMAL);
    // HAL_Delay(2000);
    // OLED_PrintString(0, 20, "你|", &font16x16, OLED_COLOR_NORMAL);
    // HAL_Delay(500);
    // OLED_PrintString(0, 20, "你好|", &font16x16, OLED_COLOR_NORMAL);
    // HAL_Delay(500);
    // OLED_PrintString(0, 20, "你好，|", &font16x16, OLED_COLOR_NORMAL);
    // HAL_Delay(500);
    // OLED_PrintString(0, 20, "你好，程|", &font16x16, OLED_COLOR_NORMAL);
    // HAL_Delay(500);
    // OLED_PrintString(0, 20, "你好，程序|", &font16x16, OLED_COLOR_NORMAL);
    // HAL_Delay(500);
    // OLED_PrintString(0, 20, "你好，程序员|", &font16x16, OLED_COLOR_NORMAL);
    // HAL_Delay(500);
    // OLED_PrintString(0, 20, "你好，程序员!|", &font16x16, OLED_COLOR_NORMAL);
    // HAL_Delay(2000);

    OLED_Typewriter(0, 20, "你好，程序员!", &font16x16, 200);
    // HAL_Delay(1000);
    currentScreen = SCREEN_CODE; // 切换到下一个动画
}

void ShowCode()
{
    OLED_TypewriterCodePaged(0, 0, &font16x16, 60); // 8x6字体，每字符60ms

    currentScreen = SCREEN_FLOWER;
}

// ...existing code...

// 打字机效果显示字符串

void OLED_Typewriter(int x, int y, char *str, const Font *font, int delay_ms)
{
    char buf[64] = {0};
    int len = strlen(str);
    for (int i = 1; i <= len; i++)
    {
        strncpy(buf, str, i);
        buf[i] = '\0';
        // 在末尾加上光标
        buf[i] = '|';
        buf[i + 1] = '\0';

        OLED_NewFrame();
        OLED_PrintString(x, y, buf, font, OLED_COLOR_NORMAL);
        OLED_ShowFrame();
        // HAL_Delay(delay_ms);
    }
    // 最后显示完整字符串（不带光标）
    OLED_NewFrame();
    OLED_PrintString(x, y, str, font, OLED_COLOR_NORMAL);
    OLED_ShowFrame();
}

/*------------------------------------------------------------------------------*/
#define PAGE_LINES 4
#define LINE_LEN 16

char *code_lines[] = {
    "#include <iostre",
    "am>",
    "using namespace ",
    "std;            ",
    "int main()      ",
    "{               ",
    "  cout <<       ",
    "\"Hello,world!\"",
    " << endl;    ",
    "return 0;       ",
    "}",
};
const int code_lines_count = sizeof(code_lines) / sizeof(code_lines[0]);

// 打字机效果显示一行，带光标
void OLED_TypewriterLine(int x, int y, char *str, const Font *font, int delay_ms)
{
    char buf[LINE_LEN + 2] = {0};
    int len = strlen(str);
    if (len > LINE_LEN)
        len = LINE_LEN;
    for (int i = 1; i <= len; i++)
    {
        strncpy(buf, str, i);
        buf[i] = '|';
        buf[i + 1] = '\0';
        // OLED_NewFrame();
        OLED_PrintString(x, y, buf, font, OLED_COLOR_NORMAL);
        OLED_ShowFrame();
        // HAL_Delay(delay_ms);
    }
    // 最后显示完整字符串（不带光标）
    // OLED_NewFrame();
    OLED_PrintString(x, y, str, font, OLED_COLOR_NORMAL);
    OLED_ShowFrame();
    // HAL_Delay(100);
}

// 分页打字机显示代码
void OLED_TypewriterCodePaged(int x, int y, const Font *font, int delay_ms)
{
    int page = 0;
    int total_pages = (code_lines_count + PAGE_LINES - 1) / PAGE_LINES;
    for (page = 0; page < total_pages; page++)
    {
        OLED_NewFrame();
        for (int l = 0; l < PAGE_LINES; l++)
        {
            int idx = page * PAGE_LINES + l;
            if (idx >= code_lines_count)
                break;
            // 每行打字机效果
            OLED_TypewriterLine(x, y + l * font->ascii->h, code_lines[idx], font, delay_ms);
        }
        // HAL_Delay(1200); // 每页显示完后停留一会
    }
}

// ...existing code...