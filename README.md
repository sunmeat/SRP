# SingleResponsibilityPrinciple

Single Responsibility Principle (SRP) – принцип единственной обязанности, принцип разделения обязанностей (на каждый класс должна быть возложена одна единственная обязанность, а также класс должен иметь одну и только одну причину для изменений).

Именно этот принцип является реализацией условия «сильное внутреннее сцепление». Он как раз и занимается усилением связей внутри класса.

https://www.youtube.com/watch?v=ph6IIeGTmmw

=============================================================

задания для практики:

№1. Вам необходимо написать класс для работы с базой данных, который будет иметь следующие методы: подключение к базе данных, выполнение запросов к базе данных, получение результатов запросов. Однако, класс не должен иметь ответственности за логику обработки результатов запросов.

Ваша задача - реализовать этот класс, следуя принципу единственной ответственности. Разделите функциональность класса так, чтобы каждый метод выполнял только одну ответственность. Весь код, связанный с обработкой результатов запросов, должен быть вынесен в отдельный класс с соответствующими методами.

Таким образом, вы создадите систему, которая будет легко расширяемой и поддерживаемой, и которая будет соответствовать принципу единственной ответственности. Вы сможете легко изменять методы обработки результатов запросов, не затрагивая код самого класса для работы с базой данных.

№2. Вам нужно написать класс для работы с файлами, который должен иметь методы для чтения, записи и удаления файлов. Однако, класс не должен быть ответственным за логику обработки данных, которые хранятся в файлах.

Ваша задача - реализовать этот класс, следуя принципу единственной ответственности. Разделите функциональность класса так, чтобы каждый метод выполнял только одну ответственность. Весь код, связанный с обработкой данных из файлов, должен быть вынесен в отдельный класс с соответствующими методами.

Таким образом, вы создадите систему, которая будет легко расширяемой и поддерживаемой, и которая будет соответствовать принципу единственной ответственности. Вы сможете легко изменять методы обработки данных, не затрагивая код самого класса для работы с файлами.
