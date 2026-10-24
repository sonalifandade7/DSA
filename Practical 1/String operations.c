#include <stdio.h>

int palindrome(char input[])
{
    int i = 0, j = 0;

    while (input[j] != '\0')
    {
        j++;
    }
    j--;

    while (i < j)
    {
        if (input[i] != input[j])
        {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

void copy(char input[], char output[])
{
    int i;

    for (i = 0; input[i] != '\0'; i++)
    {
        output[i] = input[i];
    }
    output[i] = '\0';
}

int stringlength(char input[])
{
    int i = 0;

    while (input[i] != '\0')
    {
        i++;
    }

    return i;
}

void substring(char input[])
{
    int n, i = 0, p;
    char output[10];

    printf("Enter Substring Position (0-based): ");
    scanf("%d", &p);

    n = stringlength(input);

    if (p >= 0 && p < n)
    {
        for (i = 0; p + i < n && i < 9; i++)
        {
            output[i] = input[p + i];
        }

        output[i] = '\0';

        printf("The Substring is: %s\n", output);
    }
    else
    {
        printf("Invalid Position\n");
    }
}

void reverse(char input[], char output[])
{
    int i, n = stringlength(input);

    for (i = 0; i < n; i++)
    {
        output[i] = input[n - 1 - i];
    }

    output[n] = '\0';

    printf("Reversed: %s\n", output);
}

int main()
{
    char str[10], output[10];
    int ch, c, len;

    printf("Enter The String: ");
    scanf("%9s", str);

    printf("\n1. Palindrome");
    printf("\n2. Copy");
    printf("\n3. Substring");
    printf("\n4. String Length");
    printf("\n5. Reverse");

    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1:
            c = palindrome(str);

            if (c == 1)
            {
                printf("The string is palindrome\n");
            }
            else
            {
                printf("The string is not a palindrome\n");
            }
            break;

        case 2:
            copy(str, output);
            printf("Copied String = %s\n", output);
            break;

        case 3:
            substring(str);
            break;

        case 4:
            len = stringlength(str);
            printf("Length = %d\n", len);
            break;

        case 5:
            reverse(str, output);
            break;

        default:
            printf("Invalid Choice\n");
    }

    return 0;
}
