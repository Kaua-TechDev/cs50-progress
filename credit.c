#include <cs50.h>
#include <stdio.h>

long checkSum(long number)
{
    int sum = 0;
    int position = 0;

    while (number > 0){
        int digit = number % 10;
            if(position % 2 == 1){
                digit *= 2;
                if(digit > 9){
                    digit = (digit / 10) + (digit % 10);
                }
            }
        sum += digit;
        number /= 10;
        position++;
    }

    if(sum % 10 == 0){
        return 1;
    } else {
        printf("INVALID\n");
        return 0;
    }
}

void cardType (long number){
    int length = 0;
    long counter = number;

    while(counter > 0)
    {
        counter /= 10;
        length++;
    }

    long twoDigits = number;
    while(twoDigits >= 100){
        twoDigits /= 10;
    }

    int oneDigit = twoDigits / 10;

    if((oneDigit == 4) && (length == 13 || length == 16)){
        printf("VISA\n");
    } else if((twoDigits == 34 || twoDigits == 37) && (length == 15)){
        printf("AMEX\n");
    } else if((twoDigits >= 51 && twoDigits <= 55) && (length == 16)){
        printf("MASTERCARD\n");
    } else{
        printf("INVALID\n");
    }
}

int main(){

    long cardNumber = get_long("Input a credit card number with 13 to 16 digits: ");
    if(checkSum(cardNumber)){
        cardType(cardNumber);
    }
}
