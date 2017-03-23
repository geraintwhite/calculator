# calculator
Infix command line calculator


```
Usage: ./calculator expression in infix
e.g    ./calculator '10 + 3 * 5 / ( 16 - 4 )'
```


* Infix expression input
* Floating point arithmetic support
* Requires spaces between tokens to parse correctly
* Works by converting infix to postfix, then evaluating the reverse polish notation
* Supports `+ - * / ( )`
