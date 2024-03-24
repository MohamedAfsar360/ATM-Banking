#include<stdio.h>
#include<windows.h>
#include<time.h>



int main()
{
    system("color 2F");
    int pin=1234,option,enterPin,count=0,amount=1;
    float balance=5000;
    int continueTransaction=1;

    time_t current;
    time(&current);
    printf("\t\t\t\t\t\t%s",ctime(&current));
    printf("\n\t\t\t\t\t================WELCOME TO IOB================\n");
    while(pin!=enterPin)
        {
            printf("\n enter a pin:");
            scanf("%d",&enterPin);
            if(enterPin !=pin)
            {
                Beep(1000,500);
                printf("invalid pin...!");
            }
            count++;
            if(count==3 )
                {
                    exit(0);
                }
        }
    while(continueTransaction !=0)
    {
                printf("\n\t\t\t================================Available Transaction================================");
        printf("\n\n\t\t\t1.Withdraw");
        printf("\n\t\t\t2.Deposite");
        printf("\n\t\t\t3.Check Balance");
        printf("\n\n\t select the option:");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            while(amount%500!=0)
            {
                printf("\n\t\tEnter the amount:");
                scanf("%d",&amount);
                if(amount%500!=0)
                {
                    printf("\n\t the amount should be multiple of 500");
                }
            }
            if(balance<amount)
            {
                printf("\n\t insufficient Balance");
                amount=1;
                break;
            }
            else
            {
                balance -=amount;
                printf("\n\t\t you have withdraw Rs.%d. Your new balance is %.2f",amount,balance);
                amount=1;
                break;
            }
        case 2:
            printf("\n\t\t enter the amount:");
            scanf("%d",&amount);
            balance+=amount;
            amount=1;
            printf("\n\t\t deposited Rs.%d. your balance is %.2f",amount,balance);
            break;
        case 3:
            printf("\n\t\tyour balance is Rs.%.2f",balance);
            break;
        default:
            Beep(2000,1000);
            printf("\n\t\tInvalid option");
        }
        printf("\n\t\t do you wish to perform another transaction?press1[yes]/0[no]:");
        scanf("%d",&continueTransaction);
    }
    return 0;
}
