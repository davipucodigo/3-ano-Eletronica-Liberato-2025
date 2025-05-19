#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <string.h>

#pragma pack(1)

// ======================= Header BMP Struct ======================= //
typedef struct { 
    char Signature[2]; // 2 bytes caracter hexadecimal ASCII "BM"
    int32_t FileSize; 
    int16_t Reserved1;
    int16_t Reserved2;
    int32_t File_Offset_to_PixelArray;

} FileHeader;

typedef struct{
    int32_t DIB_header_SIze; 
    int32_t width;
    int32_t height; 
    int16_t planes;
    int16_t bits_per_pixel;
    int32_t compression;
    int32_t image_size;
    int32_t X;
    int32_t Y;
    int32_t color_table;
    int32_t important_color_coun;

} DIBHeader;

typedef struct{
    uint8_t b;
    uint8_t g;
    uint8_t r;
} Color;

//Variables
char file_name[100];
int loop = 1;

//Functions
void loadFILE() {}
void ColorOutput() {}
void CroppedOutput() {}
void Exit() {
    loop = 0;
}

int main() {
    // START
    do {
        // --------- BMP file Input:
        printf("\nEnter name, example('file.bmp'): ");
        scanf("%s[^\n]",file_name);
        printf("\n%s file is defined\n",file_name);

        // --------- Load file.BMP:
        loadFILE();

        // --------- MENU Select:
        int op = 0;
        printf("\n MENU - DAVI SANT'ANNA \n 1) Color Output RGB \n 2) Cut Image \n 3) Exit \n Select Number: ");
        scanf("%d",&op);
        switch (op) {
            case 1:
                ColorOutput();
            break;
            case 2:
                CroppedOutput();
            break;
            case 3:
                Exit();
            break;
        }
    }while(loop);


    return 0;
}