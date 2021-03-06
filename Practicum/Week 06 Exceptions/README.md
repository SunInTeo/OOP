## Задача 1
В настоящите особени времена всяка обществена институция има нужда от билетна система осигуряваща ред и дистанция при опашките за обслужване на клиенти. В тази връзка реализирайте следните класове:
- class **Ticket**
	* трябва да пази информация за име (символен низ) и телефон (символен низ) на клиента, както и поредния му номер (уникално целочислено число)
	* реализирайте подходящи конструктор/деструктори и getter/setter методи
	* предефинирайте операторите за вход (*>>*) и изход(*<<*)
	* направете валидация името да съдържа само букви и интервали (' ') иначе да хвърля изключение *invalid_argument*
	* направете валидация телефонния номер да бъде 10 цифри иначе да хвърля изключение *length_error*
- class **Queue**, който има следните функции
	* *Queue(int size)* - осигурява максималната дължина на опашката
	* _int getTicket(const char* name, const char* phone)_ - който добавя нов билет в системата и връща поредния му номер, а ако е запълнен капацитета на опашката хвърля overflow_error;
	* да се предефинира оператора *[]*, който спрямо поредния номер връща билета, с този номер; а ако няма намерен билет хвърля invalid_argument
	* *Ticket next()* - изважда следващия от опашката
	* *bool empty() const*
	* *int getSize() const*

## Задача 2
Форест решил да тръгне на преход в планината и за целта си взел раница от *N* литра, но иска да не му тежи повече *М* килограма. Помогнете му да си подреди багажа в раницата като реализирате следните класове:
- class **Item**
	* има член-данни име, тегло и обем
	* _Item(const char* label, double weight, double volume)_
	* предефинирайте операторите *==*, *>*, *=*
- class **Backpack**
	* може да събира различни обекти от **Item** в определения обем и желаното тегло
	* *Backpack(double volume, double maxWeight)*
	* _void add(const Item &item)_ - ако не може да се добави следващия предмет поради недостатъчен обем хвърлете *VolumeOverflow* (дефиниран от вас), а при тегло хвърлете *WeightOverflow* (дефиниран от вас)
	* *int size()*
	* *double leftVolume()*
	* *double leftWeight()*
	* предефинирайте оператора *[]*, ако индекса е по-голям от текущия брой item-и хвърлете *out_of_range*