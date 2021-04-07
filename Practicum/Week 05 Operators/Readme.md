## Задача 1
Да се реализира клас __Time__, който има член-данни hour, minute от целочислен тип. Да се предефинират операциите събиране и присвояване за реализиране на следните видове изрази: ```// Time t1, t2, t3, t4, t5;```

* t1 + t2
* t3 = t1 + t2
* t4 = t1 + 5
* t5 = 6 + t1
* t1 > t2

## Задача 2
Да се реализира програма __WashingMashines__, която прочита характеристиките на __N__ перални и отпечатва коя притежава най-оптимални характеристики (най-голям маса пране, най-ниска консумация на електроенергия, най-ниска консумация на вода). Една пералня се описва от следните параметри:  		

- производител (char\*, max. 32)
- модел (char\*, max. 32)
- маса пране (int)
- електро консумация (double)
- консумация на вода (int)

Приложете добрите практики на обектно ориентираното програмиране и за намиране на оптимума да се предефинира една от операциите __<__ / __>__ .

Примерен вход:
```
3
AEG
7000
7
3.5
5
Miele
WWD120
8
3.0
6
Indesit
961480X
6
4.0
10
```

Примерен изход:
```
AEG 7000
```

## Задача 3
Да се преработи решението на задачата за университета и студентите (Week03, Task03) като се предефинират следните операции: 
* `university += student` - добавя студент
* `university -= student` - премахва студент
* `university[i]` - връща студента на i-та позиция
* `<< student` - отпечатва студента