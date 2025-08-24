# 📚 Algorithms & Data Structures in C++

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Build](https://img.shields.io/badge/build-passing-brightgreen.svg)
![Topics](https://img.shields.io/badge/topics-C++%20%7C%20Algorithms%20%7C%20Data%20Structures-orange.svg)

A comprehensive collection of fundamental algorithms and data structures implemented in C++. This repository serves as an educational resource for computer science students and developers looking to strengthen their understanding of core programming concepts.

## 📖 Table of Contents

- [Overview](#-overview)
- [Data Structures](#-data-structures)
- [Algorithms](#-algorithms)
- [Installation & Usage](#-installation--usage)
- [Examples](#-examples)
- [Contributing](#-contributing)
- [License](#-license)
- [Resources](#-resources)

## 🌟 Overview

This repository contains implementations of essential data structures and algorithms in C++, focusing on clarity, efficiency, and educational value. Each implementation includes detailed comments and usage examples to facilitate learning.

## 🏗️ Data Structures

### 1. Stack (Array-based)
**Location**: `stack/array_stack.cpp`

A last-in-first-out (LIFO) data structure implemented using arrays.

**Features**:
- Push operation: O(1)
- Pop operation: O(1)
- Peek operation: O(1)
- Dynamic resizing
- Empty/full checks

**Interface**:
```cpp
template <typename T>
class ArrayStack {
public:
    ArrayStack(int capacity = 10);
    void push(const T& value);
    T pop();
    T peek() const;
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
};
```

### 2. Stack (Linked List-based)
**Location**: `stack/linked_stack.cpp`

A stack implementation using linked nodes for dynamic memory allocation.

**Features**:
- No fixed capacity limitations
- Efficient memory usage
- All operations O(1) time complexity

### 3. Linked List
**Location**: `linkedlist/`

**Types**:
- **Singly Linked List** (`singly_linked_list.cpp`)
- **Doubly Linked List** (`doubly_linked_list.cpp`)
- **Circular Linked List** (`circular_linked_list.cpp`)

**Operations**:
- Insertion (beginning, end, specific position)
- Deletion (beginning, end, specific position)
- Searching
- Traversal (forward and backward for doubly linked)
- Reverse

### 4. Trees
**Location**: `trees/`

**Binary Search Tree (BST)** (`binary_search_tree.cpp`):
- Insertion, deletion, searching
- In-order, pre-order, post-order traversals
- Minimum/maximum value finding
- Successor/predecessor finding

**AVL Tree** (`avl_tree.cpp`):
- Self-balancing BST
- Rotations (left, right, left-right, right-left)
- Height balancing

**Binary Heap** (`binary_heap.cpp`):
- Min-heap and max-heap implementations
- Insertion and extraction
- Heapify operations

## ⚡ Algorithms

### Sorting Algorithms
**Location**: `algorithms/sorting/`

- **Bubble Sort** (`bubble_sort.cpp`)
- **Selection Sort** (`selection_sort.cpp`)
- **Insertion Sort** (`insertion_sort.cpp`)
- **Merge Sort** (`merge_sort.cpp`)
- **Quick Sort** (`quick_sort.cpp`)
- **Heap Sort** (`heap_sort.cpp`)

### Searching Algorithms
**Location**: `algorithms/searching/`

- **Linear Search** (`linear_search.cpp`)
- **Binary Search** (`binary_search.cpp`)
- **Depth-First Search (DFS)** (`dfs.cpp`)
- **Breadth-First Search (BFS)** (`bfs.cpp`)

### Tree Algorithms
**Location**: `algorithms/tree/`

- **Tree Traversals** (`traversals.cpp`)
- **Height Calculation** (`tree_height.cpp`)
- **Diameter Calculation** (`tree_diameter.cpp`)
- **Lowest Common Ancestor** (`lca.cpp`)

## 🚀 Installation & Usage

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- CMake (optional, for building all examples)
- Git

### Clone the Repository
```bash
git clone https://github.com/your-username/algorithms-data-structures.git
cd algorithms-data-structures
```

### Compiling Individual Files
```bash
g++ -std=c++17 stack/array_stack.cpp -o array_stack
./array_stack
```

### Building with CMake (Recommended)
```bash
mkdir build
cd build
cmake ..
make
```

## 💡 Examples

### Stack Example
```cpp
#include "stack/array_stack.cpp"

int main() {
    ArrayStack<int> stack(5);
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    std::cout << "Top element: " << stack.peek() << std::endl;
    std::cout << "Popped: " << stack.pop() << std::endl;
    std::cout << "Stack size: " << stack.size() << std::endl;
    
    return 0;
}
```

### Linked List Example
```cpp
#include "linkedlist/singly_linked_list.cpp"

int main() {
    SinglyLinkedList<int> list;
    
    list.insertAtEnd(10);
    list.insertAtBeginning(5);
    list.insertAtPosition(2, 15);
    
    list.display();
    std::cout << "Element at position 1: " << list.getElement(1) << std::endl;
    
    list.deleteFromEnd();
    list.display();
    
    return 0;
}
```

### Binary Search Tree Example
```cpp
#include "trees/binary_search_tree.cpp"

int main() {
    BST<int> bst;
    
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    
    std::cout << "In-order traversal: ";
    bst.inOrder();
    std::cout << std::endl;
    
    std::cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not found") << std::endl;
    
    return 0;
}
```

## 🤝 Contributing

We welcome contributions to enhance this repository! Please follow these steps:

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### Contribution Guidelines
- Follow the existing code style and formatting
- Add comments to explain complex algorithms
- Include test cases for new implementations
- Update the documentation accordingly
- Ensure all existing tests pass

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 📚 Resources

### Recommended Books
- "Introduction to Algorithms" by Cormen, Leiserson, Rivest, and Stein
- "Data Structures and Algorithm Analysis in C++" by Mark Allen Weiss
- "The C++ Programming Language" by Bjarne Stroustrup

### Online Courses
- [C++ For C Programmers](https://www.coursera.org/learn/c-plus-plus-a)
- [Data Structures and Algorithms](https://www.coursera.org/specializations/data-structures-algorithms)
- [Algorithmic Toolbox](https://www.coursera.org/learn/algorithmic-toolbox)

### Useful Links
- [C++ Reference](https://en.cppreference.com/)
- [GeeksforGeeks Data Structures](https://www.geeksforgeeks.org/data-structures/)
- [Visualgo Algorithm Visualizations](https://visualgo.net/en)

## 🏆 Acknowledgments

- Thanks to all contributors who have helped improve this repository
- Inspired by various computer science curricula and textbooks
- Special thanks to the open-source community for valuable feedback

---

<div align="center">

**Happy Coding!** 🚀

</div>
