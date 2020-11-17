Hash-Table
A Hash-Table is a data structure that maps keys to values.

Each position of the Hash-Table is called a slot.

The Hash-Table uses a hash function to calculate an index of an array of slots. We use the Hash-Table when the number of keys actually stored is small relatively to the number of possible keys.

The process of storing objects using a hash function is as follows:

1. Create an array of size M to store objects, this array is called Hash-Table.

2. Find a hash code of an object by passing it through the hash function.

3. Take module of hash code by the size of Hash-Table to get the index of the table where objects will be stored.

4. Finally store these objects in the designated index.

The process of searching objects in Hash-Table using a hash function is as follows:
1. Find a hash code of the object we are searching for by passing it through the hash function.

2. Take module of hash code by the size of Hash-Table to get the index of the table where objects are stored.

3. Finally, retrieve the object from the designated index.

Hash-Table Abstract Data Type (ADT)
ADT of Hash-Table contains the following functions:
Insert(x): Add object x to the data set.
Delete(x): Delete object x from the data set.
Search(x): Search object x in data set.
The Hash-Table is a useful data structure for implementing dictionary. The
average time to search for an element in a Hash-Table is O(1). A Hash Table
generalizes the notion of an array.
HashSet implementation of C++ Collections
unordered_set<> is a class which implements set which means that it store only
unique elements. unordered_set<> is implemented using a hash table. Since
unordered_set<> is implemented using a hash table its elements are not stored in
sequential order.
Example 4.8
int main()
{
// Create a hash set.
std::unordered_set<std::string> hs;
// Add elements to the hash set.
hs.insert("India");
hs.insert("USA");
hs.insert("Brazile");
hs.insert("Canada");
hs.insert("UK");
hs.insert("China");hs.insert("France");
hs.insert("Spain");
hs.insert("Italy");
for each (auto var in hs)
{
std::cout << var<< " ";
}s
td::cout << std::endl;
std::cout << "Hash Table contains USA : " << (std::find(hs.begin(), hs.end(), "USA") != hs.end()) <<
std::endl;
std::cout << "Hash Table contains Russia : "<< (std::find(hs.begin(), hs.end(), "Russia") != hs.end())
<< std::endl;
hs.erase("USA");
for each (auto var in hs)
{
std::cout << var<<" ";
}s
td::cout << std::endl;
std::cout << "Hash Table contains USA : " << (std::find(hs.begin(), hs.end(), "USA") != hs.end() )<<
std::endl;
return 0;
} O
utput
Italy India China USA Spain Brazile Canada UK France
Hash Table contains USA : 1
Hash Table contains Russia : 0
Italy India China Spain Brazile Canada UK France
Hash Table contains USA : 0
Comparison of various Set classes.
std::set std::unordered_set
Storage Red-Black Tree Hash Table
Performance Slower than unordered_set,
O(log(N))
Fastest, constant time
Order of Iteration Increasing Order No order guarantee
Map implementation in C++ Collection
A Map<> is a data structure that maps keys to values. Also called a dictionary. A
Map<> is implemented using a hash table so the key value pairs are not stored in
sorted order. Map<> does not allow duplicate keys buts values can be duplicate.Example 4.9
#include <unordered_map>
int main()
{
// Create a hash map.
std::unordered_map<std::string, int> hm;
// Put elements into the map
hm["Mason"] = 55;
hm["Jacob"] = 77;
hm["William"] = 99;
hm["Alexander"] = 80;
hm["Michael"] = 50;
hm["Emma"] = 65;
hm["Olivia"] = 77;
hm["Sophia"] = 88;
hm["Emily"] = 99;
hm["Isabella"] = 100;
std::cout << "Total number of students in class :: " << hm.size() << std::endl;
for (auto key : hm)
{
std::cout << key.first << (" score marks :") << hm[key.first] << std::endl;
}a
uto temp = hm.find("Emma") != hm.end();
std::cout << "Emma present in class :: " << temp << std::endl;
auto result = hm.find("John") != hm.end();
std::cout <<"John present in class :: " << result << std::endl;
return 0;
} O
utput
Total number of students in class :: 10
Mason score marks :55
Sophia score marks :88
Emily score marks :99
Alexander score marks :80
Jacob score marks :77
William score marks :99
Michael score marks :50
Emma score marks :65
Olivia score marks :77
Isabella score marks :100
Emma present in class :: 1
John present in class :: 0

Comparison of various map classes.
| | std::map | std::unordered_map |
|-|----------|--------------------|
|Storage | Red-Black Tree | Hash Table |
|Performance | Slower than unordered_map,O(log(N)) | Fastest, constant time |
| Order of Iteration | Increasing Order of keys | No order guarantee |
