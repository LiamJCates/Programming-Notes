# Shared Bits

Determine if two unsigned numbers share bits

### Current Shortest

```c++
#define sharedbits(a, b) (!((a) & (b)))
```


### Implementations

```c++
bool sharedbits(unsigned long long a, unsigned long long b) {
  return !(a & b);
}
```

(a & b) == 0;
Is this faster than above?


(a ^ b) == (a | b)

Remainder of iterative division by 2

for (;a && b; a/=2, b/=2) 
  if(a%2 && b%2) return false;
return true;
