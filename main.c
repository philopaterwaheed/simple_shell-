#include "main.h"

int main(void)
{
    while (1)
    {
        char *line = "exit";
        char **arguments;
        line = _getline();
        if (line != NULL)
        {
            arguments = token(line);
            parse(arguments);
            exe (arguments);
            free(line);
            free(arguments);
        }   
        else 
            continue;
    }
    return (0);
}
/*
          .sd$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$;             
 [bug]  .d$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$             
      .d$$$$$$$$$$P*"'   `"*T$$$$$$$$$$$$$$$             
     s$$$$$$$$$P*             `*T$$$$$$$$$$$             
    d$$$$$$$$P'                  `*T$$$$$$$P             
   d$$$$$$$P'                       `T$$$$P              
  d$$$$$$P'                           `T$P \
 d$$$$$P'                                   \
.$$$$$'                 .*"*                 .
:$$$$;                  .*"*-.                           
$$$$$'                 /                      `          
$$$$$.                  .s$$s.    `*.         :          
$$$$$;                 d$$$$$$b      ;     .s$s.         
$$$$$$b.              d$$$$$$$$b     ;    d$$$$$b        
$$$$$$$$$bs._        d$$$$P^^T$$b   /    d$P"""T$b       
$$$$$$$$$$$$$$bs+=- .$$P*'    `TP       dP     .`T       
$$$$$$$$$$$$$$$$P'  :P'    __          /                 
$$$$$$$$$$$$$$$P    $    .'  `.       /`-.    .          
T$$$$$$$$$$$$$$     :   /      \     .    `.             
 T$$$$$$$$$$$$$        :        ;           \.           
  T*'   `*^$$$$        |+*"$P*sss*"  :*"$P*ss*"          
 /         `T$$        |   Tbd$P     :  Tbd$P            
;  ._        T$        |    T$$P     :   T$P      _._    
     `"*+.    T       *"**--._/       \   /`. .-*"   `*. 
     .*'  `.                  `*       `*---*'          ;
    (                              `.                   |
                   .'                \                  ;
\           /     /`*+...___          `-.             .* 
 `-._   _.+'          `*. __"""****------`*-.____.+*"'   
     "*"   \             `. """****------**"/;           
            `.         \   `--..._______...'/            
              `*--..___.`.                 /             
                          `*-...______..-*'
*/
