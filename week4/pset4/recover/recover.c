#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Size  of jpg memory block that will be read and written
    const int BLOCK_SIZE = 512;

    // Open input .raw file
    FILE *raw_file = fopen(argv[1], "r");

    if (raw_file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    unsigned char buffer[BLOCK_SIZE];

    // Pointer to output file
    FILE *outputFile = NULL;

    // Declaring space for image file name
    char image[8];

    // Number of images to be created
    int n = 0;

    // Searching through raw file until a jpg is found
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // Find the beginning of a jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            // Close image if one has been created
            if (n > 0)
            {
                fclose(outputFile);
            }

            // Make name for nth image
            sprintf(image, "%03i.jpg", n);

            // Open nth image file
            outputFile = fopen(image, "w");
            if (outputFile == NULL)
            {
                printf("Could not create %s.\n", image);
                return 1;
            }

            // Increment number of image files
            n++;
        }

        // Write to image file if one exists
        if (outputFile != NULL)
        {
            // Write to image file
            fwrite(buffer, BLOCK_SIZE, 1, outputFile);
        }
    }

    // Close last image file
    fclose(outputFile);

    // Close .raw file
    fclose(raw_file);

    return 0;
}
