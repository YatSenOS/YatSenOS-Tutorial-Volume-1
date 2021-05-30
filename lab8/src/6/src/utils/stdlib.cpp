#include "os_type.h"

template <typename T>
void swap(T &x, T &y)
{
    T z = x;
    x = y;
    y = z;
}

void itos(char *numStr, uint32 num, uint32 mod)
{

    // 只能转换2~26进制的整数
    if (mod < 2 || mod > 26 || num < 0)
    {
        return;
    }

    uint32 length, temp;

    // 进制转换
    length = 0;
    while (num)
    {
        temp = num % mod;
        num /= mod;
        numStr[length] = temp > 9 ? temp - 10 + 'A' : temp + '0';
        ++length;
    }

    // 特别处理num=0的情况
    if (!length)
    {
        numStr[0] = '0';
        ++length;
    }

    // 将字符串倒转，使得numStr[0]保存的是num的高位数字
    for (int i = 0, j = length - 1; i < j; ++i, --j)
    {
        swap(numStr[i], numStr[j]);
    }

    numStr[length] = '\0';
}

void memset(void *memory, char value, int length)
{
    for (int i = 0; i < length; ++i)
    {
        ((char *)memory)[i] = value;
    }
}

int ceil(const int dividend, const int divisor)
{
    return (dividend + divisor - 1) / divisor;
}

void memcpy(void *src, void *dst, uint32 length)
{
    for (uint32 i = 0; i < length; ++i)
    {
        ((char *)dst)[i] = ((char *)src)[i];
    }
}

void strcpy(const char *src, char *dst) {
    int i = 0;
    while(src[i]) {
        dst[i] = src[i];
        ++i;
    }
    dst[i] = '\0';
}