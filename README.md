# Data-Structures---Secret-Codes

* Content:
  * **secret codes:** https://acm.cs.nthu.edu.tw/problem/12274/
  * **secret codes quiz:** https://acm.cs.nthu.edu.tw/problem/12313/

# Secret Codes

### Description

The data structures TAs want to pass secret messages to each other.

You will be given a text and a word. You should build a character distribution using the character ​frequencies of the text and do a stable sort on this list. You should then Build a Huffman tree.

Finally, encode the word based on the Huffman tree.

A Huffman tree contains characters as its leaves, and the inner nodes are the sums of the frequencies of the leaves. The edge from a parent to a left child is labeled 0, and the edge from parent to right child is labeled 1. The Huffman code for a letter will be given by the path from root to the leaf node containing that character.

In order to build a Huffman Tree:

1. Take 2 nodes with smallest frequency. Create a node  with the sum of their frequency.

1. If 2 nodes have the same frequency, choose the first inputted.

1. If an internal node and a character node have the same frequency, choose the character node.

1. Add the nodes as the children of the new node(smallest frequency as the left child).

1. Add internal node to list of internal nodes & sort.

1. Remove children from character distribution.

1. Repeat until you only have 1 node in the  character distribution (the root).

![](https://github.com/pablomp3/Data-Structures---Secret-Codes/blob/master/secret_codes_1.png)

### Input

* The first line of input contains a single positive integer n (**number of lines of the text**) and a **word**, separated by a comma, followed by newline.

* The next n lines contains zero or more characters(with whitespace), they all end in newlines. This will be the **text**.

### Output

A line of integer, without space.

### Sample Input  

    3,hello
    have a nice day
    love is in the air
    have some oranges

### Sample Output
    011111101011010111100
    
###-------------------------------------------------------------------------------------------------------------------------------------
###-------------------------------------------------------------------------------------------------------------------------------------
###-------------------------------------------------------------------------------------------------------------------------------------

# Secret Codes Quiz

### Description
You will be given a **tex**t and a **word**. You should:

1. Calculate the **character distribution in the text** and sort it using **stable ascending sort** (from low to high).
1. **Reorder the word** using the character distribution order.

![](https://github.com/pablomp3/Data-Structures---Secret-Codes/blob/master/secret_codes_quiz_1.png)

![](https://github.com/pablomp3/Data-Structures---Secret-Codes/blob/master/secret_codes_quiz_2.png)

### Input

* The first line of input contains a single positive integer n (**number of lines of the text**) and a **word**, separated by a comma, followed by newline.
* The next n lines contains zero or more characters(with whitespace), they all end in newlines. This will be the **text**.

### Output

The reordered word using the character distribution order, followed by a new line

### Sample Input  

    3,hello
    have a nice day
    love is in the air
    have some oranges

### Sample Output
    llhoe
