#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    int stringtoInt(const std:: string &str) {
        int num = 0;
        std::stringstream ss(str);
        ss>>num;
        return num;
    }
    void traversal(Node<T>* root) {
        if (root != nullptr) {
            traversal(root->left);
            cout<<root->data.eventNumber<<" ";
            traversal(root->right);
        }
    }

    void insert(Node<T>* parent, Node<T>* node) {
        if (root == nullptr) {
            root = node;
            return;
        }
        else {
            if(parent->left == nullptr && node->data.eventNumber == parent->data.leftEventNumber) {
                parent->left = node;
                return;
            }
            if(parent->right == nullptr && node->data.eventNumber == parent->data.rightEventNumber) {
                parent->right = node;
                return;
            }
        }
    }

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        ifstream myFile(filename);
        unordered_map<int, Node<T>*> storyMap;

        if(myFile.is_open()) {
            string description;
            int eventNum = 0;
            int leftNum = -1;
            int rightNum = -1;

            string tempString;
            string line;
            while(getline(myFile, line)) {
                stringstream ss(line);

                getline(ss, tempString, delimiter);
                eventNum = stringtoInt(tempString);
                getline(ss, description, delimiter);
                getline(ss, tempString, delimiter);
                leftNum = stringtoInt(tempString);
                getline(ss, tempString, delimiter);
                rightNum = stringtoInt(tempString);
                getline(ss, tempString, delimiter);

                Story story(description, eventNum, leftNum, rightNum);
                Node<T>* newNode = new Node<T>(story);
                storyMap.insert({eventNum,newNode});
            }
            myFile.close();
        }
        else {
            cout << "File could not be opened" << endl;
        }
        for(int i = 1; i <= storyMap.size(); i++) {
            Node<T>* currentNode = storyMap.at(i);
            Node<T>* parent;
            if(currentNode != nullptr) {
                if(currentNode->data.eventNumber == 1) {
                    insert(root, currentNode);
                }
                else {
                    for(int j = 1; j < currentNode->data.eventNumber; j++) {
                        parent = storyMap.at(j);
                        insert(parent, currentNode);
                    }
                }
            }
        }
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        cout<<"Welcome to the RPG"<<endl;
        Node<T>* current = root;
        int userInput = 1;
        while(userInput != -1 || current != nullptr){
            string description = current->data.description;
            if(current->data.leftEventNumber != -1 && current->data.rightEventNumber != -1) {
                cout<<""<<description<<" Do You: "<<endl;
                cout<<"1. "<<current->left->data.description<<endl;
                cout<<"2. "<<current->right->data.description<<endl;
                cout<<"Enter choice:"<<endl;
                cin>>userInput;
                if(userInput == 1) {
                    current = current->left;
                }
                else if(userInput == 2) {
                    current = current->right;
                }
                else{
                    cout<<"Choose between options 1 and 2"<<endl;
                }
            }
            else {
                cout<<description<<endl;
                cout<<""<<endl;
                break;
            }
        }
        cout<<"END.CURRENTLY UPDATING"<<endl;
    }
};

#endif // GAMEDECISIONTREE_H