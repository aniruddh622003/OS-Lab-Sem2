#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int size, m, n, pgno, pagetable[10] = {2, 4, 8 ,5, 9, 7, 6, 1, 3}, i, j, frameno;
    double m1;
    int ra = 0, ofs = 0;
    printf("Enter process size(in KB of max 40KB): "); /*reading memory size*/
    scanf("%d", &size);
    m1 = size / 4;
    n = ceil(m1);
    printf("Total No.of pages: %d\n", n);
    printf("PAGE TABLE");
    for (i = 0; i < n; i++)
        printf("\n %d -> %d", i, pagetable[i]);
    printf("\nEnter relative address(in decimal notation eg. 2432): ");
    scanf("%d", &ra);
    int mulfac = 1;
    while(ra > 10){
        ofs += ((ra%10) * mulfac);
        mulfac *= 10;
        ra = ra/10;
    }
    pgno = ra; /*calculating physical address*/
    printf("page no = %d\n", pgno);
    
    frameno = pagetable[pgno];
    printf("\nEquivalent physical address: %d%d", frameno, ofs);
    getch();
    return 0;
}