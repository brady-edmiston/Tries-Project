# Trie Project

This project implements a Trie data structure. The full proposal for this project will be included at the end of this readme, but, in short, a trie is a tree-like data structure that allows for efficient searching for words or strings. The value of a node in a trie is determined by the links traversed to arrive to it rather than some value stored within it, as is typically the case in the data structures studied in this course.

As implemented, the class has four main public methods and one public method only included for testing purposes. The methods insert, remove, contains, and get_size are intended to store and retreive data from the trie (get_root is the testing method). 

The backing structure of the trie is primarly in the node structure. The node itself is very simple, consisting of a boolean value to flag if the node is the end of a word or not and a map containing the children nodes of that node. The map is an excellent chocie for this application as the links in trie typically represent some char value and these char values can be used as the key for the corresponding node that is stored. Additionally, assuming the storage in the map is well-optimized (and, as I am using the standard library map, I hope it is!), the time complexity for retreiving children nodes can be as fast as O(1). A vector solution would likely be O(n) or even O(n^2) if we first needed to retreive the position of the node from the link's char value. The nodes are created in the heap and, during the remove method, are deleted, freeing up their memory.

The contains and insert method are very simple, traversing each char of the string provided and following the chain of children maps until the correct positions are determined. The remove method is a little more involved, using a recursive method. In some cases, to delete a word, several nodes must be removed from the trie, and this implementation is a good choice as the call stack itself keeps track of that as the code executes. 

A series of tests to validate each of these methods were implemented based on a known starting trie structure. These tests were implemented using the same testing suite as our homework assignments, along with the cmake files used to compile. As is the case in the homework, building and running ./run_tests will execute the test program. The app file does not have any functionality. 

Overall this project was very enjoyable; it allowed me to combine a lot of knowledge obtained during this class. My favorite anecdote is that I did not start with the map backing in mind. I originally had the idea of using links and nodes similar to the Linked List homework. The node had a vector keeping track of all the links leading out of it to its children. Once I needed to access these links to find the next char in my string, I realized I needed a hash structure so I could easily key off the char value itself. Once I implemented that, I realized the link structure was obsolete. Unfortunately, I had to rewrite all of my unit tests then, but it made the code very consise and much easier to write. I was unable to get the radix tree functionality to work; the real trouble was in re-expanding a collapsed node when inserting something.

# Proposal - See Moodle Submission for Figure

Tries are a data structure composed of nodes and connections in a hierarchy that are used to store keys. They are very similar to many tree data structures, such as the binary search tree (BST). The primary difference between a trie and a BST is that, in a BST, each node stores the relevant data, but in a trie the node’s position determines the value. Tries can be used to store a dictionary set of words, such as in the figure below, or numbers. They are implemented in many search algorithms, such as predictive text, spell checking, or internet protocol (IP) routing. The invariants for a trie are as follows: 

1) Links between nodes represent characters in the key.
2) All children of a node have a common prefix of the characters associated with that parent node.
3) The root node is an empty string.

Operations on tries are similar to those of a BST: insertion, deletion, and lookup of a key. Each of these operations have a linear time and space complexity, O(n). A memory-intensive implementation of a trie could be an English dictionary where each node has a link to all 26 letters in the alphabet. To store the word “trie,” you would need 456976 nodes. “Complexity” would take 141167095653376 nodes! The complexity of this trie could be reduced drastically by only adding new links as they are needed during insertion. There aren’t many words that have the string “aaaaaaab” in them, so you would not need that branching of links. A much simpler implementation is the bitwise trie, where each node has two links, 0 and 1. This trie is used to make up fixed-length binary data, such as the aforementioned IP address used in routing. 

This project will allow users to store any key composed of ASCII characters in a radix trie, which is a space-optimized trie where every node that is an only child is merged into the parent node. The public methods will be as described above: insertion, deletion, and search. I chose this data structure because I am interested in learning more about networking, and tries are a common backing of router table sused to determine the optimal 
path to send packets across a network.