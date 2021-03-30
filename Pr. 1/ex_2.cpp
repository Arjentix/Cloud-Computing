#include <iostream>
#include <list>
#include <map>
#include <string>
#include <iterator>

using Strings = std::list<std::string>;

std::ostream &operator<<(std::ostream &os, const Strings &strings) {
  os << '{';
  bool first = true;
  for (auto &s : strings) {
    if (!first) {
      os << ", ";
    }

    os << "[" << s << " -> " << s.length() << "]";
    first = false;
  }

  os << '}';
  return os;
}

Strings FilterMaxLen(Strings::iterator first, Strings::iterator last) {
  // Если передан диапазон с одним элементом, то вернуть его
  if (std::next(first) == last) {
    return Strings(first, last);
  }

  Strings strings(first, last);

  Strings::iterator cur_it = strings.begin();
  Strings::iterator next_it = std::next(cur_it);
  if (next_it->compare(*cur_it) >= 0) { // Если следующая строка лексикографически больше текущей
    if (next_it->find(*cur_it) != std::string::npos) { // И текущая является подстрокой следующей
      strings.erase(cur_it); // Удалить текущую
      return FilterMaxLen(strings.begin(), strings.end());
    }
    // Иначе это строка с другой буквой, игнор
  } else { // Если текущая строка лексикографически больше следующей
    strings.erase(next_it); // Удалить следующую
    return FilterMaxLen(strings.begin(), strings.end());
  }

  // Если удалять нечего, то запустить алгоритм с элемента следующего за начальным,
  // а сам начальный элемент потом вставить в начало результата
  Strings res = FilterMaxLen(std::next(strings.begin()), strings.end());
  res.push_front(*cur_it);
  return res;
}

int main() {
  // Буквы должны идти по возрастанию в алфавитном порядке
  Strings strings = {"aa", "aaaaaaa", "b", "b", "bbbbbb", "cccc", "c"};

  std::cout << FilterMaxLen(strings.begin(), strings.end()) << std::endl;

  return 0;
}
