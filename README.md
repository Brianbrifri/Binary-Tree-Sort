# Binary-Tree-Sort
School project that sorts a text file using binary sort.
Background: In cryptography, one way to attempt to break a code is to calculate the amount of
each single letter, the amount of combinations of letter pairs, the amount of 3-letter combinations
and so on.
For example, in the string “aadabcdaa”, this has
a: 5
b: 1
c: 1
d: 2
aa: 2
ad: 1
da: 2
ab: 1
bc: 1
cd: 1
aad : 1
and so forth.
Your program will open a file that count the occurrences up to consecutive letters ‘k’, so if the
user enters k=4, you would store the number of all consecutive letter sequences up to 4.

Description: Use a binary search tree that stores at each node both a string and a count of how
many of that node it has found. Then, go through the file given (text file) and starting with the
first letter, push it onto the tree with a count of 1. Then get the next character in the file, push it
onto the tree, and so forth. If you ever try to add a node that has already been added (for
example, pushing an ‘a’ onto the tree that already has an ‘a’, increment the count at that node.

Once that is done, go through the file again and get all consecutive 2-letter occurrences
and push them onto the tree. Again, if there is a match, increment the count.

Repeat this entire process until you reach a ‘k’ long sequence.

Note: You can of course combine all these steps also if you want. 
Output: Once your program is done, do an in order traversal of the tree, outputting the data in
the following format:
a: 27
aa: 6
aaa: 3
etc.
indicating that the letter a was found 27 times, the sequence ‘aa’ was found 6 times and so on.
Additional complication: Since it is common in code to either use misleading spaces or leave
spaces out altogether, your code should ignore any spaces in the message. Simply deal with
alphabetical characters and their sequence. So for example, the sequence ‘a a’ would still count
as consecutive ‘aa’. The file that you take in will contain only alphabetical characters and spaces.
It might or might not have endline characters, but you should ignore them in either case as you
do for spaces.
I suggest you start this assignment by having it store the statistics for single-letter occurrences
and then try it for multi-letter sequences. That way you know the tree operations and traversals
are working fine before you mess around with parsing the string.
