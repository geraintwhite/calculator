# calculator
Infix command line calculator


```
Usage: ./calculator expression in infix
e.g    ./calculator '10 + 3 * 5 / ( 16 - 4 )'
```


* Infix expression input
* Integer arithmetic only currently ([todo](https://github.com/grit96/calculator/issues/3))
* Requires spaces between tokens to parse correctly
* Works by converting infix to postfix, then evaluating the reverse polish notation
* Supports `+ - * / ( )`
