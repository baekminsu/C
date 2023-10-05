#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WIDTH = 512; // 이미지 가로 크기
int HEIGHT = 512; // 이미지 세로 크기
#define IMG_SIZE (WIDTH * HEIGHT)
#define PI 3.14159265359

int minrgb(unsigned char r, unsigned char g, unsigned char b) {
    unsigned char num = r;
    if (r > g) {
        num = g;
        if (g > b) {
            num = b;
        }
    }
    else if (r > b) {
        num = b;
        if (b > g) {
            num = g;
        }
    }
    return num;
}

// RGB를 HSI로 변환하는 함수
void RGBtoHSI(unsigned char r, unsigned char g, unsigned char b, float* H, float* S, float* I) {
    *H = acos((0.5 * (r - g) + (r - b)) / sqrt(((r - g) * (r - g)) + ((r - b) * (g - b))));
    *S = 1 - ((3.0 / (r + g + b)) * minrgb(r, g, b));
    *I = (r + g + b) * 0.3;
}
// HSI 값을 0-255 범위로 조정하는 함수
void ClampHSI(float* H, float* S, float* I) {
    *H = (*H / (PI) ) * 255;
    *S = *S * 255;
    *I = *I;
}

// HSI를 RGB로 변환하는 함수
void HSItoRGB(float H, float S, float I, float* r, float* g, float* b) {
    *r = I * *r * 3;
    *g = 3 * I * *g;
    *b = 3 * I * *b;
}

// float 값을 unsigned char로 양자화하는 함수
unsigned char Quantize(float value) {
    return (unsigned char)round(value);
}

int loadLenna(const char* filename, unsigned char** image) {

    // 파일 열기
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "lenaRGB 파일을 열 수 없습니다.\n");
        return 1;
    }

    // RGB 데이터를 저장할 배열 동적 할당
    *image = (unsigned char*)malloc(IMG_SIZE * 3 * sizeof(unsigned char));
    if (!*image) {
        fprintf(stderr, "메모리를 할당할 수 없습니다.\n");
        fclose(fp);
        return 1;
    }

    // 파일에서 RGB 데이터 읽기
    size_t read_result = fread(*image, sizeof(unsigned char), IMG_SIZE * 3, fp);
    if (read_result != IMG_SIZE * 3) {
        fprintf(stderr, "lenaRGB 파일에서 데이터를 읽을 수 없습니다.\n");
        fclose(fp);
        free(*image);
        return 1;
    }

    // 파일 닫기
    fclose(fp);

    return 0;
}

int splitHSI(const float* HSI, float** H, float** S, float** I) {
    int j;
    // 데이터를 저장할 배열 동적 할당
    (*H) = (float*)malloc(IMG_SIZE * sizeof(float));
    if (!(*H)) {
        fprintf(stderr, "메모리를 할당할 수 없습니다.\n");
        return 1;
    }

    // 데이터를 저장할 배열 동적 할당
    (*S) = (float*)malloc(IMG_SIZE * sizeof(float));
    if (!(*S)) {
        fprintf(stderr, "메모리를 할당할 수 없습니다.\n");
        free(*H);
        return 1;
    }

    // 데이터를 저장할 배열 동적 할당
    (*I) = (float*)malloc(IMG_SIZE * sizeof(float));
    if (!(*I)) {
        fprintf(stderr, "메모리를 할당할 수 없습니다.\n");
        free(*H);
        free(*S);
        return 1;
    }

    for (j = 0; j < IMG_SIZE; j++) {
        // non-interleaved
        (*H)[j] = HSI[j];
        (*S)[j] = HSI[IMG_SIZE + j];
        (*I)[j] = HSI[IMG_SIZE * 2 + j];

        // interleaved
        // (*H)[j] = HSI[j * 3];
        // (*S)[j] = HSI[j * 3 + 1];
        // (*I)[j] = HSI[j * 3 + 2];
    }
    return 0;
}

int saveHSI(const char* filename, const float* HSI) {
    int i;

    // HSI 이미지를 raw 파일로 저장
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "출력 파일을 열 수 없습니다.\n");
        return 1;
    }

    for (i = 0; i < IMG_SIZE * 3; i++) {
        unsigned char value = (unsigned char)HSI[i];
        fwrite(&value, sizeof(unsigned char), 1, fp);
    }

    fclose(fp);
    return 0;
}

