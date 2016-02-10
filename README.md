# COMP110 Worksheet 4

###Pseudocode for section A3
A guaranteed minimum number of 'like' words to appear in the list can be set.
A word is defined as being 'like' if more than half of the letters in the word match the secret word.

```
Set the guaranteed_number of like words
Set the desired number of words
Initialise the number of like_words to zero
Randomly choose the secret word
Add the secret word to the list of words

WHILE length of list of words is less than desired number of words
  Randomly choose a new_word to add to the list
  IF like_words < guaranteed_number of like words
    Get the likeness of new_word to the secret word
    IF likeness > word_length / 2
      Add the new_word to the list
      Increment number of like_words by 1
    ENDIF
  ELSE
    Add the new_word to the list
  ENDIF
ENDWHILE
```

###Fractal for section B3
The other fractal I have generated is a Julia set for f(z) = z^2 + 0.279, as described [here](https://en.wikipedia.org/wiki/Julia_set).
It's the first one in the "Examples of Julia Sets" section.
