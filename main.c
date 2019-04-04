#include <stdio.h>


// to do list: Do rotation on a string and then print the encrypted message. Use a key rotation of 1?
// key, rotation, substitution, decrypt, encrypt
/* create a user interface that allows the user to choose whether they want to see an encrypted message,
   decrypted message, or to type a message to be decrypted or encrypted yatta yatta */




// FUNCTION PROTOTYPES
void encrypt(char *someString, int someInteger);
void putInSpaces(char *someString3);
// FUNCTION PROTOTYPES



int main() {
    char userChoice = 0;
    printf("Choose an option:\n\n");
    printf("a). Have a pre-determined message encrypted with a rotation key of your choice.\n\n");
    printf("b). Have a message of your choosing encrypted with a rotation key of your choosing.\n");
    printf("Your encrypted message will then be decoded.\n\n")//i put the rest of option B here so my code didn't go off the edge the screen
    scanf("%c", &userChoice);
    if(userChoice < 'a' || userChoice > 'b') 
    {
        printf("Incorrect choice. Terminating program.\n");
        return 0;
    }
    printf("Thankyou.\n\n\n");
    
    
    
    switch(userChoice) {
        case'a': 
        {
            int rotation = 1;
            char string[] = {'i', 't', ' ', 'b', 'e', ' ', 'l', 'i', 'k', 'e', ' ', 't', 'h', 'a', 't', '\0'};
            printf("The unencrypted message: %s\n", string);
            printf("Type a rotation key\n");
            scanf("%d", &rotation);
            encrypt(string, rotation);
            printf("The encrypted message: %s\n", string);
            break;    
        }
        case 'b': 
        {
            char string2[60];
            printf("Type a message that is to be encrypted. If you wish to put spaces in between words, use a '_' symbol instead.\n");
            scanf("%s", string2);
            putInSpaces(string2);
            printf("%s\n", string2);
        }
        
        default: {break;}
    
    }
    
    
    
    
    
    return 0;
}



// FUNCTION DEFINITIONS
void encrypt(char *someString, int someInteger) 
{
    int r = 0;
    while(someString[r] != '\0') 
    {
        if(someString[r] == ' ') 
        {
            r++;
        }
        someString[r] = someString[r] + someInteger;
        r++;
    }
   
}





void putInSpaces(char *someString3)
{
    int r = 0;
    while(someString3[r] != '\0') 
    {
        if(someString3[r] == '_') 
        {
            someString3[r] = ' ';
        }
    r++;
    }

}
// FUNCTION DEFINITIONS










