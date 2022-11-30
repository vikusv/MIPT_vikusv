void fill_sieve(struct sieve_t *sv)
{
    unsigned long long n = 0, m = 0;
    sv->sieve[0] = 1;
    sv->sieve[1] = 1;
    for (n = 2; n < sv->size; n++)
    {
        if (sv->sieve[n] == 0)
        {
            for (m = n*n; m < sv->size; m += n)
                sv->sieve[m] = 1;
        }
    }
}

int nth_prime(struct sieve_t *sv, int N)
{
    unsigned long long count = 0, i = 0;
    for (count = 0, i = 0; count < N;)
    {
        if (sv->sieve[i] == 0)
            count++;
        i++;
    }

    return i - 1;
}
