#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Error while opening: %s\n", argv[1]);
        return 2;
    }

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // Allocating memory to filename
    char *filename = malloc(8 * sizeof(char));

    // Counter for jpg files found
    // int block_counter = 0;
    int photo_counter = 0;

    // Pointer for the output JPEG
    FILE *photo = NULL;

    // While there's still data left to read from the memory card
    // Read 512 bytes into the buffer
    while (fread(buffer, 1, 512, input) == 512)
    {
        // If start of the new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If first JPEG, start writing file
            if (photo_counter == 0)
            {
                sprintf(filename, "%03i.jpg", photo_counter);
                photo = fopen(filename, "w");
                fwrite(buffer, 1, 512, photo);
                photo_counter++;
            }
            // else start of another image
            else if (photo_counter > 0)
            {
                fclose(photo);
                sprintf(filename, "%03i.jpg", photo_counter);
                photo = fopen(filename, "w");
                fwrite(buffer, 1, 512, photo);
                photo_counter++;
            }
            /*
            // Checking blocks
            printf("Block %i, Photo: %i\n", block_counter, photo_counter);
            for (int i = 0; i < 4; i++)
            {
            printf("Hex: 0x%x Dec: %i\n", buffer[i], buffer[i]);
            }
            printf("\n");
            */
        }
        else if (photo_counter > 0)
        {
            fwrite(buffer, 1, 512, photo);
        }
        // block_counter++;
    }
    // Close the memory card
    fclose(input);
    fclose(photo);

    // Free malloc and set it to NULL
    free(filename);
    filename = NULL;
}
