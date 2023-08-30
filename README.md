## Как сдавать лабораторные работы (лабы)
:bangbang: Перед началом выполнения лабы переключитесь на основную ветку (master) :bangbang:
* Создайте ветку для выполнения лабы
  * Имя ветки должно совпадать именем поддиректории выше в этой странице -- lab0, lab1-0, lab1-1 и т.д.
* Переключитесь на ветку с лабой
* Напишите код лабы в файле src/main.c
  * Почаще заливайте ваши правки
  * Можно разделить код на несколько файлов *.c и *.h и добавить *.c в set(SRC src/main.c) в CMakeLists.txt через пробел после src/main.c
* Исправьте все "падения" тестов
* Создайте мерж-реквест (merge request) из ветки в master
* Назначьте исполнителем (assignee) мерж-реквеста Вашего преподавателя по программированию
* Исправьте все замечания преподавателя

## Локальное тестирование лабы
* Рекомендуется скачать тестировщик из поддиректории test и перед заливкой лабы на сервер тестировать ее на своем ноуте/десктопе
  * Под Windows используйте тестировщик *.exe
  * Под Linux используйте тестировщик без расширения
  * Под MacOS соберите [тестировщик из исходного кода](https://github.com/Evgueni-Petrov-aka-espetrov/TestDriver)
* Это быстрее, чем ждать очереди на сервере
* Это уменьшает нагрузку на сервер

## Этапы тестирования лабы на сервере
* Отладочная сборка, ограничение по памяти 1Гб, ограничение по времени 1 минута
* Релизная сборка, ограничение по памяти и по времени из формулировки лабы
* Сборка с address sanitizer-ом (проверка работы с памятью и указателями), ограничение по памяти 1Гб, ограничение по времени 1 минута
* Сборка с undefined behavior sanitizer-ом (проверка на неопределенное поведение), ограничение по памяти 1Гб, ограничение по времени 1 минута
* Проверка стиля кода

## Правила оценивания лабы
0. Нет ветки с кодом лабы и/или нет правок на этой ветке = 0 баллов
1. Есть ветка с лабой, но лаба не собирается = 1 балл
2. Есть ветка с лабой, лаба собирается, но проходит меньше 50% тестов = 2 балла
3. Есть ветка с лабой, лаба собирается, но проходит меньше 100% тестов = 3 балла
4. Есть ветка с лабой, лаба собирается, проходит все тесты, но не исправлено замечание преподавателя = 4 балла
5. Есть ветка с лабой, лаба собирается, проходит все тесты, исправлены все замечания преподавателя = 5 баллов
