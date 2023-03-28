# Study

## Questions
- [ ] How does racket differ from what you are familiar with?

## 1st rntry
On line 6, in [intro-to-lang](intro-to-lang.rkt), the example uses a keyword called `substring`. I am not too sure as to what it does; I figure relates to string manipulation in someway.

After, running some test parameters through the function

```racket
(piece "key lime")
(piece "key")
(piece "key lime pie")
(piece "keylimepie")
```

I conclude that the `substring` macro **subtracts** the characters not within the bounds specified. The specification for `substring` likely follows some format like

```racket
substring *string* [begin bound (inclusive)] [end bound (exclusive)]
```
