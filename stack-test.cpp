#include "stack.h"
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>

int main()
{
    Stack<int> s;
    assert(s.empty() && s.size() == 0);

    s.push(10);
    s.push(20);
    const Stack<int>& view = s;
    assert(!view.empty() && view.size() == 2);
    assert(view.top() == 20);
    assert(view.size() == 2); // top() must not remove anything

    s.pop();
    assert(s.top() == 10 && s.size() == 1);
    s.pop();
    assert(s.empty() && s.size() == 0);

    bool threw = false;
    try { s.top(); }
    catch (const std::underflow_error&) { threw = true; }
    assert(threw);

    threw = false;
    try { s.pop(); }
    catch (const std::underflow_error&) { threw = true; }
    assert(threw);
    assert(s.empty() && s.size() == 0);

    Stack<std::string> words;
    words.push("hello");
    assert(words.top() == "hello");
    words.pop();
    assert(words.empty());

    std::cout << "All stack tests passed!\n";
}
