#ifndef __FONT_H
#define __FONT_H
#include "stdint.h"
#include "string.h"
typedef struct ASCIIFont {
  uint8_t h;
  uint8_t w;
  uint8_t *chars;
} ASCIIFont;

extern const ASCIIFont afont8x6;
extern const ASCIIFont afont12x6;
extern const ASCIIFont afont16x8;
extern const ASCIIFont afont24x12;

/**
 * @brief 字体结构体
 * @note  字库前4字节存储utf8编码 剩余字节存储字模数据
 * @note 字库数据可以使用波特律动LED取模助手生成(https://led.baud-dance.com)
 */
typedef struct Font {
  uint8_t h;              // 字高度
  uint8_t w;              // 字宽度
  const uint8_t *chars;   // 字库 字库前4字节存储utf8编码 剩余字节存储字模数据
  uint8_t len;            // 字库长度 超过256则请改为uint16_t
  const ASCIIFont *ascii; // 缺省ASCII字体 当字库中没有对应字符且需要显示ASCII字符时使用
} Font;

//汉字字库
extern const Font font16x16;










/**
 * @brief 图片结构体
 * @note  图片数据可以使用波特律动LED取模助手生成(https://led.baud-dance.com)
 */
typedef struct Image {
  uint8_t w;           // 图片宽度
  uint8_t h;           // 图片高度
  const uint8_t *data; // 图片数据
} Image;

//三组动画各自的指针数组
extern const Image *animation_frames[];


//第一组：进度条 动画
extern const Image bilibiliImg;
extern const Image Img1;
extern const Image Img2;
extern const Image Img3;
extern const Image Img4;
extern const Image Img5;
extern const Image Img6;
extern const Image Img7;
extern const Image Img8;
extern const Image Img9;
extern const Image Img10;
extern const Image Img11;
extern const Image Img12;
extern const Image Img13;
extern const Image Img14;
extern const Image Img15;
extern const Image Img16;
extern const Image Img17;
extern const Image Img18;
extern const Image Img19;
extern const Image Img20;
extern const Image Img21;
extern const Image Img22;
extern const Image Img23;
extern const Image Img24;
extern const Image Img25;
extern const Image Img26;
extern const Image Img27;
extern const Image Img28;
extern const Image Img29;
extern const Image Img30;
extern const Image Img31;
extern const Image Img32;
extern const Image Img33;
extern const Image Img34;
extern const Image Img35;
extern const Image Img36;
extern const Image Img37;
extern const Image Img38;
extern const Image Img39;
extern const Image Img40;
extern const Image Img41;
extern const Image Img42;
extern const Image Img43;
extern const Image Img44;
extern const Image Img45;
extern const Image Img46;
extern const Image Img47;
extern const Image Img48;
extern const Image Img49;
extern const Image Img50;
extern const Image Img51;
extern const Image Img52;
extern const Image Img53;
extern const Image Img54;
extern const Image Img55;
extern const Image Img56;
extern const Image Img57;
extern const Image Img58;
extern const Image Img59;
extern const Image Img60;
extern const Image Img61;
extern const Image Img62;
extern const Image Img63;
extern const Image Img64;
extern const Image Img65;
extern const Image Img66;
extern const Image Img67;
extern const Image Img68;
extern const Image Img69;
extern const Image Img70;
extern const Image Img71;
extern const Image Img72;
extern const Image Img73;
extern const Image Img74;
extern const Image Img75;
extern const Image Img76;
extern const Image Img77;
extern const Image Img78;
extern const Image Img79;
extern const Image Img80;
extern const Image Img81;
extern const Image Img82;
extern const Image Img83;
extern const Image Img84;
extern const Image Img85;
extern const Image Img86;
extern const Image Img87;
extern const Image Img88;
extern const Image Img89;
extern const Image Img90;
extern const Image Img91;
extern const Image Img92;
extern const Image Img93;
extern const Image Img94;
extern const Image Img95;
extern const Image Img96;
extern const Image Img97;
extern const Image Img98;
extern const Image Img99;
extern const Image Img100;
extern const Image Img101;
extern const Image Img102;
extern const Image Img103;
extern const Image Img104;
extern const Image Img105;
extern const Image Img106;
extern const Image Img107;
extern const Image Img108;
extern const Image Img109;
extern const Image Img110;
extern const Image Img111;
extern const Image Img112;
extern const Image Img113;
extern const Image Img114;
extern const Image Img115;
extern const Image Img116;
extern const Image Img117;
extern const Image Img118;
extern const Image Img119;
extern const Image Img120;
extern const Image Img121;
extern const Image Img122;
extern const Image Img123;
extern const Image Img124;
extern const Image Img125;
extern const Image Img126;
extern const Image Img127;
extern const Image Img128;




#endif // __FONT_H
