/*
scHebZ C...
compiled in codeblocks v10.05.
august 29th 2011.
maybe a large waste of time however...
the following is a c program that I made and thought I would share?
it basically first of all uses data from another program
that generated a 450 data point sine curve 0-->90 degrees of amplitude 10bits or 1023.
if you would like that code also....
email me or bug me to give it too you?

this is needed to first of all, to calculate the sequence for compression,
once it is generated. the digital values are reversed so 90,89.8,89.6...0
and the resulting digital values are then subtracted from each other, the results are always no more than
3 bit numbers because it is simply the difference between each digital level, this creates a series of 3 bit numbers ranging from 0 to 4 there is
a pattern there with further time I could possibly figure out the sequence?
these numbers are then compressed into 30bit numbers.
by multiplying each value by a factor of 3 up to 9 places or (3*n) n={0,1,2,3,4,5,6,7,8,9} == {0,3,6,12,15,18,21,24,27}
which is a multiple or bit shift for each 10 3 bit numbers.
these values of which will be held in 32bit storage spaces.
* this is the sequence generated from my inital routine "not included" of values from subtraction of the digital amplitudes
of this data. this is starting from 90 degrees backwards if you want to go the other way your entrance into the array
is the last array element with data in it [44,9] as the starting point
0    [  0] [  0] [  0] [  0] [  0] [  0] [  0] [  0] [  0] [  0]    sum rN   0
1    [  0] [  0] [  1] [  0] [  0] [  0] [  0] [  1] [  0] [  0]    sum rN   2
2    [  0] [  1] [  0] [  0] [  0] [  1] [  0] [  0] [  1] [  0]    sum rN   3
3    [  0] [  1] [  0] [  1] [  0] [  1] [  0] [  0] [  1] [  0]    sum rN   4
4    [  1] [  0] [  1] [  1] [  0] [  1] [  0] [  1] [  0] [  1]    sum rN   6
5    [  1] [  0] [  1] [  1] [  0] [  1] [  1] [  0] [  1] [  1]    sum rN   7
6    [  1] [  0] [  1] [  1] [  1] [  1] [  0] [  1] [  1] [  1]    sum rN   8
7    [  1] [  1] [  1] [  0] [  1] [  1] [  1] [  1] [  1] [  1]    sum rN   9
8    [  1] [  1] [  1] [  1] [  1] [  1] [  1] [  1] [  2] [  1]    sum rN   B
9    [  1] [  1] [  1] [  1] [  1] [  1] [  2] [  1] [  1] [  1]    sum rN   B
10   [  1] [  2] [  1] [  1] [  2] [  1] [  1] [  1] [  2] [  1]    sum rN   D
11   [  1] [  2] [  1] [  2] [  1] [  1] [  2] [  1] [  2] [  1]    sum rN   E
12   [  1] [  2] [  1] [  2] [  1] [  2] [  1] [  2] [  2] [  1]    sum rN   F
13   [  2] [  1] [  2] [  1] [  2] [  2] [  1] [  2] [  2] [  1]    sum rN  10
14   [  2] [  2] [  1] [  2] [  2] [  2] [  1] [  2] [  2] [  2]    sum rN  12
15   [  1] [  2] [  2] [  2] [  2] [  2] [  1] [  2] [  2] [  2]    sum rN  12
16   [  2] [  2] [  2] [  2] [  2] [  2] [  2] [  2] [  2] [  2]    sum rN  14
17   [  2] [  2] [  2] [  2] [  2] [  2] [  2] [  2] [  2] [  2]    sum rN  14
18   [  2] [  2] [  2] [  3] [  2] [  2] [  2] [  2] [  2] [  3]    sum rN  16
19   [  2] [  2] [  2] [  2] [  3] [  2] [  2] [  2] [  3] [  2]    sum rN  16
20   [  2] [  3] [  2] [  2] [  3] [  2] [  2] [  3] [  2] [  3]    sum rN  18
21   [  2] [  2] [  3] [  2] [  3] [  2] [  2] [  3] [  2] [  3]    sum rN  18
22   [  2] [  3] [  2] [  3] [  2] [  3] [  2] [  3] [  3] [  2]    sum rN  19
23   [  3] [  2] [  3] [  3] [  2] [  3] [  2] [  3] [  3] [  2]    sum rN  1A
24   [  3] [  3] [  2] [  3] [  3] [  2] [  3] [  3] [  3] [  2]    sum rN  1B
25   [  3] [  3] [  3] [  2] [  3] [  3] [  3] [  2] [  3] [  3]    sum rN  1C
26   [  3] [  3] [  3] [  2] [  3] [  3] [  3] [  3] [  3] [  3]    sum rN  1D
27   [  3] [  2] [  3] [  3] [  3] [  3] [  3] [  3] [  3] [  3]    sum rN  1D
28   [  3] [  3] [  3] [  3] [  3] [  3] [  3] [  3] [  3] [  3]    sum rN  1E
29   [  3] [  3] [  3] [  3] [  3] [  3] [  3] [  3] [  3] [  3]    sum rN  1E
30   [  4] [  3] [  3] [  3] [  3] [  3] [  3] [  3] [  4] [  3]    sum rN  20
31   [  3] [  3] [  3] [  3] [  4] [  3] [  3] [  3] [  3] [  4]    sum rN  20
32   [  3] [  3] [  3] [  4] [  3] [  3] [  3] [  3] [  4] [  3]    sum rN  20
33   [  3] [  4] [  3] [  3] [  3] [  4] [  3] [  3] [  4] [  3]    sum rN  21
34   [  3] [  4] [  3] [  3] [  4] [  3] [  3] [  4] [  3] [  3]    sum rN  21
35   [  4] [  3] [  3] [  4] [  3] [  3] [  4] [  3] [  4] [  3]    sum rN  22
36   [  3] [  4] [  3] [  4] [  3] [  4] [  3] [  3] [  4] [  3]    sum rN  22
37   [  4] [  3] [  4] [  3] [  3] [  4] [  3] [  4] [  3] [  4]    sum rN  23
38   [  3] [  4] [  3] [  4] [  3] [  4] [  3] [  4] [  3] [  4]    sum rN  23
39   [  3] [  4] [  3] [  4] [  3] [  4] [  3] [  4] [  3] [  4]    sum rN  23
40   [  3] [  4] [  3] [  4] [  3] [  4] [  3] [  4] [  3] [  4]    sum rN  23
41   [  4] [  3] [  4] [  3] [  4] [  3] [  4] [  3] [  4] [  3]    sum rN  23
42   [  4] [  4] [  3] [  4] [  3] [  4] [  3] [  4] [  4] [  3]    sum rN  24
43   [  4] [  3] [  4] [  3] [  4] [  3] [  4] [  4] [  3] [  4]    sum rN  24
44   [  3] [  4] [  3] [  4] [  4] [  3] [  4] [  3] [  4] [  3]    sum rN  23
45   [  0] [  0] [  0] [  0] [  0] [  0] [  0] [  0] [  0] [  0]    sum rN   0

HEX SUM OF ROWS + SUM OF COLUMS is 0x3FF == 1023 **that is good means the data is correct

[224] element 225 = 724 or 45 degrees, so 724 is the digital value of a sin curve at 45 degrees at 10 bit resolution
last row ignored, of course only added for the sake of simplicty here, with further programing tricks
both the first and last rows could be ingnored, and the data compressed even further.

either add or subtract from here also depends on entry to compression of data

as you can see you could manually find out what the digital 10bit value of this set of data was
by simple subtracting from 1023 (90)degrees the values from[0,0] ...[i,j] onwards giving you your answer,
where [i,j] is the integer value of the angle needed to be found.
knowing that the data points are equal to 90/450 == 0.2 degree steps.

now the de-compression routine is started and this multiplys out each bit starting from [0,0], or [44,9]
by (9*3) then binary adds the value of the next [0,1] (8*3)... and so on.
this data is then combined into these 45 32 bit values.
which only store 45x32 = 1.44kbits of data compared to the 450 x 16 = 7.2kbit needed to hold the 10 bit vaules of each individual data point.
without the compression, which gives a compression rate of 5:1 apx.
so instead of holding 450 points into 7.2kbits of data space you can hold this in 1.44kbits.
the tradeoff of course will be computation time, to compute a value, but if space is needed, then this will work.
also you do not need to include any math.h header :).

these are the values generated after the compression
of a 10bit 450 data point 90-->0 degree
0      0x00000000    0
1      0x1C71C8E3    477219043
2      0x2391C71C    596756252
3      0x1C8E38E4    479082724
4      0x1C71C71C    477218588
5      0x238E38E3    596523235
6      0x238E38E3    596523235
7      0x238E38E3    596523235
8      0x238E371C    596522780
9      0x1C6E38E3    476985571
10     0x1C71B8DC    477214940
11     0x1B8DC6E3    462276323
12     0x1C6E36E3    476985059
13     0x1C6DB8DB    476952795
14     0x236DC6DB    594396891
15     0x1C6DB6DC    476952284
16     0x1B6DB6DB    460175067
17     0x1B6DB6DB    460175067
18     0x1B6DB6D3    460175059
19     0x1B6DB4DB    460174555
20     0x1B4DB4DB    458077403
21     0x136D369B    325924507
22     0x1369A6D3    325691091
23     0x1369A69A    325691034
24     0x1A6934D2    443102418
25     0x1A69349A    443102362
26     0x13493492    323564690
27     0x1A492692    441001618
28     0x12492492    306783378
29     0x12492492    306783378
30     0x12452491    306521233
31     0x12452452    306521170
32     0x0A45228A    172302986
33     0x0A451451    172299345
34     0x0A289451    170431569
35     0x0A24A251    170173009
36     0x09289249    153653833
37     0x0A249249    170168905
38     0x09249049    153391177
39     0x09209241    153129537
40     0x09048241    151290433
41     0x08208241    136348225
42     0x01008208    16810504
43     0x01008008    16809992
44     0x00200040    2097216
45     0x00000000    0

if you want to find the value of sin x degrees simply take the value that is found via this routine and divide it by the total in this case MAX
if you enter the degree you wish to find type 450, and are returned 724
724/1023 =.707... which is the sin of 45.0 degrees.
the resolution of this set of data is .2 degrees, it could be xpanded with not too much effort.
there may actually be a way of generating it from this data set, however that is for another day
*/

