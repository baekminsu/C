#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int WIDTH = 512; // 이미지 가로 크기
int HEIGHT = 512; // 이미지 세로 크기
#define IMG_SIZE (WIDTH * HEIGHT)

// RGB를 YCbCr로 변환하는 함수
void RGBtoYCbCr(unsigned char r, unsigned char g, unsigned char b, float* Y, float* Cb, float* Cr) {
    *Y = 0.299 * r + 0.587 * g + 0.114 * b;
    *Cb = (b - *Y) * 0.564 + 128;
    *Cr = (r - *Y) * 0.713 + 128;
}

// YCbCr 값을 0-255 범위로 조정하는 함수
void ClampYCbCr(float* Y, float* Cb, float* Cr) {
    *Y = (*Y < 0) ? 0 : ((*Y > 255) ? 255 : *Y);
    *Cb = (*Cb < 0) ? 0 : ((*Cb > 255) ? 255 : *Cb);
    *Cr = (*Cr < 0) ? 0 : ((*Cr > 255) ? 255 : *Cr);
}

// YCbCr를 RGB로 변환하는 함수
void YCbCrtoRGB(float Y, float Cb, float Cr, float* r, float* g, float* b) {
    *r = Y + 1.402 * (Cr - 128);
    *g = Y - 0.344136 * (Cb - 128) - 0.714136 * (Cr - 128);
    *b = Y + 1.772 * (Cb - 128);
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

int splitYcbcr(const float* ycbcr, float** y, float** cb, float** cr) {
    int i;
    // 데이터를 저장할 배열 동적 할당
    (*y) = (float*)malloc(IMG_SIZE * sizeof(float));
    if (!(*y)) {
        fprintf(stderr, "메모리를 할당할 수 없습니다.\n");
        return 1;
    }

    // 데이터를 저장할 배열 동적 할당
    (*cb) = (float*)malloc(IMG_SIZE * sizeof(float));
    if (!(*cb)) {
        fprintf(stderr, "메모리를 할당할 수 없습니다.\n");
        free(*y);
        return 1;
    }

    // 데이터를 저장할 배열 동적 할당
    (*cr) = (float*)malloc(IMG_SIZE * sizeof(float));
    if (!(*cr)) {
        fprintf(stderr, "메모리를 할당할 수 없습니다.\n");
        free(*y);
        free(*cb);
        return 1;
    }

    return 0;
}

int rgb2ycbcr(unsigned char* rgb, float** ycbcr) {
    int i;
    // 데이터를 저장할 배열 동적 할당
    (*ycbcr) = (float*)malloc(IMG_SIZE * 3 * sizeof(float));
    if (!(*ycbcr)) {
        fprintf(stderr, "메모리를 할당할 수 없습니다.\n");
        return 1;
    }

    // RGB를 YCbCr로 변환하여 저장
    for (i = 0; i < IMG_SIZE; i++) {
        // non-interleaved
        unsigned char r = rgb[i];
        unsigned char g = rgb[IMG_SIZE + i];
        unsigned char b = rgb[IMG_SIZE * 2 + i];

        // interleaved
        // unsigned char r = rgb[i * 3];
        // unsigned char g = rgb[i * 3 + 1];
        // unsigned char b = rgb[i * 3 + 2];

        float Y, Cb, Cr;
        RGBtoYCbCr(r, g, b, &Y, &Cb, &Cr);
        ClampYCbCr(&Y, &Cb, &Cr); // 0-255 범위로 조정

        // non-interleaved
        (*ycbcr)[i] = Y;
        (*ycbcr)[IMG_SIZE + i] = Cb;
        (*ycbcr)[IMG_SIZE * 2 + i] = Cr;

        // interleaved
        // (*ycbcr)[i * 3] = Y;
        // (*ycbcr)[i * 3 + 1] = Cb;
        // (*ycbcr)[i * 3 + 2] = Cr;
    }
    return 0;
}

int saveYcbcr(const char* filename, const float* ycbcr) {
    int i;

    // YCbCr 이미지를 raw 파일로 저장
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "출력 파일을 열 수 없습니다.\n");
        return 1;
    }

    for (i = 0; i < IMG_SIZE * 3; i++) {
        unsigned char value = (unsigned char)ycbcr[i];
        fwrite(&value, sizeof(unsigned char), 1, fp);
    }

    fclose(fp);
    return 0;
}

int saveYcbcrChannel(const char* filename, const float* channel) {
    int i;

    // YCbCr 이미지를 raw 파일로 저장
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

int ycbcr2rgb(const float* ycbcr, unsigned char** rgb) {
    int i;
    // 데이터를 저장할 배열 동적 할당
    (*rgb) = (unsigned char*)malloc(IMG_SIZE * 3 * sizeof(unsigned char));
    if (!(*rgb)) {
        fprintf(stderr, "메모리를 할당할 수 없습니다.\n");
        return 1;
    }

    // YCbCr를 RGB로 변환하고 양자화하여 저장
    for (i = 0; i < IMG_SIZE; i++) {
        // non-interleaved
        float Y = ycbcr[i];
        float Cb = ycbcr[IMG_SIZE + i];
        float Cr = ycbcr[IMG_SIZE * 2 + i];

        // interleaved
        // float Y  = ycbcr[i * 3];
        // float Cb = ycbcr[i * 3 + 1];
        // float Cr = ycbcr[i * 3 + 2];

        float r, g, b;
        YCbCrtoRGB(Y, Cb, Cr, &r, &g, &b);

        // non-interleaved
        (*rgb)[i] = Quantize(r);
        (*rgb)[IMG_SIZE + i] = Quantize(g);
        (*rgb)[IMG_SIZE * 2 + i] = Quantize(b);

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

    // rgb 를 YCbCr로 변환
    float* ycbcr = 0;
    ec = rgb2ycbcr(rgb, &ycbcr); // ycbcr은 함수내부에서 동적할당
    if (0 != ec) {
        free(rgb);
        free(ycbcr);
        return ec;
    }

    // YCbCr로 부터 Y, Cb, Cr 정보를 분리
    float* y = 0, * cb = 0, * cr = 0;
    ec = splitYcbcr(ycbcr, &y, &cb, &cr);
    if (0 != ec) {
        free(rgb);
        free(ycbcr);
        free(y);
        free(cb);
        free(cr);
        return ec;
    }

    // YCbCr처리결과 저장
    // saveYcbcr("lenaYCbCr.raw", ycbcr);
    saveYcbcrChannel("2.y.raw", y);
    saveYcbcrChannel("2.cb.raw", cb);
    saveYcbcrChannel("2.cr.raw", cr);

    // YCbCr을 RGB로 변환
    unsigned char* ycbcr_rgb = 0;
    ec = ycbcr2rgb(ycbcr, &ycbcr_rgb);
    if (0 != ec) {
        free(rgb);
        free(ycbcr);
        free(ycbcr_rgb);
        free(y);
        free(cb);
        free(cr);
        return ec;
    }

    // YCbCr을 RGB로 변환한 결과 저장
    // saveRGB("lenaYCbCr_RGB.raw", ycbcr_rgb);

    // 이미지 데이터 배열 메모리 해제
    free(rgb);
    free(ycbcr);
    free(ycbcr_rgb);
    free(y);
    free(cb);
    free(cr);

    return 0;
}

// 중요한로직 out
