#include <stdio.h>

int hash(int note_id);

void iniatialize_array(int array[]);
void print_array(int array[]);
int get_note(int value);

const int BANKNOTES[7] = {100, 50, 20, 10, 5, 2, 1};

int main()
{

    int notes[7];
    iniatialize_array(notes);

    int value;
    scanf("%d", &value);

    printf("%d\n", value);

    do
    {
        int banknote;
        int quotient;

        banknote = get_note(value);
        quotient = value / banknote;

        notes[hash(banknote)] = quotient;

        value = value % banknote;

    } while (value > 0);

    print_array(notes);

    return 0;
}

void iniatialize_array(int array[])
{
    for (int i = 0; i < 7; i++)
    {
        array[i] = 0;
    }
}

void print_array(int array[])
{

    for (int i = 0; i < 7; i++)
    {
        printf("%d nota(s) de R$ %d,00\n", array[i], BANKNOTES[i]);
    }
}

int get_note(int value)
{
    for (int i = 0; i < 7; i++)
    {
        if (value >= BANKNOTES[i])
        {
            return BANKNOTES[i];
        }
    }
    return -1;
}

int hash(int note_value)
{
    switch (note_value)
    {
    case 100:
        return 0;
    case 50:
        return 1;
    case 20:
        return 2;
    case 10:
        return 3;
    case 5:
        return 4;
    case 2:
        return 5;
    case 1:
        return 6;
    default:
        return -1;
    }
}