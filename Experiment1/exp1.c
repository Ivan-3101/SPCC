#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct SymbolEntry
{
    char symbol;
    void *address;
    char type[40];
};

void insert(struct SymbolEntry symbolTable[], int *symbolCount, char newSymbol)
{
    for (int i = 0; i < *symbolCount; i++)
    {
        if (symbolTable[i].symbol == newSymbol)
        {
            printf("Duplicate Symbol. Cannot insert.\n");
            return;
        }
    }

    symbolTable[*symbolCount].address = malloc(sizeof(int));
    strcpy(symbolTable[*symbolCount].type, isalpha(newSymbol) ? "identifier" : "operator");
    symbolTable[*symbolCount].symbol = newSymbol;
    (*symbolCount)++;
    printf("Symbol inserted successfully.\n");
}

void display(const struct SymbolEntry symbolTable[], int symbolCount)
{
    printf("\nSymbol Table\nSymbol \t Address \t Type\n");
    for (int i = 0; i < symbolCount; i++)
        printf("%c \t %p \t %s\n", symbolTable[i].symbol, symbolTable[i].address, symbolTable[i].type);
}

void delete(struct SymbolEntry symbolTable[], int *symbolCount, char symbolToDelete)
{
    int foundIndex = -1;
    for (int i = 0; i < *symbolCount; i++)
    {
        if (symbolTable[i].symbol == symbolToDelete)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
    {
        printf("Symbol not found. Cannot delete.\n");
        return;
    }

    free(symbolTable[foundIndex].address);

    for (int i = foundIndex; i < *symbolCount - 1; i++)
        symbolTable[i] = symbolTable[i + 1];

    (*symbolCount)--;
    printf("Symbol deleted successfully.\n");
}

void search(const struct SymbolEntry symbolTable[], int symbolCount, char symbolToSearch)
{
    int foundIndex = -1;
    for (int i = 0; i < symbolCount; i++)
    {
        if (symbolTable[i].symbol == symbolToSearch)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
    {
        printf("Symbol not found. Cannot display.\n");
        return;
    }

    printf("\nSymbol Information\nSymbol: %c\nAddress: %p\nType: %s\n", 
           symbolTable[foundIndex].symbol, symbolTable[foundIndex].address, symbolTable[foundIndex].type);
}

void modify(struct SymbolEntry symbolTable[], int symbolCount, char symbolToModify)
{
    int foundIndex = -1;
    for (int i = 0; i < symbolCount; i++)
    {
        if (symbolTable[i].symbol == symbolToModify)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
    {
        printf("Symbol not found. Cannot modify.\n");
        return;
    }

    printf("Symbol found. Modifying symbol type.\n");
    strcpy(symbolTable[foundIndex].type, "modified");
    printf("Symbol modified. New type: %s\n", symbolTable[foundIndex].type);
}

int main()
{
    struct SymbolEntry symbolTable[50];
    int symbolCount = 0, choice;
    char newSymbol;

    do
    {
        printf("\nSymbol Table Operations\n1. Insert Symbol\n2. Display Symbol Table\n3. Delete Symbol\n4. Search Symbol\n5. Modify Symbol\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter symbol to insert: ");
            scanf(" %c", &newSymbol);
            insert(symbolTable, &symbolCount, newSymbol);
            break;
        case 2:
            display(symbolTable, symbolCount);
            break;
        case 3:
            printf("Enter symbol to delete: ");
            scanf(" %c", &newSymbol);
            delete(symbolTable, &symbolCount, newSymbol);
            break;
        case 4:
            printf("Enter symbol to search: ");
            scanf(" %c", &newSymbol);
            search(symbolTable, symbolCount, newSymbol);
            break;
        case 5:
            printf("Enter symbol to modify: ");
            scanf(" %c", &newSymbol);
            modify(symbolTable, symbolCount, newSymbol);
            break;
        case 6:
            for (int i = 0; i < symbolCount; i++)
                free(symbolTable[i].address);

            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
