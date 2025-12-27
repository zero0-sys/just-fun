#include <stdio.h>
#include <windows.h>
#include <string.h>

#define SCREEN_WIDTH 140
#define TEXT_HEIGHT 6

const char *text[TEXT_HEIGHT] = {
"HH   HH III DDDDD   UU   UU PPPPPP     JJJJ OOOO KK  KK OOOO WW    WW III",
"HH   HH  I  DD  DD  UU   UU PP   PP      JJ OO  OO KK KK OO  OO WW    WW  I",
"HHHHHHH  I  DD   DD UU   UU PPPPPP       JJ OO  OO KKKK  OO  OO WW WW WW  I",
"HH   HH  I  DD   DD UU   UU PP            JJ OO  OO KK KK OO  OO WWWW WWW  I",
"HH   HH  I  DD  DD   UU UU  PP        JJ  JJ OO  OO KK  KK OO  OO WW    WW  I",
"HH   HH III DDDDD      UUU   PP         JJJJ  OOOO KK  KK OOOO WW    WW III"
};

int main(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ci = {1, FALSE};
    SetConsoleCursorInfo(h, &ci);

    int width = strlen(text[0]);
    int x = SCREEN_WIDTH;

    while (1){
        system("cls");

        for(int i = 0; i < TEXT_HEIGHT; i++){
            if (x > -width){
                printf("%*s%s\n",
                    x > 0 ? x : 0,
                    "",
                    text[i] + (x < 0 ? -x : 0)
                );
            }
        }

        Sleep(80);
        x--;
        if (x < -width) x = SCREEN_WIDTH;
    }
}
