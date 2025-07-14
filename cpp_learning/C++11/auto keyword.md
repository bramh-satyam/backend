# Type Inference

## What is type inference?

- automatic deduction of data type of an expression in a programming language.
- this avoid wasting time on writing the type of the variable that compiler already knows, since all the types are deduced at the compile time, the compile time increases but it doesn't affect the runtime of the created program. 
- There are 2 types of type inference in C++:
    - `auto` keyword
    - `decltype` type specifier

## auto keyword

- `auto` keyword indicates the type of declared variable to be deduced automatically from its initializer.
- If the return type of a function is `auto`, it is evaluated by the returned type expression.
> **⚠️ IMPORTANT:** Note the variable declared with `auto` keyword needs to be initialized at declaration time. Otherwise, a compilation error occurs!

- **Using auto helps avoid long initialization(specially when creating iterators for containers).**

```cpp
auto x = 4.5f; // this would make "x" float
auto x = 4; // "x" is int now
auto x = 4.56; // "x" is a double now
```


## decltype type specifier

- `decltype` specifier inspects the declared type of an entity or the type of the expression.
- basically it returns the type of expression passed to it!

```cpp
bool foo() {return true;}

int main(){
    decltype(foo()) x;  // now "x" is of same type function foo returns
}
```

## Using decltype and auto 

```cpp
int main()
{
    std::vector<int> vec(5);

    // using auto 
    for(auto i : vec){
        std::cin >> *i;
    }

    // using auto -> another way
    for(auto i = vec.begin(); i < vec.end(); i++){
        std::cin >> *i;
    }

    // using decltype
    for(decltype(vec.begin()) i = vec.begin(); i < vec.end(); i++){
        std::cin >> *i;
    }
}
```

> **⚠️ IMPORTANT:** Note the type denoted by decltype and the type deduced by auto can be different!

```cpp
// example where the type would be different from decltype and auto
auto x = 42;
int& ref = x;

// auto removes reference
auto a = ref;       // a comes out to be of type "int" which is wrong

// decltype keeps exact type(including reference)
decltype(ref) d = ref;      // d comes out to be of type "int&"
```

> auto deduces the value type and not referenc(unless you explicitly write auto&), while decltype gives you the exact declared type - including "&", "const" etc!


## Summary

- Well its not same, auto is used for automatic deduction whereas decltype yields the type of a specified expression. 
- auto deduced the type based on the value assigned to the variable while decltype deduces the type from the expression passed to it!


---

Alright! Let’s dive into some **trickier and interview-worthy cases** where `auto` vs `decltype` (and especially `decltype(auto)`) behave differently, particularly with:

* **functions returning references**
* **decltype with expressions**
* **decltype(auto) vs auto**

---

## 🔍 1. **Function Return (with and without reference)**

```cpp
int x = 10;

int& getRef() { return x; }
int  getVal() { return x; }

auto a1 = getRef();         // int (copy)
decltype(getRef()) d1 = getRef(); // int& (reference)

auto a2 = getVal();         // int
decltype(getVal()) d2 = getVal(); // int
```

👉 `auto` ignores that `getRef()` returns a reference — `a1` is a copy, but `d1` is a reference.

---

## 🔥 2. **`decltype(auto)` preserves references**

```cpp
int x = 100;

int& foo() { return x; }

auto a = foo();             // int (copy)
decltype(auto) b = foo();   // int& (reference)
```

> `decltype(auto)` is useful when you want to **preserve exact return type** including reference.

---

## 🧪 3. **`decltype(expression)` may give surprises**

```cpp
int a = 1;
int b = 2;

decltype(a + b) x = a + b;      // int
decltype((a)) y = (a);          // int& (!!)
```

### 💡 Why?

* `a + b` is an rvalue → `int`
* `(a)` is an **lvalue expression** → `decltype((a))` → `int&`

---

## 👁️‍🗨️ 4. **Trick with const**

```cpp
const int ci = 5;

auto a = ci;              // int (drops const)
decltype(ci) b = ci;      // const int
decltype((ci)) c = (ci);  // const int& (!!)
```

* `auto` drops `const`
* `decltype(ci)` preserves `const`
* `decltype((ci))` makes it a reference (because it's an lvalue)

---

## 💣 5. **Modifying reference vs value (Bug Source)**

```cpp
int x = 42;

auto a = x;
decltype(auto) b = (x);

a += 1;  // modifies a copy
b += 1;  // modifies x directly!
```

---

## TL;DR Rules:

| Expression       | Resulting Type                           |
| ---------------- | ---------------------------------------- |
| `auto`           | value type                               |
| `auto&`          | lvalue reference                         |
| `decltype(expr)` | exact deduced type (watch lvalue/rvalue) |
| `decltype(auto)` | preserves ref/const                      |

---

Let me know if you want to test these interactively or want `decltype(auto)` usage in return types of templates/functions!
