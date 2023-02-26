# Study

## Questions
- [ ] Why doesn't the `pthreads` library not mesh well with classes? [^1]
- [ ] What is POSIX?
- [ ] How does a `pthread` terminate? [^2]

[^1]: In a recent project for CS4348 (I shudder at the thought), I recall encountering many difficulties with `pthreads` when used with classes. 

[^2]: I recall reading somewhere indicating that subsequent to the execution of the `start_routine`, the thread terminates. I do not know how correct that statement was nor if memory is to be relied upon.

## 1st entry: lightweight process
The execution of [the first file](1st-entry.c) produced the output:

```txt
Leaving main
Return to main
Entered 'threadFunc()'
Exiting 'threadFunc()'
```

This indicates that as the `start_routine`, that was fed to `pthread_create()`, executes, the parent program continues with its own execution, which is similar to what might occur had I used a fork instead. This makes sense as a thread is essentially a lightweight process.