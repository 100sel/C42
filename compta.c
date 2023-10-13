#include <stdio.h>

int     main()
{
    int     PRICE     = 15;
    int     CVPU      = 1;
    int     FOUNDING  = 2000;
    int     INIT      = 1000;
    int     MARKPERK  = 10;
    float   CPC       = 0.5;
    float   CONV      = 5;
    int     capital;
    int     marketing;
    int     exploit;
    int     userbase;
    int     newUsers;
    int     growth;
    int     in;
    int     out;
    int     net;
    int     i;

    capital     = FOUNDING - INIT;
    userbase    = 0;
    i           = 0;

    while (i++ < 24)
    {
        if ( (userbase * PRICE) < (marketing + exploit) || (capital / MARKPERK < 100) || net < 100)
            marketing = 100;
        else if (net >= 10000)
            marketing = capital / MARKPERK;
        else 
            marketing = net;
        exploit     = 100 + (userbase * CVPU);
        newUsers    = marketing / CPC;
        growth      = (int) ((float)newUsers * (CONV / 100));
        userbase   += growth;
        in          = userbase * PRICE;
        out         = marketing + exploit;
        if (net >= 10000)
            out    += 8000;
        net         = in - out;
        capital    -= out;
        capital    += in;
        printf("Month: %d | Marketing: %d | Growth: %d | Userbase: %d | In: %d | Out: %d | Net: %d | Capital: %d \n", i, marketing, growth, userbase, in, out, net, capital);
    }

    return 0;
}

