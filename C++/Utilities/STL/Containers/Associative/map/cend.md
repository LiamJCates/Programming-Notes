# cend

**Description :** This function returns a constant iterator pointing to the theoretical element that follows last element in the multimap.

**Example** :

```cpp
// C++ program to illustrate the map::cend() function 
#include <bits/stdc++.h> 
  
int main() { 
  
    // initialize container 
    std::map<int, int> mp; 
  
    // insert elements in random order 
    mp.insert({ 2, 30 }); 
    mp.insert({ 1, 40 }); 
    mp.insert({ 3, 60 }); 
    mp.insert({ 4, 20 }); 
    mp.insert({ 5, 50 }); 
  
    // print the elements 
    std::cout << "\nThe map is : \n"; 
    std::cout << "KEY\tELEMENT\n"; 
    //cend() function called
    for (auto itr = mp.cbegin(); itr != mp.cend(); ++itr) { 
        std::cout << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    return 0; 
} 
```
**[Run Code](https://rextester.com/QMAMQ71096)**
