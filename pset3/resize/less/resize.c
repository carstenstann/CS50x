// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4 && (*argv[1] < 1 || *argv[1] > 100))
    {
        fprintf(stderr, "Usage: resize n infile outfile\n");
        return 1;
    }

    // remember scaling factor & filenames
    int scale_factor = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf_small;
    fread(&bf_small, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi_small;
    fread(&bi_small, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf_small.bfType != 0x4d42 || bf_small.bfOffBits != 54 || bi_small.biSize != 40 ||
        bi_small.biBitCount != 24 || bi_small.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // Declare new BITMAPFILEHEADER and BITMAPINFOHEADER
    BITMAPFILEHEADER bf_larger = bf_small;
    BITMAPINFOHEADER bi_larger = bi_small;

    // determine padding
    int padding_small = (4 - (bi_small.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // redefine headers
    bi_larger.biWidth = bi_small.biWidth * scale_factor;
    bi_larger.biHeight = bi_small.biHeight * scale_factor;

    int padding_larger = (4 - (bi_larger.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bi_larger.biSizeImage = ((sizeof(RGBTRIPLE) * bi_larger.biWidth) + padding_larger) * abs(bi_larger.biHeight);
    bf_larger.bfSize = bi_larger.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_larger, sizeof(BITMAPFILEHEADER), 1, outptr);
    //fwrite(data pointer to struct, size, number, outptr (pointer to file to write to))

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_larger, sizeof(BITMAPINFOHEADER), 1, outptr);

    RGBTRIPLE bmp_row[bi_larger.biWidth * sizeof(RGBTRIPLE)];

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi_small.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi_small.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to array
            for (int k = 0; k < scale_factor; k++)
            {
                bmp_row[(j * scale_factor) + k] = triple;
            }
        }

        // skip over padding in small bmp file if present
        fseek(inptr, padding_small, SEEK_CUR);

        for (int l = 0; l < scale_factor; l++)
        {
            // write new row to file once
            fwrite(bmp_row, sizeof(RGBTRIPLE), bi_larger.biWidth, outptr);

            // add padding if necessary
            for (int n = 0; n < padding_larger; n++)
            {
                fputc(0x00, outptr);
            }
        }

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
