#include <cs50.h>
#include <stdio.h>

int main(void)
{
    unsigned long cardNo = get_long("Hello, Please Enter your Card Number: ");
    long cardNonew = 0, cardNodigit = 0, cardNodigitsum = 0, cardNonew2 = 0, cardNodigit2 = 0, cardNodigitsum2 = 0,
         cardNoSumTotal = 0;
    long card2Nonew = 0, card2Nodigit = 0, card2Nodigitsum = 0, card2Nonew2 = 0, card2Nodigit2 = 0, card2Nodigitsum2 = 0,
         card2NoSumTotal = 0;
    long card3Nonew = 0, card3Nodigit = 0, card3Nodigitsum = 0, card3Nonew2 = 0, card3Nodigit2 = 0, card3Nodigitsum2 = 0,
         card3NoSumTotal = 0;
    long card4Nonew = 0, card4Nodigit = 0, card4Nodigitsum = 0, card4Nonew2 = 0, card4Nodigit2 = 0, card4Nodigitsum2 = 0,
         card4NoSumTotal = 0;
    bool master = false, visa = false, american = false;
    int csdigit, cs1digit, cs2digit;
    // Visa or Master
    if (cardNo >= 1000000000000000 && cardNo < 10000000000000000)
    {
        // everyother digit starting from second to last
        long j = 10;
        for (long i = 100; i <= 10000000000000000; i = i * 100)
        {
            cardNonew = cardNo;
            cardNonew = cardNonew % i;
            cardNodigit = (cardNonew / j) * 2;
            csdigit = (cardNodigit / 10) + (cardNodigit % 10);
            cardNodigitsum = cardNodigitsum + csdigit;
            j = j * 100;
        }
        // everyother digit starting from last
        long k = 1;
        for (long i = 10; i <= 10000000000000000; i = i * 100)
        {
            cardNonew2 = cardNo;
            cardNonew2 = cardNonew2 % i;
            cardNodigit2 = cardNonew2 / k;
            cardNodigitsum2 = cardNodigitsum2 + cardNodigit2;
            k = k * 100;
        }
        // Checking whether the first digit is 4 for MasterCard
        if (cardNo / 1000000000000000 == 4)
        {
            visa = true;
        }
        // Checking if first two digits lie b/w 51 and 55 for Master Card
        else if (cardNo / 100000000000000 >= 51 && cardNo / 100000000000000 <= 55)
        {
            master = true;
        }
        // checksum
        cardNoSumTotal = cardNodigitsum + cardNodigitsum2;

        if (cardNoSumTotal % 10 == 0 && visa == true)
        {
            printf("\nVISA\n");
        }
        else if (cardNoSumTotal % 10 == 0 && master == true)
        {
            printf("\nMASTERCARD\n");
        }
        else
        {
            printf("\nINVALID\n");
        }
    }
    else if (cardNo >= 1000000000000 && cardNo < 10000000000000)
    {
        long p = 10;
        for (long i = 100; i <= 10000000000000; i = i * 100)
        {
            card2Nonew = cardNo;
            card2Nonew = card2Nonew % i;
            card2Nodigit = (card2Nonew / p) * 2;
            cs1digit = (card2Nodigit / 10) + (card2Nodigit % 10);
            card2Nodigitsum = card2Nodigitsum + cs1digit;
            p = p * 100;
        }

        long o = 1;
        for (long i = 10; i <= 10000000000000; i = i * 100)
        {
            card2Nonew2 = cardNo;
            card2Nonew2 = card2Nonew2 % i;
            card2Nodigit2 = card2Nonew2 / o;
            card2Nodigitsum2 = card2Nodigitsum2 + card2Nodigit2;
            o = o * 100;
        }
        if (cardNo / 1000000000000 == 4)
        {
            visa = true;
        }
        card2NoSumTotal = card2Nodigitsum + card2Nodigitsum2;

        if (card2NoSumTotal % 10 == 0 && visa == true)
        {
            printf("\nVISA\n");
        }
        else
        {
            printf("\nINVALID\n");
        }
    }

    // AMEX
    else if (cardNo >= 100000000000000 && cardNo < 1000000000000000)
    {
        long p = 10;
        for (long i = 100; i <= 100000000000000; i = i * 100)
        {
            card4Nonew = cardNo;
            card4Nonew = card4Nonew % i;
            card4Nodigit = (card4Nonew / p) * 2;
            cs2digit = (card4Nodigit / 10) + (card4Nodigit % 10);
            card4Nodigitsum = card4Nodigitsum + cs2digit;
            p = p * 100;
        }

        long o = 1;
        for (long i = 10; i <= 1000000000000000; i = i * 100)
        {
            card4Nonew2 = cardNo;
            card4Nonew2 = card4Nonew2 % i;
            card4Nodigit2 = card4Nonew2 / o;
            card4Nodigitsum2 = card4Nodigitsum2 + card4Nodigit2;
            o = o * 100;
        }
        if (cardNo / 10000000000000 == 34 || cardNo / 10000000000000 == 37)
        {
            american = true;
        }
        card4NoSumTotal = card4Nodigitsum + card4Nodigitsum2;
        if (card4NoSumTotal % 10 == 0 && american == true)
        {
            printf("\nAMEX\n");
        }
        else
        {
            printf("\nINVALID\n");
        }
    }
    else
    {
        printf("\nINVALID\n");
    }
}
