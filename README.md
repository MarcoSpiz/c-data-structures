# Data Structures in C

This repository contains implementations of fundamental data structures in C. These are **toy implementations** created for educational purposes and fun demonstration.

## Overview

The goal of this project is to provide clean, well-documented implementations of common data structures with a focus on:
- Memory efficiency
- Performance optimization where possible
- Generic programming using `void*` pointers
- Clear, readable code structure

## Implemented Data Structures

### LinkedList

A doubly-referenced singly linked list implementation with optimizations for common operations.

#### Key Features:
- **Head and Tail pointers**: Maintains references to both the first and last elements, enabling O(1) insertion at both ends
- **Generic data storage**: Uses `void*` pointers to store any data type
- **Flexible insertion**: Support for insertion at start, end, or any specified index
- **Memory efficient**: Only allocates memory for nodes, not for data storage
- **Callback-based operations**: Uses function pointers for comparison operations, making it type-agnostic

#### Performance Characteristics:
- **Insert at start**: O(1)
- **Insert at end**: O(1)
- **Insert at index**: O(n)
- **Delete by value**: O(n)
- **Delete at index**: O(n)
- **Search**: O(n)
- **Get element at index**: O(n)
- **Size**: O(n)

#### API Functions:
- `init_linkedlist()` - Initialize empty list
- `add_element_at_start()` - Add element at beginning
- `add_element_at_end()` - Add element at end
- `add_element_at_index()` - Add element at specific position
- `delete_element()` - Remove first occurrence of value
- `delete_element_at_index()` - Remove element at specific position
- `find_element()` - Search for element and return index
- `get_element_at_index()` - Retrieve element at specific position
- `size()` - Get number of elements
- `clear()` - Free all elements

## Planned Implementations

Future data structures to be added:
- **Stack** - LIFO data structure
- **Queue** - FIFO data structure
- **Binary Search Tree** - Self-balancing tree structure
- **Hash Table** - Key-value storage with hash-based indexing
- **Dynamic Array** - Resizable array implementation
- **Heap** - Priority queue implementation

## Building

```bash
gcc main.c linkedlist/linkedlist.c
```

## Notes

- This is **toy code** intended for learning and demonstration purposes
- Memory management of stored values is the responsibility of the caller
- All implementations prioritize code clarity over maximum performance
- Designed to be easily readable and educational

## License

This project is open source and available under the MIT License.
