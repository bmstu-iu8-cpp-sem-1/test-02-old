# Рубежный контроль 2

### Инструкция
Прототипы функций должны быть вынесены в `.hpp` файл.
Все `.cpp` файлы добавить в `CMakeLists.txt`

### Задание 1
Реализовать функцию, которая вернет количество цифр в строке. Воспользуйтесь функцией `isdigit`
Пример использования функции:
```cpp
std::string s = "0a 13";
int cnt = countOfDigit(s);
// cnt == 3
```

### Задание 2
Дан динамический массив слов. Требуется реализовать функцию сортировки по возрастанию этого массива. В качестве условия сравнения использовать количество цифр в строке.
Например, строка `ccc1` меньше чем строка `aa22`, потому что в ней меньше цифр.

### Задание 3
Реализовать функцию `zip`, которая преобразует два массива в `map`, где значения из первого массива являются ключами, а значения второго массива значениями в `map`.

Пример использования функции:
```cpp
std::vector<std::string> k = {"a", "b", "c"};
std::vector<int> v = {0, 1, 2};
std::map<std::string, int> dict = zip(k, v);
// dict == {{"a", 0}, {"b", 1}, {"c", 2}}
```

### Задание 4
Реализовать функцию, которая удаляем из списка слов все слова, количесто которых больше чем 1.

Пример использования функции:
```cpp
std::list<std::string> words = {"a", "b", "c", "a", "a", "d", "b"};
clear(words);
// words == {"c", "d"};
// удалили все слова "a", потому что в списке их 3
// удалили все слова "b", потому что в списке их 2
// "c" и "d" оставили, потому что в списке их по 1
```

### Задание 5
Реализовать функцию, которая разворачивает `std::map<std::string, int>` в `std::vector<std::string>`. См. пример

Пример использования функции:
```cpp
std::map<std::string, int> dict = {{"a", 0}, {"b", 1}, {"c", 3}, {"d", 2}};
std::vector<std::string> v = unzip(dict);
// v == {"b", "c", "c", "c", "d", "d"};
// массив состоит из нуля строк "a", из одного слова "b", из трех слов "c" и из двух слов "d"
```