int saveHSIChannel(const char* filename, const float* channel) {
    int i;

    // HSI 이미지를 raw 파일로 저장
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "출력 파일을 열 수 없습니다.\n");
        return 1;
    }

    for (i = 0; i < IMG_SIZE; i++) {
        unsigned char value = (unsigned char)channel[i];
        fwrite(&value, sizeof(unsigned char), 1, fp);
    }

    fclose(fp);
    return 0;
}

int HSI2rgb(const float* HSI, unsigned char** rgb) {
    int j;
    // 데이터를 저장할 배열 동적 할당
    (*rgb) = (unsigned char*)malloc(IMG_SIZE * 3 * sizeof(unsigned char));
    if (!(*rgb)) {
        fprintf(stderr, "메모리를 할당할 수 없습니다.\n");
        return 1;
    }

    // HSI를 RGB로 변환하고 양자화하여 저장
    for (j = 0; j < IMG_SIZE; j++) {
        // non-interleaved
        float H = HSI[j];
        float S = HSI[IMG_SIZE + j];
        float I = HSI[IMG_SIZE * 2 + j];

        // interleaved
        // float H  = HSI[j * 3];
        // float S = HSI[j * 3 + 1];
        // float I = HSI[j * 3 + 2];

        float r, g, b;
        HSItoRGB(H, S, I, &r, &g, &b);

        // non-interleaved
        (*rgb)[j] = Quantize(r);
        (*rgb)[IMG_SIZE + j] = Quantize(g);
        (*rgb)[IMG_SIZE * 2 + j] = Quantize(b);

        // interleaved
        // (*rgb)[i * 3] = Quantize(r);
        // (*rgb)[i * 3 + 1] = Quantize(g);
        // (*rgb)[i * 3 + 2] = Quantize(b);
    }
    return 0;
}

int saveRGB(const char* filename, const unsigned char* rgb) {

    // 양자화된 RGB 이미지를 raw 파일로 저장
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "RGB 출력 파일을 열 수 없습니다.\n");
        return 1;
    }

    fwrite(rgb, sizeof(unsigned char), IMG_SIZE * 3, fp);

    // 파일 닫기
    fclose(fp);
}

int main() {
    // 파일을 읽고 배열에 저장
    unsigned char* rgb = 0; // 저장할 배열 포인터
    char filename[30];

    printf("\n\rINPUT FILE NAME : ");
    scanf("%s", filename);
    int ec = loadLenna(filename, &rgb); // 성공하면 0, 실패하면 1을 리턴. rgb는 함수내부에서 동적할당
    if (0 != ec) {
        free(rgb);
        return ec;
    }

    /* 파일크기를 말해 */
    printf("\rFILE SIZE [H_dim V_dim] : ");
    scanf("%d %d", &WIDTH, &HEIGHT);

    // rgb 를 HSI로 변환
    float* HSI = 0;
    ec = rgb2HSI(rgb, &HSI); // HSI은 함수내부에서 동적할당
    if (0 != ec) {
        free(rgb);
        free(HSI);
        return ec;
    }

    // HSI로 부터 H, S, I 정보를 분리
    float* H = 0, * I = 0, * S = 0;
    ec = splitHSI(HSI, &H, &S, &I);
    if (0 != ec) {
        free(rgb);
        free(HSI);
        free(H);
        free(S);
        free(I);
        return ec;
    }

    // HSI처리결과 저장
    // saveHSI("lenaHSI.raw", HSI);
    saveHSIChannel("3.H.raw", H);
    saveHSIChannel("3.S.raw", S);
    saveHSIChannel("3.I.raw", I);

    // HSI을 RGB로 변환
    unsigned char* HSI_rgb = 0;
    ec = HSI2rgb(HSI, &HSI_rgb);
    if (0 != ec) {
        free(rgb);
        free(HSI);
        free(HSI_rgb);
        free(H);
        free(S);
        free(I);
        return ec;
    }

    // HSI을 RGB로 변환한 결과 저장
    // saveRGB("lenaHSI_RGB.raw", HSIr_rgb);

    // 이미지 데이터 배열 메모리 해제
    free(rgb);
    free(HSI);
    free(HSI_rgb);
    free(H);
    free(S);
    free(I);

    return 0;
}
