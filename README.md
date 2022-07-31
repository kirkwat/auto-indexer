# Auto Indexer - CS 2341 Project 2

Developed and maintained by Kirk Watson.

Email: klwatson@smu.edu

Class: Data Structures CS 2341 - Fall 2020

Southern Methodist University


## Functionality

This program generates a keyword index by parsing bracketed keywords and numbered pages in a text file.
The index lists the keywords alphabetically (with subcategories if needed) as well as the page number they appeared in.
This program utilizes the following self-implemented data structures: String, Vector, and Linked List.


## How to Use

To use this program, compile and build with CMAKE. There are 2 command-line arguments.
To run CATCH tests on the self-implemented Linked List and Vector class, simply run the program with no command-line arguments.

### Path to Input File

* Contains a list of keywords and phrases separated into groups based on the page each word or phrase appears on.
* Formatting
  * Phrases are enclosed in square brackets.
  * Categories are enclosed in parentheses.
  * 3 correctly formatted input files are located in the `input` directory.

### Output File Path

* Empty .txt file that will hold the generated index.

Here is an example of the command-line arguments:

`../input/input01.txt ../output/output.txt`