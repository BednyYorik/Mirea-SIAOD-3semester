#Вариант 25
<h4 align="center"> 
  
███╗░░░███╗██╗██████╗░███████╗░█████╗░  ░██████╗██╗░█████╗░░█████╗░██████╗░
████╗░████║██║██╔══██╗██╔════╝██╔══██╗  ██╔════╝██║██╔══██╗██╔══██╗██╔══██╗
██╔████╔██║██║██████╔╝█████╗░░███████║  ╚█████╗░██║███████║██║░░██║██║░░██║
██║╚██╔╝██║██║██╔══██╗██╔══╝░░██╔══██║  ░╚═══██╗██║██╔══██║██║░░██║██║░░██║
██║░╚═╝░██║██║██║░░██║███████╗██║░░██║  ██████╔╝██║██║░░██║╚█████╔╝██████╔╝
╚═╝░░░░░╚═╝╚═╝╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝  ╚═════╝░╚═╝╚═╝░░╚═╝░╚════╝░╚═════╝░
  
</h4>

<h4 align = "center">
  Практическое задание №5.
  
  Тема: Основные алгоритмы работы с графами.
</h4>

## Цель работы.

Изучение основных алгоритмов работы с графами.

### Постановка задачи.

- Составить программу создания графа и реализовать процедуру для работы с графом, определенную индивидуальным вариантом задания. 
- Самостоятельно выбрать и реализовать способ представления графа в памяти. 
- В программе предусмотреть ввод с клавиатуры произвольного графа. В вариантах построения остовного дерева также разработать доступный способ (форму) вывода результирующего дерева на экран монитора. 
- Провести тестовый прогон программы на предложенном в индивидуальном варианте задания графе. Результаты тестирования в виде скриншотов экранов включить в отчет по выполненной работе. 
- Сделать выводы о проделанной работе, основанные на полученных результатах. 
- Оформить отчет с подробным описанием рассматриваемого графа, принципов программной реализации алгоритмов работы с графом, описанием текста исходного кода и проведенного тестирования программы. Ход выполнения задания.

### Описание алгоритма Крускала.

- Механизм, по которому работает данный алгоритм, очень прост. На входе имеется пустой подграф, который и будем достраивать до потенциального минимального остовного дерева. Будем рассматривать только связные графы, в другом случае при применении алгоритма Краскала мы будем получать не минимальное остовное дерево, а просто остовной лес.
    - Вначале мы производим сортировку рёбер по неубыванию по их весам.
    - Добавляем i-ое ребро в наш подграф только в том случае, если данное ребро соединяет две разные компоненты связности, одним из которых является наш подграф. То есть, на каждом шаге добавляется минимальное по весу ребро, один конец которого содержится в нашем подграфе, а другой - еще нет.
    -	Алгоритм завершит свою работу после того, как множество вершин нашего подграфа совпадет с множеством вершин исходного графа.
- Данный алгоритм называется жадным из-за того, что мы на каждом шаге пытаемся найти оптимальный вариант, который приведет к оптимальному решению в целом.
