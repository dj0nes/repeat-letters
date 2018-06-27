# repeat-letters
C code for an interview in 2015. I still think this is pretty readable as far as C goes!

## Running the code
```bash
make all
echo 'such test very pass' > test.txt
./maxletters ./test.txt. # returns test
```

## The prompt

In some English words, there is a letter that appears more than once. Search through a sample
of text to find the word with a letter that is repeated more times than any other letter is
repeated in any other word. When there is a tie between two words, choose the word that
appeared first in the sample.

The text sample will contain only alphabetic characters (“a” through “z” and “A” through “Z”),
whitespace, and punctuation marks. The words will be separated by whitespace. A letter is
considered to be the same letter regardless of whether it appears in uppercase or lowercase.
Any punctuation marks should be ignored—so, in particular, contractions, possessives, and
hyphenated words count as a single word.

Each sample is stored in a text file: Write a function that accepts a file path as its argument,
and returns the chosen word as its output.

## Alas...
I did not get the job, perhaps because I used more than [135 bytes](https://codegolf.stackexchange.com/a/53471)?