#include <stdlib.h>
#include <stdio.h>

#define DEG45   (224)
#define DEG90   (459)
#define HEXMIN  (0x00000007)
#define MAX     (1024)
#define ANGLE   (90)

#define HEXCMPSIZE90 ((ANGLE+2)/2) /* == 46  */


int DECOMPRESS(int * SININT, int * HEXDATA);
int main()
{

    int HEXCOMP90_0[HEXCMPSIZE90]=
   {0x00000000,0x1C71C8E3,0x2391C71C,0x1C8E38E4,0x1C71C71C,
    0x238E38E3,0x238E38E3,0x238E38E3,0x238E371C,0x1C6E38E3,
    0x1C71B8DC,0x1B8DC6E3,0x1C6E36E3,0x1C6DB8DB,0x236DC6DB,
    0x1C6DB6DC,0x1B6DB6DB,0x1B6DB6DB,0x1B6DB6D3,0x1B6DB4DB,
    0x1B4DB4DB,0x136D369B,0x1369A6D3,0x1369A69A,0x1A6934D2,
    0x1A69349A,0x13493492,0x1A492692,0x12492492,0x12492492,
    0x12452491,0x12452452,0x0A45228A,0x0A451451,0x0A289451,
    0x0A24A251,0x09289249,0x0A249249,0x09249049,0x09209241,
    0x09048241,0x08208241,0x01008208,0x01008008,0x00200040,
    0x00000000};
    int *HEXPTR=HEXCOMP90_0;
    float MODULO=0;

    int select=0;
    int DECOMVAL=0;

    printf("please enter a value for conversion IN FULL INTEGER VALUE IE 90.0 DEGS == 900 \n");
    printf("result will be rounded as the resolution is only .2 degees or 450 data points \n");
    scanf("%i",&select);
    if(select>=0&&select<=900)
    {
        printf("\n");
        DECOMVAL=DECOMPRESS(&select, HEXPTR);
        printf("the sin^-1 %i digital is %i\n",(2*select), DECOMVAL);
        MODULO=(((float)DECOMVAL)/((float)MAX));
        printf("The rounded value of conversion is %2.1f degrees\n", (((float)(2*(select))/10.0)));
        printf("the sin of %i digital is %f\n", DECOMVAL, MODULO);
    }


    return 0;
}
/* 000 --> 900 0 --> 90 degrees ==> forward  add from ZERO */
/* 900 --> 000 90 --> 0 degrees ==> reverse  subtract from MAX */

