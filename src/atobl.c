#include <wchar.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#define bool int
#define false 0
#define true 1

static const wchar_t fraktur_bold_lower[] = {
  L'\U0001D586', // 𝖆
  L'\U0001D587', // 𝖇
  L'\U0001D588', // 𝖈
  L'\U0001D589', // 𝖉
  L'\U0001D58A', // 𝖊
  L'\U0001D58B', // 𝖋
  L'\U0001D58C', // 𝖌
  L'\U0001D58D', // 𝖍
  L'\U0001D58E', // 𝖎
  L'\U0001D58F', // 𝖏
  L'\U0001D590', // 𝖐
  L'\U0001D591', // 𝖑
  L'\U0001D592', // 𝖒
  L'\U0001D593', // 𝖓
  L'\U0001D594', // 𝖔
  L'\U0001D595', // 𝖕
  L'\U0001D596', // 𝖖
  L'\U0001D597', // 𝖗
  L'\U0001D598', // 𝖘
  L'\U0001D599', // 𝖙
  L'\U0001D59A', // 𝖚
  L'\U0001D59B', // 𝖛
  L'\U0001D59C', // 𝖜
  L'\U0001D59D', // 𝖝
  L'\U0001D59E', // 𝖞
  L'\U0001D59F', // 𝖟
};
static const wchar_t fraktur_bold_upper[] = {
  L'\U0001D56C', // 𝕬
  L'\U0001D56D', // 𝕭
  L'\U0001D56E', // 𝕮
  L'\U0001D56F', // 𝕯
  L'\U0001D570', // 𝕰
  L'\U0001D571', // 𝕱
  L'\U0001D572', // 𝕲
  L'\U0001D573', // 𝕳
  L'\U0001D574', // 𝕴
  L'\U0001D575', // 𝕵
  L'\U0001D576', // 𝕶
  L'\U0001D577', // 𝕷
  L'\U0001D578', // 𝕸
  L'\U0001D579', // 𝕹
  L'\U0001D57A', // 𝕺
  L'\U0001D57B', // 𝕻
  L'\U0001D57C', // 𝕼
  L'\U0001D57D', // 𝕽
  L'\U0001D57E', // 𝕾
  L'\U0001D57F', // 𝕿
  L'\U0001D580', // 𝖀
  L'\U0001D581', // 𝖁
  L'\U0001D582', // 𝖂
  L'\U0001D583', // 𝖃
  L'\U0001D584', // 𝖄
  L'\U0001D585', // 𝖅
};
static const wchar_t fraktur_normal_lower[] = {
  L'\U0001D51E', // 𝔞
  L'\U0001D51F', // 𝔟
  L'\U0001D520', // 𝔠
  L'\U0001D521', // 𝔡
  L'\U0001D522', // 𝔢
  L'\U0001D523', // 𝔣
  L'\U0001D524', // 𝔤
  L'\U0001D525', // 𝔥
  L'\U0001D526', // 𝔦
  L'\U0001D527', // 𝔧
  L'\U0001D528', // 𝔨
  L'\U0001D529', // 𝔩
  L'\U0001D52A', // 𝔪
  L'\U0001D52B', // 𝔫
  L'\U0001D52C', // 𝔬
  L'\U0001D52D', // 𝔭
  L'\U0001D52E', // 𝔮
  L'\U0001D52F', // 𝔯
  L'\U0001D530', // 𝔰
  L'\U0001D531', // 𝔱
  L'\U0001D532', // 𝔲
  L'\U0001D533', // 𝔳
  L'\U0001D534', // 𝔴
  L'\U0001D535', // 𝔵
  L'\U0001D536', // 𝔶
  L'\U0001D537', // 𝔷
};
static const wchar_t fraktur_normal_upper[] = {
  L'\U0001D504', // 𝔄
  L'\U0001D505', // 𝔅
  L'\u212D',     // ℭ
  L'\U0001D507', // 𝔇
  L'\U0001D508', // 𝔈
  L'\U0001D509', // 𝔉
  L'\U0001D50A', // 𝔊
  L'\u210C',     // ℌ
  L'\u2111',     // ℑ
  L'\U0001D50D', // 𝔍
  L'\U0001D50E', // 𝔎
  L'\U0001D50F', // 𝔏
  L'\U0001D510', // 𝔐
  L'\U0001D511', // 𝔑
  L'\U0001D512', // 𝔒
  L'\U0001D513', // 𝔓
  L'\U0001D514', // 𝔔
  L'\u211C',     // ℜ
  L'\U0001D516', // 𝔖
  L'\U0001D517', // 𝔗
  L'\U0001D518', // 𝔘
  L'\U0001D519', // 𝔙
  L'\U0001D51A', // 𝔚
  L'\U0001D51B', // 𝔛
  L'\U0001D51C', // 𝔜
  L'\u2128',     // ℨ
};

int main(int argc, char *argv[]){
  setlocale(LC_ALL, "");
  bool bold = false;
  if(argc > 1 && strcmp(argv[1], "-b") == 0){
    bold = true;
  }
  wint_t ch;
  wchar_t out_char;
  while((ch = fgetwc(stdin)) != WEOF){
    if(ch >= L'a' && ch <= L'z'){
      out_char = bold ? fraktur_bold_lower[ch - L'a'] : fraktur_normal_lower[ch - L'a'];
    }else if(ch >= L'A' && ch <= L'Z'){
      out_char = bold ? fraktur_bold_upper[ch - L'A'] : fraktur_normal_upper[ch - L'A'];
    }else{ 
      out_char = (wchar_t)ch;
    }
    wprintf(L"%lc", out_char);
  }
  return 0;
}
