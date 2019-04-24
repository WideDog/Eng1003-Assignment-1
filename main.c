#include <stdio.h>







// FUNCTION PROTOTYPES
void encryptRotation(unsigned char *someString, int someInteger);
void decryptRotation(unsigned char *someString, int someInteger);
void putInSpaces(unsigned char *someString);
char spellCheck3(char letter1, char letter2, char letter3);
char spellCheck4(char letter1, char letter2, char letter3, char letter4);
void rotateByOne(unsigned char *someString);
void substitute(unsigned char *someString, char originalLiteral, char literalSubstitute, unsigned char *memoryString);
// FUNCTION PROTOTYPES







int main() {
    
    char userChoice = 0;
    printf("\n\n\nChoose an option:\n\n");
    printf("a). Have a message of your choosing encrypted with a rotation key of your choosing.\n\n");
    printf("b). decryption of rotation given text and rotation key\n\n");
    printf("c). decryption of rotation given text only\n\n");
    printf("d). encrpytion of cipher given text and substitution key\n\n");
    printf("e). decryption of cipher given text and substitution key\n\n");
    scanf("%c", &userChoice);
    if(userChoice < 'a' || userChoice > 'e') 
    {
        printf("Incorrect choice. Terminating program.\n");
        return 0;
    }
    printf("\n\n\n");
    
    
    
    switch(userChoice) {
        case'a': 
        {
            int rotation = 0;
            unsigned char string[200];
            printf("Type a message. If you wish to put spaces in between words, use a '-' symbol instead of a space.\n");
            scanf("%s", string);
            putInSpaces(string);
            printf("%s\n", string);
            printf("Choose a rotation key.\n");
            scanf("%d", &rotation);
            encryptRotation(string, rotation);
            printf("Your encrypted message: %s\n", string);
            break;
        }
        
        
        
        
        
        
        
        
        
        
        
        case 'b': 
        {
            int rotation = 0;
            unsigned char string[200];
            printf("Type a rotation cipher. If you wish to use spaces in between words, use a '-' symbol instead.\n");
            scanf("%s", string);
            putInSpaces(string);
            printf("Enter the rotation number that you used to make the cipher.");
            scanf("%d", &rotation);
            decryptRotation(string, rotation);
            printf("I assume your message was: %s\n", string);
            break;
        }
        
        
        
        
        
        
        
        
        case 'c':
        {
            int rotation = 1;
            unsigned char string[200];
            printf("Type a message. If you wish to put spaces in between words, use a '-' symbol instead of a space.\n");
            scanf("%s", string);
            putInSpaces(string);
            printf("%s\n", string);
            printf("Choose a rotation key.\n");
            scanf("%d", &rotation);
            encryptRotation(string, rotation);
            printf("Your encrypted message: %s\n", string);
            int repetition = 1;
            int wordFound = 0;
            int i = 0;
            char letter1 = 0;
            char letter2 = 0;
            char letter3 = 0;
            char letter4 = 0;
            while(repetition < 26 && wordFound != 1)
            {
                
                rotateByOne(string);
                while(string[i] != '\0')
                {
                    letter1 = string[i];
                    i++;
                    if(spellCheck3(letter1, letter2, letter3) == 1)
                    {
                        wordFound = 1; break;
                    }
                    letter2 = string[i];
                    i++;
                    if(spellCheck3(letter1, letter2, letter3) == 1)
                    {
                        wordFound = 1; break;
                    }
                    letter3 = string[i];
                    i++; 
                    if(spellCheck3(letter1, letter2, letter3) == 1)
                    {
                        wordFound = 1; break;
                    }
                }
                i = 0;
                while(string[i] != '\0')
                {
                    letter1 = string[i];
                    i++;
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1; break;
                    }
                    letter2 = string[i];
                    i++;
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1; break;
                    }
                    letter3 = string[i];
                    i++; 
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1; break;
                    }
                    letter4 = string[i];
                    i++;
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1; break;
                    }
                }
                i = 0;
                repetition++;
            }
            if(wordFound == 1)
            {
                printf("I assume your message was: %s\n", string);
            }
            if(wordFound != 1)
            {
                printf("Decryption failed.\n");
            }

            break;

            
        
        
        }
        
        
        
        
        
        
        case 'd':
        {
            unsigned char string[200];
            printf("Type a message that you wish to be encrypted.\n");
            printf("If you wish to put spaces in between words, use a '-' symbol instead of a space.\n");
            scanf("%s", string);
            putInSpaces(string);
            printf("%s\n", string);
            printf("You will now be prompted with the letters of the alphabet.\n");
            printf("Each time a letter appears, type the letter you wish the prompt-letter to be replaced with during the encryption.\n");
            printf("Remember: to create a proper substitution alphabet, you must only enter each letter of the alphabet once.\n");
            printf("Also, please use lower case when entering your substitutions.\n\n");
            char substitutions[26] = {'0'};
            int interfaceLetter = 'A';
            int i = 0;
            while(i < 26)
            {
                printf("Letters you have typed:%s", substitutions);
                printf("\nSubstitution for %c:  ", interfaceLetter);
                scanf(" %c", &substitutions[i]);
                interfaceLetter++;
                i++;
            }
            i = 0;
            int letter = 'a';
            unsigned char indexMemory[200];
            while(i < 26)
            {
                substitute(string, letter, substitutions[i], indexMemory);
                letter++;
                i++;
            }
            
            printf("%s\n", string);
            break;
            
        }  
        
        
        
        
        
        
        
        
        
        
        
        case 'e':
        {
            unsigned char indexMemory[200];
            unsigned char string[200];
            int letter = 'a';
            int interfaceLetter = 'A';
            char substitutions[26];
            int i = 0;
            printf("Type a substitution cipher. If you wish to put spaces in between words, use the '-' symbol instead.\n");
            scanf("%s", string);
            printf("You will now be prompted with the letters of the alphabet.\n");
            printf("At each prompt, please enter the letter you used in your cipher alphabet to substitute the prompt-letter.\n");
            while(i < 26)
            {
                printf("Substitution for %c:  ", interfaceLetter);
                scanf(" %c", &substitutions[i]);
                interfaceLetter++;
                i++;
            }
            i = 0;
            while(i < 26)
            {
                substitute(string, substitutions[i], letter, indexMemory);
                letter++;
                i++;
            }
            printf("I assume your message was: %s", string);
            break;
        }
        
        
        
        
        
        
        default: {break;}
    
    }
    
    
    
    
    
    return 0;
}



