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
void decryptRotation(unsigned char *someString);
void putInSpaces(unsigned char *someString);
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
            unsigned char string[100];
            printf("Type a message that is to be encrypted. If you wish to put spaces in between words, use a '-' symbol instead of a space.\n");
            scanf("%s", string);
            putInSpaces(string);
            printf("%s\n", string);
            printf("Choose a rotation key.\n");
            scanf("%d", &rotation);
            encryptRotation(string, rotation);
            printf("Your encrypted message: %s\n", string);
            decryptRotation(string);
            printf("Your message has been decrypted: %s\n", string);
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
    int i = 0;
    while(someString[i] != '\0') 
    {
        if(someString[i] == ' ' || someString[i] == '.') 
        {
            i++;
        }
        if(someString[i] <= 90 && someString[i] >= 65 && someString[i] + someInteger > 90)
        {
            someString[i] = someString[i] + someInteger - 26;
            i++;
        }
        if(someString[i] == ' ' || someString[i] == '.') 
        {
            i++;
        }
        someString[i] = someString[i] + someInteger;
        if(someString[i] > 122)
        {
            someString[i] = someString[i] - 26;
        }
        i++;
    }
   
}



void decryptRotation(unsigned char *someString)
{
    int Z = 1;
    int i = 0;
    int wordFound = 0;
    char wordCheck1 = 0;
    char wordCheck2 = 0;
    char wordCheck3 = 0;
    char wordCheck4 = 0;
    
    
    
    
    
    while(Z < 26 && wordFound == 0)
    {
        i = 0;
        while(someString[i] != '\0')
        {
            if(someString[i] == '.' || someString[i] == ' ')
            {
                i++;
            }
            if(someString[i] == '.' || someString[i] == ' ')
            {
                i++;
            }
            someString[i] = someString[i] + 1;
            if(someString[i] > 122)
            {
                someString[i] = someString[i] - 26;
            }
            if(someString[i] > 90 && someString[i] < 97)
            {
                someString[i] = someString[i] -26;
            }
            i++;
        }

        printf("%s   %d\n", someString, Z);
        i = 0;
        while(someString[i] != '\0') //HAVE TO HAVE 2 SEPRATE STORAGE VARIABLE LISTS, 1 WITH 3 AND 1 WITH 4
        {
            
            
            wordCheck1 = someString[i];
            i++;
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'a' && wordCheck3 == ' ') 
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'a' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck1 == 'a' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            wordCheck2 = someString[i];
            i++;
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'a' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'a' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck1 == 'a' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            wordCheck3 = someString[i];
            i++;
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'a' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'a' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck1 == 'a' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
              
        }
        i = 0;
        while(someString[i] != '\0')
        {
            
            
            wordCheck1 = someString[i];
            i++;
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'i' && wordCheck3 == 't' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'i' && wordCheck4 == 't' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'i' && wordCheck1 == 't' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'i' && wordCheck2 == 't' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'i' && wordCheck3 == 'n' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'i' && wordCheck4 == 'n' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'i' && wordCheck1 == 'n' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'i' && wordCheck2 == 'n' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'i' && wordCheck3 == 's' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'i' && wordCheck4 == 's' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'i' && wordCheck1 == 's' & wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'i' && wordCheck2 == 's' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 't' && wordCheck3 == 'o' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 't' && wordCheck4 == 'o' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 't' && wordCheck1 == 'o' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 't' && wordCheck2 == 'o' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'b' && wordCheck3 == 'e' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'b' && wordCheck4 == 'e' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'b' && wordCheck1 == 'e' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'b' && wordCheck2 == 'e' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'o' && wordCheck3 == 'f' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'o' && wordCheck4 == 'f' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'o' && wordCheck1 == 'f' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'o' && wordCheck2 == 'f' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            wordCheck2 = someString[i];
            i++;
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'i' && wordCheck3 == 't' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'i' && wordCheck4 == 't' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'i' && wordCheck1 == 't' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'i' && wordCheck2 == 't' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'i' && wordCheck3 == 'n' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'i' && wordCheck4 == 'n' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'i' && wordCheck1 == 'n' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'i' && wordCheck2 == 'n' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'i' && wordCheck3 == 's' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'i' && wordCheck4 == 's' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'i' && wordCheck1 == 's' & wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'i' && wordCheck2 == 's' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 't' && wordCheck3 == 'o' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 't' && wordCheck4 == 'o' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 't' && wordCheck1 == 'o' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 't' && wordCheck2 == 'o' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'b' && wordCheck3 == 'e' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'b' && wordCheck4 == 'e' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'b' && wordCheck1 == 'e' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'b' && wordCheck2 == 'e' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'o' && wordCheck3 == 'f' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'o' && wordCheck4 == 'f' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'o' && wordCheck1 == 'f' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'o' && wordCheck2 == 'f' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            wordCheck3 = someString[i];
            i++;
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'i' && wordCheck3 == 't' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'i' && wordCheck4 == 't' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'i' && wordCheck1 == 't' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'i' && wordCheck2 == 't' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'i' && wordCheck3 == 'n' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'i' && wordCheck4 == 'n' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'i' && wordCheck1 == 'n' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'i' && wordCheck2 == 'n' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'i' && wordCheck3 == 's' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'i' && wordCheck4 == 's' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'i' && wordCheck1 == 's' & wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'i' && wordCheck2 == 's' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 't' && wordCheck3 == 'o' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 't' && wordCheck4 == 'o' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 't' && wordCheck1 == 'o' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 't' && wordCheck2 == 'o' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'b' && wordCheck3 == 'e' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'b' && wordCheck4 == 'e' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'b' && wordCheck1 == 'e' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'b' && wordCheck2 == 'e' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'o' && wordCheck3 == 'f' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'o' && wordCheck4 == 'f' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'o' && wordCheck1 == 'f' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'o' && wordCheck2 == 'f' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            wordCheck4 = someString[i];
            i++;
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'i' && wordCheck3 == 't' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'i' && wordCheck4 == 't' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'i' && wordCheck1 == 't' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'i' && wordCheck2 == 't' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'i' && wordCheck3 == 'n' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'i' && wordCheck4 == 'n' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'i' && wordCheck1 == 'n' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'i' && wordCheck2 == 'n' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'i' && wordCheck3 == 's' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'i' && wordCheck4 == 's' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'i' && wordCheck1 == 's' & wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'i' && wordCheck2 == 's' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 't' && wordCheck3 == 'o' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 't' && wordCheck4 == 'o' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 't' && wordCheck1 == 'o' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 't' && wordCheck2 == 'o' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'b' && wordCheck3 == 'e' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'b' && wordCheck4 == 'e' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'b' && wordCheck1 == 'e' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'b' && wordCheck2 == 'e' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
            
            
            
            if(wordCheck1 == ' ' && wordCheck2 == 'o' && wordCheck3 == 'f' && wordCheck4 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck2 == ' ' && wordCheck3 == 'o' && wordCheck4 == 'f' && wordCheck1 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck3 == ' ' && wordCheck4 == 'o' && wordCheck1 == 'f' && wordCheck2 == ' ')
            {
                wordFound = 1;
                break;
            }
            if(wordCheck4 == ' ' && wordCheck1 == 'o' && wordCheck2 == 'f' && wordCheck3 == ' ')
            {
                wordFound = 1;
                break;
            }
        }
        Z++;
      
     }
     

}








void putInSpaces(unsigned char *someString)
{
    int i = 0;
    while(someString[i] != '\0') 
    {
        if(someString[i] == '-') 
        {
            someString[i] = ' ';
        }
    i++;
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






