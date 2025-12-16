#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])

{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    typedef uint8_t BYTE;
    FILE *inptr = fopen(argv[1], "r");
    if (!inptr)
    {
        printf("Could not open file.\n");
        return 2;
    }

    BYTE buffer[512];
    FILE *outptr = NULL;
    char filename[8];
    int count = 0;

    while (fread(buffer, 1, 512, inptr) == 512)
    {
        // JPEG header check
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (outptr)
                fclose(outptr);
            sprintf(filename, "%03i.jpg", count++);
            outptr = fopen(filename, "w");
        }

        if (outptr)
            fwrite(buffer, 1, 512, outptr);
    }

    if (outptr)
        fclose(outptr);
    fclose(inptr);

    return 0;
}
