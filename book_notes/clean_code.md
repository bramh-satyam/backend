# Clean Code

## Chapter 2: Meaningful Names

### Use Intention-Revealing Names

- Name your variable, function and class such that it should answer all the big questions like it should tell you why it exists and what it does and how is it supposed to be used.
    > if a name needs comment, then the name doesn't reveal its intent!

- Well why is clean code required? Sometimes, the code is simple but is really hard to understand, why? because it's not readable.
    > The problem isn’t the simplicity of the code but the implicity of the code

    Even if your code looks simple, its can still be hard to understand if it hides the important assumptions or context. Implicity means things the code assumes you already know, but doesn't clearly say.

    ```cpp
    int result = process(data);
    ```

    Looks simple, but it doesn't answer our question:
    - What does `process` do?
    - What is `data`?
    - What is the `result` supposed to be?

    Better version can be

    ```cpp
    int student_percentage = generate_percentage(student_marksheet); 
    ```

### Avoid 



