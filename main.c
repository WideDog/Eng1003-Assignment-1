#include <stdio.h>


// to do list: Do rotation on a string and then print the encrypted message. Use a key rotation of 1?
// key, rotation, substitution, decrypt, encrypt
/* create a user interface that allows the user to choose whether they want to see an encrypted message,
   decrypted message, or to type a message to be decrypted or encrypted yatta yatta
   Have to probably use a file for decryption. Each time a key is completed, input it into a file. Read that file, then look for ' I ', ' a ',
   and 'the' literals. then use AND/OR to verify then stop the loop to print the output.
   check for and, to, I, a, the, am
   */
//BIG PROBLEM FOR LETTER Z



// FUNCTION PROTOTYPES
void encryptRotation(unsigned char *someString, int someInteger);
void decryptRotation(unsigned char *someString2);
void putInSpaces(unsigned char *someString3);
// FUNCTION PROTOTYPES



int main() {
    
   
    
    
    char userChoice = 0;
    printf("\n\n\nChoose an option:\n\n");
    printf("a). Have a pre-determined message encrypted with a rotation key of your choice.\n\n");
    printf("b). Have a message of your choosing encrypted with a rotation key of your choosing. ");
    printf("Your encrypted message will then be decoded.\n\n");//i put the rest of option B here so my code didn't go off the edge the screen
    scanf("%c", &userChoice);
    if(userChoice < 'a' || userChoice > 'c') 
    {
        printf("Incorrect choice. Terminating program.\n");
        return 0;
    }
    printf("Thankyou.\n\n\n");
    
    
    
    switch(userChoice) {
        case'a': 
        {
            int rotation = 1;
            unsigned char string[] = {'i', 't', ' ', 'b', 'e', ' ', 'l', 'i', 'k', 'e', ' ', 't', 'h', 'a', 't', '\0'};
            printf("The unencrypted message: %s\n", string);
            printf("Type a rotation key\n");
            scanf("%d", &rotation);
            encryptRotation(string, rotation);
            printf("The encrypted message: %s\n\n\n\n", string);
            break;    
        }
        case 'b': 
        {
            int rotation = 1;
            unsigned char string2[60];
            printf("Type a message that is to be encrypted. If you wish to put spaces in between words, use a '_' symbol instead of a space.\n");
            scanf("%s", string2);
            putInSpaces(string2);
            printf("%s\n", string2);
            printf("Choose a rotation key.\n");
            scanf("%d", &rotation);
            encryptRotation(string2, rotation);
            printf("Your encrypted message: %s\n", string2);
            decryptRotation(string2);
            printf("Your message has been decrypted: %s\n", string2);
        }
        case 'c':
        {
            
            
        }
        default: {break;}
    
    }
    
    
    
    
    
    return 0;
}



// FUNCTION DEFINITIONS
void encryptRotation(unsigned char *someString, int someInteger) 
{
    int r = 0;
    while(someString[r] != '\0') 
    {
        if(someString[r] == ' ') 
        {
            r++;
        }
        if(someString[r] <= 90 && someString[r] >= 65 && someString[r] + someInteger > 90)
        {
            someString[r] = someString[r] + someInteger - 26;
            r++;
        }
        if(someString[r] == ' ') 
        {
            r++;
        }
        someString[r] = someString[r] + someInteger;
        if(someString[r] > 122)
        {
            someString[r] = someString[r] - 26;
        }
        r++;
    }
   
}



void decryptRotation(unsigned char *someString2)
{
    int Z = 1;
    int i = 0;
    int new = 0;
    char storage1 = 0;
    char storage2 = 0;
    char storage3 = 0;
    
    
    
    
    
    while(Z < 26 && new == 0)
    {
        i = 0;
        while(someString2[i] != '\0')
        {
            if(someString2[i] == ' ')
            {
                i++;
            }
            someString2[i] = someString2[i] + 1;
            if(someString2[i] > 122)
            {
                someString2[i] = someString2[i] - 26;
            }
            if(someString2[i] > 90 && someString2[i] < 97)
            {
                someString2[i] = someString2[i] -26;
            }
            i++;
            
            
            
        }
        printf("%s   %d\n", someString2, Z);
        
        i = 0;
        while(someString2[i] != '\0')
        {
            
            storage1 = someString2[i];
            i++;
            if(storage1 == ' ' && storage2 == 'a' && storage3 == ' ')
            {
                new = 1;
                break;
            }
            if(storage1 == 'a' && storage2 == ' ' && storage3 == ' ')
            {
                new = 1;
                break;
            }
            if(storage1 == ' ' && storage2 == ' ' && storage3 == 'a')
            {
                new = 1;
                break;
            }
            storage2 = someString2[i];
            i++;
             if(storage1 == ' ' && storage2 == 'a' && storage3 == ' ')
            {
                new = 1;
                break;
            }
            if(storage1 == 'a' && storage2 == ' ' && storage3 == ' ')
            {
                new = 1;
                break;
            }
            if(storage1 == ' ' && storage2 == ' ' && storage3 == 'a')
            {
                new = 1;
                break;
            }
            storage3 = someString2[i];
            i++;
            if(storage1 == ' ' && storage2 == 'a' && storage3 == ' ')
            {
                new = 1;
                break;
            }
            if(storage1 == 'a' && storage2 == ' ' && storage3 == ' ')
            {
                new = 1;
                break;
            }
            if(storage1 == ' ' && storage2 == ' ' && storage3 == 'a')
            {
                new = 1;
                break;
            }

        }
        Z++;
      
     }
     

}








void putInSpaces(unsigned char *someString3)
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



/*
 File Stuff.
            FILE *input;
            input = fopen("file.test", "w");
            fprintf(input, "foo");
            fclose(input);
            input = fopen("file.test", "r");
            char str[100];
            fscanf(input, "%s", str);
            printf("%s", str);
 */






