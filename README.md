```
 ___  _____  ____  _    ___  _____  _____  ___  ____  ___     ___ 
|  _\|_   _||  __|| |  | __||_   _||_   _|| __||  _ ||  _|   |  _|
|  _< _| |_ | |_ || |_ | __|  | |    | |  | __||    ||_  | _ | |_ 
|___/|_____||____||___||___|  |_|    |_|  |___||_|\_\|___||_||___|
```

###### BigLetters by Isaay Bankart (in BETA)

### Description

A simple c Program dependent apon cJSON library to read an input text
and then output the corrosponding Text in Big Letters.

characters used to make the big letters are `["|","\","/","_","\","<"," "]`

### big_letters2.json

A JSON file that stores the big letters as an array of strings

### Compile With:

`gcc cJSON/cJSON.c bigLetters.c -o bigLetters`

#### Dependencies:

cJSON library: [GitHub - DaveGamble/cJSON: Ultralightweight JSON parser in ANSI C](https://github.com/DaveGamble/cJSON)
