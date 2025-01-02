#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct my_struct {
  uint32_t a;
  uint16_t b;
} __attribute__((packed));  

int main ()
{
    FILE *fpA;
    FILE *fpB;
    {
        fpA = fopen( "a" , "w" );
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
        // packing is needed otherwise b will have extra zeros due to automatic alignment done by compiler
        fpB = fopen( "b" , "w" );
        struct my_struct s;
        memset(&s, 0, sizeof(struct my_struct));
        s.a = 0xFEEDFACFu;
        s.b = 0x123;
        fwrite(&s, sizeof(struct my_struct) , 1, fpB );
    }

    fclose(fpA);
    fclose(fpB);
    return(0);
}
