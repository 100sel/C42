#include "lexer.h"

int main(void)
{
    const char *content = "./test.sh | echo > grep \"test123\"; nmap --false 'foo' /cd/bar < fa >> boo";
    s_lexer lexer = lexer_new(content, strlen(content));
    s_token token;
    token = lexer_next(&lexer);
    while (token.type != TOKEN_EOF) {
        printf("%.*s (%s) \n", (int) token.text_len, token.text, token_get_type(token.type));
        token = lexer_next(&lexer);
    }
}
