#include <stdio.h>
#include <stdlib.h>

struct programstate_t
{
    unsigned reg[4];
};

enum
{
    A = 0, B = 1, C = 2, D = 3,
    MOVOPC   = 0,
    ADDOPC   = 8,
    SUBOPC   = 9,
    MULOPC   = 10,
    DIVOPC   = 11,
    INOPC    = 0x30,
    OUTOPC   = 0x31,
    INOUTMASK = 0XC0,
    ARITHMASK = 0x80
};

int exec_command(struct programstate_t * pstate, unsigned encoding);
int extract_opcode(unsigned encoding);
unsigned extract_rf(unsigned encoding, unsigned n);

int main(int argc, const char ** argv)
{
    FILE *f;
    unsigned encoding = 0;
    struct programstate_t state;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s program.enc < program.in\n", argv[0]);
        abort();
    }

    f = fopen(argv[1], "r");
    if (!f)
    {
        perror("Error opening file");
        abort();
    }

    while (fscanf(f, "%x", &encoding) == 1)
    {
        int res = 0;
        //printf("next command: %x\n", encoding);
        exec_command(&state, encoding);
        if (res != 0)
        {
            fprintf(stderr, "%s: \n", argv[0]);
            abort();
        }
    }
}

int exec_command(struct programstate_t * pstate, unsigned encoding)
{
    unsigned opc = extract_opcode(encoding);

    switch(opc)
    {
        case MOVOPC:
            pstate->reg[D] = encoding;
            break;
        case ADDOPC:
        {
            int rf0 = extract_rf(encoding, 0);
            int rf1 = extract_rf(encoding, 1);
            pstate->reg[rf1] = (pstate->reg[rf1] + pstate->reg[rf0]) % 256;
            break;
        }
        case SUBOPC:
            {
            int rf0 = extract_rf(encoding, 0);
            int rf1 = extract_rf(encoding, 1);
            pstate->reg[rf1] -= pstate->reg[rf0];
            break;
            }
        case MULOPC:
        {
        int rf0 = extract_rf(encoding, 0);
        int rf1 = extract_rf(encoding, 1);
        pstate->reg[rf1] *= pstate->reg[rf0];
        break;
        }
        case DIVOPC:
        {
        int rf0 = extract_rf(encoding, 0);
        int rf1 = extract_rf(encoding, 1);
        if (pstate->reg[rf0] == 0)
            return 1;
        pstate->reg[rf1] /= pstate->reg[rf0];
        break;
        }
        case INOPC :
        {
        int rf0 = extract_rf(encoding, 0);
        scanf("%d", pstate->reg + rf0);
        break;
        }
        case OUTOPC:
        {
        int rf0 = extract_rf(encoding, 0);
        printf("%d\n", pstate->reg[rf0]);
        break;
        }
        default:
        return 1;
    }

    return 0;
}

int extract_opcode(unsigned encoding)
{
    if ((encoding & INOUTMASK) == INOUTMASK)
        return (encoding >> 2);
    if ((encoding & ARITHMASK) == ARITHMASK)
        return (encoding >> 4);
    return (encoding >> 7);
}

unsigned extract_rf(unsigned encoding, unsigned n)
{
    return (encoding >> (2 * n)) & 0x3;
}
