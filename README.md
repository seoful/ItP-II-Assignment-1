# Text sentence separator and word finder
The program reads the input text, split it into the sentences. Then it counts the number and prints to output sentences 
with the occurrence of the specified words. Moreover, it highlights these words.

_Note:_ The algorithm is searching for the words without looking at their case e.g. `kitten = Kitten = KiTtEn` etc.

## Input and output

**Input file contains:**
* Text in **exactly** one line with sentences ending **only** with dots - `.`
* Number of words to search for - `n`
* `n` lines with single words to search for

**Example:**
```
Lorem Ipsum is simply a dummy text
of the printing and typesetting industry. Lorem Ipsum has been the industry’s standard dummy text ever since
the 1500s, when an unknown printer
took a galley of type and scrambled it
to make a type specimen book. It has
survived not only five centuries, but also
the leap into electronic typesetting, remaining essentially unchanged. It was
popularised in the 1960s with the release
of Letraset sheets containing Lorem Ipsum passages, and more recently with
desktop publishing software like Aldus
PageMaker including versions of Lorem
Ipsum.
2
dummy
release
```
\
**Output file contains**:

For each word given in the input
* The number of sentences where the word was found - `k`
* `k` lines with these sentences where the word is highlighted

**Example:**
```
2
Lorem Ipsum is simply a DUMMY text
of the printingg and typesetting industry.
Lorem Ipsum has been the industry’s
standard DUMMY text ever since the
1500s, when an unknown printer took a
galley of type and scrambled it to make
a type specimen book.
1
It was popularised in the 1960s with the
RELEASE of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software
like Aldus PageMaker including versions
of Lorem Ipsum.
```

## Requirements
The **input** is done from the file `in.txt` which **must** be located in the same directory as the `main.cpp`.\
The **output** is done into the automatically generated `out.txt` file in the directory with `main.cpp`.
