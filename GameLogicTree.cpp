#include <iostream>
#include <string>
#include <memory>  
#include <cstdlib> 
#include <ctime>   
#include <stack>

struct TreeNode {
    std::string text;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    TreeNode(const std::string& t) : text(t), left(nullptr), right(nullptr) {}
};

void playGame(TreeNode* root, int depth) {
    std::stack<TreeNode*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty() && depth > 0) {
        TreeNode* currentNode = nodeStack.top();
        nodeStack.pop();

        std::cout << currentNode->text << std::endl;

        // Base case: leaf node (end of the game)
        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            std::cout << "Game Over!" << std::endl;
            return;
        }

        // Player makes a choice
        std::string choice;
        std::cout << "Enter your choice (left/right): ";
        std::cin >> choice;

        // Update current node based on the player's choice
        if (choice == "left" && currentNode->left != nullptr) {
            nodeStack.push(currentNode->left.get());
        } else if (choice == "right" && currentNode->right != nullptr) {
            nodeStack.push(currentNode->right.get());
        } else {
            std::cout << "Invalid choice. Try again." << std::endl;
        }

        --depth;
    }
}

// Function to add random outcomes to certain nodes
void addRandomOutcomes(TreeNode* root) {
    if (root != nullptr) {
        // Introduce randomness at specific nodes
        if (rand() % 2 == 0) {
            root->left = std::make_unique<TreeNode>("You find a hidden treasure chest!");
        } else {
            root->left = std::make_unique<TreeNode>("You encounter a mischievous imp.");
        }

        if (rand() % 2 == 0) {
            root->right = std::make_unique<TreeNode>("A magical portal appears before you.");
        } else {
            root->right = std::make_unique<TreeNode>("You hear eerie whispers in the wind.");
        }

        // Recursively add random outcomes to left and right subtrees
        addRandomOutcomes(root->left.get());
        addRandomOutcomes(root->right.get());
    }
}

int main() {
    
    // Seed the random number generator with the current time
    srand(static_cast<unsigned>(time(nullptr)));

    // Build a simple binary decision tree
    std::unique_ptr<TreeNode> root = std::make_unique<TreeNode>("You find yourself in a mysterious forest.");

    // Add random outcomes to certain nodes
    addRandomOutcomes(root.get());

    // Start the game
    playGame(root.get(), 3);

    return 0;
}
