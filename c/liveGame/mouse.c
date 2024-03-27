#include <windows.h>
#include <stdio.h>

int main(){
    POINT cursorPos;
    
    while(1){
        if(GetCursorPos(&cursorPos)){
            printf("Mouse pos: x=%ld, y=%ld\n", cursorPos.x, cursorPos.y);
        }
        Sleep(100);
    }

    return 0;
}