[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Itali Pizarro Valentin`  
### **Student ID:** `826432484`  

---

## **1. Project Overview**
This project, an RPG game, introduces the player to the beginning of a story where the player can choose their character's destiny.
When the game begins, the player is shown the first line of their story, and they are given two options. And the player is asked to decide 
which option they want to follow. The player just needs to enter 1 or 2 to let the game know their choice. This happens again and again until the player enters -1, or 
they reach a leaf node. The decisions for this game are organized as a **binary decision tree**, each child node(option) is placed after their parent(another option).
The organization was done by saving every node in a map, their key being the event number of each node. To know which child was which parents, the node's event number 
was compared with every node previously added leftEventNumber and rightEventNumber. When the player enters 1 or 2 the program goes to the node 
that contains that story event, and then it returns the data under the description variable. Each choice, gives other two choices, there 
is no choice/event that asks the user to pick from more than two options. The storyline was loaded from an external file('story.txt'), which was 
read, put into nodes, and then added to decision tree.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `The function of the main.cpp file is to call other functions and start the game. The main file provides the delimiter, which helps gather data from the text file in a easier and more efficient way. The two functions that are called in the main.cpp file, is the function that loads the text file and organizes the different parts of the text into choices, and the function that interacts with the player.`  
- **`GameDecisionTree.h`** → `The GameDecisionTree.h file puts everything together. It uses the Story.h and Node.h to create nodes that contain the Story objects, which then contain details of the different choices, such as description, their event number, left event number, and right event number. For this while loops are used to be .able to read the complete file.`  
- **`Node.h`** → `This file contains the T data varible (Story object), the left pointer, and right pointer. It also contains a constructor used to call Node class (to make a node).`  
- **`Story.h`** → `This constiant different variables that are going to be used to store that Story object data. This also contains a default constructor, and parameterized constructor, which will be used to create objects/values that are going to be stored in Nodes.`  
- **`story.txt`** → `This game reads the file line by line. When it reads a line from the file, it then breaks that line into pieces. Where each piece stars and ends is decided by the delimiter in the text. The line is divided in 4 parts, three integers and 1 string. Each part is stored into local integers and string and then given to the Story object.` 

---

## **3. Decision Tree Construction**
The decision tree is build from the `story.txt` file. We start with reading the line in each file, using the information obtained from the text file, then giving the information to Story object to stored it. The Story object then is stored in a Node, which is then added to the tree based on its event number, and their parents left or right event number. 


- How are `Story` objects created from the text file? `Story` objects are created from the text file by taking the information obtained in the text file (int eventNumber, string description, int leftEventNumber, int rightEventNumber) and then assigning it to a Story object, e.g. Story story = new Story(string descr, int eventNum, int leftNum, int rightNum).
- How are nodes linked based on left and right event numbers?  Nodes are linked by comparing the parents left and right event numbers to the current node being added, if the node and one of the parent even numbers coincide, then the node is added to the right or left of the parent node.
- What happens if an event has `-1` as left or right children?  If an event has a left or right child, then the program is supposed to output a line saying that the story ended, and that the story is being updated.

---

## **4. Game Traversal**
The game moves through the decision tree based on the players input, after they are asked to choose between two options that are shown to them.

- How does user input determine the path taken?  The user determines the path taken by entering 1 or 2. If the player enters 1 then we go to the left node, and if the player enters 2 then to the right node of the current node. The current node starts at the root, but it changes through the game depending on the decisions the player takes.
- What happens when the player reaches a leaf node?  When the player reaches the leaf node, then an end game string is displayed.
- The special case where multiple events lead to the same outcome, is reached by pointing the left and right nodes of the parent node to the nodes that are already in the tree. 

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter? The file is read line by line. Each line contains three delimiters. First the even number is read, and since there is a delimiter after, the program stops, stores the event number into a tempString and that string then is changed into an integer, which is then stored into a variable eventNum. The program continues to read the next part of the line and stored the description into the description variable, the leftEventNumber and the rightEventNumber are read and stored in the same manner as the eventNumber.
- How do you ensure nodes are properly linked?  To ensure that nodes are linked properly, I used traversal function in GameDecisionTree and also selected different options when testing the game to make sure the options were linked correctly.
- Any challenges faced while handling file input?  Yes, a challenge I had was not knowing how to store the line by pieces. The delimiter was there, but I did not know how to store something in the middle of reading the line. At the end I was able to solve it, by storing the different parts into their respective variables. Another challenge that I had was changing the string to an integer, I did not know how to change a string into an integer, I first used stoi which is supposed to be a function that hadled this problem, but it did not work even when I added the string library, therefore I wrote a function to handle changing string to integer.

---

## **6. Debugging Process (Errors & Fixes)**
Initially, my program continued to crash because nodes were not linked correctly. I tried to link all nodes to their left side and then changing their position, but that came challenging, so I change my approach. I tried inserting each node, one by one without knowing the nodes parent but that also was pretty challenging. At the end I inserted every node into an unordered map and used their even number as the key.

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

---

## **7. Sample Output & Walkthrough**
Game opens, the first line you see as a player is the root node, and two options, the root node children. You are told what choice you want to make.

Sample Output:
You turn right and start walking. After walking for what appeared to be four hours you encounter a lake. You approach the lake to see your reflection and see that you are now a  Do You:
1. A woman in your 20's, with fiery red hair and red eyes. Suddenly you see something in the woods, you stand up and look at where you heard a sound, you feel someone behind you, and dodge an attack. You start fighting with the person that
   tried to hit you and then another person appears. You are not surprised with this new fighting skills since they always come with the body you are inhabiting.
2. A child that appeared to be 10 years old. Short brown hair and brown eyes. Suddenly you see something in the woods, you stand up and look at where you heard a sound, you feel pain on your head and black out.
   Enter choice:
   1

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(n^2)`  
- **Searching for an event in the tree** → `O(1)`  
- **Game traversal efficiency** → `O(1)`  

---

## **9. Edge Cases & Testing**
I tested the ending feature, if the player reached a leaf node, then the game should end correctly. 
I also tested that if when the player enters a number that is not 1 or 2, then the player is told to enter their choice again.
Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
I did not add any extra features. All the features remained the same. I did add a traversal function, to be able to test the code. And I also added a stringtoInt function to be able to change string from the file to an integer. 

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