/* HEXCOMP90_0[i] note used reverse compression counting from 90 --> 0 */
/* depending on value forward or reverse will be quicker if val is greater or less than 45 */
/* to obtain a correct result you will either need to add or subtract the value from either */
/* 0 or 1023, in this case the result will be 1023 - HEXVAL */
/* or ((MAX-1)-HEXVAL) */
int DECOMPRESS(int * SININT, int * HEXDATA)
{
    int i,j,k; /* looping vars */

    int HEXVAL=1023;
    int SINDIV=0;
    int SINTEST=0;

        /* begin expansion*/
        HEXVAL=0;
        SINTEST=*SININT%2;
        if(SINTEST==0) /* the follwing two statements gets rid of the integer divison problem */
        {
            SINDIV=*SININT/2;
            printf("%i sindiv/2\n",SINDIV);
        }
        if(SINTEST==1)
        {
            SINDIV=((*SININT)+1)/2;
            printf("%i sindiv+1/2\n",SINDIV);
        }
        k=9; /* division / multiplication factor */
        j=0;
        /* initialize intial value */

        for(i=0;i<(HEXCMPSIZE90*10);i++) /* find value within compression */
        {
            HEXVAL+=(HEXMIN&(HEXDATA[j]>>(k*3)));

            if(k==0)
            {
                j++;
                k=10;
            }

            if(i==(SINDIV+9))/* need as first array has 10 elements all of which are zero */
            {
                break;
            }
            k--;
            /* check that valid elementt has been found and leave loop with correct correlation result */

        }
        *SININT=SINDIV;

        /* notice that direction matters */
        return(HEXVAL);

}
/* end all*/
