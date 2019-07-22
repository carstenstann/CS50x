# Questions

## What's `stdint.h`?

`stdint.h` is a header file from the C99 standard library. It provides a set of type definitions for integers

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

The use of `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` enable cross-platform implementation of a standard data types by definitng parameters exactly.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

A `BYTE` is 1 bytes (8 bits).
A `DWORD` is 4 bytes (32 bits).
A `LONG` is 4 bytes (32 bits).
A `WORD` is 2 bytes (16 bits).

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes of any BMP file must be a `WORD` of
Hex:    0x424d
ASCII:  BM (bitmap!)
This value is stored in "bfType".

## What's the difference between `bfSize` and `biSize`?

bfSize is the total number of bytes in the file.
biSize is the number of bytes in the info header.

## What does it mean if `biHeight` is negative?

If biHeight is positive, the bitmap is a bottom-
up DIB with the origin at the lower left corner. If biHeight is negative, the
bitmap is a top-down DIB with the origin at the upper left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount defintes the number of bits-per-pixel. It must be one of the following numbers: 0, 1, 4, 8, 16, 24, 32.

## Why might `fopen` return `NULL` in `copy.c`?

`fopen` might return NULL if it cannot find the file to open.

## Why is the third argument to `fread` always `1` in our code?

The third argument, specifies the number of items to read and the code reads one structure, thus nmemb = 1

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

With `padding` defined as follows: `int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;`
bi.biWidth of 3 leads to a padding = 4.

## What does `fseek` do?

`fseek` moves to a specific location in a file.

## What is `SEEK_CUR`?

`SEEK_CUR` is the current position. It dictates that the offset should be placed relative to the current position.
