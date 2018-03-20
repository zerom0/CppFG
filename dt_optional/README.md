Datatype optional<>
===================

Introduction
------------
_Optional_ is a new datatype introduced in [C++17](http://en.cppreference.com/w/cpp/utility/optional) that allows for optionally set return values, parameters or variables.
It's aim is to make it explicit if a value is valid or if there are cases where it is unset.
This makes the code more readable and safe as optional values cannot be used before they have been set.

The datatype _optional_ is also known in other programming languages like Rust, Haskell and Scala, although it is sometimes called _Maybe_.

Since the datatype was introduced in C++17 and is not yet available in all compilers yet, this **example uses an implementation of a similar datatype** that can also be used in C++11 projects.

Examples
--------

### Optional return value and optional variable

```
// optional<Address> AddressBook::getByName(std::string const& name) const;

auto address = addressbook.getByName("Martin");
if (address) {
  doSomethingWith(address.value());
}
```

### Optional parameter

```
void AddressBook::addAddress(string name, optional<unsigned> age);
```

### Fallback/default values

```
optional<unsigned> httpPort = getConfigParameter("port");

auto server = Http::startAtPort(httpPort.value_or(80));
```

Exercise
--------

Get familiar with the code in the example directory and think about use cases where the datatype optional would make sense for you.
If you don't have a development environment available right now you can play with the new datatype at [Coliru](http://coliru.stacked-crooked.com).


Conclusions
-----------

- Good for value objects.
- For pointers it is redundant information as a _nullptr_ indicates an unset value.
- The C++17 standard defines _nullopt_ or _{}_ to initialize an unset _optional_.