#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    //Checking if 1 commandline arguement entered
    if (argc != 2)
    {
        fprintf(stderr, "Must enter name of file as one command-line arguement\n");
        return 1;
    }
    
    //Opening input file and checking if valid
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        return 1;
    }
    
    //Variables to be used
    unsigned char buffer[512];
    int a = 0;
    char name[8] = {0};
    FILE *img = NULL;
    
    //Reading input file
    while (fread(&buffer, sizeof(buffer), 1, f) == 1)
    {
        //Checking if jpeg signature found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If first jpeg create new file and write block to it
            if (a == 0)
            {
                sprintf(name, "%03i.jpg", a);
                img = fopen(name, "w");
                fwrite(buffer, 512, 1, img);
                a++;
            }
            
            //If not first jpeg then close previous and then create new one
            else
            {
                fclose(img);
                sprintf(name, "%03i.jpg", a);
                img = fopen(name, "w");
                fwrite(buffer, 512, 1, img);
                a++;
            }
        }
        else
        {
            //If jpeg signature not found and img is not empty then continue writing to file
            if (img != NULL)
            {
                fwrite(buffer, 512, 1, img);
            }
        }
    }
    //Close input and output files
    fclose(img);
    fclose(f);
}