// FUNCTION DEFINITIONS
void rotateByOne(unsigned char *someString)
{
    int i = 0;
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
}


void encryptRotation(unsigned char *someString, int someInteger) 
{
    int i = 0;
    while(someString[i] != '\0') 
    {
        if(someString[i] == ' ' || someString[i] == '.') 
        {
            i++;
        }
        else if(someString[i] <= 90 && someString[i] >= 65 && someString[i] + someInteger > 90)
        {
            someString[i] = someString[i] + someInteger - 26;
            i++;
        }
        else if(someString[i] <= 122 && someString[i] >= 97 && someString[i] + someInteger > 122)
        {
            someString[i] = someString[i] + someInteger - 26;
            i++;
        }
        else
        {
            someString[i] = someString[i] + someInteger;
            i++;
        }
    }
   
}




void decryptRotation(unsigned char *someString, int someInteger)
{
    int i = 0;
    while(someString[i] != '\0') 
    {
        if(someString[i] == '.' || someString[i] == ' ')
        {
            i++;
        }
        else if(someString[i] <= 122 && someString[i] >= 97 && someString[i] - someInteger < 97)
        {
            someString[i] = someString[i] - someInteger + 26;
            i++;
        }
        else if(someString[i] <= 90 && someString[i] >= 65 && someString[i] - someInteger < 65)
        {
            someString[i] = someString[i] - someInteger + 26;
            i++;
        }
        else
        {
          someString[i] = someString[i] - someInteger;
          i++;
        }
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


void substitute(unsigned char *someString, char originalLiteral, char literalSubstitute, unsigned char *memoryString)
{
    char originalUpperCase = 0;
    char substituteUpperCase = 0;
    originalUpperCase = originalLiteral - 32;
    substituteUpperCase = literalSubstitute - 32;
    int i = 0;
    while(someString[i] != '\0')
            {
                if(someString[i] == originalLiteral && memoryString[i] != '-')
                {
                    someString[i] = literalSubstitute;
                    memoryString[i] = '-';
                }
                if(someString[i] == originalUpperCase && memoryString[i] != '-')
                {
                    someString[i] = substituteUpperCase;
                    memoryString[i] = '-';
                }
                i++;
            }
}




char spellCheck3(char letter1, char letter2, char letter3)
{
    if(letter1 == ' ' && letter2 == 'a' && letter3 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'a' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter1 == 'a' && letter2 == ' ')
    {
        return 1;
    }
            
            
            
    if(letter1 == 't' && letter2 == 'h' && letter3 == 'e')
    {
        return 1;
    }
    if(letter2 == 't' && letter3 == 'h' && letter1 == 'e')
    {
        return 1;
    }
    if(letter3 == 't' && letter1 == 'h' && letter2 == 'e')
    {
        return 1;
    } 
            
    return 0;
}



char spellCheck4(char letter1, char letter2, char letter3, char letter4)
{
    if(letter1 == ' ' && letter2 == 'i' && letter3 == 't' && letter4 == ' ')
    {
       return 1;
    }
    if(letter2 == ' ' && letter3 == 'i' && letter4 == 't' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'i' && letter1 == 't' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'i' && letter2 == 't' && letter3 == ' ')
    {
        return 1;
    }
            
            
            
    if(letter1 == ' ' && letter2 == 'i' && letter3 == 'n' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'i' && letter4 == 'n' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'i' && letter1 == 'n' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'i' && letter2 == 'n' && letter3 == ' ')
    {
        return 1;
    }
            
            
            
    if(letter1 == ' ' && letter2 == 'i' && letter3 == 's' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'i' && letter4 == 's' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'i' && letter1 == 's' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'i' && letter2 == 's' && letter3 == ' ')
    {
        return 1;
    }
            
            
            
    if(letter1 == ' ' && letter2 == 't' && letter3 == 'o' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 't' && letter4 == 'o' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 't' && letter1 == 'o' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 't' && letter2 == 'o' && letter3 == ' ')
    {
        return 1;
    }
            
            
            
    if(letter1 == ' ' && letter2 == 'b' && letter3 == 'e' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'b' && letter4 == 'e' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'b' && letter1 == 'e' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'b' && letter2 == 'e' && letter3 == ' ')
    {
        return 1;
    }
            
            
            
    if(letter1 == ' ' && letter2 == 'o' && letter3 == 'f' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'o' && letter4 == 'f' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'o' && letter1 == 'f' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'o' && letter2 == 'f' && letter3 == ' ')
    {
        return 1;
    } 
    
    return 0;
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







