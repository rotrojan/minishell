```
                                   __              ___    ___      
           __          __         /\ \            /\_ \  /\_ \     
  ___ ___ /\_\    ___ /\_\    ____\ \ \___      __\//\ \ \//\ \    
/' __` __`\/\ \ /' _ `\/\ \  /',__\\ \  _ `\  /'__`\\ \ \  \ \ \   
/\ \/\ \/\ \ \ \/\ \/\ \ \ \/\__, `\\ \ \ \ \/\  __/ \_\ \_ \_\ \_ 
\ \_\ \_\ \_\ \_\ \_\ \_\ \_\/\____/ \ \_\ \_\ \____\/\____\/\____\
 \/_/\/_/\/_/\/_/\/_/\/_/\/_/\/___/   \/_/\/_/\/____/\/____/\/____/
                                           by lucocozz and rotrojan
```
# minishell
This C project from the 42school is the implementation of a not-at-all Posix compliant shell.
### Features
- execution of simple commands (with absolute or relative path);
- builtins: `cd`, `echo [-n]`, `pwd`, `export`, `unset`,  `env` and `exit`;
- pipelines `|`, output redirections `>` `>>`, input redirection `<` and  heredocument `<<`;
- list of commands with `&&`, `||`, `;` and parentheses `()` for priorities (no redirections, pipes or subshells involved);
- variables expansions within or without quotes, including `$?`;
- quoting with simple or double quotes : `'` and `"`, including variables split;
- `ctrl-L`, `ctrl-D` and `ctrl-C` control keys binded;
- incremental history of commands;
- line edition including `backspace`, `delete`, `home`, `end` and arrow keys;
- custom prompt displaying user, host and working directory in colors;
- wildcards `*` working in current directory.
### Implementation
- input using termcaps;
- lexer using tokenizers;
- recursive-descent parser building an Abstract Syntax Tree.
### Usage
```sh
$ make
$ ./minishell
```
