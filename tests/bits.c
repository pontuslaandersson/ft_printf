void bit_set(char bit, char *byte)
{
    bit = 1 << bit;
    *byte = *byte | bit;
}

//bit_set(2,&status);

int bit_test(char bit, char byte)
{
    bit = 1 << bit;
    return(bit & byte);
}

void bit_reset(char bit, char *byte)
{
    bit = 1 << bit;
    bit ^= 0xff;
    *byte = *byte & bit;
}