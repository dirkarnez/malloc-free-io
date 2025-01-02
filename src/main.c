#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct my_struct {
  uint32_t a;
  uint16_t b;
};

int main ()
{
    FILE *fpA;
    FILE *fpB;
    {
        fpA = fopen( "a.txt" , "w" );
        for (int i = 0; i < 2; i++)
        {
            if (i == 0) {
                uint32_t a = 0xFEEDFACFu;
                fwrite(&a, sizeof(uint32_t) , 1, fpA );
            } 
            else if (i == 1)
            {
                uint16_t b = 0x123;
                fwrite(&b, sizeof(uint16_t) , 1, fpA );
            }
        }
    }

    {
        fpB = fopen( "b.txt" , "w" );
        struct my_struct s;
        s.a = 0xFEEDFACFu;
        s.b = 0x123;
        fwrite(&s, sizeof(s) , 1, fpB );
    }

    fclose(fpA);
    fclose(fpB);
    return(0);
}
