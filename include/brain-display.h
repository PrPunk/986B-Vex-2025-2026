#include <string.h>

struct Button {
    unsigned int x;
    unsigned int y;
    unsigned int width;
    unsigned int height;
    char text[20];
    unsigned int color;
    void (*callback)(int);
    int param;
};

struct Page {
    Button *buttons[10];
    bool hasImage;
};