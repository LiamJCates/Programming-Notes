Each browser has it's own method of accessing the console, which can be found via a quick web search.
https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Introduction#opening_the_console


The console works the exact same way as eval: the last expression entered is returned. For the sake of simplicity, it can be imagined that every time something is entered into the console, it is actually surrounded by console.log around eval, like so:
js

console.log(eval("3 + 5"));

Multi-line input in the console


By default, if you press Enter (or Return, depending on your keyboard) after entering a line of code, then the string you typed is executed. To enter multi-line input:

    If the string you typed was incomplete (for example, you typed function foo() {) then the console will treat Enter as a line break, and let you type another line.
    If you hold down Shift while pressing Enter, then the console will treat this as a line break, and let you type another line.
    In Firefox only, you can activate multi-line input mode, in which you can enter multiple lines in a mini-editor, then run the whole thing when you are ready.