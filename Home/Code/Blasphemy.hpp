// HolyC compatibility layer for C++

#ifndef BLASPHEMY_HPP_
#define BLASPHEMY_HPP_

#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <algorithm>
typedef void U0;
typedef int64_t I64;
typedef uint8_t U8;
typedef bool Bool;
#define TRUE true
#define FALSE false
#define class struct
#define MAlloc malloc
#define Free free
#define Print printf
#define I64_MIN INT64_MIN
#define I64_MAX INT64_MAX

I64 MemCmp(U8 *ptr1, U8 *ptr2, I64 size)
{
    return memcmp(ptr1, ptr2, size);
}

U8 *MemCpy(void *ptr1, void *ptr2, I64 size)
{
    return (U8*) memcpy(ptr1, ptr2, size);
}

I64 Str2I64(U8 *s, I64 radix, U8 **end_ptr)
{
    return strtoimax((const char *) s, (char**)end_ptr, radix);
}

U8 *FileRead(const char *filename, I64 *size=NULL)
{
    FILE *f = fopen(filename, "rb");
    assert(f != NULL);
    int ret = fseek(f, 0, SEEK_END);
    assert(ret == 0);
    long m = ftell(f);
    assert(m >= 0);
    U8 *buffer = (U8*)malloc(m);
    assert(buffer != NULL);
    ret = fseek(f, 0, SEEK_SET);
    assert(ret == 0);
    fread(buffer, m, 1, f);
    assert(!ferror(f));
    ret = fclose(f);
    assert(ret == 0);
    if (size) *size = m;
    return buffer;
}

U8 *FileRead(U8 *filename, I64 *size=NULL)
{
    return FileRead((const char*)filename, size);
}

U8 *MemSet(void *ptr, I64 value, I64 size)
{
    return (U8*)memset(ptr, value, size);
}

I64 MaxI64(I64 a, I64 b)
{
    return a < b ? b : a;
}

I64 MinI64(I64 a, I64 b)
{
    return a < b ? a : b;
}

U0 SwapI64(I64 *a, I64 *b)
{
    I64 t = *a;
    *a = *b;
    *b = t;
}

I64 AbsI64(I64 a)
{
    return std::abs(a);
}

template <typename T>
U0 QSort(T *base, I64 num, I64 width, I64 (*fp_compare)(T *a, T *b))
{
    assert(sizeof(T) == width);
    std::sort(base, base + num, [&fp_compare](T &a, T &b) -> auto {
        return fp_compare(&a, &b) < 0;
    });
}

U0 QSortI64(I64 *base, I64 num, I64 (*fp_compare)(I64 a, I64 b))
{
    std::sort(base, base + num, [&fp_compare](I64 &a, I64 &b) -> auto {
        return fp_compare(a, b) < 0;
    });
}

I64 StrLen(U8 *s)
{
    return strlen((const char *)s);
}

I64 StrLen(const char *s)
{
    return StrLen((U8*)s);
}

#endif // BLASPHEMY_HPP_
