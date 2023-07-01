# debugging c code in emacs

## description
I recently switched over to Doom Emacs, from neovim, out of curiousity for why it is so popular. I wanted a minimal IDE or editor that had just enough necessary features out of the box that would not require me to setup and maintain.

In order to setup Doom Emacs for debugging C code, simply uncomment the portion of code that pertains to C code in `~/.doom.d/init.el` (you may also need to uncomment portions relating to `lsp`). Additionally, be sure to uncomment the portion `debugger`.

Be sure to also install `gdb`.

## usage
Compile the code using the necessary flags, such as

```bash 
gcc -Wall -g bugged.c -o debugging
```

Then run `gdb` from emacs, using the command `M-x gdb`, which refers to `alt + x` followed by `gdb`. A more useful layout may be found in the command `M-x gdb-many-windows`.
