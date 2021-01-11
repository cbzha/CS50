/*test if a credit card number is visa, american express , mastercard or invalid
Hans Peter Luhn' Algorithm

@Carlos Bruno
*/
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int countdigits = 0;
    int checksum = 0;
    long num = 0;
    long firstdigits = 0;
    long firstdigit = 0; 
    int count = 0;
 
    long number = get_long("type the number of the credit card: ");
    num = number;
   
   //count the algarisms
    while (num != 0)
    {
        num /= 10;
        count ++;
    }

    //if is american express 15 digits
    if (count == 15)
    {
        // gets first digts for checking for matching patterns
        firstdigits = number / 10000000000000;

        long first = number % 10;

        long sec = number % 100;
        sec = sec / 10;

        long third = number % 1000;
        third = third / 100;

        long four = number % 10000;
        four = four / 1000;

        long fifth = number % 100000;
        fifth = fifth / 10000;
   
        long sixth = number % 1000000;
        sixth = sixth / 100000;

        long seventh = number % 10000000;
        seventh = seventh / 1000000;

        long eigth = number % 100000000;
        eigth = eigth / 10000000;

        long ninth = number % 1000000000;
        ninth = ninth / 100000000;

        long tenth = number % 10000000000;
        tenth = tenth / 1000000000;

        long elv = number % 100000000000;
        elv =  elv / 10000000000;
   
        long twelth = number % 1000000000000;
        twelth =  twelth / 100000000000;

        long thirteen = number % 10000000000000;
        thirteen = thirteen / 1000000000000;

        long fourteen = number % 100000000000000;
        fourteen = fourteen / 10000000000000;

        long fifteenth = number % 1000000000000000;
        fifteenth = fifteenth / 100000000000000;

  
        int a = (sec * 2) / 10 + ((sec * 2) % 10);
        int b = (four * 2) / 10 + ((four * 2) % 10);
        int c = (sixth * 2) / 10 + ((sixth * 2) % 10);
        int d = (eigth * 2) / 10 + ((eigth * 2) % 10);
        int e = (tenth * 2) / 10 + ((tenth * 2) % 10);
        int f = (twelth * 2) / 10 + ((twelth * 2) % 10);
        int g = (fourteen * 2) / 10 + ((fourteen * 2) % 10);

        checksum = a + b + c + d + e + f + g;
        checksum = checksum + first + third + fifth + seventh + ninth + elv + thirteen + fifteenth;
        checksum = checksum % 10;

    }


    if (count == 16)
    {
        firstdigits = number / 100000000000000;
        firstdigit = number / 1000000000000000;
        // get last digit
        long first = number % 10;
        // get second to last digit
        long sec = number % 100;
        sec = sec / 10;

        long third = number % 1000;
        third = third / 100;

        long four = number % 10000;
        four = four / 1000;

        long fifth = number % 100000;
        fifth = fifth / 10000;
   
        long sixth = number % 1000000;
        sixth = sixth / 100000;

        long seventh = number % 10000000;
        seventh = seventh / 1000000;

        long eigth = number % 100000000;
        eigth = eigth / 10000000;

        long ninth = number % 1000000000;
        ninth = ninth / 100000000;

        long tenth = number % 10000000000;
        tenth = tenth / 1000000000;

        long elv = number % 100000000000;
        elv =  elv / 10000000000;
   
        long twelth = number % 1000000000000;
        twelth =  twelth / 100000000000;

        long thirteen = number % 10000000000000;
        thirteen = thirteen / 1000000000000;

        long fourteen = number % 100000000000000;
        fourteen = fourteen / 10000000000000;

        long fifteenth = number % 1000000000000000;
        fifteenth = fifteenth / 100000000000000;
   
        long sixteen = number % 10000000000000000;
        sixteen = sixteen / 1000000000000000;
  
        int a = (sec * 2) / 10 + ((sec * 2) % 10);
        int b = (four * 2) / 10 + ((four * 2) % 10);
        int c = (sixth * 2) / 10 + ((sixth * 2) % 10);
        int d = (eigth * 2) / 10 + ((eigth * 2) % 10);
        int e = (tenth * 2) / 10 + ((tenth * 2) % 10);
        int f = (twelth * 2) / 10 + ((twelth * 2) % 10);
        int g = (fourteen * 2) / 10 + ((fourteen * 2) % 10);
        int h = (sixteen * 2) / 10 + ((sixteen * 2) % 10);
       
        // algorithm's checksum
        checksum = a + b + c + d + e + f + g + h;
        checksum = checksum + first + third + fifth + seventh + ninth + elv + thirteen + fifteenth;
        // get cheksum's last digit
        checksum = checksum % 10;

    }

    if (count == 13)
    {
        firstdigits = number / 1000000000000;
        long first = number % 10;

        long sec = number % 100;
        sec = sec / 10;

        long third = number % 1000;
        third = third / 100;

        long four = number % 10000;
        four = four / 1000;

        long fifth = number % 100000;
        fifth = fifth / 10000;
   
        long sixth = number % 1000000;
        sixth = sixth / 100000;

        long seventh = number % 10000000;
        seventh = seventh / 1000000;

        long eigth = number % 100000000;
        eigth = eigth / 10000000;

        long ninth = number % 1000000000;
        ninth = ninth / 100000000;

        long tenth = number % 10000000000;
        tenth = tenth / 1000000000;

        long elv = number % 100000000000;
        elv =  elv / 10000000000;
   
        long twelth = number % 1000000000000;
        twelth =  twelth / 100000000000;

        long thirteen = number % 10000000000000;
        thirteen = thirteen / 1000000000000;
        
        // get the sum of product's digits
        int a = (sec * 2) / 10 + ((sec * 2) % 10);
        int b = (four * 2) / 10 + ((four * 2) % 10);
        int c = (sixth * 2) / 10 + ((sixth * 2) % 10);
        int d = (eigth * 2) / 10 + ((eigth * 2) % 10);
        int e = (tenth * 2) / 10 + ((tenth * 2) % 10);
        int f = (twelth * 2) / 10 + ((twelth * 2) % 10);

        checksum = a + b + c + d + e + f ;
        checksum = checksum + first + third + fifth + seventh + ninth + elv + thirteen;
        
        //get the last cheksum digit
        checksum = checksum % 10;

    }

    if (checksum == 0 && count == 16 && (firstdigits == 51 || firstdigits == 52 || firstdigits == 53 || firstdigits == 54 || firstdigits == 55))
    {
        printf("MASTERCARD\n");
    }

    else if (checksum == 0 && count == 15 && (firstdigits == 34 || firstdigits == 37))
    {
        printf("AMEX\n");
    }

    else if (checksum == 0 && (count == 13 || count == 16)  && firstdigit == 4)
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}
