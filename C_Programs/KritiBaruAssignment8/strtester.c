#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"

int main(void) {

    //TEST CASES

    printf("\n1. all_letters\nresult: %d", all_letters("hello world"));
    printf("\n2. num_in_range\nresult: %d", num_in_range("Yellow", 'f', 'm'));
    printf("\n3. diff\nresult: %d", diff("Book","Back"));
    
    char str1[] = "Hello World";
    shorten(str1, 5);
    printf("\n4. shorten\nresult: '%s'\n", str1); 
    
    printf("\n5. len_diff\nresult: %d", len_diff("Philadelphia","Hello"));
    
    char leftSp[] = "     Hello";
    rm_left_space(leftSp);
    printf("\n6. rm_left_space\nresult: '%s'\n", leftSp);
    
    char rtSp[] = "Hello    ";
    rm_right_space(rtSp);
    
    printf("\n7. rm_right_space\nresult: '%s'\n", rtSp);
    char rmSp[] = "   Hello   ";
    rm_space(rmSp);
    
    printf("\n8. rm_space\nresult: '%s'\n", rmSp);
    printf("\n9. find\nresult: %d", find("Hello ", "l"));
    printf("\n10. *ptr_to\nresult: %s", ptr_to("Hello ", "q")); // RETURN VAL?? 
    printf("\n11. is_empty\nresult: %d", is_empty(" "));
    printf("\n12. str_zip\nresult: %c", str_zip("Temple","Hello"));
    
    char cap[] = "hello world";
    capitalize(cap);
    printf("\n13. capitalize\nresult: %s", cap);
    
    printf("\n14. strcmp_ign_case\nresult: %d", strcmp_ign_case("hello","goodbye"));
    
    char tklst[] = "hello";
    take_last(tklst,3);
    printf("\n15. take_last\nresult: %s", tklst); 
    
    printf("\n16. dedup\nresult: %d", dedup("hello"));
    printf("\n17. pad\nresult: %d", pad("hello", 6));
    printf("\n18. ends_with_ignore_case\nresult: %d", ends_with_ignore_case("Coding","ing"));
    // printf("\n19. *repeat\nresult: %s", repeat("hello",3,'-'));
    // printf("\n20. *replace\nresult: %s", replace("Steph is the X","X","best"));
    // // printf("\n21. *str_connect\nresult: %s", str_connect("Hello world Hello World",4,'-'));
    
    // char words[] = {"Hello","World","","","Steph"};
    // rm_empties(words);
    // printf("\n22. *rm_empties\nresult:");
    // for (int i = 0; words[i] != NULL; i++){
    //     printf("%c ", words[i]);
    // }
   
    // printf("\n23. **str_chop_all\nresult: %c", str_chop_all("Hello/world/hello/world",'/'));

    return 0;
}
