# Questions

## What's `stdint.h`?

stdint.h is a head file in he C library to allow programmers to write more portable code 
by providing a set of typedefs that specify exact-width interger types, togedther with 
the defined min and max allowable values for each type, using macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

The naming convention for exact-width integer types.
'uint8_t': unsigned int,0 to UINT8_MAX
'uint32_t':0 to UINT32_MAX
'int32_t':INT32_MIN to INT32_MAX
'uint16_t':0 to UINT16_MAX

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

'BYTE':1 byte  (8 bits)
'DWORD':4 bytes(32 bits)
'LONG':4 bytes (32 bits)
'WORD':2 bytes (16 bits)

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first 2 bytes of BMP file format are the charater B and M in ASCII encoding.
(0x42, 0x4D in hexadecimal)
## What's the difference between `bfSize` and `biSize`?

biSize is the file size in bytes of the info header part of a BMP
bfSize is the file size in bytes of the full BMP (including both header and image).

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is top-down DIB with the  origin at the upper left corner.

(If biHeight is positive, the bitmap is bottom-up DIB with the origin at the lower left corner.
)

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

The biBitCount which is the number of bits-per-pixel determines the number of bits that define each pixel and the maximum number of colors in the bitmap.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

"'fopen' returns 'NULL'" means the file could not be opened. There are many reasons: 
1.The file doesn't exit. 2.No acceses. 3. No permissions. 4.Incorrect address.

## Why is the third argument to `fread` always `1` in our code?

size+t fread(void *restrict ptr, size_t size, size_t nitems,
       FILE *restrict stream)

Third argument to 'fread' means number of elements. Because we are interating one pixel at a time, it sould be '1'.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4
            =  4-(3*(12%4))%4 =4-1=3

## What does `fseek` do?

'fseek' sets the position indicator associated with the stream to a new position. 

## What is `SEEK_CUR`?

'SEEK_CUR'  is the current posisiotn indicator in the file.

## Whodunit?

It was Professor Pum with the candlestick in the library.
